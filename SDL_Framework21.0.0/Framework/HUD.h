#ifndef HUD_H
#define HUD_H


#include <SDL.h>
#include "Text.h"
#include "harpoonHarry.h"

class HUD
{
private:
	int hX, hY, hW, hH;


public:
	HUD();
	~HUD();

	void displayHud(SDL_Renderer* renderer, int hX_, int hY_, int hW_, int hH_, harpoonHarry* harry);

};


#endif
