#include "harpoonHarry.h"
harpoonHarry::harpoonHarry()
{
	pos = Vec3(500.0f, 50.0f, 200.0f);
	vel = Vec3(0.0f, 0.0f, 0.0f);
	accel = Vec3(0.0f, 0.0f, 0.0f);
	drag = 0.005f;
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);
	mass = 0.0f;
}

harpoonHarry::~harpoonHarry()
{
}
void harpoonHarry::HandleEvents(SDL_Event sdlEvent) {
		if (sdlEvent.type == SDL_KEYDOWN) {
			switch (sdlEvent.key.keysym.scancode) {
			case SDL_SCANCODE_W:
				printf("up!\n");
				applyForce(Vec3(0.0f, -100.0f, 0.0f));
				break;

			case SDL_SCANCODE_S:
				printf("down!\n");
				applyForce(Vec3(0.0f, 100.0f, 0.0f));
				break;
			case SDL_SCANCODE_A:
				printf("left!\n");
				applyForce(Vec3(-100.0f, 0.0f, 0.0f));
				break;
			case SDL_SCANCODE_D:
				printf("right!\n");
				applyForce(Vec3(100.0f, 0.0f, 0.0f));
				break;
			}
		}
	
}

void harpoonHarry::Update(float deltaTime)
{
	pos += vel * deltaTime + 0.5f * accel * deltaTime * deltaTime;
	vel += accel * deltaTime;
		//Movement Code
		//https://wiki.libsdl.org/SDL_KeyboardEvent
		// if (    keyboard input   ) { Acceleration = Accel + Vec3(0, 2, 0)..........

			//else { accel = 0.0f, 0.0, 0.0    Vel = 0 etc...
			//position = initail velocity * time    +   1/2   (accel * time

	
}


