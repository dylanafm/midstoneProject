#include "Shark.h"
#include "VMath.h"

Shark::Shark(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_):
	Enemy(body_, renderer, path, radius_)
{
	angle = 0.0;
	SharkSwim = new Animation(texture);
	SharkSwim->SetUpAnim(3, 1);

	HealthTex = TextureManager::LoadTexture("textures/Health.png", renderer);
	BarTex = TextureManager::LoadTexture("textures/FullBar.png", renderer);
}

Shark::~Shark()
{
	delete SharkSwim;
	SDL_DestroyTexture(BarTex);
	SDL_DestroyTexture(HealthTex);
}

void Shark::Update(float deltaTime, HarpoonHarry* harry)
{

	Vec3 direction = Vec3(harry->pos.x - pos.x - 150.0f, harry->pos.y - pos.y - 70.0f, 0.0f);
	
	vel = VMath::normalize(direction) * 110.0f;

	pos += vel * deltaTime + 0.5f * accelPrevious * deltaTime * deltaTime;
	vel += 0.5 * (accelCurrent + accelPrevious) * deltaTime;

	if (direction.x > 5.0f || direction.x < -5.0f || direction.y > 5.0f || direction.y < -5.0f) {
		angle = atan2(vel.y, vel.x) * 180.0 / M_PI + 180;
	}

	body.x = pos.x;
	body.y = pos.y;
}

void Shark::Render(SDL_Renderer* renderer)
{
	crop = SharkSwim->getCrop();
	//SDL_RendererFlip flip = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
	SDL_RenderCopyEx(renderer, texture, &crop, &body, angle, nullptr, SDL_FLIP_NONE);
}

void Shark::UpdateHealthBar(SDL_Renderer* r, int h) {
	int tHeatlh = 5 * 25;
	HealthBar = SDL_Rect{ body.x + 35, body.y - 40 , h * 25 , 15 };
	TotalBar = SDL_Rect{ body.x + 35, body.y - 40 , tHeatlh, 15 };
	SDL_RenderCopy(r, BarTex, nullptr, &TotalBar);
	SDL_RenderCopy(r, HealthTex, nullptr, &HealthBar);

}
