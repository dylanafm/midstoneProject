#ifndef MGHARPOON_H
#define MGHARPOON_H

#include <SDL.h>
#include "Vector.h"
#include "HarpoonHarry.h"

class MGHarpoon
{
private:
	Sfx* pickup;
	Vec3 pos;
	SDL_Rect box;
	SDL_Texture* tex;
	float scrollSpeed, radiusInPixels;
public:
	MGHarpoon(SDL_Rect box_, float scrollSpeed_, const char* path, SDL_Renderer* renderer);
	~MGHarpoon();

	void RapidFire(HarpoonHarry* harry);

	void Render(SDL_Renderer* renderer);
	void Scroll();
	bool checkCollide(HarpoonHarry* harry);
	Vec3 getPos() { return pos; }

};

#endif H
