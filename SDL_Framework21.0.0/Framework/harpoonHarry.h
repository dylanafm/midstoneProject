#ifndef HARPOONHARRY_H
#define HARPOONHARRY_H

#include "Body.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Vector.h"
#include "Fish.h"
#include "Animation.h"
#include "healthPickup.h"

class Animation;
class healthPickup;

class HarpoonHarry : public Body
{
public:

	Animation* swim;

	HarpoonHarry(SDL_Renderer* renderer, const char* path, float radius_);
	~HarpoonHarry();

	int health;
	Vec3 accelPrevious, accelCurrent, accel, finalForce, center;
	float drag, mass, radius, length, coefficient, radiusInPixels, timeRemaining, gunTimeRemain;
	double angle, anglePrevious, flip;
	bool Shielded, rapidFire;
	SDL_Rect harryBox;
	SDL_Rect crop;

	SDL_Texture* texture;

	void HandleEvents(SDL_Event sdlEvent);

	void Update(float deltaTime);

	void applyForce(const Vec3 force) { accel = force / mass; accelPrevious = accelCurrent; accelCurrent = force / mass;}

	bool checkCollision(HarpoonHarry* harry, Enemy* enemy);

	bool isCollided(HarpoonHarry* harry, Enemy* enemy);

	bool checkHealthCollision(HarpoonHarry* harry, healthPickup* hp);

	bool isHealthCollided(HarpoonHarry* harry, healthPickup* hp);

	void render(SDL_Renderer* render);

	void PlayAnim(int beginFrame, int endFrame, int row, float frameSpeed);

	void SetUpAnim(int amountFrameX_, int amountFrameY_);

	SDL_Texture* getTexture() { return texture; }




};

#endif