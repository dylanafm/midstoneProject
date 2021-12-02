#ifndef FISH_H
#define FISH_H

#include <SDL.h>
#include "Vector.h"
#include "Enemy.h"


using namespace MATH;

class Fish : public Enemy
{
public:
	Fish(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_);
	~Fish();
};

#endif