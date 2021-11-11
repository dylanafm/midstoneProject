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
	Fish(SDL_Rect body, SDL_Renderer* renderer);
	Vec3 pos, vel, accelPrevious, accelCurrent, accel;
	int health;
	SDL_Rect body;
	SDL_Renderer* fishRender;
	SDL_Texture* fishTex;
	void Update(float deltaTime);
	void Render(SDL_Renderer* renderer);

};

#endif