#ifndef SHARK_H
#define SHARK_H

#include <SDL.h>
#include "Vector.h"
#include "harpoonHarry.h"
#include "Enemy.h"
#include "Animation.h"
using namespace MATH;
class Animation;
class harpoonHarry;

class Shark : public Enemy
{
public:
	double angle;
	Shark(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_);
	~Shark();
	void Update(float deltaTime, harpoonHarry* harry);
	void Render(SDL_Renderer* renderer) override;
	Animation* SharkSwim;
};

#endif