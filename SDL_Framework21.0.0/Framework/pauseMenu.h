#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include "button.h"

class pauseMenu
{
private:
	button* Resume;
	button* Restart;
	button* MainMenu;
	button* Settings;
	button* Tutorial;
	button* Quit;

	button* Back;

	int currentMenu = 1;
	int newScene = 0;

	bool paused = true;

public:
	pauseMenu();
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

