#include "Camera.h"

Camera::Camera()
{
	x = 0;
	y = 0;
	w = 800;
	h = 640;

	cam = SDL_Rect{ x, y, w, h };
}
Camera::Camera(int x_, int y_, int w_, int h_)
{
	x = x_;
	y = y_;
	w = w_;
	h = h_;

}
//Call in update
void Camera::camMove(HarpoonHarry* harry)
{
	cam.x = harry->pos.x - 400;
	cam.y = harry->pos.y - 320;

	if (cam.x < 0)
		cam.x = 0;
	if (cam.y < 0)
		cam.y = 0;
	if (cam.x > cam.w)
		cam.x = cam.w;
	if (cam.y > cam.h)
		cam.y = cam.h;


}
