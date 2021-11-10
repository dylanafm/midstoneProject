#ifndef HARPOON_H
#define HARPOON_H


#include "Body.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Vector.h"
#include "Fish.h"

class Harpoon : public Body
{
private:


public:
	Harpoon(Vec3 pos_, Vec3 vel_);
	~Harpoon();

	Vec3 pos, vel, accelPrevious, accelCurrent, accel, finalForce;
	float drag, mass, radius, length, coefficient;
	double angle;
	SDL_Rect harpoonBox;
	SDL_Texture* texture;

	void Update(float deltaTime);

	void applyForce(const Vec3 force) { accel = force / mass; accelPrevious = accelCurrent; accelCurrent = force / mass; }

	void render(SDL_Renderer* render);

	bool setImage(const char* path, SDL_Renderer* renderer);
	SDL_Texture* getTexture() { return texture; }
	void setPosition(Vec3 pos_) { pos = pos_; }

	bool MouseClicked(SDL_Event event_);

	bool isCollided(Fish* fish, Harpoon* harry);

};

#endif