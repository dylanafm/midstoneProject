#ifndef DEATHMENU_H
#define DEATHMENU_H

#include "button.h"

class DeathMenu
{
private:
	button* Restart;
	button* MainMenu;
	button* Quit;
	Text text;

	int currentMenu = 1;
	int newScene = 0;
	int currentScene;

	bool paused = true;

public:
	DeathMenu(int currentScene_);
	~DeathMenu();
	void deathUpdate(SDL_Event event_);
	void deathRender(SDL_Renderer* renderer);
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

