#include <EEPROM.h>

//This code works well. Next, plan to make starting position for Low Torque motor
//Motor driver pin for High Torque
const int HTstepPin = 11;
int HTdirPin = 10;

//Motor driver pin for Low Torque
const int LTstepPin = 9;
int LTdirPin = 8;  

//initialize 4 push button with respective pins
const int Button1 = 2;  // Green 1: High Speed rotaion roll out
const int Button2 = 3;  // Green 2: Lower Speed rotation roll out
const int Button3 = 4;  // Red 1: High Speed rotation roll in
const int Button4 = 5;  // Red 2: High Speed rotation roll in
int x; // To make sure winder moves the correct direction of roll in and roll out 

//Limit Switch (for Winder) Initialization 
int LimitSwitch1 = 6;
int LimitSwitch2 = 7;

int state = HIGH;     //current state of limit switch
int reading, reading2;  //reading of limit switch
int previous = LOW;     //holding the value for limit switch 1
int previous2 = LOW;    //holding the value for limit switch 2

//Declaration time and debouncing limit
long ttime = 0;
long debounce = 250;  //default 100

 
void rollout(int Delay, int wdelay)
{ 
    digitalWrite(HTdirPin, HIGH);
    
    digitalWrite(HTstepPin, HIGH);
    delayMicroseconds(Delay);
    digitalWrite(HTstepPin, LOW);
    delayMicroseconds(Delay);

    
    digitalWrite(LTstepPin, HIGH);
    delayMicroseconds(wdelay);
    digitalWrite(LTstepPin, LOW);
    delayMicroseconds(wdelay);

    x = HIGH;

  }

void rollin(int Delay, int wdelay)
{ 
    digitalWrite(HTdirPin, LOW);
    
    digitalWrite(HTstepPin, HIGH);
    delayMicroseconds(Delay);
    digitalWrite(HTstepPin, LOW);
    delayMicroseconds(Delay);

    digitalWrite(LTstepPin, HIGH);
    delayMicroseconds(wdelay);
    digitalWrite(LTstepPin, LOW);
    delayMicroseconds(wdelay);

    x = LOW;

  }

void setup() {
  Serial.begin(9600);
  
  pinMode(HTstepPin, OUTPUT);
  pinMode(HTdirPin, OUTPUT);
  pinMode(LTstepPin, OUTPUT);
  pinMode(LTdirPin, OUTPUT);
  pinMode(LimitSwitch1, INPUT_PULLUP);
  pinMode(LimitSwitch2, INPUT_PULLUP);

  pinMode(Button1, INPUT_PULLUP);
  pinMode(Button2, INPUT_PULLUP);
  pinMode(Button3, INPUT_PULLUP);
  pinMode(Button4, INPUT_PULLUP);

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

void flipCheck()
{
  reading = digitalRead(LimitSwitch1);
  reading2 = digitalRead(LimitSwitch2);   //edit

  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if ((reading == LOW && previous == LOW && millis() - ttime > debounce) || (reading2 == LOW && previous2 == LOW && millis() - ttime > debounce)) {
    if (state == HIGH)
      state = LOW;
    else
      state = HIGH;

    ttime = millis();
  }

  digitalWrite(LTdirPin, state);

  previous = reading;
  previous2 = reading2;
}
