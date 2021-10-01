#ifndef SCENE3_H
#define SCENE3_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "Ball.h"

using namespace MATH;

#define NUM_OBJECTS 3

class Scene3 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projectionMatrix;
	Matrix4 invProjectionMatrix;
	Body* gameObject[NUM_OBJECTS];
	SDL_Renderer* renderer;

	
public:
	Scene3(SDL_Window* sdlWindow);
	~Scene3();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event &sdlEvent) ;
};

#endif

