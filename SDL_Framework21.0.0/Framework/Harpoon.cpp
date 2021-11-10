#include "Harpoon.h"
#include <math.h>
#include <cmath>
#include <iostream>
#include "VMath.h"

Harpoon::Harpoon(Vec3 pos_, Vec3 vel_)
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
}

Harpoon::~Harpoon() {
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

	//Movement Code
	//https://wiki.libsdl.org/SDL_KeyboardEvent
	// if (    keyboard input   ) { Acceleration = Accel + Vec3(0, 2, 0)..........

	//else { accel = 0.0f, 0.0, 0.0    Vel = 0 etc...
	//position = initail velocity * time    +   1/2   (accel * time
}

void Harpoon::render(SDL_Renderer* render)
{
	SDL_RenderCopyEx(render, texture, nullptr, &harpoonBox, angle, nullptr, SDL_FLIP_NONE);
}

bool Harpoon::setImage(const char* path, SDL_Renderer* renderer)
{
	SDL_Surface* harryImage = IMG_Load(path);
	SDL_Texture* harryTexture = SDL_CreateTextureFromSurface(renderer, harryImage);
	if (harryTexture == nullptr) printf("%s\n", SDL_GetError());
	if (harryImage == nullptr) {
		std::cerr << "Can't open the image" << std::endl;
		return false;
	}
	else {
		texture = harryTexture;
		SDL_FreeSurface(harryImage);
	}
	return true;
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

bool Harpoon::isCollided(Fish* fish, Harpoon* harpoon)
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
	leftB = fish->body.x;
	rightB = fish->body.x + fish->body.w;
	topB = fish->body.y;
	bottomB = fish->body.y + fish->body.h;

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
	std::cout << "BANG!\n";
	return true;
}