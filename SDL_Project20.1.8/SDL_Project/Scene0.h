#ifndef SCENE0_H
#define SCENE0_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Ball.h"

using namespace MATH;
#define NUM_BALLS 1

class Scene0 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projectionMatrix;
	Ball* ballArray[NUM_BALLS];
	SDL_Renderer* renderer;
	
public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event &sdlEvent) ;
};

#endif

