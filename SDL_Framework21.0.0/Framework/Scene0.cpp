#include "Scene0.h"
#include <SDL.h>
Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;
	balloon = new Body();
}

Scene0::~Scene0(){
	delete balloon;
}

bool Scene0::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;
	
	return true;
}

void Scene0::OnDestroy() {}

void Scene0::Update(const float deltaTime) {
	balloon->Update(deltaTime);
}

void Scene0::Render() {
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));

	Vec3 screenCoords = projectionMatrix * balloon->getPos();
	SDL_Rect square;
	square.x = (int) screenCoords.x; /// We must update this with C11 typecasting - SSF
	square.y = (int) screenCoords.y;
	square.w = 30;
	square.h = 30;
	SDL_FillRect(screenSurface, &square, SDL_MapRGB(screenSurface->format,255, 0, 0));

	SDL_UpdateWindowSurface(window);
}