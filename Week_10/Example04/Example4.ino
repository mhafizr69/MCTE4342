#include <DCMotor.h>

DCMotor motor1('B',0,50);

void setup() {
  // put your setup code here, to run once:
  motor1.Write(0.5);
}

void loop() {
  // put your main code here, to run repeatedly:
  motor1.Refresh();
}
