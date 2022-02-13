#include <LiquidCrystal_I2C.h>
#include <Wire.h>

// Creating object for LCD i2c 
#define lcd_size_x 16
#define lcd_size_y 2
LiquidCrystal_I2C lcd (0x27, lcd_size_x, lcd_size_y);

// Initialize the music notes frequency for buzzer.
#define NOTE_C 523
#define NOTE_D 587
#define NOTE_E 659
#define NOTE_F 698
#define NOTE_G 784
#define NOTE_A 880
#define NOTE_B 988

int selectedSong[] = {}; //Array used in songPlay function to assign song array chosen into a general array.

//Song arrays. Can add more songs.
int Mary[] = 
{ 
      NOTE_E, NOTE_D, NOTE_C, NOTE_D, NOTE_E, NOTE_E, NOTE_E,
      NOTE_D, NOTE_D, NOTE_D, NOTE_E, NOTE_G, NOTE_G,
      NOTE_E, NOTE_D, NOTE_C, NOTE_D, NOTE_E, NOTE_E, NOTE_E,
      NOTE_D, NOTE_D, NOTE_E, NOTE_D, NOTE_C
  
};

int Star[] = 
{
      NOTE_C, NOTE_C, NOTE_G, NOTE_G, NOTE_A, NOTE_A, NOTE_G,
      NOTE_F, NOTE_F, NOTE_E, NOTE_E, NOTE_D, NOTE_D, NOTE_C,
      NOTE_G, NOTE_G, NOTE_F, NOTE_F, NOTE_E, NOTE_E, NOTE_D,
      NOTE_G, NOTE_G, NOTE_F, NOTE_F, NOTE_E, NOTE_E, NOTE_D,
      NOTE_C, NOTE_C, NOTE_G, NOTE_G, NOTE_A, NOTE_A, NOTE_G,
      NOTE_F, NOTE_F, NOTE_E, NOTE_E, NOTE_D, NOTE_D, NOTE_C
  
};

int Spider[] = 
{
      NOTE_C, NOTE_C, NOTE_C, NOTE_D, NOTE_E, NOTE_E,
      NOTE_E, NOTE_D, NOTE_C, NOTE_D, NOTE_E, NOTE_C,
      NOTE_E, NOTE_E, NOTE_F, NOTE_G, NOTE_G, NOTE_F, NOTE_E,
      NOTE_F, NOTE_G, NOTE_E,
      NOTE_C, NOTE_C, NOTE_D, NOTE_E, NOTE_E, NOTE_D, NOTE_C,
      NOTE_D, NOTE_E, NOTE_C,
      NOTE_G, NOTE_G, NOTE_C, NOTE_C, NOTE_C, NOTE_D, NOTE_E,
      NOTE_E, NOTE_E, NOTE_D, NOTE_C, NOTE_D, NOTE_E, NOTE_C
  
};

// Dedicating pins to variables
const int Bu1 = 12; 
const int Bu2 = 11;
const int Bu3 = 10; 
const int Bu4 = 8; 
const int Bu5 = 7; 
const int Bu6 = 6; 
const int Bu7 = 4; 
const int buzzer = 3; 
const int poten = A3;

const int LED1 = 13; 
const int LED2 = A0; 
const int LED3 = 9; 
const int LED4 = A1; 
const int LED5 = A2; 
const int LED6 = 5; 
const int LED7 = 2; 

// Change to 0.5 for a slower version of the song, 1.25 for a faster version
const float songSpeed = 1.0;

// Notes Played
char *note[] = {"B", "A", "G", "F", "E", "D", "C"};

int gmode; //Store the game mode selected by user

bool played = false; //Check if user repeats the game or not

// States of button
int s1, s2, s3, s4, s5, s6, s7, var;
    
void setup() {

  Serial.begin(9600);
  lcd.init(); // Initialize the LCD
  lcd.backlight(); // Turn on the backlight of the LCD
      
  // Set pins to either input or output
  pinMode(Bu1, INPUT_PULLUP);
  pinMode(Bu2, INPUT_PULLUP);
  pinMode(Bu3, INPUT_PULLUP);
  pinMode(Bu4, INPUT_PULLUP);
  pinMode(Bu5, INPUT_PULLUP);
  pinMode(Bu6, INPUT_PULLUP);
  pinMode(Bu7, INPUT_PULLUP);
  pinMode(poten, INPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);

  lcd.setCursor(0,0); // Set to print from column 0, row 0
  lcd.print("Hello!! ^_^");
  lcd.setCursor(0,1); // Set to print from column 0, row 1
  lcd.print("Future Pianist!!");
  delay(2000); // delay the process by 2000ms / 2s
  lcd.clear(); // Clear the LCD display
  
  Song(); // Jump to game mode selection function
}

void loop() {
  
  lcd.clear();
  switch(gmode)
  {
    case (1): played = true; songPlay(); break;
    case (2): played = true; songPlay(); break;
    case (3): played = true; songPlay(); break;
    case (4): freePlay(); break;
  }
  
  
}

int Song(){

  lcd.setCursor(0,0); 
  lcd.print("Spin the left");
  lcd.setCursor(0,1);
  lcd.print("analog stick to");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("analog stick to");
  lcd.setCursor(0,1);
  lcd.print("change song/mode");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("To Select:");
  lcd.setCursor(0,1);
  lcd.print("Press The Bright");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press The Bright");
  lcd.setCursor(0,1);
  lcd.print("Button (B)");
  delay(2000);
  lcd.clear();
  
  int flag = 0; // Check if user selected a song or not
  gmode = 0; //Set game mode to none
  
  //Loop until a game mode is selected.
  do
  {
    digitalWrite(LED1, HIGH); //Turn on the LED of button ‘B’
    int potVal = analogRead(poten); // Read potentiometer.
    potVal = map(potVal, 0, 1023, 1, 5); // Map potentiometer to value of 1 to 5
    //Serial.print(potVal); // To check potentiometer reading
    int currentVal = potVal; // To check if there is difference in potentiometer value
    int preVal;
    
    // Clear LCD if there is change in potentiometer value.
    if (currentVal!= preVal)
    {
      lcd.setCursor(0,0);
      for(int n = 0; n < 16; n++) // 20 indicates symbols in line. For 2x16 LCD write - 16
      {
        lcd.print(" ");
      }
      lcd.setCursor(0,1);
      for(int n = 0; n < 16; n++) // 20 indicates symbols in line. For 2x16 LCD write - 16
      {
        lcd.print(" ");
      }
      preVal = currentVal; // Set current potentiometer reading as previous potentiometer reading.
    }
    
    int select = digitalRead(Bu1); // Read button ‘B’ 
    //Serial.println(select); // To check reading of button 'B'
    
    // Switch for displaying mode selection on LCD
    switch(potVal)
    {
      case 1: 
        lcd.setCursor(0,0);
        lcd.print("1.Mary Had A ");
        lcd.setCursor(2,1);
        lcd.print("Little Lamb...");
        break;
    
      case 2:
        lcd.setCursor(0,0);
        lcd.print("2.TwinkleTwinkle");
        lcd.setCursor(2,1);
        lcd.print("Little Star...");
        break;
    
      case 3:
        lcd.setCursor(0,0);
        lcd.print("3.The Itsy Bitsy");
        lcd.setCursor(2,1);
        lcd.print("Spider...");
        break;
    
      case 4 ...5:
        lcd.setCursor(0,0);
        lcd.print("4.Free Play"); break; 
    
      default: break;  
    }
    
    // Check if button ‘B’ is pushed.
    if (select == 0)
    {
      if(potVal==5){
        potVal=4;} // Set value 5 of potentiometer to 4.
      gmode = potVal; // Set game to selected mode.
      flag = 1; // Set flag since mode has been selected.
    }
    
  }while(flag == 0); // Exit "do" loop if game mode has been selected.
  
  digitalWrite(LED1, LOW); // Turn off the LED on button ‘B’

  // Check if the game has been repeated or not.
  if (played == true)
    loop(); // Go back to main loop.
}

// The function that loops infinitely if free play mode is selected.
void freePlay(){

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("You are now in");
  lcd.setCursor(0,1);
  lcd.print("Free Play");
  delay(2000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Press Reset");
  lcd.setCursor(0,1);
  lcd.print("(Red) Button To");
  delay(1500);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("(Red) Button To");
  lcd.setCursor(0,1);
  lcd.print("Change Mode");
  delay(2000);
  lcd.clear();
  delay(500);
  
  do{

    var = 0; // Set note played to none
    
    // Check and set the notes played
    s1 = digitalRead(Bu1);
    s2 = digitalRead(Bu2);
    s3 = digitalRead(Bu3);
    s4 = digitalRead(Bu4);
    s5 = digitalRead(Bu5);
    s6 = digitalRead(Bu6);
    s7 = digitalRead(Bu7);
    
    if (s1==0)
      var = 1;
    if (s2==0)
      var = 2;
    if (s3==0)
      var = 3;
    if (s4==0)
      var = 4;
    if (s5==0)
      var = 5;
    if (s6==0)
      var = 6;
    if (s7==0)
      var = 7;
  
    //For debugging switch input.
    //  Serial.print(s1);
    //  Serial.print("\t");
    //  Serial.print(s2);
    //  Serial.print("\t");
    //  Serial.print(s3);
    //  Serial.print("\t");
    //  Serial.print(s4);
    //  Serial.print("\t");
    //  Serial.print(s5);
    //  Serial.print("\t");
    //  Serial.print(s6);
    //  Serial.print("\t");
    //  Serial.println(s7);

    switch(var){
      case 1: digitalWrite(LED1, HIGH);tone(buzzer, 988, 25); break;
      case 2: digitalWrite(LED2, HIGH);tone(buzzer, 880, 25); break;
      case 3: digitalWrite(LED3, HIGH);tone(buzzer, 784, 25); break;
      case 4: digitalWrite(LED4, HIGH);tone(buzzer, 698, 25); break;
      case 5: digitalWrite(LED5, HIGH);tone(buzzer, 659, 25); break;
      case 6: digitalWrite(LED6, HIGH);tone(buzzer, 587, 25); break;
      case 7: digitalWrite(LED7, HIGH);tone(buzzer, 523, 25); break;
      default: digitalWrite(LED1, LOW);digitalWrite(LED2, LOW);digitalWrite(LED3, LOW);digitalWrite(LED4, LOW);digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);digitalWrite(LED7, LOW);noTone(buzzer); break;
    }

    // Display the notes played on LCD
    lcd.setCursor(2,0); 
    lcd.print("Note Played");
    
    if (var > 0){
      lcd.setCursor(7,1); 
      lcd.print(note[var-1]);
    }
    else{
      lcd.setCursor(7,1);
      lcd.print(" ");
    }
    
  }while(true);
  
}

// Loop for guided song mode.
void songPlay(){

  int i, j, totalNotes;
  
  // Switch for selecting the song selected.
  switch(gmode){
    case 1: 
      namePrint(gmode); // Call function to display name of song.
      totalNotes = sizeof(Mary) / sizeof(int); // Calculate the length of notes for song selected.
      for (i = 0; i<totalNotes; i++)
      {
         selectedSong[i] = Mary[i]; // Assign song notes into general array.
      }
      break;

    case 2:
      namePrint(gmode); // Call function to display name of song.
      totalNotes = sizeof(Star) / sizeof(int); // Calculate the length of notes for song selected.
      for (i = 0; i<totalNotes; i++)
      {
         selectedSong[i] = Star[i]; // Assign song notes into general array.
      }
      break;

    case 3:
      namePrint(gmode); // Call function to display name of song.
      totalNotes = sizeof(Spider) / sizeof(int); // Calculate the length of notes for song selected.
        for (i = 0; i<totalNotes; i++)
        { 
          selectedSong[i] = Spider[i]; // Assign song notes into general array.
        }
      break;

    default: break;
  }

      delay(1000);
      
      // Loop to play each note of the selected song.
      for(i = 0; i < totalNotes; i++)
      {
        bool noteFlag = false; // Set flag as false and will turn true if button pressed is same as current note.
        const int currentNote = selectedSong[i]; // Assign the current note of selected song to a temporary variable.

        // A loop that will break only when the current note is same with button pressed.
        do
        {
          switch (currentNote){
            case (NOTE_C): 
            
              // Turn On LED 7
              digitalWrite(LED7, HIGH);
              delay(50);
              s7 = digitalRead(Bu7);
            
              if(s7==0)
              {
                // Turn off LED 7
                digitalWrite(LED7, LOW);
                noteFlag = true;
              }
              break;
        
            case (NOTE_D): 

              // Turn On LED 6
              digitalWrite(LED6, HIGH);
              delay(50);
              s6 = digitalRead(Bu6);
            
              if(s6==0)
              {
                // Turn off LED 6
                digitalWrite(LED6, LOW);
                noteFlag = true;
              }
              break;
        
            case (NOTE_E): 
        
              // Turn On LED 5
              digitalWrite(LED5, HIGH);
              delay(50);
              s5 = digitalRead(Bu5);
            
              if(s5==0)
              {
                // Turn off LED 5
                digitalWrite(LED5, LOW);
                noteFlag = true;
              }
              break;
        
            case (NOTE_F): 
        
              // Turn On LED 4
              digitalWrite(LED4, HIGH);
              delay(50);
              s4 = digitalRead(Bu4);
            
              if(s4==0)
              {
                // Turn off LED 4
                digitalWrite(LED4, LOW);
                noteFlag = true;
              }
              break;
        
            case (NOTE_G): 
        
              // Turn On LED 3
              digitalWrite(LED3, HIGH);
              delay(50);
              s3 = digitalRead(Bu3);
            
              if(s3==0)
              {
                // Turn off LED 3
                digitalWrite(LED3, LOW);
                noteFlag = true;
              }
              break;
        
            case (NOTE_A): 
        
              // Turn On LED 2
              digitalWrite(LED2, HIGH);
              delay(50);
              s2 = digitalRead(Bu2);
            
              if(s2==0)
              {
                // Turn off LED 2
                digitalWrite(LED2, LOW);
                noteFlag = true;
              }
              break;
        
            case (NOTE_B): 
        
              // Turn On LED 1
              digitalWrite(LED1, HIGH);
              delay(50);
              s1 = digitalRead(Bu1);
            
              if(s1==0)
              {
                // Turn off LED 1
                digitalWrite(LED1, LOW);
                noteFlag = true;
              }
              break;
        
              default: break;

            }
        
        }while(noteFlag==false);
      
        tone(buzzer, selectedSong[i], 500); // Play the tone of current note.
        delay(500);
        
      }

      // The section prompts the user if they want to repeat the selected guided song.
      delay(500);
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("Do you want to");
      lcd.setCursor(0,1); 
      lcd.print("repeat song?");
      delay(2000);
      lcd.clear();
      lcd.setCursor(0,0); 
      lcd.print("Green: YES");
      lcd.setCursor(0,1); 
      lcd.print("Red: NO");
      
      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      
      // A loop that that will break when user made the decision to repeat song or not.
      do
      {        
        s1 = digitalRead(Bu1);
        s2 = digitalRead(Bu2);

        if(s2==0){
          digitalWrite(LED1, LOW);
          digitalWrite(LED2, LOW);
          Song(); 
        }
          

        else if (s1==0){
          digitalWrite(LED1, LOW);
          digitalWrite(LED2, LOW);
          lcd.clear();
          delay(500);
          songPlay();
        }
                   
      }while(s1==1 && s2==1);
      
}

// Function to display names of song depending on the song selected by user.
void namePrint(int x){
  
    switch(gmode){
    case 1: 
      lcd.setCursor(2,0); 
      lcd.print("Mary  Had  A");
      lcd.setCursor(2,1); 
      lcd.print("Little  Lamb");
      break;

    case 2:
      lcd.setCursor(0,0); 
      lcd.print("Twinkle,Twinkle,");
      lcd.setCursor(2,1); 
      lcd.print("Little  Star");
      break;

    case 3:
      lcd.setCursor(1,0); 
      lcd.print("The Itsy Bitsy");
      lcd.setCursor(5,1); 
      lcd.print("Spider");
      break;

    default: break;
  }
  
}
