#ifndef HARPOONHARRY_H
#define HARPOONHARRY_H


#include "Body.h"
#include <SDL.h>
class harpoonHarry : public Body
{
private:

	int health;
	Vec3 pos;
	Vec3 vel;
	Vec3 accel;
	float mass;

public:
	harpoonHarry();
	~harpoonHarry();

	void Update(float deltaTime);

	void applyForce(const Vec3 force) { accel = force / mass; }


	Vec3 getPos() { return pos; }
	Vec3 getVel() { return vel; }
	Vec3 getAccel() { return accel;  }





};

#endif