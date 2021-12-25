#include <ServoESD.h>

ServoESD servo('B',0,20000);

unsigned long last_time;
int Min = 544;
int Max = 2400;
int Step = 10;
int Delay_ms = 25;
int Current = Min;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
    unsigned long now =millis();
    if (now - last_time >= Delay_ms)
    {
      last_time = now;
      Current += Step;
      servo.Write(Current);
      if(Current >= Max || Current <= Min)
      {
        Step = -Step;
      }
    }
    servo.Refresh();
}
