#include <glew.h>
#include <iostream>
#include "Debug.h"
#include "Scene5.h"
#include "DemoObject.h"
#include "ObjLoader.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "Debug.h"
#include "Camera.h"
#include "SkyBox.h"
#include "Noise.h"

Scene5::Scene5():sphere(nullptr), camera(nullptr)
, sphereMesh(nullptr), shader(nullptr), totalTime(0.0f){
	camera = new Camera();
	Debug::Info("Created Scene5: ", __FILE__, __LINE__);
}

Scene5::~Scene5() {
	delete camera;
}

bool Scene5::OnCreate() {

	noiseTextureID = CreateNoise3D();
	bool status = camera->getSkyBox()->loadSkyBox("textures/StarSkyboxPosx.png", "textures/StarSkyboxNegx.png",
		"textures/StarSkyboxPosy.png", "textures/StarSkyboxNegy.png",
		"textures/StarSkyboxPosz.png", "textures/StarSkyboxNegz.png");

	shader = new Shader("shaders/turbulenceVert.glsl", "shaders/turbulenceFrag.glsl");
	if (ObjLoader::loadOBJ("meshes/Sphere.obj") == false) {
		return false;
	}
	sphereMesh = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	sphere = new DemoObject(sphereMesh, shader, nullptr);
	sphere->setModelMatrix(MMath::scale(Vec3(2.0f, 2.0f, 2.0f)));
	return true;
}

void Scene5::HandleEvents(const SDL_Event &sdlEvent) {
	camera->HandleEvents(sdlEvent);
}

void Scene5::Update(const float deltaTime) {
	totalTime += deltaTime;
	offset.x += 0.001f;
	offset.y += 0.001f;
	offset.z -= 0.005f;
}

void Scene5::Render() const {
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
	//glUniform1f(sphere->getShader()->getUniformID("time"), totalTime);
	glUniform3fv(sphere->getShader()->getUniformID("offset"), 1, offset);
	glBindTexture(GL_TEXTURE_3D, noiseTextureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, camera->getSkyBox()->getSkyBoxTextureID());
	sphere->Render();
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
	glBindTexture(GL_TEXTURE_3D, 0);

	glUseProgram(0);
}


void Scene5::OnDestroy() {
	if (sphereMesh) delete sphereMesh, sphereMesh = nullptr;
	if (shader) delete shader, shader = nullptr;
	DeleteNoise3D();
}
