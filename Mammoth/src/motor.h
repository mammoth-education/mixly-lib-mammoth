#ifndef motor_h
#define motor_h

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <ESP32PWM.h>

#define DEBUG 0

#define MIN 0
#define MAX 100

class Motor {
  public:
    Motor();
    ESP32PWM PWM;
    int pin;
  
    void begin(int pin);
    void setStatus(int status);
    void setStatus(int status, int t);
    void setPower(int power, int t);

  private:
    int currentPower = 0;
    void write(int value);
};

#endif
