#include "Scene0.h"
#include "mainMenu.h"
#include "GameManager.h"
#include <SDL.h>
#include <SDL_image.h>

mainMenu::mainMenu(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	
	//Buttons and Colors
	Back.x = 50;
	Back.y = 50;
	Back.w = 50;
	Back.h = 50;

	colorValueBack = Vec3(255, 255, 255);

	//Main Menu
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
	
	//Levels Menu

	
	colorValueLevelOne = Vec3(255, 255, 255);

	
	
	
	LevelOne.x = 250;
	LevelOne.y = 200;
	LevelOne.w = 200;
	LevelOne.h = 200;







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
	newText.~Text();
	SDL_DestroyRenderer(renderer);
}

void mainMenu::Update(const float deltaTime) {
	SDL_Event event;
	std::cout << currentMenu;
	if (SDL_PollEvent(&event))
	{

		int x, y; \
			Uint32 buttons;
		buttons = SDL_GetMouseState(&x, &y);


		if (currentMenu == 1) {

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
					currentMenu = 2;

				}
				if ((x > Settings.x) && (x < Settings.x + Settings.w) && (y > Settings.y) && (y < Settings.y + Settings.h))
				{
					currentMenu = 3;

				}
				if ((x > Tutorial.x) && (x < Tutorial.x + Tutorial.w) && (y > Tutorial.y) && (y < Tutorial.y + Tutorial.h))
				{
					currentMenu = 4;

				}
				if ((x > Quit.x) && (x < Quit.x + Quit.w) && (y > Quit.y) && (y < Quit.y + Quit.h))
				{
					newScene = -1; //Switch scene
					
				}
			}

		}
		else if (currentMenu == 2) {

			if ((x > Back.x) && (x < Back.x + Back.w) && (y > Back.y) && (y < Back.y + Back.h))
			{
				colorValueBack = Vec3(255, 0, 0);

			}
			else if ((x > LevelOne.x) && (x < LevelOne.x + LevelOne.w) && (y > LevelOne.y) && (y < LevelOne.y + LevelOne.h))
			{
				colorValueLevelOne = Vec3(0, 255, 255);
			}
			else {
				(colorValueLevelOne = Vec3(255, 255, 255)) && (colorValueBack = Vec3(255, 255, 255));
			}


			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{

					//Get the mouse offsets
					x = event.button.x;
					y = event.button.y;

					//If the mouse is over the levels button
					if ((x > Back.x) && (x < Back.x + Back.w) && (y > Back.y) && (y < Back.y + Back.h))
					{
						currentMenu = 1;

					}
					else if ((x > LevelOne.x) && (x < LevelOne.x + LevelOne.w) && (y > LevelOne.y) && (y < LevelOne.y + LevelOne.h))
					{
						newScene = 1; //Switch scene
					}

				}
			}
		}
		else if (currentMenu = 3) {
			
			if ((x > Back.x) && (x < Back.x + Back.w) && (y > Back.y) && (y < Back.y + Back.h))
			{
				colorValueBack = Vec3(255, 0, 0);

			}
			else {
				colorValueBack = Vec3(255, 255, 255);
			}






			if (event.button.button == SDL_BUTTON_LEFT)
			{

				//Get the mouse offsets
				x = event.button.x;
				y = event.button.y;

				//If the mouse is over the levels button
				if ((x > Back.x) && (x < Back.x + Back.w) && (y > Back.y) && (y < Back.y + Back.h))
				{
					currentMenu = 1;

				}


			}




		}
		else
		{
		if ((x > Back.x) && (x < Back.x + Back.w) && (y > Back.y) && (y < Back.y + Back.h))
		{
			colorValueBack = Vec3(255, 0, 0);

		}
		else {
			colorValueBack = Vec3(255, 255, 255);
		}






		if (event.button.button == SDL_BUTTON_LEFT)
		{

			//Get the mouse offsets
			x = event.button.x;
			y = event.button.y;

			//If the mouse is over the levels button
			if ((x > Back.x) && (x < Back.x + Back.w) && (y > Back.y) && (y < Back.y + Back.h))
			{
				currentMenu = 1;

			}


		}
		}







		
	}
}

void mainMenu::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	Vec3 screenCoords;

	if (currentMenu == 1) {
		//Levels Button

		SDL_SetRenderDrawColor(renderer, colorValueL.x, colorValueL.y, colorValueL.z, 255);
		SDL_RenderFillRect(renderer, &Levels);

		//Settings Button

		SDL_SetRenderDrawColor(renderer, colorValueS.x, colorValueS.y, colorValueS.z, 255);
		SDL_RenderFillRect(renderer, &Settings);

		///Tutorial Button

		SDL_SetRenderDrawColor(renderer, colorValueT.x, colorValueT.y, colorValueT.z, 255);
		SDL_RenderFillRect(renderer, &Tutorial);

		//Quit Button

		SDL_SetRenderDrawColor(renderer, colorValueQ.x, colorValueQ.y, colorValueQ.z, 255);
		SDL_RenderFillRect(renderer, &Quit);

		newText.writeText("Levels", SDL_Color{ 120, 255, 0 }, SDL_Rect{ Levels.x + 300, Levels.y, Levels.w - 600, Levels.h }, renderer);

		newText.writeText("Settings", SDL_Color{ 120, 255, 0 }, SDL_Rect{ Settings.x + 300, Settings.y, Settings.w - 600, Settings.h }, renderer);

		newText.writeText("Tutorial", SDL_Color{ 120, 255, 0 }, SDL_Rect{ Tutorial.x + 300, Tutorial.y, Tutorial.w - 600, Tutorial.h }, renderer);

		newText.writeText("Quit", SDL_Color{ 120, 255, 0 }, SDL_Rect{ Quit.x + 300, Quit.y, Quit.w - 600, Quit.h }, renderer);

	}
	else if (currentMenu == 2){
	
		
		SDL_SetRenderDrawColor(renderer, colorValueBack.x, colorValueBack.y, colorValueBack.z, 255);
		SDL_RenderFillRect(renderer, &Back);
	
		SDL_SetRenderDrawColor(renderer, colorValueLevelOne.x, colorValueLevelOne.y, colorValueLevelOne.z, 255);
		SDL_RenderFillRect(renderer, &LevelOne);

		newText.writeText("Level One", SDL_Color{ 120, 255, 0 }, SDL_Rect{ LevelOne.x, LevelOne.y, LevelOne.w, LevelOne.h }, renderer);
	}
	else  if (currentMenu == 3) {
	SDL_SetRenderDrawColor(renderer, colorValueBack.x, colorValueBack.y, colorValueBack.z, 255);
	SDL_RenderFillRect(renderer, &Back);


}
	else {
	SDL_SetRenderDrawColor(renderer, colorValueBack.x, colorValueBack.y, colorValueBack.z, 255);
	SDL_RenderFillRect(renderer, &Back);
}

	SDL_RenderPresent(renderer);
}