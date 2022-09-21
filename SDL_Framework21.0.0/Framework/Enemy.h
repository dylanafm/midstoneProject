#ifndef ENEMY_H
#define ENEMY_H
#include <SDL.h>
#include "Vector.h"

using namespace MATH;

class Enemy {
public:
	Vec3 pos, vel, accelPrevious, accelCurrent, accel;
	int health;
	float scrollSpeed, radiusInPixels;
	SDL_Rect body;
	SDL_Rect crop;
	SDL_Texture* texture;

	Enemy();
	~Enemy();
	Enemy(SDL_Rect body, Vec3 vel_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_);
	Enemy(SDL_Rect body, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_);
	
	virtual void Update(float deltaTime);
	void Scroll();
	virtual void Render(SDL_Renderer* renderer);
};

#endif
