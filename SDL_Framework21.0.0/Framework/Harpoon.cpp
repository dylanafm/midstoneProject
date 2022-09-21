#include "Harpoon.h"
#include <math.h>
#include <cmath>
#include <iostream>
#include "VMath.h"
#include "TextureManager.h"

Harpoon::Harpoon(Vec3 pos_, Vec3 vel_, SDL_Renderer* renderer, const char* path)
{
	pos = pos_;
	vel = vel_;
	accel = Vec3(0.0f, 0.0f, 0.0f);
	drag = 0.005f;
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);
	radius = 0.05f;
	length = 1.0f;
	coefficient = 50.0f;
	mass = 100.0f;
	finalForce = Vec3(0.0f, 0.0f, 0.0f);
	texture = nullptr;
	angle = 0.0;


	harpoonBox.x = pos.x;
	harpoonBox.y = pos.y;
	harpoonBox.w = 30.0f;
	harpoonBox.h = 10.5f;

	texture = TextureManager::LoadTexture(path, renderer);
}

Harpoon::~Harpoon() {
	SDL_DestroyTexture(texture);
}

void Harpoon::Update(float deltaTime)
{
	applyForce(finalForce);
	finalForce = Vec3(0.0f, 0.0f, 0.0f);

	pos += vel * deltaTime + 0.5f * accelPrevious * deltaTime * deltaTime;
	vel += 0.5 * (accelCurrent + accelPrevious) * deltaTime;

	angle = atan2(vel.y, vel.x) * 180.0 / M_PI;

	harpoonBox.x = pos.x;
	harpoonBox.y = pos.y;
}

void Harpoon::render(SDL_Renderer* render)
{
	SDL_RenderCopyEx(render, texture, nullptr, &harpoonBox, angle, nullptr, SDL_FLIP_NONE);
}

bool Harpoon::MouseClicked(SDL_Event event_)
{
	int x, y;
	Uint32 buttons;
	buttons = SDL_GetMouseState(&x, &y);

	if (event_.button.button == SDL_BUTTON_LEFT && event_.type == SDL_MOUSEBUTTONDOWN)
	{

		//Get the mouse offsets
		x = event_.button.x;
		y = event_.button.y;
		return true;
	}
	return false;
}

bool Harpoon::isCollided(Enemy* enemy, Harpoon* harpoon)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = harpoonBox.x;
	rightA = harpoonBox.x + harpoonBox.w;
	topA = harpoonBox.y;
	bottomA = harpoonBox.y + harpoonBox.h;

	//Calculate the sides of rect B
	leftB = enemy->body.x;
	rightB = enemy->body.x + enemy->body.w;
	topB = enemy->body.y;
	bottomB = enemy->body.y + enemy->body.h;

	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}
