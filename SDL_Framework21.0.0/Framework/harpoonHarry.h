#ifndef HARPOONHARRY_H
#define HARPOONHARRY_H


#include "Body.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Vector.h"
#include "Fish.h"
#include <gif_lib.h>

class harpoonHarry : public Body
{
private:
	int imageH;
	int imageW;

public:
	harpoonHarry(SDL_Renderer* renderer, const char* path);
	~harpoonHarry();

	int health, currentFrame, animDelay, amountFrameX, amountFrameY;
	Vec3 accelPrevious, accelCurrent, accel, finalForce;
	float drag, mass, radius, length, coefficient;
	double angle, anglePrevious, flip;
	
	SDL_Rect harryBox;
	SDL_Rect crop;

	SDL_Texture* texture;

	void HandleEvents(SDL_Event sdlEvent);

	void Update(float deltaTime);

	void applyForce(const Vec3 force) { accel = force / mass; accelPrevious = accelCurrent; accelCurrent = force / mass;}

	bool checkCollision(harpoonHarry* harry, Enemy* enemy);

	bool isCollided(harpoonHarry* harry, Enemy* enemy);

	void render(SDL_Renderer* render);

	void PlayAnim(int beginFrame, int endFrame, int row, float frameSpeed);

	void SetUpAnim(int amountFrameX_, int amountFrameY_);

	SDL_Texture* getTexture() { return texture; }




};

#endif