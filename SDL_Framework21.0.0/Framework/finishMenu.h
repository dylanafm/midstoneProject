#ifndef FINISHMENU_H
#define FINISHMENU_H

#include "Button.h"
#include "Text.h"

class FinishMenu
{
private:
	Button* NextLevel;
	Button* MainMenu;
	Button* Quit;
	Text text;

	int newScene = 0;

	bool paused = true;

public:
	FinishMenu(SDL_Renderer* r);
	~FinishMenu();
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

