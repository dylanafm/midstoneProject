#include "DeathMenu.h"

DeathMenu::DeathMenu()
{
	Restart = button(250, 200, 800, 40, Vec3(255, 255, 255), Vec3(0, 255, 255), Vec3(120, 255, 0), "Restart");
	MainMenu = button(250, 300, 800, 40, Vec3(255, 255, 255), Vec3(0, 255, 255), Vec3(120, 255, 0), "Main Menu");
	Quit = button(250, 400, 800, 40, Vec3(255, 255, 255), Vec3(255, 0, 0), Vec3(120, 255, 0), "Quit");
}

DeathMenu::~DeathMenu()
{
}

void DeathMenu::deathUpdate(SDL_Event event_)
{
	Restart.Update();
	MainMenu.Update();
	Quit.Update();

	if (Restart.buttonClicked(event_)) { newScene = 1; paused = false; }
	if (MainMenu.buttonClicked(event_)) { newScene = 2; paused = false; }
	if (Quit.buttonClicked(event_)) { newScene = -1; paused = false; }
}

void DeathMenu::deathRender(SDL_Renderer* renderer)
{
	if (currentMenu == 1) {
		Restart.Render(renderer);
		MainMenu.Render(renderer);
		Quit.Render(renderer);
	}
}
