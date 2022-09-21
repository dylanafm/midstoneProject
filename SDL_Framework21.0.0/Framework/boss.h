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
class Projectile;
class InGameTimer;

class Boss : public Enemy
{
public:
	double angle;
	bool isActive;
	Animation* swim;

	Projectile* projectile;
	bool isProjectileFired;
	InGameTimer* projectileReloadTimer;

	Sfx* playerHurt;

	//Health Bar

	SDL_Rect TotalBar;
	SDL_Rect HealthBar;

	SDL_Texture* BarTex;
	SDL_Texture* HealthTex;

	Boss(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_);
	~Boss();
	void Update(float deltaTime, HarpoonHarry* harry, SDL_Renderer* renderer);
	void Render(SDL_Renderer* renderer) override;

	void UpdateHealthBar(SDL_Renderer* r, int h);
	void spawnProjectile(HarpoonHarry* harry, SDL_Renderer* renderer);
};

#endif