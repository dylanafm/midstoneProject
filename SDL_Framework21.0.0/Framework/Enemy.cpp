#include "Enemy.h"
#include "TextureManager.h"


Enemy::Enemy(SDL_Rect body_, Vec3 vel_, SDL_Renderer* renderer, const char* path, float radius_)
	:Body(body_, vel_, renderer, path)
{
	health = 1;
	radiusInPixels = radius_;
}

Enemy::Enemy(SDL_Rect body_, SDL_Renderer* renderer, const char* path, float radius_)
	:Body(body_, Vec3(0.0f, 0.0f, 0.0f), renderer, path)
{
	
	health = 1;
	radiusInPixels = radius_;
}

Enemy::~Enemy() {

}
