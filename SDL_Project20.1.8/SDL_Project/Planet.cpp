#include "Planet.h"

Planet::Planet(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_):
			Body( pos_,  vel_,  accel_,  mass_) {
}

Planet::~Planet() { }
