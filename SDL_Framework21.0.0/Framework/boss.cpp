#include "Boss.h"
#include "VMath.h"

Boss::Boss(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_):
	Enemy(body_, renderer, path, radius_){
	angle = 0.0;
	swim = new Animation(texture);
	swim->SetUpAnim(2, 1);
	isActive = false;
	isProjectileFired = false;
	projectile = nullptr;
	projectileReloadTimer = nullptr;
	playerHurt = new Sfx("SFX/pain.wav", 10);


	HealthTex = TextureManager::LoadTexture("textures/Health.png", renderer);
	BarTex = TextureManager::LoadTexture("textures/FullBar.png", renderer);
}

Boss::~Boss()
{
	delete swim;
	SDL_DestroyTexture(BarTex);
	SDL_DestroyTexture(HealthTex);
	if (projectileReloadTimer != nullptr) delete projectileReloadTimer;
	if (projectile != nullptr) delete projectile;
	if (playerHurt != nullptr) delete playerHurt;
}

void Boss::Update(float deltaTime, HarpoonHarry* harry, SDL_Renderer* renderer)
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

	if (!isProjectileFired && pos.x < 1280) {
		spawnProjectile(harry, renderer);
	}


	if (projectile != nullptr) {
		projectile->Update(deltaTime);
		if (harry->isCollided(harry, projectile)) {
			if (!harry->Shielded) playerHurt->playSFX();
			delete projectile;
			projectile = nullptr;
		}
	}

	if (isProjectileFired && projectileReloadTimer != nullptr) {
		projectileReloadTimer->Update(deltaTime, isProjectileFired);
		if (!isProjectileFired) {
			projectileReloadTimer = nullptr;
			delete projectileReloadTimer;
		}
	}
}

void Boss::Render(SDL_Renderer* renderer)
{

	crop = swim->getCrop();
	//SDL_RendererFlip flip = (SDL_RendererFlip)(SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
	SDL_RenderCopyEx(renderer, texture, &crop, &body, angle, nullptr, SDL_FLIP_NONE);
	if (projectile != nullptr) projectile->Render(renderer);
}

void Boss::UpdateHealthBar(SDL_Renderer* r, int h) {
	int tHeatlh = 5 * 25;
	HealthBar = SDL_Rect{ body.x + 35, body.y - 40 , h * 25 , 15 };
	TotalBar = SDL_Rect{ body.x + 35, body.y - 40 , tHeatlh, 15 };
	SDL_RenderCopy(r, BarTex, nullptr, &TotalBar);
	SDL_RenderCopy(r, HealthTex, nullptr, &HealthBar);

}

void Boss::spawnProjectile(HarpoonHarry* harry, SDL_Renderer* renderer)
{
	Vec3 axes(0, 0, 1);
	Matrix4 rotation = MMath::rotate((float)angle, axes);
	Vec3 centerPos = Vec3(150.0f, 30.0f, 0.0f);
	Vec3 offset = rotation * centerPos;
	Vec3 bossCenter = pos + Vec3(body.w / 2, body.h / 2, 0.0f);
	Vec3 newPos = bossCenter - offset;


	Vec3 direction = Vec3(harry->pos.x + 25.0f - newPos.x, harry->pos.y + 25.0f - newPos.y, 0.0f);
	Vec3 velocity = VMath::normalize(direction) * 300.0f;
	projectile = new Projectile(SDL_Rect{ (int)newPos.x, (int)newPos.y, 25, 25 }, velocity, renderer, "textures/Bubble_1.png", 12.5f);

	isProjectileFired = true;
	projectileReloadTimer = new InGameTimer(4.5f);
}
