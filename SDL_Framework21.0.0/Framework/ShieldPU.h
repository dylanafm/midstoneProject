#ifndef SHIELDPU_H
#define SHIELDPU_H
#include "Powerups.h"
class Powerups;
class ShieldPU
{
private:
	Sfx* pickup;
	Vec3 pos;
	SDL_Rect box;
	SDL_Texture* tex;
	float scrollSpeed, radiusInPixels;
public:
	ShieldPU(SDL_Rect box_, float scrollSpeed_, const char* path, SDL_Renderer* renderer);
	~ShieldPU();

	void Protect(HarpoonHarry* harry);

	void Render(SDL_Renderer* renderer);
	void Scroll();
	bool checkCollide(HarpoonHarry* harry);
	Vec3 getPos() { return pos; }

};

#endif // !SHIELDPU_H
