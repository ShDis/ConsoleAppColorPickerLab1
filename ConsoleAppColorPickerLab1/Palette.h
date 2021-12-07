#pragma once
#include "AHSL.h"
#include <string>

class Palette
{
public:
	Palette();
	Palette(int elemCount);
	bool modifyPalette(int elemId, int hue, int saturation, int lightness);
	bool modifyPalette(int elemId, AHSL color);
private:
	bool checkIndex(int elemId);
	AHSL* elemsArr;
};

