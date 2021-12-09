#ifndef FINISHMENU_H
#define FINISHMENU_H

#include "button.h"
#include "Text.h"

class finishMenu
{
private:
	button* NextLevel;
	button* MainMenu;
	button* Quit;
	Text text;

	int newScene = 0;

	bool paused = true;

public:
	finishMenu(SDL_Renderer* r);
	~finishMenu();
	void finishUpdate(SDL_Event event_);
	void finishRender(SDL_Renderer* renderer);
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

	bool GameWin;
};
#endif

