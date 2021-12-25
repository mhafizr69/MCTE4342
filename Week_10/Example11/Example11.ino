#include <ServoESDSweeper.h>

#include <ServoESD.h>

ServoESD motor1('B',0,20000);
ServoESD motor2('B',1,20000);
ServoESD motor3('B',2,20000);
ServoESD motor4('B',3,20000);

ServoESDSweeper a(&servo1,500,2000,10,15);
ServoESDSweeper b(&servo2,500,2000,10,20);
ServoESDSweeper c(&servo3,800,1500,10,15);
ServoESDSweeper d(&servo4,800,1500,10,20);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  a.Refresh();
  b.Refresh();
  c.Refresh();
  d.Refresh();
}
