#ifndef PHYSICS_H
#define PHYSICS_H
#include "harpoonHarry.h"
#include "VMath.h"

using namespace MATH;

class Physics {
public:
	
	static void ApplyForces(harpoonHarry&object, const float waterHeight);
	static void SimpleNewtonMotion(harpoonHarry& object, const float deltaTime);

};

#endif