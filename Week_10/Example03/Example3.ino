#include <Blinky.h>

Blinky blinker('B', 5, 100, 200) ; //Blink PB5 1s ON and 1s OFF

void setup() {
  // put your setup code here, to run once:
  
}

void loop() {
  // put your main code here, to run repeatedly:
  blinker.Refresh();
}
