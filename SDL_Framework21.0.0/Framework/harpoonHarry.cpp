#include "harpoonHarry.h"
harpoonHarry::harpoonHarry()
{
	pos = Vec3(500.0f, 50.0f, 200.0f);
	vel = Vec3(0.0f, 0.0f, 0.0f);
	accel = Vec3(0.0f, 0.0f, 0.0f);
	drag = 0.005f;
	accelCurrent = Vec3(0.0f, 0.0f, 0.0f);
	accelPrevious = Vec3(0.0f, 0.0f, 0.0f);
	radius = 0.3f;
	length = 1.7f;
	coefficient = 50.0f;
	mass = 100.0f;
	health = 100;
	finalForce = Vec3(0.0f, 0.0f, 0.0f);
}

harpoonHarry::~harpoonHarry(){
}
void harpoonHarry::HandleEvents(SDL_Event sdlEvent) {

	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_SCANCODE_W]) {
		finalForce += Vec3(0.0f, -10000.0f, 0.0f);
	}
	if (keystate[SDL_SCANCODE_S]) {
		finalForce += Vec3(0.0f, 10000.0f, 0.0f);
	}
	if (keystate[SDL_SCANCODE_A]) {
		finalForce += Vec3(-10000.0f, 0.0f, 0.0f);
	}
	if (keystate[SDL_SCANCODE_D]) {
		finalForce += Vec3(10000.0f, 0.0f, 0.0f);
	}
	//if (sdlEvent.type == SDL_KEYDOWN) {
	//	switch (sdlEvent.key.keysym.scancode) {
	//	case SDL_SCANCODE_W:
	//		printf("up!\n");
	//		vel = Vec3(0.0f, -100.0f, 0.0f);
	//		break;
	//	case SDL_SCANCODE_S:
	//		printf("down!\n");
	//		vel = Vec3(0.0f, 100.0f, 0.0f);
	//		break;

	//	case SDL_SCANCODE_A:
	//		printf("left!\n");
	//		vel = Vec3(-100.0f, 0.0f, 0.0f);
	//		break;
	//	case SDL_SCANCODE_D:
	//		printf("right!\n");
	//		vel = Vec3(100.0f, 0.0f, 0.0f);
	//		break;
	//	}
	//}else if (sdlEvent.type == SDL_KEYUP) {
	//	applyForce(Vec3(0.0f, -10000.0f, 0.0f)); //pulls upwards -10000 is sweet spot
	//};
	
}

void harpoonHarry::Update(float deltaTime)
{
	applyForce(finalForce);
	finalForce = Vec3(0.0f, 0.0f, 0.0f);
	pos += vel * deltaTime + 0.5f * accelPrevious * deltaTime * deltaTime;
	vel += 0.5 * (accelCurrent + accelPrevious) * deltaTime;

		//Movement Code
		//https://wiki.libsdl.org/SDL_KeyboardEvent
		// if (    keyboard input   ) { Acceleration = Accel + Vec3(0, 2, 0)..........

			//else { accel = 0.0f, 0.0, 0.0    Vel = 0 etc...
			//position = initail velocity * time    +   1/2   (accel * time

	
}


