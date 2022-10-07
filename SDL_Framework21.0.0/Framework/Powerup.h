#ifndef POWERUP_H
#define POWERUP_H

#include "Body.h"
#include <SDL.h>
#include "TextureManager.h"
//#include "HarpoonHarry.h"
#include "Sfx.h"

class HarpoonHarry;

class Powerup :  public Body
{
public:
	float scrollSpeed, radiusInPixels;
	Sfx* pickup;

	Powerup(SDL_Rect body_, SDL_Renderer* renderer, const char* path);
	~Powerup();

	virtual void Ability(HarpoonHarry* harry);

	void Scroll();
	Vec3 getPos() { return pos; }

};
#endif

