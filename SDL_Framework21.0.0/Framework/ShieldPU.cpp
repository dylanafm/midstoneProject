#include "ShieldPU.h"
#include "HarpoonHarry.h"


ShieldPU::ShieldPU(SDL_Rect body_, SDL_Renderer* renderer):
	Powerup(body_, renderer, "textures/Shield.png")
{
	pickupSound = new Sfx("SFX/shield.wav", 10);

}

ShieldPU::~ShieldPU()
{
}

void ShieldPU::Ability(HarpoonHarry* harry)
{
	pickupSound->playSFX();
	isActive = false;
	texture = nullptr;

	harry->Shielded = true;
	harry->timeRemaining = 5.0f;
}

