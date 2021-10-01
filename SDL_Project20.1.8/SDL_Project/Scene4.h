#ifndef SCENE4_H
#define SCENE4_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Ball.h"
#include "Planet.h"
#include "Star.h"

using namespace MATH;
#define NUM_OBJECTS 3

class Scene4 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projectionMatrix;
	Matrix4 invProjectionMatrix;
	Body* gameObjects[NUM_OBJECTS];
	SDL_Renderer* renderer;

	
public:
	Scene4(SDL_Window* sdlWindow);
	~Scene4();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event &sdlEvent) ;
};

#endif

