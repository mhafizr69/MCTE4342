int incByte; // Stores incoming command

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT); // Led pin
  Serial.println("Ready"); // Ready to receive commands
}

void loop() {
  if (Serial.available() > 0) { // A byte is ready to receive

    incByte = Serial.read();
    if (incByte == 'a') { // byte is 'a'
      digitalWrite(13, HIGH);
      Serial.println("LED - On");
      delay(1000);
    }
    else { // byte isn't 'a'
      digitalWrite(13, LOW);
      Serial.println("LED - off");
    }
  }
}
