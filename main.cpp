#include <wiringPi.h>
#include <wiringPiSPI.h>
#include <wiringSerial.h>
#include <iostream>
#include <fstream>

#define	CS_PIN = 10;
#define DC_PIN = 5;
#define RST_PIN = 6;

int main(void)
{
	wiringPiSetupSys();

	int CHANNEL_1 = 0;
	const int CHANNEL_2 = 1;
	const int BAUD = 6000000;

	std::string state;

	if (wiringPiSPISetup(CHANNEL_1, BAUD) == -1)
	{
		CHANNEL_1 = 1;
		wiringPiSPISetup(CHANNEL_1, BAUD);
	}
	else
	{
		state = "Setup Successfull";
	}

	std::ofstream outfile;
	outfile.open("output.txt");
	outfile << "USED CHANNEL: " << CHANNEL_1 << std::endl;
	outfile << "STATE: " << state << std::endl;
	outfile.close();

	return 0;
}