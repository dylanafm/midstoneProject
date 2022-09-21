#include "boss.h"
#include "VMath.h"

Boss::Boss(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_):
	Enemy(body_, scrollSpeed, renderer, path, radius_){
	angle = 0.0;
	swim = new Animation(texture);
	swim->SetUpAnim(2, 1);
}

Boss::~Boss()
{
	delete swim;
}

void Boss::Update(float deltaTime, harpoonHarry* harry)
{
	Vec3 direction = Vec3(harry->pos.x - pos.x - 100.0f, harry->pos.y - pos.y - 100.0f, 0.0f);
	vel = VMath::normalize(direction) * 90.0f;

	pos += vel * deltaTime + 0.5f * accelPrevious * deltaTime * deltaTime;
	vel += 0.5 * (accelCurrent + accelPrevious) * deltaTime;

	if (direction.x > 5.0f || direction.x < -5.0f || direction.y > 5.0f || direction.y < -5.0f) {
		angle = atan2(vel.y, vel.x) * 180.0 / M_PI + 180;
	}

	body.x = pos.x;
	body.y = pos.y;
}

void Boss::Render(SDL_Renderer* renderer)
{
	crop = swim->getCrop();
	//SDL_RendererFlip flip = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
	SDL_RenderCopyEx(renderer, texture, &crop, &body, angle, nullptr, SDL_FLIP_NONE);
}
