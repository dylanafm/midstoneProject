#ifndef MAINMENU_H
#define MAINMENU_H

#include "MMath.h"
#include "Scene.h"
#include "Body.h"
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_TTF.h"

using namespace MATH;
class mainMenu : public Scene {
private:
	SDL_Window* window;
	Matrix4 projectionMatrix;
	SDL_Renderer* renderer;

	SDL_Rect Levels;
	SDL_Rect Settings;
	SDL_Rect Tutorial;
	SDL_Rect Quit;


	SDL_Rect Back;


	SDL_Rect LevelOne;
	SDL_Rect LevelTwo;
	SDL_Rect LevelThree;



	Vec3 colorValueL;
	Vec3 colorValueS;
	Vec3 colorValueT;
	Vec3 colorValueQ;
	
	
	Vec3 colorValueBack;
	Vec3 colorValueLevelOne;

	TTF_Font* font;
	SDL_Surface* text;
	SDL_Texture* text_texture;


	int currentMenu = 1; // Switch between menus in the main menu. 1 = Main Menu, 2 = Levels Menu, 3 = Settings Menu, 4 = Tutorial Menu
	int newScene = 0;

public:
	mainMenu(SDL_Window* sdlWindow);
	~mainMenu();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	int getScene() {
		int temp = newScene;
		return temp;
	}
};

#endif

