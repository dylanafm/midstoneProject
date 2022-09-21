#ifndef MAINMENU_H
#define MAINMENU_H

#include "MMath.h"
#include "Scene.h"
#include "Body.h"
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_TTF.h"
#include "Text.h"
#include "MusicPlayer.h"
#include "button.h"
#include "InGameTimer.h"

using namespace MATH;
class MainMenu : public Scene {
private:


	SDL_Window* window;
	Matrix4 projectionMatrix;
	SDL_Renderer* renderer;

	Button* Start;
	
	Button* Levels;
	Button* Settings;
	Button* Tutorial;
	Button* Quit;
	Button* Credits;
	
	Button* Back;

	Button* LevelOne;
	Button* LevelTwo;
	Button* LevelThree;

	SDL_Texture* backgroundTexture;

	SDL_Texture* creditBG;

	SDL_Texture* tutorialIMG;
	SDL_Rect tutorialBox;

	SDL_Texture* logoTex;
	SDL_Rect logoBox;

	SDL_Texture* slam;
	SDL_Texture* slamCred;

	Text slamText;

	InGameTimer* timer;

	Text newText;

	MusicPlayer* Song;

	int creditScroll;

	Text creditText[9];

	int currentMenu = 1; // Switch between menus. 0 = Intro, 1 = Main Menu, 2 = Levels Menu, 3 = Settings Menu, 4 = Tutorial Menu, 5 = Credit
	int newScene = 0; // Switch between scenes. -1 = Quit, 1 = LevelOne, 0 = Dont switch
	bool startTimer;
public:
	MainMenu(SDL_Window* sdlWindow);
	~MainMenu();
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
};

#endif

