#ifndef BODY_H
#define BODY_H
#include "Vector.h"
#include <SDL.h>

using namespace MATH;

class Body {
public:
	Vec3 pos, vel, accelPrevious, accelCurrent, accel;
	float mass;
	SDL_Rect body;
	SDL_Texture* texture;
public:
	Body();
	Body(SDL_Rect body_, Vec3 vel_, SDL_Renderer* renderer, const char* path);
	~Body();
	void Update(float deltaTime);
	void Render(SDL_Renderer* renderer);
	Vec3 getPos() { return pos; }
};

#endif