#include "LevelOne.h"
#include "Physics.h"
#include <SDL.h>
#include "Timer.h"

LevelOne::LevelOne(SDL_Window* sdlWindow_) {

	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//a = new Animator(renderer);
	bg = new Background(renderer, 1, "textures/layers/1.png", 1, "textures/layers/2.png", 2, "textures/layers/3.png", 3, "textures/layers/4.png", 3, "textures/layers/5.png", 4, "textures/layers/6.png", 0, "textures/filler.png", 0, "textures/filler.png", 0.03f);
	SharkBoss = new Shark(SDL_Rect{ 2000, 360, 300, 200 }, 2.0f, renderer, "textures/SharkBoss.png", 100.0f);
	SharkBoss->health = 5;
	harry = new harpoonHarry(renderer, "textures/HarrySheet.png", 25.0f);
	harry->pos = Vec3(100.0f, 100.0f, 100.0f);
	

	bg->SetProgress(99.0f);


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

	fish[0] = new Fish(SDL_Rect{ 400, 200, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
	fish[1] = new Fish(SDL_Rect{ 800, 50, 50, 50 }, 2, renderer, "textures/blobfish.png", 25.0f);
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



	Shield = new ShieldPU(SDL_Rect{ 800, 40, 50, 50 }, 2, "textures/Shield.png", renderer);
	rf = new MGHarpoon(SDL_Rect{ 900, 500, 50, 50 }, 2, "textures/MGH.png", renderer);

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
	fMenu = new finishMenu(renderer);
	dMenu = new DeathMenu();

	if (!pMenu->setUpButtons(renderer)) return false;
	if (!dMenu->setUpButtons(renderer)) return false;
	if (!fMenu->setUpButtons(renderer)) return false;

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
			for (int i = 0; i < std::size(fish); i++) {
				if (fish[i] != nullptr) fish[i]->Scroll();
			}
			//if (SharkBoss != nullptr) SharkBoss->Scroll();
		}

		
		
	}
	harry->Update(deltaTime);
	for (int i = 0; i < std::size(harpoon); i++) {
		if (harpoon[i] != nullptr) harpoon[i]->Update(deltaTime);
		
		for (int ii = 0; ii < std::size(fish); ii++) {

			if (harpoon[i] != nullptr && fish[ii] != nullptr) {
				if (harpoon[i]->isCollided(fish[ii], harpoon[i])) {
					fishHurt->playSFX();
					harpoon[i] = nullptr;
					fish[ii] = nullptr;
					delete harpoon[i];
					delete fish[ii];

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
	if (SharkBoss != nullptr) {
		if (!isBitten) {
			if (harry->isCollided(harry, SharkBoss)) {
				playerHurt->playSFX();

				biteTimer = new InGameTimer(2.0f);
				isBitten = true;
			}
		}
	}

	if (projectile != nullptr) {
		projectile->Update(deltaTime);
		if (harry->isCollided(harry, projectile)) {
			if(!harry->Shielded) playerHurt->playSFX();
			delete projectile;
			projectile = nullptr;
		}
	}

	for (int i = 0; i < std::size(fish); i++) {

		if (fish[i] != nullptr) fish[i]->Update(deltaTime);
		if (SharkBoss != nullptr && bg->getProg() >= 90.0f) { 
			SharkBoss->Update(deltaTime, harry); 
			/*if(!isProjectileFired && SharkBoss->pos.x < 1200.0f)	spawnProjectile();*/
		}


		if (fish[i] != nullptr) {


			if (harry->isCollided(harry, fish[i])) {
				playerHurt->playSFX();

				delete fish[i];
				fish[i] = nullptr;
			}
		}



	}
	for (int i = 0; i < std::size(harpoon); i++) {
		if (harpoon[i] != nullptr && SharkBoss != nullptr) {
			if (harpoon[i]->isCollided(SharkBoss, harpoon[i])) {
				if (SharkBoss->health > 1) {
					bossHurt->playSFX();
					SharkBoss->health -= 1;
					harpoon[i] = nullptr;
					delete harpoon[i];
					//std::cout << SharkBoss->health << std::endl;
				}
				else {
					bossHurt->playSFX();

					harpoon[i] = nullptr;
					SharkBoss = nullptr;
					delete harpoon[i];
					delete SharkBoss;
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
		else if (SharkBoss != nullptr && paused) pMenu->pauseUpdate(event);
		if (SharkBoss == nullptr && paused) fMenu->finishUpdate(event);
	}
	harry->HandleEvents(event);
	if (SharkBoss == nullptr && !paused) paused = !paused;

	if (harry->health <= 0 && !paused) {
		playerDie->playSFX();
	}
	if (harry->health <= 0) {
		if (!paused) paused = true;
		newScene = dMenu->getScene();
		paused = dMenu->getPaused();
	}
	else if (SharkBoss != nullptr && paused) {
		newScene = pMenu->getScene();
		paused = pMenu->getPaused();
		if (!paused) pMenu->setDefault(); // Reset the Pause menu when Resume was pressed
	}
	if (SharkBoss == nullptr && paused) {
		newScene = fMenu->getScene();
		paused = fMenu->getPaused();
		if (!paused) fMenu->setDefault(); // Reset the Finish menu when Resume was pressed
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
		for (int i = 0; i < std::size(fish); i++) {
			if (fish[i] != nullptr) fish[i]->Move(deltaTime, 200);
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


	if (Shield != nullptr) Shield->Render(renderer);
	if (rf != nullptr) rf->Render(renderer);



	if (projectile != nullptr) projectile->Render(renderer);
	if (SharkBoss != nullptr) SharkBoss->UpdateHealthBar(renderer, SharkBoss->health);

	if (!paused) {
		if (SharkBoss != nullptr) SharkBoss->SharkSwim->PlayAnim(0, 2, 0, 175);

		harry->swim->PlayAnim(0, 7, 0, 175);
		
		playerHUD->displayHUD(renderer, 20, 10, 50, 50, harry, reloadTimer, bg);
	}
	if (SharkBoss != nullptr)
	SharkBoss->Render(renderer);
	for (int i = 0; i < std::size(harpoon); i++) {

		if (harpoon[i] != nullptr) harpoon[i]->render(renderer);
	}

	for (int i = 0; i < std::size(fish); i++) {
		if (fish[i] != nullptr) fish[i]->Render(renderer);
		if (fish[i] != nullptr && !paused) fish[i]->fishAnim->PlayAnim(0, 5, 0, 175);

	}
	
	if (harry->health <= 0) dMenu->deathRender(renderer);
	else if (SharkBoss != nullptr && paused) pMenu->pauseRender(renderer);
	if (SharkBoss == nullptr && paused) fMenu->finishRender(renderer);


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

void LevelOne::spawnProjectile()
{
	Vec3 axes(0, 0, 1);
	Matrix4 rotation = MMath::rotate((float)SharkBoss->angle, axes);
	Vec3 centerPos = Vec3(150.0f, 30.0f, 0.0f);
	Vec3 offset = rotation * centerPos;
	Vec3 bossCenter = SharkBoss->pos + Vec3(SharkBoss->body.w / 2, SharkBoss->body.h / 2, 0.0f);
	Vec3 newPos = bossCenter - offset;


	Vec3 direction = Vec3(harry->pos.x + 25.0f - newPos.x, harry->pos.y + 25.0f - newPos.y, 0.0f);
	Vec3 velocity = VMath::normalize(direction) * 300.0f;
	projectile = new Projectile(SDL_Rect{(int)newPos.x, (int)newPos.y, 25, 25 }, velocity, renderer, "textures/Bubble_1.png", 12.5f);
	
	isProjectileFired = true;
	projectileReloadTimer = new InGameTimer(4.5f);
}
