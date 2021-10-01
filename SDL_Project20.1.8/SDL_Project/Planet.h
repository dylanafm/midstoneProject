#ifndef PLANET_H
#define PLANET_H
#include "Body.h"
	class Planet : public Body {
	public:
		Planet(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_);
		~Planet();
	};

#endif
