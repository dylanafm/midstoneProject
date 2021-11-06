#include "DeathMenu.h"

DeathMenu::DeathMenu()
{
	Restart = new button(250, 200, 800, 40, Vec3(120, 255, 0), "Restart");
	MainMenu = new button(250, 300, 800, 40, Vec3(120, 255, 0), "Main Menu");
	Quit = new button(250, 400, 800, 40, Vec3(120, 255, 0), "Quit");
}

DeathMenu::~DeathMenu()
{
}

void DeathMenu::deathUpdate(SDL_Event event_)
{
	Restart->Update();
	MainMenu->Update();
	Quit->Update();

	if (Restart->buttonClicked(event_)) { newScene = 1; paused = false; }
	if (MainMenu->buttonClicked(event_)) { newScene = 2; paused = false; }
	if (Quit->buttonClicked(event_)) { newScene = -1; paused = false; }
}

void DeathMenu::deathRender(SDL_Renderer* renderer)
{
	if (currentMenu == 1) {
		Restart->Render(renderer);
		MainMenu->Render(renderer);
		Quit->Render(renderer);
	}
}

bool DeathMenu::setUpButtons(SDL_Renderer* renderer)
{
	if (!Restart->setImage("textures/blue_button01.png", renderer)) return false;
	if (!MainMenu->setImage("textures/blue_button01.png", renderer)) return false;
	if (!Quit->setImage("textures/blue_button01.png", renderer)) return false;
	return true;
}
