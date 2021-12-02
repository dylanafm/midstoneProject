#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "Body.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Vector.h"
#include "Enemy.h"

class Projectile : public Enemy
{
public:
	Projectile(SDL_Rect body_, Vec3 vel_, SDL_Renderer* renderer, const char* path, float radius_);
	~Projectile();
};

#endif

