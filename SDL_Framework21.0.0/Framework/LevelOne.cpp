#include "LevelOne.h"
#include "Physics.h"
#include <SDL.h>
#include "Timer.h"

LevelOne::LevelOne(SDL_Window* sdlWindow_) {

	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	harry = new harpoonHarry();
	harry->pos = Vec3(100.0f, 100.0f, 100.0f);

	fish[0] = new Fish(SDL_Rect{ 200, 200, 50, 50 });
	fish[1] = new Fish(SDL_Rect{ 300, 250, 50, 50 });
	fish[2] = new Fish(SDL_Rect{ 200, 25, 50, 50 });
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

	pMenu = new pauseMenu();
	dMenu = new DeathMenu();

	if (!pMenu->setUpButtons(renderer)) return false;
	if (!dMenu->setUpButtons(renderer)) return false;

	if (!harry->setImage("textures/harry.png", renderer)) return false;

	return true;
}

void LevelOne::OnDestroy() {
	SDL_DestroyRenderer(renderer);
}

void LevelOne::Update(const float deltaTime) {
	SDL_Event event;

	harry->Update(deltaTime);
	if(harpoon != nullptr) harpoon->Update(deltaTime);

	for (int i = 0; i < std::size(fish); i++) {

		if (fish[i] != nullptr) fish[i]->Update(deltaTime);
		if (fish[i] != nullptr) harry->isCollided(fish[i], harry);

		if (harpoon != nullptr && fish[i] != nullptr) {
			if (harpoon->isCollided(fish[i], harpoon)) {
				harpoon = nullptr;
				fish[i] = nullptr;
				delete harpoon;
				delete fish[i];
			}
		}
	}

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
			paused = !paused;
		}
		if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN && !isFired && !paused) {
			spawnHarpoon();
		}
		if (harry->health <= 0) dMenu->deathUpdate(event);
		else if (paused) pMenu->pauseUpdate(event);
	}
	harry->HandleEvents(event);
	
	if (harry->health <= 0) {
		if (!paused) paused = true;
		newScene = dMenu->getScene();
		paused = dMenu->getPaused();
	}
	else if (paused) {
		newScene = pMenu->getScene();
		paused = pMenu->getPaused();
		if (!paused) pMenu->setDefault(); // Reset the Pause menu when Resume was pressed
	}

	Physics::ApplyForces(*harry, 0.0f);
	//Physics::SimpleNewtonMotion(*harry, deltaTime);

	if (harpoon != nullptr) {
		if (harpoon->pos.x < -50.0f || harpoon->pos.x > 1300.0f || harpoon->pos.y < -50.0f || harpoon->pos.y > 800.0f) {
			delete harpoon;
			harpoon = nullptr;
		}
	}
	if (isFired && reloadTimer != nullptr) {
		reloadTimer->Update(deltaTime, isFired);
		if (!isFired) {
			reloadTimer = nullptr;
			delete reloadTimer;
		}
	}
}

void LevelOne::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 120, 120, 0);
	SDL_RenderClear(renderer);

	harry->render(renderer);

	if (harpoon != nullptr) harpoon->render(renderer);

	for (int i = 0; i < std::size(fish); i++) {
		if (fish[i] != nullptr) fish[i]->Render(renderer);
	}
	
	newHud.displayHud(renderer, 25, 25, 50, 50, harry);

	if (harry->health <= 0) dMenu->deathRender(renderer);
	else if (paused) pMenu->pauseRender(renderer);

	SDL_RenderPresent(renderer);

}

void LevelOne::spawnHarpoon()
{
	int x, y;
	Uint32 buttons;
	buttons = SDL_GetMouseState(&x, &y);
	float xf = static_cast<float>(x);
	float yf = static_cast<float>(y);

	Vec3 position = Vec3(harry->pos.x + 10.0f, harry->pos.y + 19.75f, 0.0f);
	Vec3 direction = Vec3(xf - position.x - 15.0f, yf - position.y - 5.25f, 0.0f);
	Vec3 velocity = VMath::normalize(direction) * 420.0f;
	harpoon = new Harpoon(position, velocity);
	harpoon->setImage("textures/Harpoon.png", renderer);

	isFired = true;
	reloadTimer = new InGameTimer(3.0f);
}
