#ifndef HEALTHPICKUP_H
#define HEALTHPICKUP_H
#include "LevelOne.h"
#include "LTexture.h"
#include "HarpoonHarry.h"

class HarpoonHarry;

class HealthPickup
{
public:
	HealthPickup(Vec3 pos_,float scrollSpeed_, SDL_Renderer* render_);
	~HealthPickup();
	Vec3 pos, vel, accelPrevious, accelCurrent, accel;
	float scrollSpeed, radiusInPixels;
	void scroll();
	void render(SDL_Renderer* render);
	void collide(HarpoonHarry* harry);
	void update(float deltaTime);


	SDL_Rect body;
	SDL_Texture* healthTexture;
};

#endif
