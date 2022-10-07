#include "HealthPickup.h"
#include "HarpoonHarry.h"

HealthPickup::HealthPickup(SDL_Rect body_, SDL_Renderer* renderer, const char* path):
	Powerup(body_, renderer, path)
{
	pickup = new Sfx("SFX/life_pickup.flac", 10);

}

HealthPickup::~HealthPickup()
{
	delete pickup;
}

void HealthPickup::Ability(HarpoonHarry* harry)
{
	pickup->playSFX();
	isActive = false;
	texture = nullptr;
	if (harry->health < 3) {
		harry->health += 1;
	}
}

