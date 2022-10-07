#include "Powerup.h"

Powerup::Powerup(SDL_Rect body_, SDL_Renderer* renderer, const char* path) :
	Body(body_, Vec3(0.0f, 0.0f, 0.0f), renderer, path)
{
	scrollSpeed = 2.0f;
	radiusInPixels = body.w / 2;

}

Powerup::~Powerup()
{
}

void Powerup::Ability(HarpoonHarry* harry)
{
}

void Powerup::Scroll()
{

	pos.x = pos.x - scrollSpeed;
}