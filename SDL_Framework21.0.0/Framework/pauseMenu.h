#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "button.h"

class pauseMenu
{
private:
	Button* Resume;
	Button* Restart;
	Button* MainMenu;
	Button* Settings;
	Button* Tutorial;
	Button* Quit;

	Button* Back;

	SDL_Texture* tutorialIMG;
	SDL_Rect tutorialBox;

	int currentMenu = 1;
	int newScene = 0;
	int currentScene;

	bool paused = true;

public:
	pauseMenu(SDL_Renderer* r, int currentScene_);
	~pauseMenu();
	void pauseUpdate(SDL_Event event_);
	void pauseRender(SDL_Renderer* renderer);
	bool getPaused() {
		return paused;
	}
	int getScene() {
		return newScene;
	}
	void setDefault() {
		paused = true;
		newScene = 0;
	}
	bool setUpButtons(SDL_Renderer* renderer);

};
#endif

