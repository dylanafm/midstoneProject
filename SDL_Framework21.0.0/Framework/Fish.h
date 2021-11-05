#ifndef FISH_H
#define FISH_H

#include <SDL.h>
#include "Vector.h"


using namespace MATH;

class Fish
{
public:
	Fish();
	~Fish();
	Fish(SDL_Rect body);
	Vec3 pos, vel, accelPrevious, accelCurrent, accel;
	int health;
	SDL_Rect body;
	void Update(float deltaTime);
	void Render(SDL_Renderer* renderer);

};

#endif