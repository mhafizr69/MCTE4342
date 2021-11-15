unsigned char *ddrb =(unsigned char*)0x24;
unsigned char *ocr1a =(unsigned char*)0x88;
unsigned char *tccr1a = (unsigned char*)0x80;
unsigned char *tccr1b = (unsigned char*)0x81;

void setup() {
  
  *ddrb = 2; //Set Bit 1 (Pin 9) of DDRB = 0b00100010
  *ocr1a = 255; //Set Output Compare Register of Timer 1 Register A Value to 255 (Duty Cycle 25%)
  *tccr1a = 0b10000011;
  *tccr1b = 0b00000010; // WGM [0011]: Phase Correct 10 bit PWM TOP 0xFF ; Register A Normal Output ; Clock source [010] : Prescalar 8

}
void loop() {
  // put your main code here, to run repeatedly:

}
