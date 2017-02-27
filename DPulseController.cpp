#include "DPulseController.h"
#include <wiringPi.h>

#define	PulsePin	17

void DPulseController::pulse(unsigned long amountOfPulses, unsigned long duration)
{
	for (int i = 0; i < amountOfPulses; i++)
	{
		digitalWrite(PulsePin, HIGH);
		delayMicroseconds(duration);
		digitalWrite(PulsePin, LOW);
		delayMicroseconds(duration); //75 ms latency
	}
}