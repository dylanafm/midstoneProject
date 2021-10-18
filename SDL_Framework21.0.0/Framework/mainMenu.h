#ifndef MAINMENU_H
#define MAINMENU_H

#include "MMath.h"
#include "Scene.h"
#include "Body.h"
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_TTF.h"
#include "Text.h"
#include "button.h"

using namespace MATH;
class mainMenu : public Scene {
private:
	SDL_Window* window;
	Matrix4 projectionMatrix;
	SDL_Renderer* renderer;

	
	
	button Levels;
	button Settings;
	button Tutorial;
	button Quit;
	
	
	button Back;



	button LevelOne;
	button LevelTwo;
	button LevelThree;




	Text newText;

	int currentMenu = 1; // Switch between menus in the main menu. 1 = Main Menu, 2 = Levels Menu, 3 = Settings Menu, 4 = Tutorial Menu
	int newScene = 0; // Switch between scenes. -1 = Quit, 1 = LevelOne, 0 = Dont switch

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
};

#endif

