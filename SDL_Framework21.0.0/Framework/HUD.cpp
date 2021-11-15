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

void HUD::displayHUD(SDL_Renderer* renderer, int hX_, int hY_, int hW_, int hH_, harpoonHarry* harry, InGameTimer* reload, Background* levelProgress)
{
	hX = hX_;
	hY = hY_;
	hW = hW_;
	hH = hH_;

	char HealthText[100];
	sprintf_s(HealthText, "HP :  %i", harry->health);

	Text Health;

	Health.writeText(HealthText, SDL_Color{ 0 ,0,0 }, SDL_Rect{ hX, hY, hW, hH }, renderer);

	Text TimerText;
	char Timer[100];

	if (reload == nullptr) {
		TimerText.writeText("Shoot!", SDL_Color{ 0,0,0 }, SDL_Rect{ hX + 500 , hY, hW + 100, hH }, renderer);

	}
	else {
		float reloadT = reload->timer;
		sprintf_s(Timer, "Reloading:  %.1f /3", reloadT);
		TimerText.writeText(Timer, SDL_Color{ 0,0,0 }, SDL_Rect{ hX + 500 , hY, hW + 200, hH }, renderer);

	}
	

	Text LevelProgress;
	char Prog[100];

	
	float FinalProgress = levelProgress->getProg();
	sprintf_s(Prog, "Progress: %.0f", FinalProgress);

	LevelProgress.writeText(Prog, SDL_Color{ 0,0,0 }, SDL_Rect{ hX + 1000 , hY, hW + 200, hH }, renderer);


}

