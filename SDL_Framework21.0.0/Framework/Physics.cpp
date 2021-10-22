#include "Physics.h"
#include <iostream>
#include <cmath>


void Physics::ApplyForces(harpoonHarry& object, const float waterHeight)
{
	float V, theta;
	theta = 2 * acos(abs(object.pos.y - waterHeight) / object.radius);
	if (object.pos.y >= waterHeight && object.pos.y - object.radius <= waterHeight)
	{
		V = 0.5 * object.radius * object.radius * (theta - sin(theta)) * object.length;
	}
	else if (object.pos.y < waterHeight && object.pos.y + object.radius > waterHeight) 
	{
		V = 3.14 * object.radius * object.radius * object.length - 0.5 * object.radius * object.radius * (theta - sin(theta)) * object.length;
	}
	else if (object.pos.y < waterHeight + object.radius) {
		V = 0.0f;
	}
	else{
		V = 3.14 * object.radius * object.radius * object.length;
	}
	Vec3 Fw = object.mass * Vec3(0.0f, 9.8f, 0.0f);
	Vec3 Fd = -object.coefficient * object.vel;
	Vec3 Fb = 997.0f * Vec3(0.0f, -9.8f, 0.0f) * V;
	Vec3 Ffinal = Fw + Fd + Fb;
	//std::cout << Fw.y << " " << Fd.y << " " << Fb.y << std::endl;
	object.finalForce += Ffinal;
}

void Physics::SimpleNewtonMotion(harpoonHarry& object, const float deltaTime) {
	object.pos += object.vel * deltaTime + 0.5f * object.accelPrevious * deltaTime * deltaTime;
	object.vel += 0.5 * (object.accelCurrent + object.accelPrevious) * deltaTime;
}