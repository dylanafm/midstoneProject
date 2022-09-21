#ifndef BOSS_H
#define BOSS_H

#include <SDL.h>
#include "Vector.h"
#include "HarpoonHarry.h"
#include "Enemy.h"
#include "Animation.h"
using namespace MATH;
class Animation;
class HarpoonHarry;

class Boss : public Enemy
{
public:
	double angle;
	Boss(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_);
	~Boss();
	void Update(float deltaTime, HarpoonHarry* harry);
	void Render(SDL_Renderer* renderer) override;
	Animation* swim;
};

#endif