#include "HealthPickup.h"
#include "HarpoonHarry.h"

HealthPickup::HealthPickup(SDL_Rect body_, SDL_Renderer* renderer):
	Powerup(body_, renderer, "textures/HealthIMG.png")
{
	pickupSound = new Sfx("SFX/life_pickup.flac", 10);

}

HealthPickup::~HealthPickup()
{
}

void HealthPickup::Ability(HarpoonHarry* harry)
{
	pickupSound->playSFX();
	isActive = false;
	texture = nullptr;

	if (harry->health < 3) {
		harry->health += 1;
	}
}

