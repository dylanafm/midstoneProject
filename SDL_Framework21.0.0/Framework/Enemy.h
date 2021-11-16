#ifndef ENEMY_H
#define ENEMY_H
#include <SDL.h>
#include "Vector.h"

using namespace MATH;

class Enemy {
public:
	Vec3 pos, vel, accelPrevious, accelCurrent, accel;
	int health;
	float scrollSpeed;

	Enemy();
	~Enemy();
	Enemy(SDL_Rect body, float scrollSpeed, SDL_Renderer* renderer, const char* path);
	SDL_Rect body;
	SDL_Texture* texture;

	//Health Bar

	SDL_Rect TotalBar;
	SDL_Rect HealthBar;

	SDL_Texture* BarTex;
	SDL_Texture* HealthTex;
	

	virtual void Update(float deltaTime);
	void UpdateHealthBar(SDL_Renderer* r, int h);
	void Scroll();
	void Render(SDL_Renderer* renderer);
};

#endif
