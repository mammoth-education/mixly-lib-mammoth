#ifndef servo_h
#define servo_h

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <ESP32Servo.h>

#define DEBUG 1

class MServo {
  public:
    MServo();

    int pin;
    int minPulse = 500;
    int maxPulse = 2500;
    int minAngle = 0;
    int maxAngle = 270;
    Servo myservo;
  
    void begin(int p);
    void begin(int p, int minPulse, int maxPulse, int minAngle, int maxAngle);
    void setAngle(int angle);

  private:
    void init();
};

#endif
