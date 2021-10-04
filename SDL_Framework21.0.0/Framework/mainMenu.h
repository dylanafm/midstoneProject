#ifndef MAINMENU_H
#define MAINMENU_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Body.h"

using namespace MATH;
class mainMenu : public Scene {
private:
	SDL_Window* window;
	Matrix4 projectionMatrix;
	SDL_Rect Levels;
	SDL_Rect Settings;
	SDL_Rect Tutorial;
	SDL_Rect Quit;

	Vec3 colorValueL;
	Vec3 colorValueS;
	Vec3 colorValueT;
	Vec3 colorValueQ;
public:
	mainMenu(SDL_Window* sdlWindow);
	~mainMenu();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
};

#endif

