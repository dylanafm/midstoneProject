#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "VMath.h"
#include "Body.h"
#include "HarpoonHarry.h"
#include "PauseMenu.h"
#include "FinishMenu.h"
#include "DeathMenu.h"
#include "HUD.h"
#include "Harpoon.h"
#include "Powerup.h"
#include "InGameTimer.h"
#include "Map.h"
#include "boss.h"
#include "Enemy.h"
#include "ShieldPU.h"
#include "Background.h"
#include "Projectile.h"
#include "MusicPlayer.h"
#include "HealthPickup.h"
#include "Sfx.h"
#include "MGHarpoon.h"

using namespace MATH;
class HUD;
class HealthPickup;
class Background;
class Shark;
class Harpoon;
class Fish;
class Powerup;
class ShieldPU;
class MGHarpoon;
class LevelTwo : public Scene {
private:

	MusicPlayer* song;
	int currentHarpoon;
	ShieldPU* Shield;
	MGHarpoon* rf;
	HUD* playerHUD;

	Background* bg;
	//Animator* a;

	HarpoonHarry* harry;
	Harpoon* harpoon[50];
	Fish* tigerFish[80];
	Boss* boss1;
	SDL_Window* window;
	Matrix4 projectionMatrix;
	HealthPickup* hp[4];

	SDL_Renderer* renderer;

	DeathMenu* dMenu;
	PauseMenu* pMenu;
	FinishMenu* fMenu;
	bool paused = false;
	Map* map;
	InGameTimer* reloadTimer;
	InGameTimer* biteTimer;
	int newScene = 0;
	bool isFired = false;
	bool isBitten = false;
public:

	//HUD hud;

	LevelTwo(SDL_Window* sdlWindow);
	~LevelTwo();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void spawnHarpoon();
	bool getPaused() {
		return paused;
	}
	int getScene() {
		return newScene;
	}

	Sfx* harpoonShoot;
	Sfx* fishHurt;
	Sfx* playerHurt;
	Sfx* playerDie;
	Sfx* bossHurt;
	Sfx* healthsfx;

};

#endif
