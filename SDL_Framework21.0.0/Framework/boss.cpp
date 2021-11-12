#include "boss.h"
#include "TextureManager.h"

boss::boss()
{
	pos = Vec3(450.0f, 100.0f, 100.0f);
	health = 100;
	body.x = pos.x;
	body.y = pos.y;
	body.w = 200.0f;
	body.h = 200.0f;

	vel = Vec3(0.0f, 0.0f, 0.0f);
	accel = Vec3(0.0f, 0.0f, 0.0f);
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);
}

boss::~boss()
{
}

boss::boss(SDL_Rect body_)
{
	body = body_;
}

void boss::Update(float deltaTime)
{
	pos += vel * deltaTime + 0.5f * accelPrevious * deltaTime * deltaTime;
	vel += 0.5 * (accelCurrent + accelPrevious) * deltaTime;
}

void boss::Render(SDL_Renderer* renderer)
{
	bossTex = TextureManager::LoadTexture("textures/bossPNG.png", renderer);

	if (bossTex == nullptr) {
		printf("Where da fish at?\n");
	}
	SDL_RenderCopy(renderer, bossTex, nullptr, &body);
}
