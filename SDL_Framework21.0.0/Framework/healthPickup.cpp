#include "HealthPickup.h"
#include "HarpoonHarry.h"

HealthPickup::HealthPickup(SDL_Rect body_, SDL_Renderer* renderer, const char* path):
	Powerup(body_, renderer, path)
{

}

HealthPickup::~HealthPickup()
{

}

void HealthPickup::Ability(HarpoonHarry* harry)
{
	if (harry->health < 3) {
		harry->health += 1;
	}
}

