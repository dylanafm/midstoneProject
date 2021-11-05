#include "Fish.h"
Fish::Fish() 
{
	pos = Vec3(450.0f, 100.0f, 100.0f);
	health = 100;
	body.x = pos.x;
	body.y = pos.y;
	body.w = 50.0f;
	body.h = 50.0f;

	vel = Vec3(0.0f, 0.0f, 0.0f);
	accel = Vec3(0.0f, 0.0f, 0.0f);
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);
}
Fish::~Fish()
{
}
Fish::Fish(SDL_Rect body_)
{
	body = body_;
}
void Fish::Update(float deltaTime)
{
	pos += vel * deltaTime + 0.5f * accelPrevious * deltaTime * deltaTime;
	vel += 0.5 * (accelCurrent + accelPrevious) * deltaTime;
}
void Fish::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, 100, 150, 0, 255);
	SDL_RenderFillRect(renderer, &body);
	//printf("Rendered!\n");

	//std::cout << body.x << ", " << body.y << " , " << body.w << " , " << body.h << "\n";


}
