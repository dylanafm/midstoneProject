#ifndef STAR_H
#define STAR_H
#include "Body.h"
	class Star : public Body {
	public:
		Star(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_);
		~Star();
	};

#endif
