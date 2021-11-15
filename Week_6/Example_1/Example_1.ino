unsigned char *ddrd=(unsigned char*)0x2A;
unsigned char *ocr0b =(unsigned char*)0x48;
unsigned char *tccr0a = (unsigned char*)0x44;
unsigned char *tccr0b = (unsigned char*)0x45;

void setup() {
  
  *ddrd= 1 << 5; //Set Bit 5 (Pin 5) of DDRD = 0b00100000
  *ocr0b = 127; //Set the output compare value of Timer 0 Register B (Duty Cycle 50%)
  *tccr0a = 0b00100011;
  *tccr0b = 0b00000011; // WGM [011]: Fast PWM TOP 0xFF ; Register B Normal Output ; Clock source [011] : Prescalar 64

}

void loop() {
  
}
