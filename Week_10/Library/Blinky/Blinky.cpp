
#include "Arduino.h"
#include "Blinky.h"


    Blinky::Blinky()//Constructor without arguments
    {
      Initialize('B',5,1000000,1000000);
    }
    

    Blinky::Blinky(char port,int pin,long ontime,long offtime) //Constructor with arguments
    {
      Initialize(port,pin,ontime,offtime);
    }
    

    void Blinky::Initialize(char port,int pin,long ontime,long offtime)
    {
      OnTime=ontime;
      OffTime=offtime;
      switch(port)
      {
      case'B':
        DDR = (char*)0x24;
        PORT = (char*)0x25;
        break;
      case'C':
        DDR =(char*)0x27;
        PORT =(char*)0x28;
        break;
      case'D':
        DDR = (char*)0x2A;
        PORT = (char*)0x2B;
        break;
      }
      mask = (1 << pin); //The expression (1 << pin) will be used often, it is faster to store it
      mask_inv= ~mask;//The inverse of the expression (1 << pin) will also be used often
      *DDR |=mask;//Set the pin as output pin
    }


    void Blinky::ChangeOnOffTimes(long ontime,long offtime)
    {
      OnTime=ontime;
      OffTime=offtime;
    }


    void Blinky::Refresh()
    {
      unsigned long now =micros();
      if (*PORT & mask)//The pin is currently HIGH
      {
        if(now -last_time>=OnTime)//If the pin has been HIGH for long enough
        {
          if(OffTime>0)//If OffTimeis 0, no need to even turn it OFF
          {
            *PORT &=mask_inv; //Make the pin LOW
          }
          last_time=now;//Take note of the time
        }
      }
      else//The pin is currently LOW
      {
        if(now -last_time>=OffTime)//If the pin has been LOW for long enough
        {
          if (OnTime>0)//If OnTimeis 0, no need to even turn it ON
          {
            *PORT |=mask;//Make the pin HIGH
          }
          last_time=now;//Take note of the time
        }
      }
    }