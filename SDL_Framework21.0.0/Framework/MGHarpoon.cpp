#include "MGHarpoon.h"
#include "HarpoonHarry.h"

MGHarpoon::MGHarpoon(SDL_Rect body_, SDL_Renderer* renderer):
	Powerup(body_, renderer, "textures/MGH.png")
{
	pickupSound = new Sfx("SFX/MGH.wav", 10);

}

MGHarpoon::~MGHarpoon()
{
}

void MGHarpoon::Ability(HarpoonHarry* harry)
{
	pickupSound->playSFX();
	isActive = false;
	texture = nullptr;

	harry->rapidFire = true;
	harry->gunTimeRemain = 5.0f;
}
