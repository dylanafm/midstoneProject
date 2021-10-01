#include "Ball.h"

Ball::Ball(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_): 
			Body( pos_,  vel_,  accel_,  mass_) {
}

Ball::~Ball() { }
