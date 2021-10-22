#ifndef HUD_H
#define HUD_H


#include <SDL.h>
#include "Text.h"
class HUD
{
private:
	int health;
	int hX, hY, hW, hH;


public:
	HUD();
	HUD(int health_);
	~HUD();

	void displayHud(SDL_Renderer* renderer, int hX_, int hY_, int hW_, int hH_);

	inline int GetHealth() { return health; }
};


#endif
