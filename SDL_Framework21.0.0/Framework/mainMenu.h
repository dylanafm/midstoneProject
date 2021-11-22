#ifndef MAINMENU_H
#define MAINMENU_H

#include "MMath.h"
#include "Scene.h"
#include "Body.h"
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_TTF.h"
#include "Text.h"
#include "musicPlayer.h"
#include "button.h"
#include "InGameTimer.h"

using namespace MATH;
class mainMenu : public Scene {
private:


	SDL_Window* window;
	Matrix4 projectionMatrix;
	SDL_Renderer* renderer;

	button* Start;
	
	button* Levels;
	button* Settings;
	button* Tutorial;
	button* Quit;
	button* Credits;
	
	button* Back;



	button* LevelOne;
	button* LevelTwo;
	button* LevelThree;

	SDL_Texture* backgroundTexture;
	SDL_Texture* creditBG;



	SDL_Texture* logoTex;
	SDL_Texture* slam;
	SDL_Texture* slamCred;

	Text slamText;
	InGameTimer* timer;

	SDL_Rect logoBox;

	Text newText;

	musicPlayer* Song;


	int creditScroll;

	Text creditText[9];

	int currentMenu = 0; // Switch between menus in the main menu. 0 = Intro 1 = Main Menu, 2 = Levels Menu, 3 = Settings Menu, 4 = Tutorial Menu 5 = Credit
	int newScene = 0; // Switch between scenes. -1 = Quit, 1 = LevelOne, 0 = Dont switch
	bool startTimer;
public:
	mainMenu(SDL_Window* sdlWindow);
	~mainMenu();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	bool getPaused() {
		return false;
	}
	int getScene() {
		return newScene;
	}
	bool setBackground();
};

#endif

