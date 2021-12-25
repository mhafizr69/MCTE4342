
#include "Arduino.h"
#include "Blinky.h"
#include "ServoESD.h"


	ServoESD::ServoESD()
	{
	Initialize('B',5,20000);
	}

	ServoESD::ServoESD(char port,int pin,int period)
	{
	Initialize(port,pin,period);
	}

	void ServoESD::Initialize(char port,int pin,int period)
	{
	Period =period;
	oscillator.Initialize(port,pin,0,period);
	}

	void ServoESD::Write(int ontime)
	{
	oscillator.ChangeOnOffTimes(ontime, Period -ontime);
	}

	void ServoESD::Refresh()
	{
	oscillator.Refresh();
	}