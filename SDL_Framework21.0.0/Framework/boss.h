#ifndef BOSS_H
#define BOSS_H

#include <SDL.h>
#include "Vector.h"
#include "harpoonHarry.h"
#include "Enemy.h"
#include "Animation.h"
using namespace MATH;
class Animation;
class harpoonHarry;

class boss : public Enemy
{
public:
	double angle;
	boss(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_);
	~boss();
	void Update(float deltaTime, harpoonHarry* harry);
	void Render(SDL_Renderer* renderer) override;
	Animation* swim;
};

#endif