#ifndef servo_h
#define servo_h

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <ESP32PWM.h>

#define SERVO_DEBUG 0

class MServo {
  public:
    MServo();

    int minPulse = 905;
    int maxPulse = 2125;
    int minAngle = 0;
    int maxAngle = 180;
  
    void begin(int p);
    void begin(int p, int minPulse, int maxPulse, int minAngle, int maxAngle);
    void setAngle(int angle);

  private:
    void init();
    bool _checkPwm(int pin);
    int _pin;
    ESP32PWM _pwm;
    int _freq = 50;
    int _resolution = 10;
};

#endif
