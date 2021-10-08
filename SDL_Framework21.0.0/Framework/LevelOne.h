#ifndef LEVELONE_H
#define LEVELONE_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Body.h"
#include "harpoonHarry.h"

using namespace MATH;
class LevelOne : public Scene {
private:
	harpoonHarry* harry;
	SDL_Window* window;
	Matrix4 projectionMatrix;

	SDL_Rect harryBox;
	SDL_Renderer* renderer;


public:
	LevelOne(SDL_Window* sdlWindow);
	~LevelOne();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	int getScene() {
		return 0;
	};
};

#endif

