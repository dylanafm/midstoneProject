#include "Scene4.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Randomizer.h"
#include <iostream>
#include "VMath.h"
using namespace MATH;

Scene4::Scene4(SDL_Window* sdlWindow_){
	Randomizer r;
	window = sdlWindow_;
	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
	
		gameObjects[0] = new Planet(Vec3(10.0f, 20.0f, 0.0f),
							    Vec3(4.0, -1.0f, 0.0f), 
								Vec3(0.0f, 0.0f, 0.0f), 1.0f);

		gameObjects[1] = new Star(Vec3(5.0f, 10.0f, 0.0f),
								Vec3(0.0, 0.0f, 0.0f),
								Vec3(0.0f, 0.0f, 0.0f), 100.0f);

		gameObjects[2] = new Star(Vec3(15.0f, 25.0f, 0.0f),
								Vec3(0.0, 0.0f, 0.0f),
								Vec3(0.0f, 0.0f, 0.0f), 150.0f);
	
}

Scene4::~Scene4(){
	for(int i = 0; i < NUM_OBJECTS; ++i){
		delete gameObjects[i];
	}
	SDL_DestroyRenderer(renderer);
}

bool Scene4::OnCreate() {
	int w, h;
	float xAxis = 25.0f;
	float yAxis = 40.0f;
	SDL_GetWindowSize(window,&w,&h);
	
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(0.0f, xAxis, 0.0f, yAxis, 0.0f, 1.0f);
	projectionMatrix = ndc * ortho;
	invProjectionMatrix = MMath::inverse(projectionMatrix);
	
	IMG_Init(IMG_INIT_PNG);
	SDL_Surface* saturnImage = IMG_Load("saturn.png");
	SDL_Texture* saturnTexture = SDL_CreateTextureFromSurface(renderer,saturnImage);
	if(saturnTexture == nullptr) printf("%s\n",SDL_GetError());
	if(saturnImage == nullptr){
		std::cerr << "Can't open the image" << std::endl;
		return false;
	} else {
		
		/// Do some tricks with the image coords
		Vec3 upperLeft(0.0f,0.0f,0.0f); 
		Vec3 lowerRight(static_cast<float>(saturnImage->w), static_cast<float>(saturnImage->h),0.0f);
		Vec3 ulWorld = invProjectionMatrix * upperLeft;
		Vec3 lrWorld = invProjectionMatrix * lowerRight;
		Vec3 worldCoordsFromScreenCoords = lrWorld - ulWorld;
		///float r = worldCoordsFromScreenCoords.x / 2.0f;
		
		gameObjects[1]->setTexture(saturnTexture);
		gameObjects[1]->setImageSizeWorldCoords(worldCoordsFromScreenCoords);
		gameObjects[2]->setTexture(saturnTexture);
		gameObjects[2]->setImageSizeWorldCoords(worldCoordsFromScreenCoords);
		SDL_FreeSurface(saturnImage);	
	}
	SDL_Surface* birdImage = IMG_Load("flappybird1.png");
	SDL_Texture* birdTexture = SDL_CreateTextureFromSurface(renderer, birdImage);
	if (birdTexture == nullptr) printf("%s\n", SDL_GetError());
	if (birdImage == nullptr) {
		std::cerr << "Can't open the image" << std::endl;
		return false;
	}
	else {

		/// Do some tricks with the image coords
		Vec3 upperLeft(0.0f, 0.0f, 0.0f);
		Vec3 lowerRight(static_cast<float>(birdImage->w), static_cast<float>(birdImage->h), 0.0f);
		Vec3 ulWorld = invProjectionMatrix * upperLeft;
		Vec3 lrWorld = invProjectionMatrix * lowerRight;
		Vec3 worldCoordsFromScreenCoords = lrWorld - ulWorld;
		///float r = worldCoordsFromScreenCoords.x / 2.0f;

		gameObjects[0]->setTexture(birdTexture);
		gameObjects[0]->setImageSizeWorldCoords(worldCoordsFromScreenCoords);
		SDL_FreeSurface(birdImage);
	}
	return true;
}

void Scene4::OnDestroy() {
	/// We really need to deal with the textures better, they are left dangling right now
	SDL_DestroyRenderer(renderer);
}

void Scene4::Update(const float deltaTime) {
	Vec3 f1 = gameObjects[1]->getPos() - gameObjects[0]->getPos(); // calculated the directions
	Vec3 f2 = gameObjects[2]->getPos() - gameObjects[0]->getPos();


	float fg1 = (gameObjects[1]->getMass() * gameObjects[0]->getMass()) / // calculated the forces of gravity
		(VMath::mag(f1) * VMath::mag(f1));
	float fg2 = (gameObjects[2]->getMass() * gameObjects[0]->getMass()) /
		(VMath::mag(f2) * VMath::mag(f2));


	f1 = VMath::normalize(f1);
	f2 = VMath::normalize(f2);


	f1 *= fg1;
	f2 *= fg2;

	//std::cout << "--------------\n";

	gameObjects[0]->ApplyForce(f1 + f2);
	gameObjects[0]->Update(deltaTime);
}


void Scene4::HandleEvents(const SDL_Event& sdlEvent){
	/*if (sdlEvent.type == SDL_MOUSEBUTTONDOWN && sdlEvent.button.button == SDL_BUTTON_LEFT) {
		Vec3 mouseCoords(static_cast<float>(sdlEvent.button.x), static_cast<float>(sdlEvent.button.y),0.0f);
		Vec3 worldCoords = invProjectionMatrix * mouseCoords;
		worldCoords.z = 0.0f;
		for (int i = 0; i < NUM_OBJECTS; ++i) {
			Vec3 pos = gameObjects[i]->getPos();
			float distance = VMath::distance(pos , worldCoords);
			float radius = gameObjects[i]->getRadius();
			if(distance < radius){
				printf("Gotcha saturn %d\n",i);
			}
		}
	}*/
}


void Scene4::Render() {
	SDL_SetRenderDrawColor(renderer, 0,0,0,0);
	SDL_RenderClear(renderer);
	SDL_Rect square;
	Vec3 screenCoords;
	int w,h;
	
	for(int i = 0; i < NUM_OBJECTS; ++i){
		SDL_QueryTexture(gameObjects[i]->getTexture(), nullptr, nullptr, &w, &h);
		screenCoords = projectionMatrix * gameObjects[i]->getPos();
		square.x = static_cast<int>(screenCoords.x) - w/2;
		square.y = static_cast<int>(screenCoords.y) - h/2;
		square.w = w;
		square.h = h;
		SDL_RenderCopyEx(renderer, gameObjects[i]->getTexture(),nullptr, &square, gameObjects[i]->getRotation(), nullptr, SDL_FLIP_NONE);
		
	}
	SDL_RenderPresent(renderer);
}