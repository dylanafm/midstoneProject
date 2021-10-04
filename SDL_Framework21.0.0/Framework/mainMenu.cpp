#include "Scene0.h"
#include "mainMenu.h"
#include "GameManager.h"
#include <SDL.h>
mainMenu::mainMenu(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	
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
	
	//if (event.button.button == SDL_BUTTON_LEFT)
	//{
	//	//Get the mouse offsets
	//	x = event.button.x;
	//	y = event.button.y;

	//	//If the mouse is over the button
	//	if ((x > box.x) && (x < box.x + box.w) && (y > box.y) && (y < box.y + box.h))
	//	{
	//		//do here all what you want to...
	//		show_menu = true;
	//	}
	//}
}

void mainMenu::Render() {
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));

	//Vec3 screenCoords = projectionMatrix * balloon->getPos();
	//SDL_Rect square;
	//square.x = (int)screenCoords.x; /// We must update this with C11 typecasting - SSF
	//square.y = (int)screenCoords.y;
	//square.w = 30;
	//square.h = 30;
	//SDL_FillRect(screenSurface, &square, SDL_MapRGB(screenSurface->format, 255, 0, 0));

	SDL_UpdateWindowSurface(window);
}