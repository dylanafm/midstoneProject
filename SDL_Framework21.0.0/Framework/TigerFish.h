#ifndef TIGERFISH_H
#define TIGERFISH_H

#include <SDL.h>
#include "Vector.h"
#include "Enemy.h"
#include "Animation.h"

using namespace MATH;
class Animation;
class TigerFish : public Enemy
{
private:

	bool directionUp;
	float moveSpeed;
	float moveRange;
	float startingY;
	float deltaTime;
	int moveDir;
public:
	TigerFish(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_);
	~TigerFish();

	void Render(SDL_Renderer* renderer);
	void Move(float deltaTime_, float moveRange_);
	Animation* tigerFishAnim;

};

#endif