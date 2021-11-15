unsigned char *ddrd=(unsigned char*)0x2A;
unsigned char *ocr0a =(unsigned char*)0x47;
unsigned char *ocr0b =(unsigned char*)0x48;
unsigned char *tccr0a = (unsigned char*)0x44;
unsigned char *tccr0b = (unsigned char*)0x45;

void setup() {
  
  *ddrd= 1 << 5; //Set Bit 5 (Pin 5) of DDRD = 0b00100000
  *ocr0a = 5; //Set output compare value of Timer 0 Register A which is TOP Value to 5
  *tccr0a = 0b00100011;
  *tccr0b = 0b00001001; // WGM [011]: Fast PWM TOP OCR0A ; Register B Normal Output ; Clock source [011] : Prescalar 1

}

void loop() {
  
  *ocr0b = 0; //Set the output compare value of Timer 0 Register B (Duty Cycle 0%)
  delay(1000);
  *ocr0b = 1; //Set the output compare value of Timer 0 Register B (Duty Cycle 25%)
  delay(1000);
  *ocr0b = 2; //Set the output compare value of Timer 0 Register B (Duty Cycle 50%)
  delay(1000);
  *ocr0b = 3; //Set the output compare value of Timer 0 Register B (Duty Cycle 75%)
  delay(1000);
  *ocr0b = 4; //Set the output compare value of Timer 0 Register B (Duty Cycle 100%)
  delay(1000);
  
}
