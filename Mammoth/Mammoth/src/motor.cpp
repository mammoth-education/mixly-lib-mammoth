/*
Simple library to use a BH1745NUC Digital Light Sensor.
SunFounder 2021
*/

#include "motor.h"

/**
 * Constructor
 */
Motor::Motor() {}

/**
 * Configure sensor
 */
void Motor::begin(int p) {
  pin = p;
  
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  ESP32PWM::allocateTimer(3);

  if (ESP32PWM::hasPwm(pin) &&  // Is it possible for this pin to PWM
     (ESP32PWM::channelsRemaining() > 0 || // New channels availible to allocate
     pwmFactory(pin) != NULL || // already allocated this pin in the factory
     pin == 25 || pin == 26)) {// one of the  2 DAC outputs, no timer needed
    if (pwmFactory(pin) == NULL) {   // check if its the first time for the pin or its a DAC
      #if DEBUG == 1
      if (pin == 25 || pin == 26) {  // one of the 2 DAC outputs, no timer needed
        Serial.println("DAC to pin " + String(pin));
      } else
        Serial.println("Writing to pin " + String(pin));
      #endif
      PWM.attachPin(pin, 5000, 10);
    }
  } else {
    Serial.print("Pin is not avaiable");Serial.println(pin);
    while (1){
      delay(1000);
    }
  }
  #if DEBUG == 1
  Serial.begin(115200);
  #endif
}

void Motor::write(int value) {
  // uint32_t brightness = (255 / MAX) * min(value, MAX);
	// analogWrite(pin, brightness);
  float a = value / 100.0;
  PWM.writeScaled(a);
}

/**
 *  Set motor power
 */
void Motor::setStatus(int status){
  setStatus(status, 2);
}

void Motor::setStatus(int status, int t){
  setPower(status*70, t);
}

void Motor::setPower(int power, int t){
  int p = currentPower;
  while (1) {
    #if DEBUG == 1
    Serial.print("power: ");Serial.println(power);
    Serial.print("p: ");Serial.println(p);
    Serial.print("currentPower: ");Serial.println(currentPower);
    #endif
    write(p);
    if (power > currentPower){
      p += 1;
      if (p > power){
        break;
      }
    } else {
      p -= 1;
      if (p < power){
        break;
      }
    }
    delay(t);
  }
  currentPower = power;
}
