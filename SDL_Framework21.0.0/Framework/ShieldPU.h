#ifndef SHIELDPU_H
#define SHIELDPU_H

#include "Powerup.h"
#include "Sfx.h"

class Powerup;

class ShieldPU : public Powerup
{
private:
	Sfx* pickup;
public:
	ShieldPU(SDL_Rect body_, SDL_Renderer* renderer, const char* path);
	~ShieldPU();

	void Ability(HarpoonHarry* harry);
};

#endif // !SHIELDPU_H
