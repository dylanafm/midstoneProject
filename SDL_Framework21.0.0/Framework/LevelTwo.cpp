#include "LevelTwo.h"
#include "Physics.h"
#include <SDL.h>
#include "Timer.h"

LevelTwo::LevelTwo(SDL_Window* sdlWindow_) {

	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//a = new Animator(renderer);
	bg = new Background(renderer, 1, "textures/layers2/1.png", 1, "textures/layers2/2.png", 2, "textures/layers2/3.png", 3, "textures/layers2/4.png", 1, "textures/layers2/5.png", 4, "textures/layers2/6.png", 4, "textures/layers2/7.png", 4, "textures/layers2/8.png", 0.03f);

	boss1 = new boss(SDL_Rect{ 1280, 360, 300, 200 }, 1, renderer, "textures/bossAnim.png", 100.0f);
	boss1->health = 5;
	harry = new harpoonHarry(renderer, "textures/HarrySheet.png", 25.0f);
	harry->pos = Vec3(100.0f, 100.0f, 100.0f);

	playerHUD = new HUD();
	currentHarpoon = 0;
	song = new musicPlayer("Music/levelonetheme.ogg", 2);

	hp[0] = new healthPickup(Vec3(1000.0f, 600.0f, 0.0f), 2.0f, renderer);
	hp[1] = new healthPickup(Vec3(1400.0f, 400.0f, 0.0f), 2.0f, renderer);
	hp[2] = new healthPickup(Vec3(1800.0f, 150.0f, 0.0f), 2.0f, renderer);
	hp[3] = new healthPickup(Vec3(2200.0f, 115.0f, 0.0f), 2.0f, renderer);
	hp[4] = new healthPickup(Vec3(2400.0f, 200.0f, 0.0f), 2.0f, renderer);
	hp[5] = new healthPickup(Vec3(2800.0f, 500.0f, 0.0f), 2.0f, renderer);
	hp[6] = new healthPickup(Vec3(3200.0f, 640.0f, 0.0f), 2.0f, renderer);
	hp[7] = new healthPickup(Vec3(3600.0f, 460.0f, 0.0f), 2.0f, renderer);
	hp[8] = new healthPickup(Vec3(4000.0f, 11.0f, 0.0f), 2.0f, renderer);

	tigerFish[0] = new TigerFish(SDL_Rect{ 400, 200, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[1] = new TigerFish(SDL_Rect{ 800, 50, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[2] = new TigerFish(SDL_Rect{ 1200, 600, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[3] = new TigerFish(SDL_Rect{ 1600, 300, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[4] = new TigerFish(SDL_Rect{ 2000, 100, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[5] = new TigerFish(SDL_Rect{ 2400, 500, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[6] = new TigerFish(SDL_Rect{ 2800, 200, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[7] = new TigerFish(SDL_Rect{ 3200, 600, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[8] = new TigerFish(SDL_Rect{ 3600, 300, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[9] = new TigerFish(SDL_Rect{ 4000, 640, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[10] = new TigerFish(SDL_Rect{ 4400, 220, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[11] = new TigerFish(SDL_Rect{ 4800, 115, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[12] = new TigerFish(SDL_Rect{ 5200, 450, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[13] = new TigerFish(SDL_Rect{ 5600, 500, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[14] = new TigerFish(SDL_Rect{ 6000, 630, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[15] = new TigerFish(SDL_Rect{ 6400, 200, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[16] = new TigerFish(SDL_Rect{ 6800, 340, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[17] = new TigerFish(SDL_Rect{ 7200, 112, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[18] = new TigerFish(SDL_Rect{ 7600, 400, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);
	tigerFish[19] = new TigerFish(SDL_Rect{ 8000, 320, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f);



	Shield = new ShieldPU(SDL_Rect{ 800, 40, 50, 50 }, 2, "textures/Shield.png", renderer);
	rf = new MGHarpoon(SDL_Rect{ 900, 500, 50, 50 }, 2, "textures/MGH.png", renderer);

	harpoonShoot = new sfx("SFX/shoot.ogg", 10);
	fishHurt = new sfx("SFX/blobdeath.wav", 10);
	playerHurt = new sfx("SFX/pain.wav", 10);
	playerDie = new sfx("SFX/die.wav", 10);
	bossHurt = new sfx("SFX/bossdeath.wav", 10);
	healthsfx = new sfx("SFX/life_pickup.flac", 10);







}

LevelTwo::~LevelTwo() {
	delete window;
	delete harry;
	delete renderer;
}

bool LevelTwo::OnCreate() {
	int w, h;
	SDL_GetWindowSize(window, &w, &h);

	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;

	song->playSong();

	pMenu = new pauseMenu(renderer);
	dMenu = new DeathMenu();

	if (!pMenu->setUpButtons(renderer)) return false;
	if (!dMenu->setUpButtons(renderer)) return false;

	return true;
}

void LevelTwo::OnDestroy() {
	SDL_DestroyRenderer(renderer);
}

void LevelTwo::Update(const float deltaTime) {
	SDL_Event event;
	for (int i = 0; i < std::size(hp); i++) {
		if (hp[i] != nullptr)  hp[i]->update(deltaTime);
		if (hp[i] != nullptr) {
			if (harry->isHealthCollided(harry, hp[i])) {
				healthsfx->playSFX();
				delete hp[i];
				hp[i] = nullptr;
			}
		}
	}
	if (Shield != nullptr)  Shield->Protect(harry);
	if (Shield != nullptr && Shield->checkCollide(harry)) {
		delete Shield;
		Shield = nullptr;
	}

	if (rf != nullptr)  rf->RapidFire(harry);
	if (rf != nullptr && rf->checkCollide(harry)) {
		delete rf;
		rf = nullptr;
	}

	if (!paused) {
		if (bg->getProg() <= 100.0f) {
			if (Shield != nullptr)  Shield->Scroll();
			if (rf != nullptr)  rf->Scroll();

			bg->Scroll();
			for (int i = 0; i < std::size(hp); i++) {
				if (hp[i] != nullptr) hp[i]->scroll();
			}
			for (int i = 0; i < std::size(tigerFish); i++) {
				if (tigerFish[i] != nullptr) tigerFish[i]->Scroll();
			}
			//if (boss1 != nullptr) boss1->Scroll();
		}




	}
	harry->Update(deltaTime);
	for (int i = 0; i < std::size(harpoon); i++) {
		if (harpoon[i] != nullptr) harpoon[i]->Update(deltaTime);

		for (int ii = 0; ii < std::size(tigerFish); ii++) {

			if (harpoon[i] != nullptr && tigerFish[ii] != nullptr) {
				if (harpoon[i]->isCollided(tigerFish[ii], harpoon[i])) {
					fishHurt->playSFX();
					harpoon[i] = nullptr;
					tigerFish[ii] = nullptr;
					delete harpoon[i];
					delete tigerFish[ii];

				}
			}
			if (harpoon[i] != nullptr) {
				if (harpoon[i]->pos.x < -50.0f || harpoon[i]->pos.x > 1300.0f || harpoon[i]->pos.y < -50.0f || harpoon[i]->pos.y > 800.0f) {
					delete harpoon[i];
					harpoon[i] = nullptr;
				}
			}
		}

	}
	if (boss1 != nullptr) {
		if (!isBitten) {
			if (harry->isCollided(harry, boss1)) {
				playerHurt->playSFX();

				biteTimer = new InGameTimer(2.0f);
				isBitten = true;
			}
		}
	}

	if (projectile != nullptr) {
		projectile->Update(deltaTime);
		if (harry->isCollided(harry, projectile)) {
			if (!harry->Shielded) playerHurt->playSFX();
			delete projectile;
			projectile = nullptr;
		}
	}

	for (int i = 0; i < std::size(tigerFish); i++) {

		if (tigerFish[i] != nullptr) tigerFish[i]->Update(deltaTime);
		if (boss1 != nullptr && bg->getProg() >= 100.0f) {
			boss1->Update(deltaTime, harry);
			if (!isProjectileFired)	spawnProjectile();
		}


		if (tigerFish[i] != nullptr) {


			if (harry->isCollided(harry, tigerFish[i])) {
				playerHurt->playSFX();

				delete tigerFish[i];
				tigerFish[i] = nullptr;
			}
		}



	}
	for (int i = 0; i < std::size(harpoon); i++) {
		if (harpoon[i] != nullptr && boss1 != nullptr) {
			if (harpoon[i]->isCollided(boss1, harpoon[i])) {
				if (boss1->health > 1) {
					bossHurt->playSFX();
					boss1->health -= 1;
					harpoon[i] = nullptr;
					delete harpoon[i];
					//std::cout << boss1->health << std::endl;
				}
				else {
					bossHurt->playSFX();

					harpoon[i] = nullptr;
					boss1 = nullptr;
					delete harpoon[i];
					delete boss1;
				}
			}
		}
	}

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
			paused = !paused;
		}
		if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN && !isFired && !paused) {
			if (harry->rapidFire == true) {
				currentHarpoon = currentHarpoon + 1;
				if (currentHarpoon == 50) currentHarpoon = 0;
				spawnHarpoon();
			}
			else
			{
				spawnHarpoon();

			}
		}
		if (harry->health <= 0) dMenu->deathUpdate(event);
		else if (paused) pMenu->pauseUpdate(event);
	}
	harry->HandleEvents(event);

	if (harry->health <= 0) {
		playerDie->playSFX();
		if (!paused) paused = true;
		newScene = dMenu->getScene();
		paused = dMenu->getPaused();
	}
	else if (paused) {
		newScene = pMenu->getScene();
		paused = pMenu->getPaused();
		if (!paused) pMenu->setDefault(); // Reset the Pause menu when Resume was pressed
	}

	Physics::ApplyForces(*harry, 0.0f);


	if (isFired && reloadTimer != nullptr) {
		reloadTimer->Update(deltaTime, isFired);
		if (!isFired) {
			reloadTimer = nullptr;
			delete reloadTimer;
		}
	}
	if (isBitten && biteTimer != nullptr) {
		biteTimer->Update(deltaTime, isBitten);
		if (!isBitten) {
			biteTimer = nullptr;
			delete biteTimer;
		}
	}
	if (isProjectileFired && projectileReloadTimer != nullptr) {
		projectileReloadTimer->Update(deltaTime, isProjectileFired);
		if (!isProjectileFired) {
			projectileReloadTimer = nullptr;
			delete projectileReloadTimer;
		}
	}


	if (!paused) {
		for (int i = 0; i < std::size(tigerFish); i++) {
			if (tigerFish[i] != nullptr) tigerFish[i]->Move(deltaTime, 200);
		}
	}
}

void LevelTwo::Render() {

	SDL_RenderClear(renderer);
	bg->Render(renderer);
	for (int i = 0; i < std::size(hp); i++) {
		if (hp[i] != nullptr) hp[i]->render(renderer);
	}
	//a->Render(renderer);
	harry->render(renderer);


	if (Shield != nullptr) Shield->Render(renderer);
	if (rf != nullptr) rf->Render(renderer);



	if (projectile != nullptr) projectile->Render(renderer);
	if (boss1 != nullptr) boss1->UpdateHealthBar(renderer, boss1->health);

	if (!paused) {
		if (boss1 != nullptr) boss1->swim->PlayAnim(0, 1, 0, 175);

		harry->swim->PlayAnim(0, 7, 0, 175);

		playerHUD->displayHUD(renderer, 20, 10, 50, 50, harry, reloadTimer, bg);
	}
	if (boss1 != nullptr)
		boss1->Render(renderer);
	for (int i = 0; i < std::size(harpoon); i++) {

		if (harpoon[i] != nullptr) harpoon[i]->render(renderer);
	}

	for (int i = 0; i < std::size(tigerFish); i++) {
		if (tigerFish[i] != nullptr) tigerFish[i]->Render(renderer);
		if (tigerFish[i] != nullptr && !paused) tigerFish[i]->tigerFishAnim->PlayAnim(0, 2, 0, 175);

	}

	if (harry->health <= 0) dMenu->deathRender(renderer);
	else if (paused) pMenu->pauseRender(renderer);


	SDL_RenderPresent(renderer);

}

void LevelTwo::spawnHarpoon()
{
	int x, y;

	Uint32 buttons;
	buttons = SDL_GetMouseState(&x, &y);
	float xf = static_cast<float>(x);
	float yf = static_cast<float>(y);

	Vec3 position = Vec3(harry->pos.x + 10.0f, harry->pos.y + 19.75f, 0.0f);
	Vec3 direction = Vec3(xf - position.x - 15.0f, yf - position.y - 5.25f, 0.0f);
	Vec3 velocity = VMath::normalize(direction) * 420.0f;
	harpoonShoot->playSFX();
	if (harry->rapidFire == false) {
		isFired = true;
		reloadTimer = new InGameTimer(3.0f);
		harpoon[0] = new Harpoon(position, velocity, renderer, "textures/Harpoon.png");

	}
	else
	{

		harpoon[currentHarpoon] = new Harpoon(position, velocity, renderer, "textures/Harpoon.png");

		isFired = true;
		reloadTimer = new InGameTimer(0.0f);
	}


}

void LevelTwo::spawnProjectile()
{
	Vec3 axes(0, 0, 1);
	Matrix4 rotation = MMath::rotate((float)boss1->angle, axes);
	Vec3 centerPos = Vec3(150.0f, 30.0f, 0.0f);
	Vec3 offset = rotation * centerPos;
	Vec3 bossCenter = boss1->pos + Vec3(boss1->body.w / 2, boss1->body.h / 2, 0.0f);
	Vec3 newPos = bossCenter - offset;


	Vec3 direction = Vec3(harry->pos.x + 25.0f - newPos.x, harry->pos.y + 25.0f - newPos.y, 0.0f);
	Vec3 velocity = VMath::normalize(direction) * 300.0f;
	projectile = new Projectile(SDL_Rect{ (int)newPos.x, (int)newPos.y, 25, 25 }, velocity, renderer, "textures/Bubble_1.png", 12.5f);

	isProjectileFired = true;
	projectileReloadTimer = new InGameTimer(4.5f);
}
