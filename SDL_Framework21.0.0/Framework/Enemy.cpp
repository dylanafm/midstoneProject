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

	

	
}


Enemy::~Enemy() {

}

Enemy::Enemy(SDL_Rect body_, float scrollSpeed_ , SDL_Renderer* renderer, const char* path)
{
	body = body_;
	pos = Vec3(body.x, body.y, 0.0f);
	scrollSpeed = scrollSpeed_;
	vel = Vec3(0.0f, 0.0f, 0.0f);
	accel = Vec3(0.0f, 0.0f, 0.0f);
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);

	texture = TextureManager::LoadTexture(path, renderer);
	HealthTex = TextureManager::LoadTexture("textures/Health.png", renderer);
	BarTex = TextureManager::LoadTexture("textures/FullBar.png", renderer);

	health = 1;
}

void Enemy::Update(float deltaTime)
{
	pos += vel * deltaTime + 0.5f * accelPrevious * deltaTime * deltaTime;
	vel += 0.5 * (accelCurrent + accelPrevious) * deltaTime;
	
}
void Enemy::UpdateHealthBar(SDL_Renderer* r, int h) {
	HealthBar = SDL_Rect{ body.x + 45, body.y - 40 , h * 50 , 15 };
	TotalBar = SDL_Rect{ body.x + 45, body.y - 40 , 150, 15 };
	SDL_RenderCopy(r, BarTex, nullptr, &TotalBar);
	SDL_RenderCopy(r, HealthTex, nullptr, &HealthBar);

	cout << HealthBar.x << endl;
}
void Enemy::Scroll()
{
	body.x = body.x - scrollSpeed;
}

void Enemy::Render(SDL_Renderer* renderer)
{

	
	SDL_RenderCopy(renderer, texture, nullptr, &body);

}
