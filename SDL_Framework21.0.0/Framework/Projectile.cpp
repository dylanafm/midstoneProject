#include "Projectile.h"
#include "TextureManager.h"

Projectile::Projectile(Vec3 pos_, Vec3 vel_, SDL_Renderer* renderer, const char* path)
{
	pos = pos_;
	vel = vel_;
	accel = Vec3(0.0f, 0.0f, 0.0f);
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);
	finalForce = Vec3(0.0f, 0.0f, 0.0f);
	texture = nullptr;


	body.x = pos.x;
	body.y = pos.y;
	body.w = 30.0f;
	body.h = 30.0f;

	texture = TextureManager::LoadTexture(path, renderer);
}

Projectile::~Projectile()
{
}

void Projectile::Update(float deltaTime)
{
	pos += vel * deltaTime + 0.5f * accelPrevious * deltaTime * deltaTime;
	vel += 0.5 * (accelCurrent + accelPrevious) * deltaTime;

	body.x = pos.x;
	body.y = pos.y;
}

void Projectile::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, nullptr, &body);
}
