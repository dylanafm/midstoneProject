#ifndef FISH_H
#define FISH_H

#include <SDL.h>
#include "Vector.h"
#include "Enemy.h"
#include "Animation.h"

using namespace MATH;
class Animation;
class Fish : public Enemy
{
public:
	Fish(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_);
	~Fish();

	void Render(SDL_Renderer* renderer);

	Animation* fishAnim;
};

#endif