#include "HarpoonHarry.h"
#include <math.h>
#include <cmath>
#include <iostream>
#include "VMath.h"
#include "TextureManager.h"


HarpoonHarry::HarpoonHarry(SDL_Renderer* renderer, const char* path, float radius_)
{
	timeRemaining = 0.0f;
	gunTimeRemain = 0.0f;
	pos = Vec3(500.0f, 50.0f, 200.0f);
	vel = Vec3(0.0f, 0.0f, 0.0f);
	accel = Vec3(0.0f, 0.0f, 0.0f);
	drag = 0.005f;
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);
	length = 1.7f;
	coefficient = 50.0f;
	mass = 100.0f;
	health = 3;
	finalForce = Vec3(0.0f, 0.0f, 0.0f);
	angle = 0.0;
	anglePrevious = 0.0;
	flip = 0.0;
	radius = 0.3f;


	harryBox.x = pos.x;
	harryBox.y = pos.y;
	harryBox.w = 50.0f;
	harryBox.h = 50.0f;
	texture = TextureManager::LoadTexture(path, renderer);
	
	swim = new Animation(texture);
	swim->SetUpAnim(8, 1);

	Shielded = false;
	rapidFire = false;
	

	radiusInPixels = radius_;
}

HarpoonHarry::~HarpoonHarry(){
	delete swim;
	SDL_DestroyTexture(texture);
}
void HarpoonHarry::HandleEvents(SDL_Event sdlEvent) {
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

void HarpoonHarry::Update(float deltaTime)
{
	if (timeRemaining > 0.0f) {

		timeRemaining -= deltaTime;

	}
	if (timeRemaining <= 0.0f)
	{
		Shielded = false;
	}

	if (gunTimeRemain > 0.0f) {

		gunTimeRemain -= deltaTime;

	}
	if (gunTimeRemain <= 0.0f)
	{
		rapidFire = false;
	}	
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

bool HarpoonHarry::checkEnemyCollision(HarpoonHarry* harry, Enemy* enemy)
{
	
	Vec3 enemyCenter = Vec3(enemy->pos.x + enemy->body.w / 2.0f, enemy->pos.y + enemy->body.h / 2.0f, 0.0f);
	Vec3 harryCenter = Vec3(harry->pos.x + harry->harryBox.w / 2.0f, harry->pos.y + harry->harryBox.h / 2.0f, 0.0f);

	if (((enemyCenter.x - harryCenter.x) * (enemyCenter.x - harryCenter.x) +
		(harryCenter.y - enemyCenter.y) * (harryCenter.y - enemyCenter.y)) <=
		((enemy->radiusInPixels + harry->radiusInPixels) * (enemy->radiusInPixels + harry->radiusInPixels))) {
		return true;
	}

	return false;
}

bool HarpoonHarry::isEnemyCollided(HarpoonHarry* harry, Enemy* enemy)
{
	if (!Shielded) {
		if ((harry->checkEnemyCollision(harry, enemy)) == true) {
			health--;
			return true;
		}
	}
	else {
		if ((harry->checkEnemyCollision(harry, enemy)) == true) {
			return true;
		}
	}
	
	return false;
}

bool HarpoonHarry::checkPowerupCollision(HarpoonHarry* harry, Powerup* powerup)
{
	Vec3 hpCenter = Vec3(powerup->pos.x + powerup->body.w / 2.0f, powerup->pos.y + powerup->body.h / 2.0f, 0.0f);
	Vec3 harryCenter = Vec3(harry->pos.x + harry->harryBox.w / 2.0f, harry->pos.y + harry->harryBox.h / 2.0f, 0.0f);

	if (((hpCenter.x - harryCenter.x) * (hpCenter.x - harryCenter.x) +
		(harryCenter.y - hpCenter.y) * (harryCenter.y - hpCenter.y)) <=
		((powerup->radiusInPixels + harry->radiusInPixels) * (powerup->radiusInPixels + harry->radiusInPixels))) {
		return true;
	}

	return false;
}

bool HarpoonHarry::isPowerupCollided(HarpoonHarry* harry, Powerup* powerup)
{
	if ((harry->checkPowerupCollision(harry, powerup)) == true) {
		powerup->Ability(this);
		return true;
	}
	return false;
}

void HarpoonHarry::render(SDL_Renderer* render)
{
	crop = swim->getCrop();

	SDL_RenderCopyEx(render, texture, &crop, &harryBox, angle + 90.0, nullptr, SDL_FLIP_NONE);
}
