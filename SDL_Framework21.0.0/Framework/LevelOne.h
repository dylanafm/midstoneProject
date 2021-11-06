#ifndef LEVELONE_H
#define LEVELONE_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Body.h"
#include "harpoonHarry.h"
#include "pauseMenu.h"
#include "DeathMenu.h"
#include "HUD.h"
#include "Fish.h"


using namespace MATH;
class LevelOne : public Scene {
private:
	harpoonHarry* harry;
	Fish* fish1;
	Fish* fish2;
	Fish* fish3;
	SDL_Window* window;
	Matrix4 projectionMatrix;

	SDL_Renderer* renderer;

	DeathMenu* dMenu;
	pauseMenu* pMenu;
	bool paused = false;

	int newScene = 0;

public:

	HUD newHud;

	LevelOne(SDL_Window* sdlWindow);
	~LevelOne();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	bool getPaused() {
		return paused;
	}
	int getScene() {
		return newScene;
	}
};

#endif

