#ifndef ServoESD_h
#define ServoESD_h

#include "Arduino.h"
#include "Blinky.h"

class ServoESD
{
	private:
		Blinky oscillator;
		int Period;
	public:
		ServoESD();
		
		ServoESD(char port,int pin,int period);
		
		void Initialize(char port,int pin,int period);
		
		void Write(int ontime);
		
		void Refresh();
		
};

#endif