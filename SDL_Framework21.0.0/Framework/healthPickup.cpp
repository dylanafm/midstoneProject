#include "HealthPickup.h"
#include "TextureManager.h"

HealthPickup::HealthPickup(Vec3 pos_, float scrollSpeed_, SDL_Renderer* render)
{
	pos = pos_;
	scrollSpeed = scrollSpeed_;
	body.x = pos.x;
	body.y = pos.y;
	body.w = 50.0f;
	body.h = 50.0f;
	healthTexture = TextureManager::LoadTexture("textures/HealthIMG.png", render);

	vel = Vec3(0.0f, 0.0f, 0.0f);
	accel = Vec3(0.0f, 0.0f, 0.0f);
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);
	radiusInPixels = 1.0f;
}

HealthPickup::~HealthPickup()
{
	SDL_DestroyTexture(healthTexture);
}

void HealthPickup::scroll()
{
	pos.x = pos.x - scrollSpeed;
}

void HealthPickup::render(SDL_Renderer* render)
{
	SDL_RenderCopy(render, healthTexture, nullptr, &body);
}

void HealthPickup::collide(HarpoonHarry* harry)
{
}

void HealthPickup::update(float deltaTime)
{
	body.x = pos.x;
	body.y = pos.y;
	pos += vel * deltaTime + 0.5f * accelPrevious * deltaTime * deltaTime;
	vel += 0.5 * (accelCurrent + accelPrevious) * deltaTime;
}

