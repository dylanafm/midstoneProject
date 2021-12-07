#include "finishMenu.h"
#include "TextureManager.h"

finishMenu::finishMenu(SDL_Renderer* r)
{
	NextLevel = new button(390, 230, 500, 60, Vec3(20, 20, 210), "Next Level");
	MainMenu = new button(415, 330, 450, 60, Vec3(20, 20, 210), "Main Menu");
	Quit = new button(540, 430, 200, 60, Vec3(20, 20, 210), "Quit");
}

finishMenu::~finishMenu()
{
}

void finishMenu::finishUpdate(SDL_Event event_)
{
	NextLevel->Update();
	MainMenu->Update();
	Quit->Update();
	if (NextLevel->buttonClicked(event_)) { NextLevel->click->playSFX(); newScene = 1; paused = false; }
	if (MainMenu->buttonClicked(event_)) { MainMenu->click->playSFX(); newScene = 2; paused = false; }
	if (Quit->buttonClicked(event_)) { Quit->click->playSFX(); newScene = -1; paused = false; }
}

void finishMenu::finishRender(SDL_Renderer* renderer)
{
	text.writeText("Well Done!", SDL_Color{ 0, 255, 255 }, SDL_Rect{ 415, 150, 450, 60 }, renderer);
	NextLevel->Render(renderer);
	MainMenu->Render(renderer);
	Quit->Render(renderer);
}

bool finishMenu::setUpButtons(SDL_Renderer* renderer)
{
	if (!NextLevel->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!MainMenu->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Quit->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	return true;
}
