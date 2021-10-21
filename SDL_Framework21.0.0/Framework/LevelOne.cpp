#include "LevelOne.h"
#include "Physics.h"
#include <SDL.h>
#include "Timer.h"

LevelOne::LevelOne(SDL_Window* sdlWindow_) {

	window = sdlWindow_;

	harry = new harpoonHarry();

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	harry->pos = Vec3(100.0f, 100.0f, 100.0f);

	harryBox.x = harry->pos.x;
	harryBox.y = harry->pos.y;
	harryBox.w = 50.0f;
	harryBox.h = 50.0f;
	harry->mass = 3000.0f;


}

LevelOne::~LevelOne() {
	delete window;
	delete harry;
	delete renderer;
}

bool LevelOne::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;

	harry->calculateMass(800.0f);

	return true;
}

void LevelOne::OnDestroy() {
	SDL_DestroyRenderer(renderer);
}

void LevelOne::Update(const float deltaTime) {
	SDL_Event event;
	harry->Update(deltaTime);
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
			std::cout << "esc";
			paused = !paused;
		}
		harry->HandleEvents(event);
	}
	
	if (paused) {
		pMenu.pauseUpdate(event);
		newScene = pMenu.getScene();
		paused = pMenu.getPaused();
		
		if (!paused) pMenu.setDefault();
	}

	harryBox.x = harry->pos.x;
	harryBox.y = harry->pos.y;

	Physics::ApplyForces(*harry, 10.0f);
	Physics::SimpleNewtonMotion(*harry, deltaTime);

}

void LevelOne::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 120, 120, 0);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
	SDL_RenderFillRect(renderer, &harryBox);

	if (paused)	pMenu.pauseRender(renderer);

	SDL_RenderPresent(renderer);

}