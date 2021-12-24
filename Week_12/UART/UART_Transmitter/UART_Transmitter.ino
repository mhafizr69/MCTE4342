//Transmitter

#include <SoftwareSerial.h>
SoftwareSerial softSerial(0, 1);

void setup()  
{
  softSerial.begin(9600);
} 
void loop()  
{ 
  softSerial.write("UART Communication");
  delay (100);
}
