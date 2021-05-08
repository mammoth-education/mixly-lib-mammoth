#include <motor.h>
#include <servo.h>

#define DEBUG 1

MServo servo = MServo();
int minAngle = 0;
int maxAngle = 180;
void setup() {
  servo.begin(4);
}

void loop() {
  for (int i = minAngle; i <= maxAngle; i++) {
    servo.setAngle(i);
    delay(10);
  }
  for (int i = maxAngle; i >= minAngle; i--) {
    servo.setAngle(i);
    delay(10);
  }
}
