#pragma once

class AHSL
{
public:
	AHSL();
	AHSL(int hue, int saturation, int lightness);
	//AHSL(AHSL elem);
	int get_hue();
	int get_saturation();
	int get_lightness();
	bool modifyElement(int hue, int saturation, int lightness);
private:
	int hue;
	int saturation;
	int lightness;
};

