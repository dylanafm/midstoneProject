#include "Body.h"
#include "TextureManager.h"


Body::Body(){
	pos = Vec3(0.0f, 0.0f, 0.0f);
	vel = Vec3(0.0f, 0.0f, 0.0f);
	accel = Vec3(0.0f, 0.0f, 0.0f);
	body = SDL_Rect{ 0, 0, 100, 100 };

	texture = nullptr;
	mass = 0.0f;
}

Body::Body(SDL_Rect body_, Vec3 vel_, SDL_Renderer* renderer, const char* path)
{
	body = body_;
	pos = Vec3(body.x, body.y, 0.0f);
	vel = vel_;
	accel = Vec3(0.0f, 0.0f, 0.0f);
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);

	texture = TextureManager::LoadTexture(path, renderer);
}

Body::~Body(){
	SDL_DestroyTexture(texture);
}

void Body::Update(float deltaTime){
	pos += vel * deltaTime + 0.5f * accelPrevious * deltaTime * deltaTime;
	vel += 0.5 * (accelCurrent + accelPrevious) * deltaTime;
	body.x = pos.x;
	body.y = pos.y;
}

void Body::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, nullptr, &body);
}
