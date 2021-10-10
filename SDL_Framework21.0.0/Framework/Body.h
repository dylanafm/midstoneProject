#ifndef BODY_H
#define BODY_H
#include "Vector.h"

using namespace MATH;

class Body {
private:
	Vec3 pos;
	Vec3 vel;
	Vec3 accel;
	float mass;
public:
	Body();
	~Body();
	void Update(float deltaTime);
	Vec3 getPos() { return pos; }

};

#endif