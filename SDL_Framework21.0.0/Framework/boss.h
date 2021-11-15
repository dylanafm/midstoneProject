#ifndef BOSS_H
#define BOSS_H

#include <SDL.h>
#include "Vector.h"
#include "Enemy.h"


using namespace MATH;

class boss : public Enemy
{
public:
	boss(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path);
	~boss();
};

#endif