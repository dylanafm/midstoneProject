#include "LevelOne.h"
#include <SDL.h>
LevelOne::LevelOne(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	harry = new harpoonHarry();
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	harry->pos = Vec3(100.0f, 100.0f, 100.0f);

	harryBox.x = harry->pos.x;
	harryBox.y = harry->pos.y;
	harryBox.w = 50.0f;
	harryBox.h = 50.0f;


}

LevelOne::~LevelOne() {

}

bool LevelOne::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;

	return true;
}

void LevelOne::OnDestroy() {}

void LevelOne::Update(const float deltaTime) {
	harry->Update(deltaTime);
}

void LevelOne::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	Vec3 screenCoords;

	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));


	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderFillRect(renderer, &harryBox);

	SDL_UpdateWindowSurface(window);

	SDL_RenderPresent(renderer);
}