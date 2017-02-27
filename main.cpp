#include "wiringPi.h"
#include "wiringPiSPI.h"

#include <string>
#include "tft_st7735.h"
#include "tft_manager.h"
#include "tft_field.h"
#include "GCSoundController.h"
#include "DPulseController.h"
#include <softTone.h>

int main(void)
{

	wiringPiSetupSys();

	wiringPiSPISetup(0, 32000000);

	pinMode(17, OUTPUT);


	TFT_ST7735 tft = *new TFT_ST7735(0, 24, 25, 32000000);
	tft.commonInit();         // initialize SPI and reset display
	tft.initR();              // initialize display
	tft.setBackground(TFT_BLACK);

	tft.clearScreen();        // reset Display
	tft.setRotation(rotate_E::DEGREE_270);
	tft.drawString(1, 5, "Initiated Sucessfully", TFT_WHITE, 1);
	tft.drawHorizontalLine(1, 20, TFT_height, TFT_GRAY);






	int counter = 0;

	char c = counter;

	std::string s = std::to_string(counter);
	while (counter < 254)
	{
		tft.drawLetter(c, 60, 80, TFT_BLUE, 1);
		tft.drawString(20, 50, s.c_str(), TFT_GRAY, 1);
		counter++;
		c = counter;
		s = std::to_string(counter);
		delay(20);
	}


	for (int x = 0; x < 200; x++)
	{
		for (int y = 0; y < 200; y++)
		{
			tft.drawPixel(x, y, TFT_BLUE);
		}
	}



	//DPulseController controller;
	//controller.pulse(2000, 3500);

	/*
	int i;
	int frequency[8] = {262, 294, 330, 349, 392, 440, 494, 525};

	softToneCreate(17);

	softToneWrite(17, 450);
	delay(220);

	softToneWrite(17, 0);
	delay(50);

	softToneWrite(17, 450);
	delay(220);

	softToneWrite(17, 0);
	delay(100);

	softToneWrite(17, 340);
	delay(400);

	softToneWrite(17, 0);
	delay(100);
	*/

	/*
	delay(1000);
	controller.pulse(10, 64);
	delay(1000);
	controller.pulse(10, 512);
	delay(1000);
	controller.pulse(10, 64);
	delay(1000);
	controller.pulse(10, 512);
	delay(1000);
	controller.pulse(10, 64);
	delay(1000);
	*/




	/*
	GCSoundController CSCTRL;
	CSCTRL.PlaySound(ESoundType::BEEB);
	delay(500);
	CSCTRL.PlaySound(ESoundType::BEEB_2);
	delay(500);
	CSCTRL.PlaySound(ESoundType::BEEB_3);
	delay(500);
	CSCTRL.PlaySound(ESoundType::BEEB_4);
	delay(500);
	CSCTRL.PlaySound(ESoundType::LONG);
	delay(500);
	CSCTRL.PlaySound(ESoundType::LONG_1);
	delay(500);
	CSCTRL.PlaySound(ESoundType::LONG_2);
	delay(500);
	CSCTRL.PlaySound(ESoundType::LONG_3);
	*/
	//tft.clearScreen();



	return 0;
}