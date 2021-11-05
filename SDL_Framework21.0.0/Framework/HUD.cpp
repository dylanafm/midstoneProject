#include "HUD.h"
#include <iostream>
HUD::HUD()
{
	hX = 0;
	hY = 0;
	hW = 0;
	hH = 0;
}

HUD::~HUD()
{
}

void HUD::displayHud(SDL_Renderer* renderer, int hX_, int hY_, int hW_, int hH_, harpoonHarry* harry)
{
	hX = hX_;
	hY = hY_;
	hW = hW_;
	hH = hH_;

	char HealthText[100];
	sprintf_s(HealthText, "HP :  %i", harry->health);

	Text NewText;

	NewText.writeText(HealthText, SDL_Color{ 255,255,255 }, SDL_Rect{ hX, hY, hW, hH }, renderer);


}
