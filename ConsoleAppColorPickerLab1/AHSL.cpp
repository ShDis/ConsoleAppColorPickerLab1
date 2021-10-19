#include "AHSL.h"

void AHSL::ASHL(int hue, int saturation, int lightness)
{
	this->hue = hue;
	this->saturation = saturation;
	this->lightness = lightness;
}

int AHSL::get_hue()
{
	return hue;
}

int AHSL::get_saturation()
{
	return saturation;
}

int AHSL::get_lightness()
{
	return lightness;
}
