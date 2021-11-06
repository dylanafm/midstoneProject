#include "pauseMenu.h"

pauseMenu::pauseMenu()
{
	Resume = new button(250, 100, 800, 40, Vec3(120, 255, 0), "Resume");
	Restart = new button(250, 200, 800, 40, Vec3(120, 255, 0), "Restart");
	MainMenu = new button(250, 300, 800, 40, Vec3(120, 255, 0), "Main Menu");
	Settings = new button(250, 400, 800, 40, Vec3(120, 255, 0), "Settings");
	Tutorial = new button(250, 500, 800, 40, Vec3(120, 255, 0), "Tutorial");
	Quit = new button(250, 600, 800, 40, Vec3(120, 255, 0), "Quit");
	Back = new button(50, 50, 50, 50, Vec3(120, 255, 0), "Back");

}

pauseMenu::~pauseMenu()
{
}

void pauseMenu::pauseUpdate(SDL_Event event_)
{
	Resume->Update();
	Restart->Update();
	MainMenu->Update();
	Settings->Update();
	Tutorial->Update();
	Quit->Update();
	Back->Update();

	if (Resume->buttonClicked(event_)) { paused = false; }
	if (Restart->buttonClicked(event_)) { newScene = 1; paused = false; }
	if (MainMenu->buttonClicked(event_)) { newScene = 2; paused = false; }
	if (Settings->buttonClicked(event_)) { currentMenu = 3; }
	if (Tutorial->buttonClicked(event_)) { currentMenu = 4; }
	if (Quit->buttonClicked(event_)) { newScene = -1; paused = false; }

	if (Back->buttonClicked(event_)) { currentMenu = 1; }
}

void pauseMenu::pauseRender(SDL_Renderer* renderer)
{
	if (currentMenu == 1) {
		Resume->Render(renderer);
		Restart->Render(renderer);
		MainMenu->Render(renderer);
		Settings->Render(renderer);
		Tutorial->Render(renderer);
		Quit->Render(renderer);
	}
	else  if (currentMenu == 3) {
		Back->Render(renderer);
	}
	else if (currentMenu == 4) {
		Back->Render(renderer);
	}
}

bool pauseMenu::setUpButtons(SDL_Renderer* renderer)
{
	if (!Resume->setImage(IMG_Load("buttonOriginal.png"), renderer)) return false;
	if (!Restart->setImage(IMG_Load("buttonOriginal.png"), renderer)) return false;
	if (!MainMenu->setImage(IMG_Load("buttonOriginal.png"), renderer)) return false;
	if (!Settings->setImage(IMG_Load("buttonOriginal.png"), renderer)) return false;
	if (!Tutorial->setImage(IMG_Load("buttonOriginal.png"), renderer)) return false;
	if (!Quit->setImage(IMG_Load("buttonOriginal.png"), renderer)) return false;
	if (!Back->setImage(IMG_Load("buttonOriginal.png"), renderer)) return false;
	return true;
}
