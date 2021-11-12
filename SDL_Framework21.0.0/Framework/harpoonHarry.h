#ifndef HARPOONHARRY_H
#define HARPOONHARRY_H


#include "Body.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Vector.h"
#include "Fish.h"
#include "boss.h"

class harpoonHarry : public Body
{
private:


public:
	harpoonHarry();
	~harpoonHarry();

	int health;
	Vec3 pos, vel, accelPrevious, accelCurrent, accel, finalForce;
	float drag, mass, radius, length, coefficient;
	double angle, anglePrevious, flip;
	SDL_Rect harryBox;
	SDL_Texture* texture;

	void HandleEvents(SDL_Event sdlEvent);

	void Update(float deltaTime);

	void applyForce(const Vec3 force) { accel = force / mass; accelPrevious = accelCurrent; accelCurrent = force / mass;}

	bool checkCollision(harpoonHarry* harry, Fish* fish);

	bool checkBossCollision(harpoonHarry* harry, boss* boss1);

	bool isCollided(Fish* fish, harpoonHarry* harry);

	bool isBossCollided(boss* boss1, harpoonHarry* harry);

	void render(SDL_Renderer* render);

	bool setImage(const char* path, SDL_Renderer* renderer);
	SDL_Texture* getTexture() { return texture; }




};

#endif