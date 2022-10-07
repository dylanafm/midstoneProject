#ifndef ENEMY_H
#define ENEMY_H
#include <SDL.h>
#include "Vector.h"
#include "Body.h"

using namespace MATH;

class Enemy : public Body 
{
public:
	int health;
	float radiusInPixels;
	SDL_Rect crop;
	
	// Projectile
	Enemy(SDL_Rect body, Vec3 vel_, SDL_Renderer* renderer, const char* path, float radius_);
	Enemy(SDL_Rect body, SDL_Renderer* renderer, const char* path, float radius_);
	~Enemy();
};

#endif
