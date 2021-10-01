#include "Body.h"

Body::Body(){
	pos.x = 3.0f;
	pos.y = 12.5f;
	pos.z = 0.0f;

	vel.x = 0.0f;
	vel.y = 0.0f;
	vel.z = 0.0f;

	accel.x = 0.0f;
	accel.y = -9.81f;
	accel.z = 0.0f;

	mass = 0.0f;
}

Body::~Body(){

}

void Body::Update(float deltaTime){
	
}
