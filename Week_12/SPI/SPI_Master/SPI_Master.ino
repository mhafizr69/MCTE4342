//SPI Master

#include<SPI.h>                             //Library for SPI 
#define LED 8           
#define button 4
int buttonval;
int x;
void setup (){
  
  Serial.begin(9600);                   //Starts Serial Communication at Baud Rate 9600 
  
  pinMode(button,INPUT);                //Sets pin 4 as input 
  pinMode(LED,OUTPUT);                    //Sets pin 8 as Output
  
  SPI.begin();                            //Begins the SPI commnuication
  SPI.setClockDivider(SPI_CLOCK_DIV16);    //Sets clock for SPI communication at 16 (16/16=1Mhz)
  digitalWrite(SS,HIGH);                  // Setting SlaveSelect as HIGH (So master doesnt connnect with slave)
}

void loop(){
  
  byte Mastersend,Mastereceive;          

  buttonval = digitalRead(button);   //Reads the status of the pin 4

  if(buttonval == HIGH)                //Logic for Setting x value (To be sent to slave) depending upon input from pin 4
  {
    x = 1;
  }
  
  else
  {
    x = 0;
  }
  
  digitalWrite(SS, LOW);                  //Starts communication with Slave connected to master
  
  Mastersend = x;                            
  Mastereceive=SPI.transfer(Mastersend); //Send the mastersend value to slave also receives value from slave
  
  if(Mastereceive == 1)                   //Logic for setting the LED output depending upon value received from slave
  {
     digitalWrite(LED,HIGH);              //Sets pin 8 HIGH
     Serial.println("Master LED ON");
  }
  
  else
  {
     digitalWrite(LED,LOW);               //Sets pin 8 LOW
     Serial.println("Master LED OFF");
  }
  
  delay(1000);
  
}
