#include "ShieldPU.h"
#include "HarpoonHarry.h"


ShieldPU::ShieldPU(SDL_Rect body_, SDL_Renderer* renderer, const char* path):
	Powerup(body_, renderer, path)
{

}

ShieldPU::~ShieldPU()
{

}

void ShieldPU::Ability(HarpoonHarry* harry)
{
	pickup->playSFX();
	harry->Shielded = true;
	harry->timeRemaining = 5.0f;
}

