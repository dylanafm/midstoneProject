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
	Body* balloon;


public:
	mainMenu(SDL_Window* sdlWindow);
	~mainMenu();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
};

#endif

