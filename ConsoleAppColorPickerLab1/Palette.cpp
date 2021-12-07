#include "Palette.h"
#include <iostream>

Palette::Palette()
{
	elemsArr = new AHSL[10];
	std::cout << "Created Palette with " << 10 << " indexes" << "\n";
}

Palette::Palette(int elemCount)
{
	if (elemCount < 1 || elemCount > 2147483647)
		Palette();
	else
	{
		elemsArr = new AHSL[elemCount];
		std::cout << "Created Palette with " << elemCount << " indexes." << "\n";
	}
}

bool Palette::modifyPalette(int elemId, int hue, int saturation, int lightness)
{
	if (!checkIndex(elemId))
	{
		std::cout << "There are no such id." << "\n";
		return false;
	}
	if (!elemsArr[elemId].modifyElement(hue, saturation, lightness))
	{
		std::cout << "Range check failed." << "\n";
		return false;
	}
	std::cout << "Element " << elemId << "successfully modified." << "\n";
	return true;
}

bool Palette::modifyPalette(int elemId, AHSL color)
{
	return modifyPalette(elemId, color.getHue(), color.getSaturation(), color.getLightness());
}

bool Palette::checkIndex(int elemId)
{
	if (sizeof(elemsArr) <= elemId || elemId < 0)
		return false;
	else return true;
}
