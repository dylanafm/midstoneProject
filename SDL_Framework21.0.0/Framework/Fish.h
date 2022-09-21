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
private:

	bool directionUp;
	float moveSpeed;
	float moveRange;
	float startingY;
	float deltaTime;
	int moveDir;
public:
	Fish(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_, int frames);
	~Fish();

	void Render(SDL_Renderer* renderer);
	void Move(float deltaTime_, float moveRange_);
	Animation* fishAnim;
};

#endif