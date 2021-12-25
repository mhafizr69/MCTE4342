#define button 12
#define led 3

volatile bool state;
bool changes = 0;

unsigned char *sreg = (unsigned char*) 0x5F;
unsigned char *pcicr = (unsigned char*) 0x68;
unsigned char *pcmsk0 = (unsigned char*) 0x6B;

void setup() {
  
  Serial.begin(9600);

  *sreg |= (1<<7); //Set the interrupt flag in the shift register
  *pcicr = 1; //Enable PCINT0 which is interrupt for PORT B
  *pcmsk0 = (1<<4);
  
  pinMode(button,INPUT_PULLUP);
  pinMode(led,OUTPUT);

}

void loop() {
 
  if (changes == 1)
  {
    delay(500); //To let the change settle down and toggles correctly.
    state = !state; 
    digitalWrite(led,state);
    //Serial.println(state); //To troubleshoot state
    changes = 0; //reset the interrupt variable
  }
  
}

ISR (PCINT0_vect)
{
  changes = 1;
}
