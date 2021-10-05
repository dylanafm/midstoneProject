#include "Scene0.h"
#include "mainMenu.h"
#include "GameManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_TTF.h"

mainMenu::mainMenu(SDL_Window* sdlWindow_) {

	if (TTF_Init() < 0) {
		std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
	}

	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	font = TTF_OpenFont("OpenSans.ttf", 64);
	if (!font) {
		std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
	}
	
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

void mainMenu::OnDestroy() {
	TTF_CloseFont(font);
	TTF_Quit();
}

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
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);
	Vec3 screenCoords;

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



	SDL_Color color = { 120, 0, 0 };

	text = TTF_RenderText_Solid(font, "Hello World!", color);
	if (!text) {
		std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
	}
	text_texture = SDL_CreateTextureFromSurface(renderer, text);

	SDL_Rect dest = { 0, 0, 240, 240 };

	SDL_RenderCopy(renderer, text_texture, NULL, &dest);

	SDL_DestroyTexture(text_texture);
	SDL_FreeSurface(text);
	


	SDL_RenderPresent(renderer);
}