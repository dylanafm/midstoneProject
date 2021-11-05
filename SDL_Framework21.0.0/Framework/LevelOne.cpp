#include "LevelOne.h"
#include "Physics.h"
#include <SDL.h>
#include "Timer.h"

LevelOne::LevelOne(SDL_Window* sdlWindow_) {

	window = sdlWindow_;

	harry = new harpoonHarry();
	fish1 = new Fish(SDL_Rect{ 200, 200, 50, 50 });
	fish2 = new Fish(SDL_Rect{ 300, 250, 50, 50 });
	fish3 = new Fish(SDL_Rect{ 200, 25, 50, 50 });
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	harry->pos = Vec3(100.0f, 100.0f, 100.0f);


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

	SDL_Surface* harryImage = IMG_Load("harry.png");
	SDL_Texture* harryTexture = SDL_CreateTextureFromSurface(renderer, harryImage);
	if (harryTexture == nullptr) printf("%s\n", SDL_GetError());
	if (harryImage == nullptr) {
		std::cerr << "Can't open the image" << std::endl;
		return false;
	}
	else {
		harry->setTexture(harryTexture);
		SDL_FreeSurface(harryImage);
	}

	return true;
}

void LevelOne::OnDestroy() {
	SDL_DestroyRenderer(renderer);
}

void LevelOne::Update(const float deltaTime) {
	SDL_Event event;

	harry->Update(deltaTime);
	fish1->Update(deltaTime);
	fish2->Update(deltaTime);
	fish3->Update(deltaTime);
	harry->isCollided(fish1,harry);
	harry->isCollided(fish2,harry);
	harry->isCollided(fish3,harry);

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
			std::cout << "esc";
			paused = !paused;
		}
		harry->HandleEvents(event);
	}
	
	if (harry->health <= 0) {
		if (!paused)	paused = true;
		dMenu.deathUpdate(event);
		newScene = dMenu.getScene();
		paused = dMenu.getPaused();

		//if (!paused) pMenu.setDefault(); // Reset the Pause menu when Resume was pressed
	}
	else if (paused) {
		pMenu.pauseUpdate(event);
		newScene = pMenu.getScene();
		paused = pMenu.getPaused();

		if (!paused) pMenu.setDefault(); // Reset the Pause menu when Resume was pressed
	}


	Physics::ApplyForces(*harry, 0.0f);
	//Physics::SimpleNewtonMotion(*harry, deltaTime);

}

void LevelOne::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 120, 120, 0);
	SDL_RenderClear(renderer);

	fish1->Render(renderer);
	fish2->Render(renderer);
	fish3->Render(renderer);
	harry->render(renderer);
	newHud.displayHud(renderer, 25, 25, 50, 50, harry);



	if (harry->health <= 0) dMenu.deathRender(renderer);
	else if (paused)	pMenu.pauseRender(renderer);

	SDL_RenderPresent(renderer);

}