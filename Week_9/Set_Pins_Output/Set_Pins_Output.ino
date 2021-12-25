unsigned char *ddrb= (unsigned char*)0x24;
unsigned char *ddrc= (unsigned char*)0x27;
unsigned char *ddrd= (unsigned char*)0x2A;

void setup() {
  // put your setup code here, to run once:
    *ddrb=0b11111111;
    *ddrc=0b11111111;
    *ddrd=0b11111111;
}

void loop() {
  // put your main code here, to run repeatedly:

}
