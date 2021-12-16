#include <motor.h>

Motor motor = Motor();
void setup() {
  motor.begin(13);
}

void loop() {
  motor.setStatus(1);
  delay(1000);
  motor.setStatus(0);
  delay(1000);
  motor.setStatus(1, 1);
  delay(1000);
  motor.setStatus(0, 2);
  delay(1000);
  motor.setPower(50, 3);
  delay(1000);
  motor.setPower(20, 4);
  delay(1000);
}