#include <motor.h>
#include <servo.h>

MServo servo = MServo();
Motor motor = Motor();
void setup() {
  servo.begin(4);
  motor.begin(13);
}

void loop() {
  if (digitalRead(0) == 0){
    servo.setAngle(0);
    motor.setStatus(1);
  }
  if (digitalRead(5) == 0){
    servo.setAngle(180);
    motor.setStatus(0);
  }
}
