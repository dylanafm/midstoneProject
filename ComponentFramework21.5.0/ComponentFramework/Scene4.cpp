#include <glew.h>
#include <iostream>
#include "Debug.h"
#include "Scene4.h"
#include "DemoObject.h"
#include "ObjLoader.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Debug.h"
#include "Camera.h"
#include "SkyBox.h"

Scene4::Scene4():sphere(nullptr), camera(nullptr)
, sphereMesh(nullptr), shader(nullptr){
	camera = new Camera();
	Debug::Info("Created Scene4: ", __FILE__, __LINE__);
}

Scene4::~Scene4() {
	delete camera;
}

bool Scene4::OnCreate() {
	bool status = camera->getSkyBox()->loadSkyBox("textures/posx.jpg", "textures/negx.jpg",
		"textures/posy.jpg", "textures/negy.jpg",
		"textures/posz.jpg", "textures/negz.jpg");

	shader = new Shader("shaders/reflectionVert.glsl", "shaders/reflectionFrag.glsl");
	if (ObjLoader::loadOBJ("meshes/Skull.obj") == false) {
		return false;
	}
	sphereMesh = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	sphere = new DemoObject(sphereMesh, shader, nullptr);
	return true;
}

void Scene4::HandleEvents(const SDL_Event &sdlEvent) {
	camera->HandleEvents(sdlEvent);
}

void Scene4::Update(const float deltaTime) {
	//camera->Update(deltaTime);
}

void Scene4::Render() const {
	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	/// Draw your scene here
	camera->Render();
	glUseProgram(sphere->getShader()->getProgram());
	glUniformMatrix4fv(sphere->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, camera->getProjectionMatrix());
	glUniformMatrix4fv(sphere->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE, camera->getViewMatrix() * camera->getTrackball()->getMatrix4());
	glBindTexture(GL_TEXTURE_CUBE_MAP, camera->getSkyBox()->getSkyBoxTextureID());
	sphere->Render();
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	glUseProgram(0);
}


void Scene4::OnDestroy() {
	if (sphereMesh) delete sphereMesh, sphereMesh = nullptr;
	if (shader) delete shader, shader = nullptr;
	//if (camera->getSkyBox()) delete camera->getSkyBox();
}
