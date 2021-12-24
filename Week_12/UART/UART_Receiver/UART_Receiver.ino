//Receiver

#include <SoftwareSerial.h>
SoftwareSerial softSerial(0, 1);
char ip;
void setup()  
{
  softSerial.begin(9600);
} 
void loop()  
{ 
  if (softSerial.available())
  {
    ip=softSerial.read();
    softSerial.println(ip);
  }
}
