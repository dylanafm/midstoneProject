#ifndef LEVELONE_H
#define LEVELONE_H

#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "VMath.h"
#include "Body.h"
#include "harpoonHarry.h"
#include "pauseMenu.h"
#include "DeathMenu.h"
#include "finishMenu.h"
#include "HUD.h"
#include "Fish.h"
#include "Harpoon.h"
#include "InGameTimer.h"
#include "Map.h"
#include "Shark.h"
#include "Enemy.h"
#include "ShieldPU.h"
#include "Background.h"
#include "Projectile.h"
#include "musicPlayer.h"
#include "healthPickup.h"
#include "sfx.h"
#include "Powerups.h"
#include "MGHarpoon.h"

using namespace MATH;
class HUD;
class healthPickup;
class Background;
class harpoonHarry;
class Shark;
class Harpoon;
class Fish;
class ShieldPU;
class MGHarpoon;
class LevelOne : public Scene {
private:

	musicPlayer* song;
	int currentHarpoon;
	ShieldPU* Shield;
	MGHarpoon* rf;
	HUD* playerHUD;

	Background* bg;
	//Animator* a;
	
	harpoonHarry* harry;
	Harpoon* harpoon[50];
	Fish* fish[20];
	Shark* SharkBoss;
	SDL_Window* window;
	Matrix4 projectionMatrix;
	Projectile* projectile;
	healthPickup* hp[9];

	SDL_Renderer* renderer;

	DeathMenu* dMenu;
	pauseMenu* pMenu;
	finishMenu* fMenu;
	bool paused = false;
	Map* map;
	InGameTimer* reloadTimer;
	InGameTimer* projectileReloadTimer;
	InGameTimer* biteTimer;
	int newScene = 0;
	bool isFired = false;
	bool isProjectileFired = false;
	bool isBitten = false;
public:

	//HUD hud;

	LevelOne(SDL_Window* sdlWindow);
	~LevelOne();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void spawnHarpoon();
	void spawnProjectile();
	bool getPaused() {
		return paused;
	}
	int getScene() {
		return newScene;
	}	

	sfx* harpoonShoot;
	sfx* fishHurt;
	sfx* playerHurt;
	sfx* playerDie;
	sfx* bossHurt;
	sfx* healthsfx;

};

#endif

