#ifndef PHYSICS_H
#define PHYSICS_H
#include "HarpoonHarry.h"
#include "VMath.h"

using namespace MATH;

class Physics {
public:
	
	static void ApplyForces(HarpoonHarry&object, const float waterHeight);
	static void SimpleNewtonMotion(HarpoonHarry& object, const float deltaTime);

};

#endif