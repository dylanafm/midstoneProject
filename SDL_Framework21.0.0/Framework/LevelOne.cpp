#include "LevelOne.h"
#include "Physics.h"
#include <SDL.h>
#include "Timer.h"

LevelOne::LevelOne(SDL_Window* sdlWindow_) {

	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//a = new Animator(renderer);
	bg = new Background(renderer);
	boss1 = new boss(SDL_Rect{ 1280, 360, 300, 200 }, 1, renderer, "textures/bossAnim.png", 100.0f);
	boss1->health = 5;
	harry = new harpoonHarry(renderer, "textures/HarrySheet.png", 25.0f);
	harry->pos = Vec3(100.0f, 100.0f, 100.0f);
	
	playerHUD = new HUD();

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

	fish[0] = new Fish(SDL_Rect{ 400, 200, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[1] = new Fish(SDL_Rect{ 800, 400, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[2] = new Fish(SDL_Rect{ 1200, 600, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[3] = new Fish(SDL_Rect{ 1600, 300, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[4] = new Fish(SDL_Rect{ 2000, 100, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[5] = new Fish(SDL_Rect{ 2400, 500, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[6] = new Fish(SDL_Rect{ 2800, 200, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[7] = new Fish(SDL_Rect{ 3200, 600, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[8] = new Fish(SDL_Rect{ 3600, 300, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[9] = new Fish(SDL_Rect{ 4000, 640, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[10] = new Fish(SDL_Rect{ 4400, 220, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[11] = new Fish(SDL_Rect{ 4800, 115, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[12] = new Fish(SDL_Rect{ 5200, 450, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[13] = new Fish(SDL_Rect{ 5600, 500, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[14] = new Fish(SDL_Rect{ 6000, 630, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[15] = new Fish(SDL_Rect{ 6400, 200, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[16] = new Fish(SDL_Rect{ 6800, 340, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[17] = new Fish(SDL_Rect{ 7200, 112, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[18] = new Fish(SDL_Rect{ 7600, 400, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[19] = new Fish(SDL_Rect{ 8000, 320, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);

	harpoonShoot = new sfx("SFX/shoot.ogg", 10);
	fishHurt = new sfx("SFX/blobdeath.wav", 10);
	playerHurt = new sfx("SFX/pain.wav", 10);
	playerDie = new sfx("SFX/die.wav", 10);
	bossHurt = new sfx("SFX/bossdeath.wav", 10);
	healthsfx = new sfx("SFX/life_pickup.flac", 10);



	

	
	
}

LevelOne::~LevelOne() {
	delete window;
	delete harry;
	delete renderer;
}

bool LevelOne::OnCreate() {
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

void LevelOne::OnDestroy() {
	SDL_DestroyRenderer(renderer);
}

void LevelOne::Update(const float deltaTime) {
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
	if (!paused) {
		if (bg->getProg() <= 100.0f) {
			bg->Scroll();
			for (int i = 0; i < std::size(hp); i++) {
				if (hp[i] != nullptr) hp[i]->scroll();
			}
			for (int i = 0; i < std::size(fish); i++) {
				if (fish[i] != nullptr) fish[i]->Scroll();
			}
			//if (boss1 != nullptr) boss1->Scroll();
		}

		
		
	}
	harry->Update(deltaTime);

	if (harpoon != nullptr) harpoon->Update(deltaTime);
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
			playerHurt->playSFX();
			delete projectile;
			projectile = nullptr;
		}
	}

	for (int i = 0; i < std::size(fish); i++) {

		if (fish[i] != nullptr) fish[i]->Update(deltaTime);
		if (boss1 != nullptr && bg->getProg() >= 100.0f) { 
			boss1->Update(deltaTime, harry); 
			//if(!isProjectileFired)	spawnProjectile();
		}


		if (fish[i] != nullptr) {


			if (harry->isCollided(harry, fish[i])) {
				playerHurt->playSFX();

				delete fish[i];
				fish[i] = nullptr;
			}
		}

		if (harpoon != nullptr && fish[i] != nullptr) {
			if (harpoon->isCollided(fish[i], harpoon)) {
				fishHurt->playSFX();
				harpoon = nullptr;
				fish[i] = nullptr;
				delete harpoon;
				delete fish[i];

			}
		}

	}
	
	if (harpoon != nullptr && boss1 != nullptr) {
		if (harpoon->isCollided(boss1, harpoon)) {
			if (boss1->health > 1) {
				bossHurt->playSFX();
				boss1->health -= 1;
				harpoon = nullptr;
				delete harpoon;
				//std::cout << boss1->health << std::endl;
			}
			else {
				bossHurt->playSFX();

				harpoon = nullptr;
				boss1 = nullptr;
				delete harpoon;
				delete boss1;
			}
		}
	}

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_KEYDOWN && event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
			paused = !paused;
		}
		if (event.button.button == SDL_BUTTON_LEFT && event.type == SDL_MOUSEBUTTONDOWN && !isFired && !paused) {
			spawnHarpoon();
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

	if (harpoon != nullptr) {
		if (harpoon->pos.x < -50.0f || harpoon->pos.x > 1300.0f || harpoon->pos.y < -50.0f || harpoon->pos.y > 800.0f) {
			delete harpoon;
			harpoon = nullptr;
		}
	}
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

}

void LevelOne::Render() {

	SDL_RenderClear(renderer);
	bg->Render(renderer);
	for (int i = 0; i < std::size(hp); i++) {
		if (hp[i] != nullptr) hp[i]->render(renderer);
	}
	//a->Render(renderer);
	harry->render(renderer);
	if (projectile != nullptr) projectile->Render(renderer);
	if (boss1 != nullptr) boss1->UpdateHealthBar(renderer, boss1->health);

	if (!paused) {
		if (boss1 != nullptr) boss1->swim->PlayAnim(0, 1, 0, 175);

		harry->swim->PlayAnim(0, 7, 0, 175);
		
		playerHUD->displayHUD(renderer, 20, 10, 50, 50, harry, reloadTimer, bg);
	}
	if (boss1 != nullptr)
	boss1->Render(renderer);
	if (harpoon != nullptr) harpoon->render(renderer);


	for (int i = 0; i < std::size(fish); i++) {
		if (fish[i] != nullptr) fish[i]->Render(renderer);
		if (fish[i] != nullptr && !paused) fish[i]->fishAnim->PlayAnim(0, 5, 0, 175);

	}
	
	if (harry->health <= 0) dMenu->deathRender(renderer);
	else if (paused) pMenu->pauseRender(renderer);


	SDL_RenderPresent(renderer);

}

void LevelOne::spawnHarpoon()
{
	int x, y;
	Uint32 buttons;
	buttons = SDL_GetMouseState(&x, &y);
	float xf = static_cast<float>(x);
	float yf = static_cast<float>(y);

	Vec3 position = Vec3(harry->pos.x + 10.0f, harry->pos.y + 19.75f, 0.0f);
	Vec3 direction = Vec3(xf - position.x - 15.0f, yf - position.y - 5.25f, 0.0f);
	Vec3 velocity = VMath::normalize(direction) * 420.0f;
	harpoon = new Harpoon(position, velocity, renderer, "textures/Harpoon.png");
	harpoonShoot->playSFX();

	isFired = true;
	reloadTimer = new InGameTimer(3.0f);
}

void LevelOne::spawnProjectile()
{
	Vec3 axes(0, 0, 1);
	std::cout << boss1->angle << std::endl;
	Matrix4 temp = MMath::rotate((float)boss1->angle, axes);
	Vec3 TranslationVector = - boss1->pos + Vec3(boss1->body.w / 2, boss1->body.h / 2, 0.0f);
	Vec3 rotatedPoint = temp * TranslationVector;
	Vec3 newPos = boss1->pos - rotatedPoint;

	Vec3 direction = Vec3(harry->pos.x + 25.0f - newPos.x, harry->pos.y + 25.0f - newPos.y, 0.0f);
	Vec3 velocity = VMath::normalize(direction) * 300.0f;
	projectile = new Projectile(SDL_Rect{(int)newPos.x, (int)newPos.y, 25, 25 }, velocity, renderer, "textures/Bubble_1.png", 12.5f);
	
	isProjectileFired = true;
	projectileReloadTimer = new InGameTimer(4.5f);
}
