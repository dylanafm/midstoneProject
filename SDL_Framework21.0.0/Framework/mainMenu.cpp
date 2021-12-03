#include "Scene0.h"
#include "mainMenu.h"
#include "GameManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include "TextureManager.h"


mainMenu::mainMenu(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	creditScroll = 700;
	timer = new InGameTimer(3.0f);

	startTimer = true;

	Song = new musicPlayer("Music/mainmenutheme.mp3", 2);
	//Song->volume = 2;
	logoTex = TextureManager::LoadTexture("textures/HarryLogo.png", renderer);
	logoBox = SDL_Rect{ 430, 10, 400, 200 };

	tutorialIMG = TextureManager::LoadTexture("textures/TutorialPic.png", renderer);
	tutorialBox = SDL_Rect{ 100 , 50, 1100, 600 };


	slam = TextureManager::LoadTexture("textures/Slam.png", renderer);
	slamCred = TextureManager::LoadTexture("textures/Slam.png", renderer);

	creditBG = TextureManager::LoadTexture("textures/CreditsBG.jpg", renderer);

	Start = new button(470, 600, 300, 60, Vec3(20, 20, 210), "Continue");
	Levels = new button(490, 195, 300, 60, Vec3(20, 20, 210), "Levels");
	Settings = new button(440, 295, 400, 60, Vec3(20, 20, 210), "Settings");
	Tutorial = new button(440, 395, 400, 60, Vec3(20, 20, 210), "Tutorial");
	Quit = new button(540, 495, 200, 60, Vec3(20, 20, 210), "Quit");
	Credits = new button(1150, 650, 100, 60, Vec3(20, 20, 210), "Credits");
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
	Song->playSong();
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, 30.0f, 0.0f, 15.0f, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;

	if (!Start->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Levels->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Settings->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Tutorial->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Quit->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Back->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!LevelOne->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;
	if (!Credits->setImage("textures/blue_button01.png", "textures/green_button00.png", renderer)) return false;

	if (!setBackground()) return false;

	return true;
}

void mainMenu::OnDestroy() {
	SDL_DestroyRenderer(renderer);
}

void mainMenu::Update(const float deltaTime) {
	SDL_Event event;
	if (Song == nullptr) { cout << "Song is Null" << endl; }

	if (currentMenu == 0) {
		
		if (timer != nullptr && startTimer == true) timer->Update(deltaTime, startTimer);
		Start->Update();

	}
	if (currentMenu == 1) {
		Levels->Update();
		Settings->Update();
		Tutorial->Update();
		Quit->Update();
		Credits->Update();
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
	else if (currentMenu == 4) {
		Back->Update();
	}
	else {
		if (creditScroll > -700) { creditScroll -= 2; }		
		Back->Update();
	}

	while(SDL_PollEvent(&event))
	{

		if (Start->buttonClicked(event) && currentMenu == 0) { Start->click->playSFX(); currentMenu = 1; }
		if (LevelOne->buttonClicked(event) && currentMenu == 2) { LevelOne->click->playSFX(); newScene = 1; Song->stopSong(); }

		if (Levels->buttonClicked(event) && currentMenu == 1) {
			Levels->click->playSFX();
			currentMenu = 2; 
		}
		if (Settings->buttonClicked(event) && currentMenu == 1) { Settings->click->playSFX(); currentMenu = 3; }
		if (Tutorial->buttonClicked(event) && currentMenu == 1) { Tutorial->click->playSFX(); currentMenu = 4; }
		if (Credits->buttonClicked(event) && currentMenu == 1) { Credits->click->playSFX(); currentMenu = 5; creditScroll = 700; }
		if (Quit->buttonClicked(event) && currentMenu == 1) { Quit->click->playSFX(); newScene = -1; }

		if (Back->buttonClicked(event) && !currentMenu == 0 ) { Back->click->playSFX(); currentMenu = 1; }

		
	}

}

void mainMenu::Render() {

	//SDL_SetRenderDrawColor(renderer, 0, 120, 200, 0);
	SDL_RenderClear(renderer);
	if(currentMenu == 5) {
		SDL_RenderCopyEx(renderer, creditBG, nullptr, new SDL_Rect{ 0, 0, 1280, 720 }, 0.0, nullptr, SDL_FLIP_NONE);
	}
	else {
		SDL_RenderCopyEx(renderer, backgroundTexture, nullptr, new SDL_Rect{ 0, 0, 1280, 720 }, 0.0, nullptr, SDL_FLIP_NONE);


	}

	if (currentMenu == 0) {
		


		if (startTimer == false) {
			logoBox = SDL_Rect{ 175,50, 900, 500 };
			SDL_RenderCopy(renderer, logoTex, nullptr, &logoBox);
			Start->Render(renderer);
			slam = nullptr;
			slamText.writeText(" ", SDL_Color{ 0, 0, 0 }, SDL_Rect{ 300, 600, 800, 100 }, renderer);
		}
		else
		{
			logoBox = SDL_Rect{ 300 ,50, 700, 700 };
			SDL_RenderCopy(renderer, slam, nullptr, &logoBox);
			slamText.writeText("A Slam Productions Game", SDL_Color{ 0, 0, 0 }, SDL_Rect{ 300, 600, 800, 100 }, renderer);
			
		}


	}

	else if (currentMenu == 1) {
		
		logoBox = SDL_Rect{ 430, 10, 400, 200 };

		//Levels Button
		SDL_RenderCopy(renderer, logoTex, nullptr, &logoBox);

		Levels->Render(renderer);
		Settings->Render(renderer);
		Tutorial->Render(renderer);
		Quit->Render(renderer);
		Credits->Render(renderer);

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
	else if (currentMenu == 4) {
		SDL_RenderCopy(renderer, tutorialIMG, nullptr, &tutorialBox);
		Back->Render(renderer);

	}
	else
	{
		//cout << creditScroll << endl;
		Back->Render(renderer);
		creditText[1].writeText("Credits", SDL_Color{ 255, 255, 255 }, SDL_Rect{ 550, creditScroll, 250, 50 }, renderer);
		creditText[2].writeText("Slam Productions Team", SDL_Color{ 255, 255, 255 }, SDL_Rect{ 575, creditScroll + 100, 200, 40 }, renderer);
		creditText[3].writeText("Dylan Miller", SDL_Color{ 255, 255, 255 }, SDL_Rect{ 600, creditScroll + 200, 150, 30 }, renderer);
		creditText[4].writeText("Julien Eustasie", SDL_Color{ 255, 255, 255 }, SDL_Rect{ 600, creditScroll + 300, 150, 30 }, renderer);
		creditText[5].writeText("Kenneth Tumandao", SDL_Color{ 255, 255, 255 }, SDL_Rect{ 600, creditScroll + 400, 150, 30 }, renderer);
		creditText[6].writeText("Vladimir Ianuskin", SDL_Color{ 255, 255, 255 }, SDL_Rect{ 600, creditScroll + 500, 150, 30 }, renderer);
		creditText[7].writeText("Assets Used", SDL_Color{ 255, 255, 255 }, SDL_Rect{ 550, creditScroll + 600, 250, 40 }, renderer);

		creditText[8].writeText("Follow The Slam Productions Twitter! @SlamProdCA For Development Updates!", SDL_Color{ 255, 255, 255 }, SDL_Rect{ 300, creditScroll + 900, 800, 75 }, renderer);
		logoBox = SDL_Rect{ 476 , creditScroll + 990 , 485, 485 };
		SDL_RenderCopy(renderer, slamCred, nullptr, &logoBox);

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
