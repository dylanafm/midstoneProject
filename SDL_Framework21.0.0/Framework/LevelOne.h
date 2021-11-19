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
#include "HUD.h"
#include "Fish.h"
#include "Harpoon.h"
#include "InGameTimer.h"
#include "Map.h"
#include "boss.h"
#include "Enemy.h"
#include "Background.h"
#include "Projectile.h"
#include "musicPlayer.h"
#include "healthPickup.h"

using namespace MATH;
class HUD;
class healthPickup;
class Background;

class LevelOne : public Scene {
private:

	musicPlayer* song;

	HUD* playerHUD;

	Background* bg;
	//Animator* a;
	
	harpoonHarry* harry;
	Harpoon* harpoon;
	Fish* fish[20];
	boss* boss1;
	SDL_Window* window;
	Matrix4 projectionMatrix;
	Projectile* projectile;
	healthPickup* hp;

	SDL_Renderer* renderer;

	DeathMenu* dMenu;
	pauseMenu* pMenu;
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
};

#endif

