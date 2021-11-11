#include "LEGO_Technic_Motor.h"

/**
 * Constructor
 */
LEGO_Technic_Motor::LEGO_Technic_Motor() {}

/**
 * Configure sensor
 */
void LEGO_Technic_Motor::begin(int pin1, int pin2, int freq, int resolution) {
  _pin1 = pin1;
  _pin2 = pin2;
  _pwm1 = ESPPWM();
  _pwm2 = ESPPWM();
  _freq = freq;
  _resolution = resolution;
  init();
}

void LEGO_Technic_Motor::init() {
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  if (ESP32PWM::hasPwm(pin) &&  // Is it possible for this pin to PWM
      (ESP32PWM::channelsRemaining() >
           0 ||                    // New channels availible to allocate
       pwmFactory(pin) != NULL ||  // already allocated this pin in the factory
       pin == 25 ||
       pin == 26)) {  // one of the  2 DAC outputs, no timer needed
    if (pwmFactory(pin) ==
        NULL) {  // check if its the first time for the pin or its a DAC
#if DEBUG == 1
      if (pin == 25 ||
          pin == 26) {  // one of the 2 DAC outputs, no timer needed
        Serial.println("DAC to pin " + String(pin));
      } else
        Serial.println("Writing to pin " + String(pin));
#endif
      pinMode(pin, OUTPUT);
    }
    _pwm1.attachPin(_pin1, _freq, _resolution);
    _pwm2.attachPin(_pin2, _freq, _resolution);
  } else {
    Serial.print("Pin is not avaiable");
    Serial.println(pin);
    while (1) {
      delay(1000);
    }
  }
#if DEBUG == 1
  Serial.begin(115200);
#endif
}

/**
 *  Set motor power
 */
void LEGO_Technic_Motor::setSpeed(int speed) {
  float power = abs(speed / 100.0);
  int duty = power * pow(2, _resolution);
  if (speed > 0) {
    _pwm1.setDuty(duty);
    _pwm2.setDuty(0);
  } else {
    _pwm1.setDuty(0);
    _pwm2.setDuty(duty);
  }
}
