#ifndef BLINKY_H
#define BLINKY_H

#include "Arduino.h"

class Blinky
{
  private:
    unsigned long OnTime;//The ON duration in ìs
    unsigned long OffTime; //The OFF duration in ìs
    unsigned long last_time=0; //The last time a transition occurred
    char mask;//If pin = 3, mask = 0000 1000
    char mask_inv; //If pin = 3, mask_inv= 1111 0111
    char* DDR;
    char* PORT;
    
  public:
    Blinky()//Constructor without arguments;
    Blinky(char port,int pin,long ontime,long offtime); //Constructor with arguments
    void Initialize(char port,int pin,long ontime,long offtime);
    void ChangeOnOffTimes(long ontime,long offtime);
    void Refresh();
    
};

#endif