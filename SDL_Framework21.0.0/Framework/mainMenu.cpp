#include "Scene0.h"
#include "mainMenu.h"
#include "GameManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"


mainMenu::mainMenu(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	logoTex = TextureManager::LoadTexture("textures/HarryLogo.png", renderer);
	logoBox = SDL_Rect{ 430, 10, 400, 200 };

	Levels = new button(490, 195, 300, 60, Vec3(20, 20, 210), "Levels");
	Settings = new button(440, 295, 400, 60, Vec3(20, 20, 210), "Settings");
	Tutorial = new button(440, 395, 400, 60, Vec3(20, 20, 210), "Tutorial");
	Quit = new button(540, 495, 200, 60, Vec3(20, 20, 210), "Quit");

	Back = new button(50, 50, 50, 50, Vec3(20, 20, 210), "Back");

	LevelOne = new button(250, 200, 200, 200, Vec3(20, 20, 210), "1");
	//LevelTwo = button(350, 200, 200, 200, Vec3(255, 255, 255), Vec3(0, 255, 255), Vec3(120, 255, 0), "Level Two");
	//LevelThree = button(450, 200, 200, 200, Vec3(255, 255, 255), Vec3(0, 255, 255), Vec3(120, 255, 0), "LevelThree");
}

mainMenu::~mainMenu() {
	delete window;
	delete renderer;
}

bool mainMenu::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;

	if (!Levels->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Settings->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Tutorial->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Quit->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Back->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!LevelOne->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;

	if (!setBackground()) return false;

	return true;
}

void mainMenu::OnDestroy() {
	SDL_DestroyRenderer(renderer);
}

void mainMenu::Update(const float deltaTime) {
	SDL_Event event;

	if (currentMenu == 1) {
		Levels->Update();
		Settings->Update();
		Tutorial->Update();
		Quit->Update();
	}
	else if (currentMenu == 2) {

		Back->Update();
		LevelOne->Update();
		//LevelTwo->Update(renderer);
		//LevelThree->Update(renderer);

	}
	else  if (currentMenu == 3) {
		Back->Update();
	}
	else {
		Back->Update();
	}

	while(SDL_PollEvent(&event))
	{
		if (LevelOne->buttonClicked(event) && currentMenu == 2) { newScene = 1; }

		if (Levels->buttonClicked(event)) { 
			currentMenu = 2; 
		}
		if (Settings->buttonClicked(event)) { currentMenu = 3; }
		if (Tutorial->buttonClicked(event)) { currentMenu = 4; }
		if (Quit->buttonClicked(event)) { newScene = -1; }

		if (Back->buttonClicked(event)) { currentMenu = 1; }

		
	}

}

void mainMenu::Render() {

	SDL_SetRenderDrawColor(renderer, 0, 120, 200, 0);
	SDL_RenderClear(renderer);

	SDL_RenderCopyEx(renderer, backgroundTexture, nullptr, new SDL_Rect{ 0, 0, 1280, 720 }, 0.0, nullptr, SDL_FLIP_NONE);
	

	if (currentMenu == 1) {
		
		
		//Levels Button
		SDL_RenderCopy(renderer, logoTex, nullptr, &logoBox);

		Levels->Render(renderer);
		Settings->Render(renderer);
		Tutorial->Render(renderer);
		Quit->Render(renderer);
		

	}
	else if (currentMenu == 2){
	
		Back->Render(renderer);
		LevelOne->Render(renderer);
		//LevelTwo->Render(renderer);
		//LevelThree->Render(renderer);
		
	}
	else  if (currentMenu == 3) {
		Back->Render(renderer);


	}
	else {
		Back->Render(renderer);

	}
	SDL_RenderPresent(renderer);
}

bool mainMenu::setBackground()
{
	SDL_Surface* tempSurface = IMG_Load("textures/3_game_background.png");
	SDL_Texture* tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	if (tempTexture == nullptr) printf("%s\n", SDL_GetError());
	if (tempSurface == nullptr) {
		std::cerr << "Can't open the original image" << std::endl;
		return false;
	}
	else {
		backgroundTexture = tempTexture;
		SDL_FreeSurface(tempSurface);
	}
	return true;
}
