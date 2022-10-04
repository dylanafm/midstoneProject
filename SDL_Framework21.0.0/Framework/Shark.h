#ifndef SHARK_H
#define SHARK_H

#include <SDL.h>
#include "Vector.h"
#include "HarpoonHarry.h"
#include "Enemy.h"
#include "Animation.h"
using namespace MATH;
class Animation;
class HarpoonHarry;

class Shark : public Enemy
{
public:
	double angle;
	Animation* SharkSwim;

	//Health Bar

	SDL_Rect TotalBar;
	SDL_Rect HealthBar;

	SDL_Texture* BarTex;
	SDL_Texture* HealthTex;

	Shark(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_);
	~Shark();
	void Update(float deltaTime, HarpoonHarry* harry);
	void Render(SDL_Renderer* renderer);

	void UpdateHealthBar(SDL_Renderer* r, int h);
};

#endif