#include "Scene2.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Randomizer.h"
#include "Ball.h"
Scene2::Scene2(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	printf("%s\n",SDL_GetError());
	Randomizer r;

	for (int i = 0; i < NUM_OBJECTS; i++) {
		gameObject[i] = new Ball(Vec3(0.0f, 2.2f, 0.0f),
			Vec3(5.0f, 0.0f, 0.0f),
			Vec3(0.0f, 0.0f, 0.0f), 1.0f);
	}
}

Scene2::~Scene2() {
	for (int i = 0; i < NUM_OBJECTS; ++i) {
		delete gameObject[i];
	}
}

bool Scene2::OnCreate() {
	int w, h;
	float xAxis = 30.0f;
	float yAxis = 15.0f;
	SDL_GetWindowSize(window, &w, &h);

	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, xAxis, 0.0f, yAxis, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;


	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* ballImage = IMG_Load("ball.png");
	SDL_Texture* ballTexture = SDL_CreateTextureFromSurface(renderer, ballImage);
	if (ballImage == nullptr) {
		std::cerr << "Can't open the image" << std::endl;
		return false;
	} else {
		Vec3 worldCoordsFromScreenCoords;
		worldCoordsFromScreenCoords.x = xAxis / static_cast<float>(w) * static_cast<float>(ballImage->w);
		worldCoordsFromScreenCoords.y = yAxis / static_cast<float>(h) * static_cast<float>(ballImage->h);
		for (int i = 0; i < NUM_OBJECTS; i++) {
			gameObject[i]->setTexture(ballTexture);
			gameObject[i]->setImageSizeWorldCoords(worldCoordsFromScreenCoords);
		}
		SDL_FreeSurface(ballImage);
	}
	return true;
}

void Scene2::OnDestroy() {
	/// We really need to deal with the textures better, they are left dangling right now
	SDL_DestroyRenderer(renderer);
}

void Scene2::Update(const float deltaTime) {
	for (int i = 0; i < NUM_OBJECTS; i = i + 1) {
		gameObject[i]->Update(deltaTime);
	}
}


void Scene2::HandleEvents(const SDL_Event& sdlEvent) {
	for (int i = 0; i < NUM_OBJECTS; ++i) {
		gameObject[i]->HandleEvents(sdlEvent);
	}
}



void Scene2::Render() {
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	SDL_Rect square;
	Vec3 screenCoords;
	int w, h;
	for (int i = 0; i < NUM_OBJECTS; i++) {
		SDL_QueryTexture(gameObject[i]->getTexture(), nullptr, nullptr, &w, &h);
		screenCoords = projectionMatrix * gameObject[i]->getPos();
		square.x = static_cast<int>(screenCoords.x);
		square.y = static_cast<int>(screenCoords.y);
		square.w = w;
		square.h = h;
		SDL_RenderCopyEx(renderer, gameObject[i]->getTexture(), nullptr, &square,
			gameObject[i]->getRotation(), nullptr, SDL_FLIP_NONE);

	}

	SDL_RenderPresent(renderer);
}