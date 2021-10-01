#ifndef BALL_H
#define BALL_H
#include "Body.h"
	class Ball : public Body {
	public:
		Ball(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_);
		~Ball();
	};

#endif
