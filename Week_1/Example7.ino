const int led1 = 8; //Yellow LED
const int led2 = 9; //Green LED

unsigned long prev1 = 0;
unsigned long prev2 = 0;
unsigned long current1 = 0;
unsigned long current2 = 0;
bool flag1 = 0;
bool flag2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  current1 = millis();
  current2 = millis();
  if (flag1 == 0) {
    digitalWrite(led1, HIGH);
    if ((current1 - prev1) > 750) {
      flag1 = 1;
      prev1 = current1;
    }
  }
  if (flag1 == 1) {
    digitalWrite(led1, LOW);
    if ((current1 - prev1) > 350) {
      flag1 = 0;
      prev1 = current1;
    }
  }
  
  if (flag2 == 0) {
    digitalWrite(led2, HIGH);
    if ((current2 - prev2) > 400) {
      flag2 = 1;
      prev2 = current2;
    }
  }
  if (flag2 == 1) {
    digitalWrite(led2, LOW);
    if ((current2 - prev2) > 600) {
      flag2 = 0;
      prev2 = current2;
    }
  }
}
