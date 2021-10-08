#ifndef HARPOONHARRY_H
#define HARPOONHARRY_H


#include "Body.h"
#include <SDL.h>
#include "Vector.h"

class harpoonHarry : public Body
{
private:


public:
	harpoonHarry();
	~harpoonHarry();

	int health;
	Vec3 pos;
	Vec3 vel;
	Vec3 accel;
	float mass;

	void Update(float deltaTime);

	void applyForce(const Vec3 force) { accel = force / mass; }

	/*inline void setPos(const Vec3& pos_) { pos_ = pos; }
	inline void setVel(const Vec3& vel_) { vel_ = vel; }
	inline Vec3 getVel() { return vel; }
	inline void setAccel(const Vec3& accel_) { accel_ = accel; }
	inline Vec3 getAccel() { return accel; }*/

	Vec3 getPos() { return pos; }
	Vec3 getVel() { return vel; }
	Vec3 getAccel() { return accel;  }





};

#endif