#include "GameManager.h"
#include "Window.h"
#include "Timer.h"
#include "Scene0.h"
#include "mainMenu.h"
#include "LevelOne.h"
#include "LevelTwo.h"

#include <iostream>


GameManager::GameManager() {
	windowPtr = nullptr;
	timer = nullptr;
	isRunning = true;
	currentScene = nullptr;
}


/// In this OnCreate() method, fuction, subroutine, whatever the word, 
bool GameManager::OnCreate() {
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 720;
	windowPtr = new Window(SCREEN_WIDTH, SCREEN_HEIGHT);

	if (windowPtr == nullptr) {
		OnDestroy();
		return false;
	}
	if (windowPtr->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	timer = new Timer();
	if (timer == nullptr) {
		OnDestroy();
		return false;
	}

	currentScene = new mainMenu(windowPtr->GetSDL_Window());
	if (currentScene == nullptr) {
		OnDestroy();
		return false;
	}

	if (currentScene->OnCreate() == false) {
		OnDestroy();
		return false;
	}

	return true;
}

/// Here's the whole game
void GameManager::Run() {
	timer->Start();
	while (isRunning) {

		//Check if need to switch scenes
		if (currentScene->getScene() == 1) {
			currentScene->OnDestroy();
			currentScene = new LevelOne(windowPtr->GetSDL_Window());
			currentScene->OnCreate();
		}
		if (currentScene->getScene() == 3) {
			currentScene->OnDestroy();
			currentScene = new LevelTwo(windowPtr->GetSDL_Window());
			currentScene->OnCreate();
		}
		if (currentScene->getScene() == 2) {
			currentScene->OnDestroy();
			currentScene = new mainMenu(windowPtr->GetSDL_Window());
			currentScene->OnCreate();
		}
		if (currentScene->getScene() == -1) {
			isRunning = false;
		}
		if (currentScene->getPaused()) {
			currentScene->Update(0.0f);
		}
		else {
			currentScene->Update(timer->GetDeltaTime());
		}
		
		currentScene->Render();
		timer->UpdateFrameTicks();

		/// Keeep the event loop running at a proper rate
		SDL_Delay(timer->GetSleepTime(60)); ///60 frames per sec
	}
}

GameManager::~GameManager() {}

void GameManager::OnDestroy(){
	if (windowPtr) delete windowPtr;
	if (timer) delete timer;
	if (currentScene) delete currentScene;
}