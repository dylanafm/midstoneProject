#ifndef HARPOONHARRY_H
#define HARPOONHARRY_H

#include <SDL.h>
#include <SDL_image.h>
#include "Body.h"
#include "Vector.h"
#include "Enemy.h"
//#include "Powerup.h"
#include "Animation.h"

class Animation;
class Powerup;

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

	bool checkEnemyCollision(HarpoonHarry* harry, Enemy* enemy);

	bool isEnemyCollided(HarpoonHarry* harry, Enemy* enemy);

	bool checkPowerupCollision(HarpoonHarry* harry, Powerup* powerup);

	bool isPowerupCollided(HarpoonHarry* harry, Powerup* powerup);

	void render(SDL_Renderer* render);

	void PlayAnim(int beginFrame, int endFrame, int row, float frameSpeed);

	void SetUpAnim(int amountFrameX_, int amountFrameY_);

	SDL_Texture* getTexture() { return texture; }




};

#endif