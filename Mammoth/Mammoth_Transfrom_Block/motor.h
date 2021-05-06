#ifndef motor_h
#define motor_h

#if (ARDUINO >= 100)
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#define DEBUG 1

#define LEDC_CHANNEL_0     0
#define LEDC_TIMER_13_BIT  13
#define LEDC_BASE_FREQ     100

#define MIN 0
#define MAX 100

class Motor {
  public:
    Motor();

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
