#include "HUD.h"
#include <iostream>
HUD::HUD()
{
	health = 0;



}

HUD::HUD(int health_)
{
	health = health_;
}

HUD::~HUD()
{
}

void HUD::displayHud(SDL_Renderer* renderer, int hX_, int hY_, int hW_, int hH_)
{
	hX = hX_;
	hY = hY_;
	hW = hW_;
	hH = hH_;

	char HealthText[100];
	sprintf_s(HealthText, "%d", health);

	Text NewText;

	NewText.writeText(HealthText, SDL_Color{ 255,255,255 }, SDL_Rect{ hX, hY, hW, hH }, renderer);


}
