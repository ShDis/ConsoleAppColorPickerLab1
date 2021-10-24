#include "AHSL.h"
#include <math.h>

AHSL::AHSL()
{
	this->hue = 0; //0 - 360, 0 == 360
	this->saturation = 0; //0 - 255
	this->lightness = 0; //-100 - 100
}

AHSL::AHSL(int hue, int saturation, int lightness)
{
	this->hue = abs(hue % 360); //0 - 360, 0 == 360
	this->saturation = abs(saturation % 256); //0 - 255
	this->lightness = lightness % 101; //-100 - 100
}

//AHSL::AHSL(AHSL elem)
//{
//	this->hue = abs(elem.hue % 360); //0 - 360, 0 == 360
//	this->saturation = abs(elem.saturation % 256); //0 - 255
//	this->lightness = elem.lightness % 101; //-100 - 100
//}

int AHSL::get_hue() { return hue; }

int AHSL::get_saturation() { return saturation; }

int AHSL::get_lightness() { return lightness; }

bool AHSL::modifyElement(int hue, int saturation, int lightness)
{
	if (hue < 0 || hue > 360 && saturation < 0 || saturation > 255 && lightness < -100 || lightness > 100) //fail-fast
		return false;
	return true;
}
