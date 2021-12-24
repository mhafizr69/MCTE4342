#include <EEPROM.h>

#define button 12
#define led 3

int state;

void setup() {
  
  Serial.begin(9600);
  
  pinMode(button,INPUT_PULLUP);
  pinMode(led,OUTPUT);
  
 //Read value from address 0 of EEPROM
  state = EEPROM.read(0);

}

void loop() {
 
  digitalWrite(led,state);

  int val = digitalRead(button);
  
  if (val == LOW)
  {
        state = !state;
  }
  
  //Serial.println(state);
  
  //Save the value of "state" inside EEPROM address 0
  EEPROM.update(0,state); 
  
}
