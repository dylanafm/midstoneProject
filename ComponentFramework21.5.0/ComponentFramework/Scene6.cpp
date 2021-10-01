#include <glew.h>
#include <iostream>
#include "Debug.h"
#include "Scene6.h"
#include "DemoObject.h"
#include "ObjLoader.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Debug.h"
#include "Camera.h"
#include "SkyBox.h"
#include "Noise.h"

Scene6::Scene6(): camera(nullptr),
shader(nullptr), totalTime(0.0f){
	camera = new Camera();
	Debug::Info("Created Scene6: ", __FILE__, __LINE__);
}

Scene6::~Scene6() {
	delete camera;
}

bool Scene6::OnCreate() {
	particles = new Particles();

	bool status = camera->getSkyBox()->loadSkyBox("textures/StarSkyboxPosx.png", "textures/StarSkyboxNegx.png",
		"textures/StarSkyboxPosy.png", "textures/StarSkyboxNegy.png",
		"textures/StarSkyboxPosz.png", "textures/StarSkyboxNegz.png");

	shader = new Shader("shaders/particlesVert.glsl", "shaders/particlesFrag.glsl");

	return true;
}

void Scene6::HandleEvents(const SDL_Event &sdlEvent) {
	camera->HandleEvents(sdlEvent);
}

void Scene6::Update(const float deltaTime) {
	totalTime += deltaTime;
}

void Scene6::Render() const {
	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	/// Draw your scene here
	//camera->Render();
	glUseProgram(shader->getProgram());
	glUniformMatrix4fv(shader->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
	glUniformMatrix4fv(shader->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix() * camera->getTrackball()->getMatrix4());
	glUniform1f(shader->getUniformID("totalTime"), totalTime);
	particles->Render();
	glUseProgram(0);
}


void Scene6::OnDestroy() {
	if (shader) delete shader, shader = nullptr;
	if (particles) delete particles, particles = nullptr;
}
