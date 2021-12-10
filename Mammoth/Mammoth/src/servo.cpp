#include "servo.h"

MServo::MServo() {}

void MServo::begin(int p) {
  _pin = p;
  init();
}

void MServo::begin(int p, int minPulse, int maxPulse, int minAngle,
                   int maxAngle) {
  _pin = p;
  this->minPulse = minPulse;
  this->maxPulse = maxPulse;
  this->minAngle = minAngle;
  this->maxAngle = maxAngle;
  init();
}

void MServo::init() {
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  _checkPwm(_pin);
  _pwm = ESP32PWM();
  _pwm.attachPin(_pin, _freq, _resolution);
#if SERVO_DEBUG == 1
  Serial.begin(115200);
#endif
}

/**
 *  Set motor power
 */
void MServo::setAngle(int angle) {
#if SERVO_DEBUG == 1
  Serial.print("Set angle: ");Serial.println(angle);
#endif
  float pulseWidth;
  int value;
  if (angle < this->minAngle)
    angle = this->minAngle;
  else if (angle > this->maxAngle)
    angle = this->maxAngle;

  pulseWidth = map(angle, this->minAngle, this->maxAngle, this->minPulse,
              this->maxPulse);
  value = pulseWidth / 20000 * pow(2, 10);
#if SERVO_DEBUG == 1
  Serial.print("Set value: ");Serial.println(value);
#endif
  _pwm.write(value);
}

bool MServo::_checkPwm(int pin) {
  if (ESP32PWM::hasPwm(pin) &&  // Is it possible for this pin to PWM
      (ESP32PWM::channelsRemaining() >
           0 ||                    // New channels availible to allocate
       pwmFactory(pin) != NULL ||  // already allocated this pin in the factory
       pin == 25 ||
       pin == 26)) {  // one of the  2 DAC outputs, no timer needed
    if (pwmFactory(pin) ==
        NULL) {  // check if its the first time for the pin or its a DAC
#if SERVO_DEBUG == 1
      if (pin == 25 ||
          pin == 26) {  // one of the 2 DAC outputs, no timer needed
        Serial.println("DAC to pin " + String(pin));
      } else
        Serial.println("Writing to pin " + String(pin));
#endif
      pinMode(pin, OUTPUT);
    }
    return true;
  } else {
    Serial.print("Pin is not avaiable");
    Serial.println(pin);
    while (1) {
      delay(1000);
    }
  }
}