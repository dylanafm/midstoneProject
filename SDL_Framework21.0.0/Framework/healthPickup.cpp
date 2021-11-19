#include "healthPickup.h"
#include "TextureManager.h"

healthPickup::healthPickup(Vec3 pos_, float scrollSpeed_, SDL_Renderer* render)
{
	pos = pos_;
	scrollSpeed = scrollSpeed_;
	body.x = pos.x;
	body.y = pos.y;
	body.w = 100.0f;
	body.h = 100.0f;
	healthTexture = TextureManager::LoadTexture("textures/HealthIMG.png", render);

	vel = Vec3(0.0f, 0.0f, 0.0f);
	accel = Vec3(0.0f, 0.0f, 0.0f);
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);
}

healthPickup::~healthPickup()
{
}

void healthPickup::scroll()
{
	pos.x = pos.x - scrollSpeed;
}

void healthPickup::render(SDL_Renderer* render)
{
	SDL_RenderCopy(render, healthTexture, nullptr, &body);
}

void healthPickup::collide(harpoonHarry* harry)
{
}

void healthPickup::update(float deltaTime)
{
	body.x = pos.x;
	body.y = pos.y;
	pos += vel * deltaTime + 0.5f * accelPrevious * deltaTime * deltaTime;
	vel += 0.5 * (accelCurrent + accelPrevious) * deltaTime;
}

