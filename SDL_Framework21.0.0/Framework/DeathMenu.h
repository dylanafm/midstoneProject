#ifndef DEATHMENU_H
#define DEATHMENU_H

#include "button.h"

class DeathMenu
{
private:
	button Restart;
	button MainMenu;
	button Quit;

	int currentMenu = 1;
	int newScene = 0;

	bool paused = true;

public:
	DeathMenu();
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

};
#endif

