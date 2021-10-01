#include "Scene1.h"
#include <SDL.h>
#include <SDL_image.h>
Scene1::Scene1(SDL_Window* sdlWindow_) {
	window = sdlWindow_;
	bird = new Body(Vec3(0.0f, 15.0f, 0.0f), Vec3(4.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 1.0f);
	cliff = new Body(Vec3(0.0f, 15.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 0.0f, 0.0f), 0.0f);
}

Scene1::~Scene1() {
	delete bird;
	delete cliff;
}

bool Scene1::OnCreate() {
	int w, h;
	float xAxis = 30.0f;
	float yAxis = 15.0f;
	SDL_GetWindowSize(window, &w, &h);

	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, xAxis, 0.0f, yAxis, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;


	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* birdImage = IMG_Load("flappybird1.png");
	SDL_Surface* cliffImage = IMG_Load("cliff.png");
	if (birdImage == nullptr || cliffImage == nullptr) {
		std::cerr << "Can't open the image" << std::endl;
		return false;
	} else {
		bird->setImage(birdImage);
		cliff->setImage(cliffImage);
		Vec3 worldCoordsFromScreenCoords;
		worldCoordsFromScreenCoords.x = xAxis / static_cast<float>(w) * static_cast<float>(birdImage->w);
		worldCoordsFromScreenCoords.y = yAxis / static_cast<float>(h) * static_cast<float>(birdImage->h);
		bird->setImageSizeWorldCoords(worldCoordsFromScreenCoords);

		worldCoordsFromScreenCoords.x = xAxis / static_cast<float>(w) * static_cast<float>(cliffImage->w);
		worldCoordsFromScreenCoords.y = yAxis / static_cast<float>(h) * static_cast<float>(cliffImage->h);
		cliff->setImageSizeWorldCoords(worldCoordsFromScreenCoords);
	}
	return true;
}

void Scene1::OnDestroy() {
	/// Yes, there is a memory leak caused by IMG_Load(...),
	///  but Im not ready to deal with it right now. 
}

void Scene1::Update(const float deltaTime) {
	bird->ApplyForce(Vec3(0.0f, -9.8f, 0.0f));
	bird->Update(deltaTime);
	///cliff->Update(deltaTime); /// the cliff doesn't move don't bother 
}

void Scene1::HandleEvents(const SDL_Event& sdlEvent){

}
void Scene1::Render() {
	SDL_Rect square;
	Vec3 screenCoords;
	SDL_Surface* screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0, 0, 0));

	screenCoords = projectionMatrix * cliff->getPos();
	square.x = static_cast<int>(screenCoords.x);
	square.y = static_cast<int>(screenCoords.y);
	square.w = cliff->getImage()->w;
	square.h = cliff->getImage()->h;
	SDL_BlitSurface(cliff->getImage(), nullptr, screenSurface, &square);

	screenCoords = projectionMatrix * bird->getPos();
	square.x = static_cast<int>(screenCoords.x);
	square.y = static_cast<int>(screenCoords.y);
	square.w = bird->getImage()->w;
	square.h = bird->getImage()->h;
	SDL_BlitSurface(bird->getImage(), nullptr, screenSurface, &square);

	SDL_UpdateWindowSurface(window);
}