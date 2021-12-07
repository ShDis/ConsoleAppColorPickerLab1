#pragma once

class AHSL
{
public:
	AHSL();
	AHSL(int hue, int saturation, int lightness);
	//AHSL(AHSL elem);
	int getHue();
	int getSaturation();
	int getLightness();

	bool modifyElement(int hue, int saturation, int lightness);

	bool modifyHue(int hue);
	bool modifySaturation(int saturation);
	bool modifyLightness(int lightness);

	bool checkRangeHue(int hue);
	bool checkRangeSaturation(int saturation);
	bool checkRangeLightness(int lightness);
private:
	int hue;
	int saturation;
	int lightness;
};

