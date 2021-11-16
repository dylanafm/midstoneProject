#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Body.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Vector.h"

class Projectile
{
public:
	Vec3 pos, vel, accelPrevious, accelCurrent, accel, finalForce;
	SDL_Rect body;
	SDL_Texture* texture;

	Projectile(Vec3 pos_, Vec3 vel_, SDL_Renderer* renderer, const char* path);
	~Projectile();

	void Update(float deltaTime);
	void Render(SDL_Renderer* renderer);
};

#endif

