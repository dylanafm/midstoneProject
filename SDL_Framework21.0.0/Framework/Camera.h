#ifndef CAMERA_H
#define CAMERA_H
#include "LevelOne.h"
#include "Map.h"
#include "harpoonHarry.h"

class Camera
{
public:
	Camera();
	Camera(int x_, int y_, int w_, int h_);
	~Camera();

	int x, y, w, h;

	SDL_Rect cam;
	
	void camMove(harpoonHarry* harry);
private:
};

#endif