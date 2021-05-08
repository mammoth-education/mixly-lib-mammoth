#ifndef servo_h
#define servo_h

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <ESP32Servo.h>

#define DEBUG 0

class MServo {
  public:
    MServo();

    int pin;
    int MIN_PULSE = 500;
    int MAX_PULSE = 2500;
    int MIN_ANGLE = 0;
    int MAX_ANGLE = 270;
    Servo myservo;
  
    void begin(int p);
    void begin(int p, int minPulse, int maxPulse, int minAngle, int maxAngle);
    void setAngle(int angle);

  private:
    void init();
};

#endif
