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

int AHSL::getHue() { return hue; }

int AHSL::getSaturation() { return saturation; }

int AHSL::getLightness() { return lightness; }

bool AHSL::modifyElement(int hue, int saturation, int lightness)
{
	if (!checkRangeHue(hue) || !checkRangeSaturation(saturation) || !checkRangeLightness(lightness))
		return false; //fail-fast
	return true;
}

bool AHSL::modifyHue(int hue)
{
	if (!checkRangeHue(hue))
		return false;
	else this->hue = hue;
	return true;
}

bool AHSL::modifySaturation(int saturation)
{
	if (!checkRangeSaturation(saturation))
		return false;
	else this->saturation = saturation;
	return true;
}

bool AHSL::modifyLightness(int lightness)
{
	if (!checkRangeLightness(lightness))
		return false;
	else this->lightness = lightness;
	return true;
}

bool AHSL::checkRangeHue(int hue)
{
	if (hue < 0 || hue > 360)
		return false;
	return true;
}

bool AHSL::checkRangeSaturation(int saturation)
{
	if (saturation < 0 || saturation > 255)
		return false;
	return true;
}

bool AHSL::checkRangeLightness(int lightness)
{
	if (lightness < -100 || lightness > 100)
		return false;
	return true;
}
