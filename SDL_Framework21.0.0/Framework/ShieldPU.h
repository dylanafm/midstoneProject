#ifndef SHIELDPU_H
#define SHIELDPU_H
#include "Powerups.h"
class Powerups;
class ShieldPU
{
private:
	sfx* pickup;
	Vec3 pos;
	SDL_Rect box;
	SDL_Texture* tex;
	float scrollSpeed, radiusInPixels;
public:
	ShieldPU(SDL_Rect box_, float scrollSpeed_, const char* path, SDL_Renderer* renderer);
	~ShieldPU();

	void Protect(harpoonHarry* harry);

	void Render(SDL_Renderer* renderer);
	void Scroll();
	bool checkCollide(harpoonHarry* harry);
	Vec3 getPos() { return pos; }

};

#endif // !SHIELDPU_H
