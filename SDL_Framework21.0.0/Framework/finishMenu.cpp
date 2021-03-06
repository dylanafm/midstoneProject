#include "finishMenu.h"
#include "TextureManager.h"

finishMenu::finishMenu(SDL_Renderer* r)
{
	if(!GameWin) NextLevel = new button(390, 230, 500, 60, Vec3(20, 20, 210), "Next Level");
	MainMenu = new button(415, 330, 450, 60, Vec3(20, 20, 210), "Main Menu");
	Quit = new button(540, 430, 200, 60, Vec3(20, 20, 210), "Quit");
}

finishMenu::~finishMenu()
{
	delete NextLevel;
	delete MainMenu;
	delete Quit;
}

void finishMenu::finishUpdate(SDL_Event event_)
{
	if (!GameWin) NextLevel->Update();
	MainMenu->Update();
	Quit->Update();
	if (NextLevel->buttonClicked(event_) && !GameWin) { NextLevel->click->playSFX(); newScene = 3; paused = false; }
	if (MainMenu->buttonClicked(event_)) { MainMenu->click->playSFX(); newScene = 2; paused = false; }
	if (Quit->buttonClicked(event_)) { Quit->click->playSFX(); newScene = -1; paused = false; }
}

void finishMenu::finishRender(SDL_Renderer* renderer)
{
	if (!GameWin) text.writeText("Well Done!", SDL_Color{ 0, 255, 255 }, SDL_Rect{ 415, 150, 450, 60 }, renderer);
	if (GameWin) text.writeText("Game Complete!", SDL_Color{ 0, 255, 255 }, SDL_Rect{ 415, 255, 450, 60 }, renderer);
	if (!GameWin) NextLevel->Render(renderer);
	MainMenu->Render(renderer);
	Quit->Render(renderer);
}

bool finishMenu::setUpButtons(SDL_Renderer* renderer)
{
	if (!GameWin) {
		if (!NextLevel->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	}
	if (!MainMenu->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Quit->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	return true;
}
