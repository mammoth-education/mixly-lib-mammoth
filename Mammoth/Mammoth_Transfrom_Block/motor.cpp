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
void Motor::begin(int pin) {
  pin = pin;
  ledcSetup(LEDC_CHANNEL_0, LEDC_BASE_FREQ, LEDC_TIMER_13_BIT);
  ledcAttachPin(pin, LEDC_CHANNEL_0);
  analogWrite(LEDC_CHANNEL_0);
  #if DEBUG == 1
  Serial.begin(115200);
  #endif
}

void Motor::analogWrite(int value) {
  uint32_t duty = (8191 / MAX) * min(value, MAX);
  ledcWrite(pin, duty);
}

/**
 *  Set motor power
 */
void Motor::setStatus(int status){
  setStatus(status, 200);
}

void Motor::setStatus(int status, int t){
  setPower(status*100, t);
}

void Motor::setPower(int power, int t){
  int delta = power - currentPower;
  int dir = 1;
  if (delta > 0){
    dir = 1;
  } else {
    dir = -1;
  }
  delta = abs(delta);
  t = max(t/delta, 1);
  #if DEBUG == 1
  Serial.print("delta: ");Serial.println(delta);
  Serial.print("t: ");Serial.println(t);
  #endif
  if (dir > 0){
    for (int i=currentPower; i<=power; i += dir){
      #if DEBUG == 1
      Serial.print("power: ");Serial.println(i);
      #endif
      analogWrite(i);
      delay(t);
    }
  } else {
    for (int i=currentPower; i>=power; i += dir){
      #if DEBUG == 1
      Serial.print("power: ");Serial.println(i);
      #endif
      analogWrite(i);
      delay(t);
    }
  }
  currentPower = power;
}