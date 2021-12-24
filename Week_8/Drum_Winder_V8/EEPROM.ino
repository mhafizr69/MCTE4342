#include <EEPROM.h>

void setup() {
  Serial.begin(9600);
  
 //Remember state of direction for low torque motor before arduino turned off or reset
  state = EEPROM.read(0);
  //Remember state of direction for low torque motor before arduino turned off or reset
  x = EEPROM.read(1); 

}

void loop() {

  flipCheck(); //Check if limit switch is pressed
  
  if (digitalRead(Button1) == LOW)
  {
      if (x == LOW){
        state = !state;
      }
    
      rollout(100, 800);
  }

  if (digitalRead(Button2) == LOW)
  {
      if (x == LOW){
        state = !state;
      }

      rollout(250, 800);
  }

  if (digitalRead(Button3) == LOW)
  {
      if (x == HIGH){
        state = !state;
      }
        
      rollin(250, 800);
  }

  if (digitalRead(Button4) == LOW)
  {
      if (x == HIGH){
        state = !state;
      }
      rollin(100, 800);
  }

  EEPROM.update(0,state); //Save the value of "state" inside EEPROM address 0
  EEPROM.update(1,x); ////Save the value of "x" inside EEPROM address 1
  
}

