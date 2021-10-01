#include <glew.h>
#include <iostream>
#include "Debug.h"
#include "Scene3.h"
#include "DemoObject.h"
#include "ObjLoader.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Debug.h"
#include "Camera.h"
#include "SkyBox.h"

Scene3::Scene3():meshPtr(nullptr),shaderPtr(nullptr), camera(nullptr) {
	camera = new Camera();
	Debug::Info("Created Scene3: ", __FILE__, __LINE__);
}

Scene3::~Scene3() {
	delete camera;
}

bool Scene3::OnCreate() {
	bool status = camera->getSkyBox()->loadSkyBox("textures/posx.jpg", "textures/negx.jpg",
		"textures/posy.jpg", "textures/negy.jpg",
		"textures/posz.jpg", "textures/negz.jpg");
	if (status == false) return false;
	/*camera->setSkyBox(new SkyBox("textures/posx.jpg", "textures/negx.jpg",
								 "textures/posy.jpg", "textures/negy.jpg",
								 "textures/posz.jpg", "textures/negz.jpg"));*/

	return true;
}

void Scene3::HandleEvents(const SDL_Event &sdlEvent) {
	camera->HandleEvents(sdlEvent);
}

void Scene3::Update(const float deltaTime) {
	camera->Update(deltaTime);
}

void Scene3::Render() const {
	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	/// Draw your scene here
	camera->Render();
	/// These pass the matricies and the light position to the GPU

	glUseProgram(0);
}


void Scene3::OnDestroy() {
	if (meshPtr) delete meshPtr, meshPtr = nullptr;
	if (shaderPtr) delete shaderPtr, shaderPtr = nullptr;
	//if (camera->getSkyBox()) delete camera->getSkyBox();
}
