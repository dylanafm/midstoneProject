#ifndef HARPOONHARRY_H
#define HARPOONHARRY_H


#include "Body.h"
#include <SDL.h>
#include "Vector.h"
#include "Fish.h"

class harpoonHarry : public Body
{
private:


public:
	harpoonHarry();
	~harpoonHarry();

	int health;
	Vec3 pos, vel, accelPrevious, accelCurrent, accel, finalForce;
	float drag, mass, radius, length, coefficient;
	double angle;
	SDL_Rect harryBox;
	SDL_Texture* texture;

	void HandleEvents(SDL_Event sdlEvent);

	void Update(float deltaTime);

	void applyForce(const Vec3 force) { accel = force / mass; accelPrevious = accelCurrent; accelCurrent = force / mass;}

	bool checkCollision(harpoonHarry* harry, Fish* fish);

	void isCollided(Fish* fish, harpoonHarry* harry);

	void render(SDL_Renderer* render);
	/*inline void setPos(const Vec3& pos_) { pos_ = pos; }
	inline void setVel(const Vec3& vel_) { vel_ = vel; }
	inline Vec3 getVel() { return vel; }
	inline void setAccel(const Vec3& accel_) { accel_ = accel; }
	inline Vec3 getAccel() { return accel; }*/
	inline void calculateMass(float density_) { mass = density_ * radius * radius * length * 3.14; std::cout << mass; }

	Vec3 getPos() { return pos; }
	Vec3 getVel() { return vel; }
	Vec3 getAccel() { return accel;  }

	void setTexture(SDL_Texture* texture_) { texture = texture_; }
	SDL_Texture* getTexture() { return texture; }




};

#endif