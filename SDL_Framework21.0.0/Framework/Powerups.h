#ifndef POWERUPS_H
#define POWERUPS_H
#include "harpoonHarry.h"
#include "TextureManager.h"



class Powerups
{
private:
	Vec3 pos;
	SDL_Rect box;
	SDL_Texture* tex;
	float scrollSpeed, radiusInPixels;
	
public:
	Powerups(SDL_Rect box_, float scrollSpeed_, const char* path, SDL_Renderer* renderer);
	~Powerups();

	void Render(SDL_Renderer* renderer);
	void Scroll();
	bool checkCollide(harpoonHarry* harry);
	Vec3 getPos() { return pos; }

};



#endif // !POWERUPS_H



