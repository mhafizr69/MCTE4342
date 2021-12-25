

#include "Arduino.h"
#include "Blinky.h"


	DCMotor::DCMotor()
	{
	Initialize('B', 5,100);
	}

	DCMotor::DCMotor(char port, int pin,double frequency_in_herts)
	{
	Initialize(port,pin,frequency_in_herts);
	}

	void DCMotor::Initialize(char port,int pin,double frequency_in_herts)
	{
	Period =1000000 /frequency_in_herts;
	oscillator.Initialize(port,pin,0,Period);
	}

	void DCMotor::Write(double duty_cycle)
	{
	unsigned long OnTime=Period * duty_cycle;
	unsigned long OffTime=Period -OnTime;
	oscillator.ChangeOnOffTimes(OnTime,OffTime);
	}

	void DCMotor::Refresh()
	{
	oscillator.Refresh();
	}