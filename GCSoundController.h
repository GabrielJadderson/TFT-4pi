#pragma once

enum ESoundType
{
	NONE,
	BEEB,
	BEEB_2,
	BEEB_3,
	BEEB_4,
	LONG,
	LONG_1,
	LONG_2,
	LONG_3
};

class GCSoundController
{

public:
	GCSoundController();

	void PlaySound(ESoundType soundType);

private:

	void Beeb(int deltaSpeed, int gapDuration, int sleep_1, int sleep_2, int sleep_3, int sleep_4);

	void Long(int deltaSpeed, int sleep_1, int sleep_2);

};