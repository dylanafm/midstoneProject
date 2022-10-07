#ifndef HEALTHPICKUP_H
#define HEALTHPICKUP_H

#include "Powerup.h"

class Powerup;

class HealthPickup : public Powerup
{
public:
	HealthPickup(SDL_Rect body_, SDL_Renderer* renderer, const char* path);
	~HealthPickup();

	void Ability(HarpoonHarry* harry);
};

#endif
