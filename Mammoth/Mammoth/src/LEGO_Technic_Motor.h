#ifndef LEGO_Technic_Motor_h
#define LEGO_Technic_Motor_h

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <ESP32PWM.h>

#define DEBUG 0

class LEGO_Technic_Motor {
  public:
    LEGO_Technic_Motor();

  
    void begin(int pin1, int pin2, int freq=50, int resolution=10);
    void setSpeed(int speed);

  private:
    void init();
    int _pin1;
    int _pin2;
    ESP32PWM _pwm1;
    ESP32PWM _pwm2;
    int _freq;
    int _resolution;
    bool _checkPwm(int pin);
};

#endif
