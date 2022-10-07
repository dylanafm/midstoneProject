#ifndef SHIELDPU_H
#define SHIELDPU_H

#include "Powerup.h"

class Powerup;

class ShieldPU : public Powerup
{
public:
	ShieldPU(SDL_Rect body_, SDL_Renderer* renderer);
	~ShieldPU();

	void Ability(HarpoonHarry* harry);
};

#endif // !SHIELDPU_H
