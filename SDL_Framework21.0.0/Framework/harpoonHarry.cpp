#include "harpoonHarry.h"
#include <math.h>
#include <cmath>
#include <iostream>
#include "VMath.h"
#include "TextureManager.h"

harpoonHarry::harpoonHarry(SDL_Renderer* renderer, const char* path)
{
	
	pos = Vec3(500.0f, 50.0f, 200.0f);
	vel = Vec3(0.0f, 0.0f, 0.0f);
	accel = Vec3(0.0f, 0.0f, 0.0f);
	drag = 0.005f;
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);
	radius = 0.3f;
	length = 1.7f;
	coefficient = 50.0f;
	mass = 100.0f;
	health = 3;
	finalForce = Vec3(0.0f, 0.0f, 0.0f);
	angle = 0.0;
	anglePrevious = 0.0;
	flip = 0.0;


	harryBox.x = pos.x;
	harryBox.y = pos.y;
	harryBox.w = 50.0f;
	harryBox.h = 50.0f;
	texture = TextureManager::LoadTexture(path, renderer);

	SDL_QueryTexture(texture, nullptr, nullptr, &imageW, &imageH);
	
	crop = SDL_Rect{ 0, 0, imageW, imageH };

	currentFrame = 0;
	amountFrameX = 0;
	amountFrameY = 0;
}

harpoonHarry::~harpoonHarry(){
}
void harpoonHarry::HandleEvents(SDL_Event sdlEvent) {
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_SCANCODE_W]) {
		finalForce += Vec3(0.0f, -10000.0f, 0.0f);
	}
	if (keystate[SDL_SCANCODE_S]) {
		finalForce += Vec3(0.0f, 10000.0f, 0.0f);
	}
	if (keystate[SDL_SCANCODE_A]) {
		finalForce += Vec3(-10000.0f, 0.0f, 0.0f);
	}
	if (keystate[SDL_SCANCODE_D]) {
		finalForce += Vec3(10000.0f, 0.0f, 0.0f);
	}	
}

void harpoonHarry::Update(float deltaTime)
{
	if (pos.x <= 0) {

		pos.x = 1;

	}
	else if (pos.x >= 1225) {

		pos.x = 1224;
	}
	else if (pos.y <= 0)
	{
		pos.y = 1;
	}
	else if (pos.y >= 675) {
		
		pos.y = 674;
	}
	else
	{


		applyForce(finalForce);
		finalForce = Vec3(0.0f, 0.0f, 0.0f);
		pos += vel * deltaTime + 0.5f * accelPrevious * deltaTime * deltaTime;
		vel += 0.5 * (accelCurrent + accelPrevious) * deltaTime;

		if (vel.y > 90.0f) vel.y = 90.0f;
		if (vel.y < -90.0f) vel.y = -90.0f;

		anglePrevious = angle;
		double angleCurrent = atan2(vel.y, vel.x) * 180.0 / M_PI + flip;

		if (angleCurrent - anglePrevious > 180.0f)  flip -= 360;
		if (angleCurrent - anglePrevious < -180.0f) flip += 360;

		angle = atan2(vel.y, vel.x) * 180.0 / M_PI + flip;

		angle = angle + 0.9 * (anglePrevious - angle); // Lerp function

		harryBox.x = pos.x;
		harryBox.y = pos.y;
	}
	}

bool harpoonHarry::checkCollision(harpoonHarry* harry, Enemy* enemy)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = harryBox.x;
	rightA = harryBox.x + harryBox.w;
	topA = harryBox.y;
	bottomA = harryBox.y + harryBox.h;

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
	std::cout << "BANG!\n";
	return true;
}

bool harpoonHarry::isCollided(harpoonHarry* harry, Enemy* enemy)
{
	if ((harry->checkCollision(harry, enemy)) == true) {
		health--;
		std::cout << "Health = " << health << "\n";
		return true;
	}
	return false;
}

void harpoonHarry::render(SDL_Renderer* render)
{
	SDL_RenderCopyEx(render, texture, &crop, &harryBox, angle, nullptr, SDL_FLIP_NONE);
}

void harpoonHarry::PlayAnim(int beginFrame, int endFrame, int row, float frameSpeed) {

	if (animDelay + frameSpeed < SDL_GetTicks()) {

		if (endFrame <= currentFrame)
		{
			currentFrame = beginFrame;
		}
		else {
			currentFrame++;
		}


		crop.x = currentFrame * imageW / amountFrameX;
		crop.y = row * (imageH / amountFrameY);
		crop.w = imageW / amountFrameX;
		crop.h = imageH / amountFrameY;
		
		animDelay = SDL_GetTicks();
	}



}


void harpoonHarry::SetUpAnim(int amountFrameX_, int amountFrameY_) {

	amountFrameX = amountFrameX_;
	amountFrameY = amountFrameY_;


}