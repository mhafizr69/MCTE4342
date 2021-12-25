unsigned char *adcsra= (unsigned char*)0x7A;
unsigned char *acsr= (unsigned char*)0x50;

void setup() {
  // put your setup code here, to run once:
    *adcsra = 0;
    *acsr = 1<< 7;

    DeepSleep();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void DeepSleep()
{
  unsigned char *smcr = (unsigned char*)0x53;
  volatile char *mcucr = (char*) 0x55;
  *smcr = 5; //Sleep mode = POWER DOWN, Sleep Enable = True
  *mcucr = 0b01100000; //Set Both BODS and BODSE
  *mcucr = 0b01000000; //Set BODS and clear BODSE
  asm("sleep"); //Invoke in line assembler to sleep
}
