#include "ShieldPU.h"
#include "HarpoonHarry.h"


ShieldPU::ShieldPU(SDL_Rect body_, SDL_Renderer* renderer, const char* path):
	Powerup(body_, renderer, path)
{
	pickup = new Sfx("SFX/shield.wav", 10);

}

ShieldPU::~ShieldPU()
{
	delete pickup;
}

void ShieldPU::Ability(HarpoonHarry* harry)
{
	pickup->playSFX();
	harry->Shielded = true;
	harry->timeRemaining = 5.0f;
}

