#ifndef SCENE2_H
#define SCENE2_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Ball.h"

#define NUM_OBJECTS  1

using namespace MATH;
class Scene2 : public Scene {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	Matrix4 projectionMatrix;
	Ball* gameObject[NUM_OBJECTS];



public:
	Scene2(SDL_Window* sdlWindow);
	~Scene2();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& sdlEvent);
};

#endif

