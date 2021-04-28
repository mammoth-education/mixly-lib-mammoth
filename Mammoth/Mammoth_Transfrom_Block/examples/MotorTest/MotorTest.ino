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
  motor.setStatus(1, 1000);
  delay(1000);
  motor.setStatus(0, 1000);
  delay(1000);
  motor.setPower(50, 1000);
  delay(1000);
  motor.setPower(20, 1000);
  delay(1000);
}