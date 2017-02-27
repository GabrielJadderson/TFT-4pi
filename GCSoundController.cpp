#include "GCSoundController.h"
#include <wiringPi.h>


#define	LED	17

GCSoundController::GCSoundController()
{
}

void GCSoundController::PlaySound(ESoundType soundType)
{
	switch (soundType)
	{
		case NONE:
			break;
		case BEEB:
			Beeb(256, 100, 600, 600, 600, 600);
			break;
		case BEEB_2:
			Beeb(256, 100, 400, 400, 400, 400);
			break;
		case BEEB_3:
			Beeb(256, 100, 400, 500, 600, 700);
			break;
		case BEEB_4:
			Beeb(256, 100, 1200, 1400, 1200, 1400);
			break;
		case LONG:
			Long(1000, 600, 600);
			break;
		case LONG_1:
			Long(500, 1200, 1200);
			break;
		case LONG_2:
			Long(1500, 1600, 1600);
			break;
		case LONG_3:
			Long(1000, 1, 1);
			break;
		default:
			break;
	}
}

void GCSoundController::Beeb(int deltaSpeed, int gapDuration, int sleep_1, int sleep_2, int sleep_3, int sleep_4)
{
	Long(deltaSpeed, sleep_1, sleep_2);
	delayMicroseconds(gapDuration * 1000);
	Long(deltaSpeed, sleep_3, sleep_4);
}

void GCSoundController::Long(int deltaSpeed, int sleep_1, int sleep_2)
{
	for (int i = 0; i < deltaSpeed; i++)
	{
		//digitalWrite(LED, HIGH);
		//delayMicroseconds(sleep_1);
		//digitalWrite(LED, LOW);
		//delayMicroseconds(sleep_2);

		pwmSetMode(PWM_MODE_MS);
		pwmWrite(LED, 1000);
	}
}