#include "pauseMenu.h"
#include "TextureManager.h"

pauseMenu::pauseMenu(SDL_Renderer* r, int currentScene_)
{
	Resume = new button(490, 95, 300, 60, Vec3(20, 20, 210), "Resume");
	Restart = new button(465, 195, 350, 60, Vec3(20, 20, 210), "Restart");
	MainMenu = new button(415, 295, 450, 60, Vec3(20, 20, 210), "Main Menu");
	Settings = new button(440, 395, 400, 60, Vec3(20, 20, 210), "Settings");
	Tutorial = new button(440, 495, 400, 60, Vec3(20, 20, 210), "Tutorial");
	Quit = new button(540, 595, 200, 60, Vec3(20, 20, 210), "Quit");

	Back = new button(50, 50, 50, 50, Vec3(20, 20, 210), "Back");


	tutorialIMG = TextureManager::LoadTexture("textures/TutorialPic.png", r);
	tutorialBox = SDL_Rect{ 100 , 50, 1100, 600 };
	currentScene = currentScene_;

}

pauseMenu::~pauseMenu()
{
	delete Resume;
	delete Restart;
	delete MainMenu;
	delete Settings;
	delete Tutorial;
	delete Quit;
	delete Back;
	SDL_DestroyTexture(tutorialIMG);
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
	if (Resume->buttonClicked(event_) && (currentMenu == 1)) { Resume->click->playSFX(); paused = false; }
	if (Restart->buttonClicked(event_) && (currentMenu == 1)) { Restart->click->playSFX(); newScene = currentScene; paused = false; }
	if (MainMenu->buttonClicked(event_) && (currentMenu == 1)) { MainMenu->click->playSFX(); newScene = 2; paused = false; }
	if (Settings->buttonClicked(event_) && (currentMenu == 1)) { Settings->click->playSFX(); currentMenu = 3; }
	if (Tutorial->buttonClicked(event_) && (currentMenu == 1)) { Tutorial->click->playSFX(); currentMenu = 4; }
	if (Quit->buttonClicked(event_) && (currentMenu == 1)) { Quit->click->playSFX(); newScene = -1; paused = false; }
	if (Back->buttonClicked(event_)) { printf("click");  Back->click->playSFX(); currentMenu = 1; }
	
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
		SDL_RenderCopy(renderer, tutorialIMG, nullptr, &tutorialBox);
		Back->Render(renderer);
	}
}

bool pauseMenu::setUpButtons(SDL_Renderer* renderer)
{
	if (!Resume->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Restart->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!MainMenu->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Settings->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Tutorial->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Quit->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Back->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	return true;
}
