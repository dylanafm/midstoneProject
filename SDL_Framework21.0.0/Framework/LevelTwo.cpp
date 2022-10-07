#include "LevelTwo.h"
#include "Physics.h"
#include <SDL.h>
#include "Timer.h"

LevelTwo::LevelTwo(SDL_Window* sdlWindow_) {

	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	//a = new Animator(renderer);
	bg = new Background(renderer, 1, "textures/layers2/1.png", 1, "textures/layers2/2.png", 2, "textures/layers2/3.png", 3, "textures/layers2/4.png", 1, "textures/layers2/5.png", 4, "textures/layers2/6.png", 4, "textures/layers2/7.png", 4, "textures/layers2/8.png", 0.030f);

	bg->SetProgress(0.0f);



	boss1 = new Boss(SDL_Rect{ 1400, 360, 300, 200 }, 1, renderer, "textures/bossAnim.png", 100.0f);
	boss1->health = 5;
	harry = new HarpoonHarry(renderer, "textures/HarrySheet.png", 25.0f);
	harry->pos = Vec3(100.0f, 100.0f, 100.0f);

	playerHUD = new HUD();
	currentHarpoon = 0;
	song = new MusicPlayer("Music/levelonetheme.ogg", 2);

	hp[0] = new HealthPickup(SDL_Rect{ 2500, rand() % 680, 50, 50 }, renderer);
	hp[1] = new HealthPickup(SDL_Rect{ 4100, rand() % 680, 50, 50 }, renderer);
	hp[2] = new HealthPickup(SDL_Rect{ 5800, rand() % 680, 50, 50 }, renderer);
	hp[3] = new HealthPickup(SDL_Rect{ 6500, rand() % 680, 50, 50 }, renderer);

	tigerFish[0] = new Fish(SDL_Rect{ 400, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[1] = new Fish(SDL_Rect{ 800, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[2] = new Fish(SDL_Rect{ 1200, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[3] = new Fish(SDL_Rect{ 1600, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[4] = new Fish(SDL_Rect{ 1600, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[5] = new Fish(SDL_Rect{ 1800, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[6] = new Fish(SDL_Rect{ 1800, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[7] = new Fish(SDL_Rect{ 2000, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[8] = new Fish(SDL_Rect{ 2000, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);

	tigerFish[9] = new Fish(SDL_Rect{ 3000, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[10] = new Fish(SDL_Rect{ 3000, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[11] = new Fish(SDL_Rect{ 3100, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[12] = new Fish(SDL_Rect{ 3100, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[13] = new Fish(SDL_Rect{ 3200, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[14] = new Fish(SDL_Rect{ 3200, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[15] = new Fish(SDL_Rect{ 3200, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[16] = new Fish(SDL_Rect{ 3300, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[17] = new Fish(SDL_Rect{ 3300, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[18] = new Fish(SDL_Rect{ 3400, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[19] = new Fish(SDL_Rect{ 3400, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[20] = new Fish(SDL_Rect{ 3500, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[21] = new Fish(SDL_Rect{ 3500, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[22] = new Fish(SDL_Rect{ 3500, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[23] = new Fish(SDL_Rect{ 3500, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[24] = new Fish(SDL_Rect{ 3600, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[25] = new Fish(SDL_Rect{ 3600, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[26] = new Fish(SDL_Rect{ 3700, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[27] = new Fish(SDL_Rect{ 3800, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[28] = new Fish(SDL_Rect{ 3900, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[29] = new Fish(SDL_Rect{ 4000, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[30] = new Fish(SDL_Rect{ 4000, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[31] = new Fish(SDL_Rect{ 4000, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[32] = new Fish(SDL_Rect{ 4000, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[33] = new Fish(SDL_Rect{ 4300, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[34] = new Fish(SDL_Rect{ 4300, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[35] = new Fish(SDL_Rect{ 4300, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[36] = new Fish(SDL_Rect{ 4400, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[37] = new Fish(SDL_Rect{ 4400, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[38] = new Fish(SDL_Rect{ 4400, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[39] = new Fish(SDL_Rect{ 4500, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[40] = new Fish(SDL_Rect{ 4500, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[41] = new Fish(SDL_Rect{ 4600, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[42] = new Fish(SDL_Rect{ 4600, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[43] = new Fish(SDL_Rect{ 4700, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);

	tigerFish[44] = new Fish(SDL_Rect{ 5600, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[45] = new Fish(SDL_Rect{ 5600, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[46] = new Fish(SDL_Rect{ 5700, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[47] = new Fish(SDL_Rect{ 5700, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[48] = new Fish(SDL_Rect{ 5700, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[49] = new Fish(SDL_Rect{ 5800, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[50] = new Fish(SDL_Rect{ 5800, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[51] = new Fish(SDL_Rect{ 5800, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[52] = new Fish(SDL_Rect{ 5900, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[53] = new Fish(SDL_Rect{ 5900, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[54] = new Fish(SDL_Rect{ 5900, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[55] = new Fish(SDL_Rect{ 6000, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[56] = new Fish(SDL_Rect{ 6000, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[57] = new Fish(SDL_Rect{ 6100, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[58] = new Fish(SDL_Rect{ 6100, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[59] = new Fish(SDL_Rect{ 6100, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[60] = new Fish(SDL_Rect{ 6100, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[61] = new Fish(SDL_Rect{ 6200, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[62] = new Fish(SDL_Rect{ 6200, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[63] = new Fish(SDL_Rect{ 6300, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[64] = new Fish(SDL_Rect{ 6300, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[65] = new Fish(SDL_Rect{ 6300, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[66] = new Fish(SDL_Rect{ 6400, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[67] = new Fish(SDL_Rect{ 6400, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[68] = new Fish(SDL_Rect{ 6500, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	tigerFish[69] = new Fish(SDL_Rect{ 6500, rand() % 680, 50, 50 }, 2, renderer, "textures/TigerFish.png", 25.0f, 3);
	
	Shield = new ShieldPU(SDL_Rect{ 4400, rand() % 680, 50, 50 }, renderer);
	rf = new MGHarpoon(SDL_Rect{ 6100, rand() % 680, 50, 50 }, renderer);

	harpoonShoot = new Sfx("SFX/shoot.ogg", 10);
	fishHurt = new Sfx("SFX/blobdeath.wav", 10);
	playerHurt = new Sfx("SFX/pain.wav", 10);
	playerDie = new Sfx("SFX/die.wav", 10);
	bossHurt = new Sfx("SFX/bossdeath.wav", 10);

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

	pMenu = new PauseMenu(renderer, 3);
	dMenu = new DeathMenu(3);
	fMenu = new FinishMenu(renderer);

	if (!pMenu->setUpButtons(renderer)) return false;
	if (!dMenu->setUpButtons(renderer)) return false;
	if (!fMenu->setUpButtons(renderer)) return false;

	fMenu->GameWin = true;
	return true;
}

void LevelTwo::OnDestroy() {
	SDL_DestroyRenderer(renderer);
	if (song != nullptr) delete song;
	if (Shield != nullptr) delete Shield;
	if (rf != nullptr) delete rf;
	if (playerHUD != nullptr) delete playerHUD;
	if (bg != nullptr) delete bg;
	if (harry != nullptr) delete harry;
	if (boss1 != nullptr) delete boss1;
	if (dMenu != nullptr) delete dMenu;
	if (pMenu != nullptr) delete pMenu;
	if (fMenu != nullptr) delete fMenu;
	if (reloadTimer != nullptr) delete reloadTimer;
	if (biteTimer != nullptr) delete biteTimer;
	if (harpoonShoot != nullptr) delete harpoonShoot;
	if (fishHurt != nullptr) delete fishHurt;
	if (playerHurt != nullptr) delete playerHurt;
	if (playerDie != nullptr) delete playerDie;
	if (bossHurt != nullptr) delete bossHurt;
	for (int i = 0; i < std::size(hp); i++)
		if (hp[i] != nullptr) delete hp[i];
	for (int i = 0; i < std::size(tigerFish); i++)
		if (tigerFish[i] != nullptr) delete tigerFish[i];
	for (int i = 0; i < std::size(harpoon); i++)
		if (harpoon[i] != nullptr) delete harpoon[i];
	if (map != nullptr) delete map;
	//if (projectionMatrix != nullptr) delete projectionMatrix;
}

void LevelTwo::Update(const float deltaTime) {
	SDL_Event event;
	// Update powerups
	for (int i = 0; i < std::size(hp); i++) {
		if (hp[i] != nullptr && hp[i]->isActive) {
			hp[i]->Update(deltaTime);
			harry->isPowerupCollided(harry, hp[i]);
		}
	}

	if (Shield != nullptr && Shield->isActive) {
		Shield->Update(deltaTime);
		harry->isPowerupCollided(harry, Shield);
	}

	if (rf != nullptr && rf->isActive) {
		rf->Update(deltaTime);
		harry->isPowerupCollided(harry, rf);
	}

	// Delete powerups that are outside the screen
	for (int i = 0; i < std::size(hp); i++) {
		if (hp[i] != nullptr) {
			if (hp[i]->pos.x < 0) {
				delete hp[i];
				hp[i] = nullptr;
			}
		}
	}

	if (Shield != nullptr) {
		if (Shield->pos.x < 0) {
			delete Shield;
			Shield = nullptr;
		}
	}

	if (rf != nullptr) {
		if (rf->pos.x < 0) {
			delete rf;
			rf = nullptr;
		}
	}

	// Pause Menu
	if (!paused) {
		if (bg->getProg() <= 100.0f) {
			if (Shield != nullptr)  Shield->Scroll();
			if (rf != nullptr)  rf->Scroll();

			bg->Scroll();
			for (int i = 0; i < std::size(hp); i++) {
				if (hp[i] != nullptr) hp[i]->Scroll();
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
			if (harry->isEnemyCollided(harry, boss1)) {
				playerHurt->playSFX();

				biteTimer = new InGameTimer(2.0f);
				isBitten = true;
			}
		}
	}

	if (boss1 != nullptr && bg->getProg() >= 99.0f) {
		boss1->Update(deltaTime, harry, renderer);
	}

	for (int i = 0; i < std::size(tigerFish); i++) {

		if (tigerFish[i] != nullptr) tigerFish[i]->Update(deltaTime);


		if (tigerFish[i] != nullptr) {


			if (harry->isEnemyCollided(harry, tigerFish[i])) {
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
		else if (boss1 != nullptr && paused) pMenu->pauseUpdate(event);
		if (boss1 == nullptr && paused) fMenu->finishUpdate(event);
	}
	harry->HandleEvents(event);
	if (boss1 == nullptr && !paused) paused = !paused;

	if (harry->health <= 0 && !paused) {
		playerDie->playSFX();
	}

	if (harry->health <= 0) {
		if (!paused) paused = true;
		newScene = dMenu->getScene();
		paused = dMenu->getPaused();
	}
	else if (boss1 != nullptr && paused) {
		newScene = pMenu->getScene();
		paused = pMenu->getPaused();
		if (!paused) pMenu->setDefault(); // Reset the Pause menu when Resume was pressed
	}
	if (boss1 == nullptr && paused) {
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
		if (hp[i] != nullptr) hp[i]->Render(renderer);
	}
	//a->Render(renderer);
	harry->render(renderer);


	if (Shield != nullptr) Shield->Render(renderer);
	if (rf != nullptr) rf->Render(renderer);



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
		if (tigerFish[i] != nullptr && !paused) tigerFish[i]->fishAnim->PlayAnim(0, 2, 0, 175);

	}

	if (harry->health <= 0) dMenu->deathRender(renderer);
	else if (boss1 != nullptr && paused) pMenu->pauseRender(renderer);
	if (boss1 == nullptr && paused) fMenu->finishRender(renderer);

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

