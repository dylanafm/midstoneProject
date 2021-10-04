#include "Scene0.h"
#include "mainMenu.h"
#include "GameManager.h"
#include <SDL.h>
#include "SDL_TTF.h"

mainMenu::mainMenu(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	
	
	Levels.x = 250;
	Levels.y = 200;
	Levels.w = 800;
	Levels.h = 40;


	Settings.x = 250;
	Settings.y = 300;
	Settings.w = 800;
	Settings.h = 40;

	Tutorial.x = 250;
	Tutorial.y = 400;
	Tutorial.w = 800;
	Tutorial.h = 40;

	Quit.x = 250;
	Quit.y = 500;
	Quit.w = 800;
	Quit.h = 40;

	colorValueL = Vec3(255, 255, 255);
	colorValueS = Vec3(255, 255, 255);
	colorValueT = Vec3(255, 255, 255);
	colorValueQ = Vec3(255, 255, 255);

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

void mainMenu::OnDestroy() {}

void mainMenu::Update(const float deltaTime) {
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{

		int x, y;\
		Uint32 buttons;
		buttons = SDL_GetMouseState(&x, &y);
		
		SDL_Log("Mouse cursor is at %d, %d", x, y);


		if ((x > Levels.x) && (x < Levels.x + Levels.w) && (y > Levels.y) && (y < Levels.y + Levels.h)) 
		{
			colorValueL = Vec3(0, 255, 255);

		}
		else if ((x > Tutorial.x) && (x < Tutorial.x + Tutorial.w) && (y > Tutorial.y) && (y < Tutorial.y + Tutorial.h))
		{
			colorValueT = Vec3(0, 255, 255);
		}
		else if ((x > Settings.x) && (x < Settings.x + Settings.w) && (y > Settings.y) && (y < Settings.y + Settings.h))
		{
			colorValueS = Vec3(0, 255, 255);
		}
		else if ((x > Quit.x) && (x < Quit.x + Quit.w) && (y > Quit.y) && (y < Quit.y + Quit.h))
		{
			colorValueQ = Vec3(255, 0, 0);
		}
		else { 
			(colorValueL = Vec3(255, 255, 255)) && (colorValueS = Vec3(255, 255, 255)) && (colorValueT = Vec3(255, 255, 255)) && (colorValueQ = Vec3(255, 255, 255));
		}


		if (event.button.button == SDL_BUTTON_LEFT)
		{

			//Get the mouse offsets
			x = event.button.x;
			y = event.button.y;

			//If the mouse is over the levels button
			if ((x > Levels.x) && (x < Levels.x + Levels.w) && (y > Levels.y) && (y < Levels.y + Levels.h))
			{
				
				
			}
		}

		


	}
}

void mainMenu::Render() {
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));
	Vec3 screenCoords;
	
	



	
	SDL_FillRect(screenSurface, &Levels, SDL_MapRGB(screenSurface->format, colorValueL.x, colorValueL.y, colorValueL.z));

	//Settings Button
	
	SDL_FillRect(screenSurface, &Settings, SDL_MapRGB(screenSurface->format, colorValueS.x, colorValueS.y, colorValueS.z));

	///Tutorial Button
	
	SDL_FillRect(screenSurface, &Tutorial, SDL_MapRGB(screenSurface->format, colorValueT.x, colorValueT.y, colorValueT.z));

	//Quit Button
	
	
	SDL_FillRect(screenSurface, &Quit, SDL_MapRGB(screenSurface->format, colorValueQ.x, colorValueQ.y, colorValueQ.z));
	
	
	
	
	
	
	SDL_UpdateWindowSurface(window);
}