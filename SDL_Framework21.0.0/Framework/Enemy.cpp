#include "Enemy.h"
#include "TextureManager.h"

Enemy::Enemy() {
	pos = Vec3(0.0f, 0.0f, 0.0f);
	body.x = pos.x;
	body.y = pos.y;
	body.w = 10.0f;
	body.h = 10.0f;

	vel = Vec3(0.0f, 0.0f, 0.0f);
	accel = Vec3(0.0f, 0.0f, 0.0f);
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);

	texture = nullptr;
	health = 1;

	scrollSpeed = 1.0f;
	radiusInPixels = 1.0f;

}


Enemy::~Enemy() {
	SDL_DestroyTexture(texture);
}

Enemy::Enemy(SDL_Rect body_, Vec3 vel_, float scrollSpeed_, SDL_Renderer* renderer, const char* path, float radius_)
{
	body = body_;
	pos = Vec3(body.x, body.y, 0.0f);
	scrollSpeed = scrollSpeed_;
	vel = vel_;
	accel = Vec3(0.0f, 0.0f, 0.0f);
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);

	texture = TextureManager::LoadTexture(path, renderer);

	health = 1;
	radiusInPixels = radius_;
}

Enemy::Enemy(SDL_Rect body_, float scrollSpeed_ , SDL_Renderer* renderer, const char* path, float radius_)
{
	body = body_;
	pos = Vec3(body.x, body.y, 0.0f);
	scrollSpeed = scrollSpeed_;
	vel = Vec3(0.0f, 0.0f, 0.0f);
	accel = Vec3(0.0f, 0.0f, 0.0f);
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);

	texture = TextureManager::LoadTexture(path, renderer);

	health = 1;
	radiusInPixels = radius_;
}

void Enemy::Update(float deltaTime)
{
	pos += vel * deltaTime + 0.5f * accelPrevious * deltaTime * deltaTime;
	vel += 0.5 * (accelCurrent + accelPrevious) * deltaTime;
	body.x = pos.x;
	body.y = pos.y;
}

void Enemy::Scroll()
{
	pos.x = pos.x - scrollSpeed;
}

void Enemy::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, nullptr, &body);
}
