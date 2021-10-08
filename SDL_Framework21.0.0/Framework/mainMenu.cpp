#include "Scene0.h"
#include "mainMenu.h"
#include "GameManager.h"
#include <SDL.h>
#include <SDL_image.h>


mainMenu::mainMenu(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	Levels = button(250, 200, 800, 40, Vec3(255, 255, 255), Vec3(0, 255, 255), Vec3(120, 255, 0), "Levels");
	Settings = button(250, 300, 800, 40, Vec3(255, 255, 255), Vec3(0, 255, 255), Vec3(120, 255, 0), "Settings");
	Tutorial = button(250, 400, 800, 40, Vec3(255, 255, 255), Vec3(0, 255, 255), Vec3(120, 255, 0), "Tutorial");
	Quit = button(250, 500, 800, 40, Vec3(255, 255, 255), Vec3(0, 255, 255), Vec3(120, 255, 0), "Quit");

	Back = button(50, 50, 50, 50, Vec3(255, 255, 255), Vec3(255, 0, 0), Vec3(120, 255, 0), "Back");

	LevelOne = button(250, 200, 200, 200, Vec3(255, 255, 255), Vec3(0, 255, 255), Vec3(120, 255, 0), "Level One");
	LevelTwo = button(350, 200, 200, 200, Vec3(255, 255, 255), Vec3(0, 255, 255), Vec3(120, 255, 0), "Level Two");
	LevelThree = button(450, 200, 200, 200, Vec3(255, 255, 255), Vec3(0, 255, 255), Vec3(120, 255, 0), "LevelThree");

	
	

}

mainMenu::~mainMenu() {
}

bool mainMenu::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;

	return true;
}

void mainMenu::OnDestroy() {
	


	SDL_DestroyRenderer(renderer);
}

void mainMenu::Update(const float deltaTime) {
	SDL_Event event{};

	Levels.Update();
	Settings.Update();
	Tutorial.Update();
	Quit.Update();

	Back.Update();
	LevelOne.Update();
	LevelTwo.Update();
	LevelThree.Update();


	if (Levels.buttonClicked(event)) { currentMenu = 2; }
	if (Settings.buttonClicked(event)) { currentMenu = 3; }
	if (Tutorial.buttonClicked(event)) { currentMenu = 4; }
	if (Quit.buttonClicked(event)) { newScene = -1; }
	
	if (Back.buttonClicked(event)) { currentMenu = 1; }

	if (LevelOne.buttonClicked(event)) { newScene = 1; }

}

void mainMenu::Render() {

	//SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	//SDL_RenderClear(renderer);
	Vec3 screenCoords;
	
	if (currentMenu == 1) {
		
		
		//Levels Button
		

		Levels.Render(renderer);
		Settings.Render(renderer);
		Tutorial.Render(renderer);
		Quit.Render(renderer);
		

	}
	else if (currentMenu == 2){
	
		Back.Render(renderer);
		LevelOne.Render(renderer);
		LevelTwo.Render(renderer);
		LevelThree.Render(renderer);
		
	}
	else  if (currentMenu == 3) {
		Back.Render(renderer);


}
	else {
		Back.Render(renderer);

	}
	SDL_RenderPresent(renderer);

	SDL_UpdateWindowSurface(window);

}