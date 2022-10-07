#ifndef POWERUP_H
#define POWERUP_H

#include "Body.h"
#include "Sfx.h"
//#include "HarpoonHarry.h"

class HarpoonHarry;

class Powerup :  public Body
{
private:
	float scrollSpeed, radiusInPixels;

public:
	Sfx* pickupSound;

	Powerup(SDL_Rect body_, SDL_Renderer* renderer, const char* path);
	~Powerup();

	void Scroll();
	virtual void Ability(HarpoonHarry* harry);
	float getRadius() { return radiusInPixels; }
};
#endif

