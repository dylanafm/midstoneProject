#ifndef MGHARPOON_H
#define MGHARPOON_H

#include "Powerup.h"

class MGHarpoon : public Powerup
{
public:
	MGHarpoon(SDL_Rect body_, SDL_Renderer* renderer);
	~MGHarpoon();

	void Ability(HarpoonHarry* harry);

};

#endif H
