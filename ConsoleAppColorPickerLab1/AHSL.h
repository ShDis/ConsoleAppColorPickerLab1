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
private:
	int hue;
	int saturation;
	int lightness;
};

