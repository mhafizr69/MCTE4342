unsigned char *adcsra= (unsigned char*)0x7A;
unsigned char *acsr= (unsigned char*)0x50;

void setup() {
  // put your setup code here, to run once:
    *adcsra = 0;
    *acsr = 1<< 7;

    Sleep();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void Sleep()
{
  unsigned char *smcr = (unsigned char*)0x53;
  *smcr = 5; //Sleep mode = POWER DOWN, Sleep Enable = True
  asm("sleep"); //Invoke in line assembler to sleep
}
