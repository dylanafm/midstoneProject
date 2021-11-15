#ifndef HUD_H
#define HUD_H


#include <SDL.h>
#include "Text.h"
#include "harpoonHarry.h"
#include "Harpoon.h"
#include "InGameTimer.h"
#include "LevelOne.h"
#include "Background.h"
class HUD
{
private:
	int hX, hY, hW, hH;


public:
	HUD();
	~HUD();

	void displayHUD(SDL_Renderer* renderer, int hX_, int hY_, int hW_, int hH_, harpoonHarry* harry, InGameTimer* reload, Background* levelProgress);

};


#endif
