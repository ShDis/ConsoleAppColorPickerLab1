#pragma once

class AHSL
{
public:
	void ASHL(int hue, int saturation, int lightness);
	int get_hue();
	int get_saturation();
	int get_lightness();
private:
	int hue;
	int saturation;
	int lightness;
};

