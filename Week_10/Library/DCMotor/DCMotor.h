#ifndef DCMOTOR_H
#define DCMOTOR_H

#include "Arduino.h"
#include "Blinky.h"

class DCMotor
{
	private:
		Blinky oscillator;
		unsigned long Period;
	public:
		DCMotor();
		
		DCMotor(char port, int pin,double frequency_in_herts);
		
		void Initialize(char port,int pin,double frequency_in_herts);
		
		void Write(double duty_cycle);
		
		void Refresh();
		
};

#endif