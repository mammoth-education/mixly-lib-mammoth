/*
Simple library to use a BH1745NUC Digital Light Sensor.
SunFounder 2021
*/

#include "servo.h"

/**
 * Constructor
 */
MServo::MServo() {}

/**
 * Configure sensor
 */
void MServo::begin(int p) {
  pin = p;
  init();
}

void MServo::begin(int p, int min_pulse, int max_pulse, int min_angle, int max_angle) {
  pin = p;
  MIN_PULSE = min_pulse;
  MAX_PULSE = max_pulse;
  MIN_ANGLE = min_angle;
  MAX_ANGLE = max_angle;
  init();
}

void MServo::init(){
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
      pinMode(pin, OUTPUT);
    }
    myservo.setPeriodHertz(50);    // standard 50 hz servo
	  myservo.attach(pin, MIN_PULSE, MAX_PULSE, MIN_ANGLE, MAX_ANGLE); // attaches the servo on pin 18 to the servo object
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

/**
 *  Set motor power
 */
void MServo::setAngle(int angle){
  myservo.write(angle);
}
