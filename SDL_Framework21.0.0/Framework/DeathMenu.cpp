#include "DeathMenu.h"

DeathMenu::DeathMenu()
{
	Restart = new button(465, 230, 350, 60, Vec3(20, 20, 210), "Restart");
	MainMenu = new button(415, 330, 450, 60, Vec3(20, 20, 210), "Main Menu");
	Quit = new button(540, 430, 200, 60, Vec3(20, 20, 210), "Quit");
}

DeathMenu::~DeathMenu()
{
}

void DeathMenu::deathUpdate(SDL_Event event_)
{
	Restart->Update();
	MainMenu->Update();
	Quit->Update();

	if (Restart->buttonClicked(event_)) { Restart->click->playSFX();  newScene = 1; paused = false; }
	if (MainMenu->buttonClicked(event_)) { MainMenu->click->playSFX(); newScene = 2; paused = false; }
	if (Quit->buttonClicked(event_)) { Quit->click->playSFX(); newScene = -1; paused = false; }
}

void DeathMenu::deathRender(SDL_Renderer* renderer)
{
	if (currentMenu == 1) {
		text.writeText("You Died", SDL_Color{ 255, 0, 0 }, SDL_Rect{ 440, 150, 400, 60 }, renderer);
		Restart->Render(renderer);
		MainMenu->Render(renderer);
		Quit->Render(renderer);
	}
}

bool DeathMenu::setUpButtons(SDL_Renderer* renderer)
{
	if (!Restart->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!MainMenu->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Quit->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	return true;
}
