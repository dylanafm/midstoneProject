#ifndef POWERUP_H
#define POWERUP_H

#include "Body.h"
#include <SDL.h>
#include "Sfx.h"
//#include "HarpoonHarry.h"

class HarpoonHarry;

class Powerup :  public Body
{
public:
	float scrollSpeed, radiusInPixels;
	Sfx* pickupSound;

	Powerup(SDL_Rect body_, SDL_Renderer* renderer, const char* path);
	~Powerup();

	virtual void Ability(HarpoonHarry* harry);

	void Scroll();
	Vec3 getPos() { return pos; }

};
#endif

