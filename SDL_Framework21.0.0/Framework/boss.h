#ifndef BOSS_H
#define BOSS_H

#include <SDL.h>
#include "Vector.h"


using namespace MATH;

class boss
{
public:
	boss();
	~boss();
	boss(SDL_Rect body);
	Vec3 pos, vel, accelPrevious, accelCurrent, accel;
	int health;
	SDL_Rect body;
	SDL_Texture* bossTex;
	void Update(float deltaTime);
	void Render(SDL_Renderer* renderer);

};

#endif