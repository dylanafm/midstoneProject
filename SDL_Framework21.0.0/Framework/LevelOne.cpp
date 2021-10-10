#include "LevelOne.h"
#include <SDL.h>
#include "Timer.h"

LevelOne::LevelOne(SDL_Window* sdlWindow_) {

	window = sdlWindow_;

	SDL_Event e;

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

void LevelOne::OnDestroy() {
	SDL_DestroyRenderer(renderer);
}

void LevelOne::Update(const float deltaTime) {
	SDL_Event event;
	harry->Update(deltaTime);
	harry->HandleEvents(event);
}

void LevelOne::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 120, 120, 0);
	SDL_RenderClear(renderer);


	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderFillRect(renderer, &harryBox);

	SDL_RenderPresent(renderer);

}