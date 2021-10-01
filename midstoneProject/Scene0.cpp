#include <glew.h>
#include <iostream>
#include "Debug.h"
#include "Scene0.h"
#include "DemoObject.h"
#include "ObjLoader.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"
#include "MMath.h"
#include "Debug.h"
#include "Physics.h"
#include "Trackball.h"
#include "Timer.h"

Scene0::Scene0(): earth(nullptr),meshPtr(nullptr),mars(nullptr),moon(nullptr),
					shaderPtr(nullptr),moonTexturePtr(nullptr),earthTexturePtr(nullptr),
					marsTexturePtr(nullptr) {
	trackball = new Trackball();
	Debug::Info("Created Scene0: ", __FILE__, __LINE__);
}

Scene0::~Scene0() {
	delete trackball;
}

bool Scene0::OnCreate() {
	Timer::SetSingleEvent(5000, (void*)"start");
	Timer::SetSingleEvent(10000, (void*)"middle");
	//Timer::SetSingleEvent(3000, (void*)"end");

	lightSource = Vec3(0.0f,0.0f,0.0f);
	projectionMatrix = MMath::perspective(45.0f, (16.0f / 9.0f), 0.5f, 100.0f);
	viewMatrix = MMath::lookAt(Vec3(0.0f, 0.0f, 10.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f));
	viewMatrix.print();

	if (ObjLoader::loadOBJ("meshes/Sphere.obj") == false) {
		return false;
	}
	meshPtr = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	shaderPtr = new Shader("shaders/texturePhongVert.glsl", "shaders/texturePhongFrag.glsl");
	earthTexturePtr = new Texture();
	moonTexturePtr = new Texture();
	marsTexturePtr = new Texture();
	if (meshPtr == nullptr|| shaderPtr == nullptr || earthTexturePtr == nullptr || moonTexturePtr == nullptr || marsTexturePtr == nullptr) {
		Debug::FatalError("Couldn't create game object assets", __FILE__, __LINE__);
		return false;
	}


	if (earthTexturePtr->LoadImage("textures/earthclouds.jpg") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}
	if (moonTexturePtr->LoadImage("textures/moon.jpg") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}
	if (marsTexturePtr->LoadImage("textures/mars.jpg") == false) {
		Debug::FatalError("Couldn't load texture", __FILE__, __LINE__);
		return false;
	}

	earth = new DemoObject(nullptr, meshPtr, shaderPtr, earthTexturePtr);
	if (earth == nullptr) {
		Debug::FatalError("GameObject could not be created", __FILE__, __LINE__);
		return false;
	}
	moon = new DemoObject(earth, meshPtr, shaderPtr, moonTexturePtr);
	if (moon == nullptr) {
		Debug::FatalError("GameObject could not be created", __FILE__, __LINE__);
		return false;
	}
	mars = new DemoObject(earth, meshPtr, shaderPtr, marsTexturePtr);
	if (mars == nullptr) {
		Debug::FatalError("GameObject could not be created", __FILE__, __LINE__);
		return false;
	}
	return true;
}

void Scene0::HandleEvents(const SDL_Event &sdlEvent) {
	trackball->HandleEvents(sdlEvent);
	if (sdlEvent.type == SDL_USEREVENT) {
		printf("%d: %s\n", sdlEvent.user.data1, sdlEvent.user.data2);
		if (sdlEvent.user.data1 == (void*)0) {
			earth->setAngularVel(15.0f);
		}else if (sdlEvent.user.data1 == (void*)1) {
			earth->setAngularVel(30.0f);
		}
	}
}

void Scene0::Update(const float deltaTime) {
	static float totalTime = 0.0f;
	totalTime += deltaTime;

	earth->Update(deltaTime);
	moon->Update(deltaTime);
	mars->Update(deltaTime);
	Physics::RigidBodyRotation(*earth, deltaTime);
	Physics::RigidBodyRotation(*moon, deltaTime);
	Physics::SimpleNewtonMotion(*earth, deltaTime);
	Physics::SimpleNewtonMotion(*moon, deltaTime);

	Matrix4 studioMaxFix = MMath::rotate(-90.0f, Vec3(1.0f, 0.0f, 0.0f));
	earth->setModelMatrix(MMath::rotate(earth->getAngle(), Vec3(0.0f, 1.0f, 0.0f)));
	moon->setModelMatrix(
		MMath::translate(5.0f, 0.0f, 0.0f) *
		MMath::rotate(moon->getAngle(), Vec3(0.0f, 1.0f, 0.0f)) *
							MMath::scale(0.25f, 0.25f, 0.25f) *
							studioMaxFix);
	mars->setModelMatrix(
		MMath::translate(-5.0f, 0.0f, 0.0f) *
		MMath::scale(0.7f, 0.7f, 0.7f) *
		studioMaxFix);

}

void Scene0::Render() const {
	/// Clear the screen
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	/// Draw your scene here
	GLuint program = earth->getShader()->getProgram();
	glUseProgram(program);

	//GLuint program
	/// These pass the matricies and the light position to the GPU
	glUniformMatrix4fv(earth->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, projectionMatrix);
	glUniformMatrix4fv(earth->getShader()->getUniformID("viewMatrix"), 1, GL_FALSE,viewMatrix);
	glUniform3fv(earth->getShader()->getUniformID("lightPos"), 1, lightSource);

	earth->Render();
	moon->Render();
	mars->Render();

	glUseProgram(0);
}


void Scene0::OnDestroy() {
	if (meshPtr) delete meshPtr, meshPtr = nullptr;
	if (earthTexturePtr) delete earthTexturePtr, earthTexturePtr = nullptr;
	if (moonTexturePtr) delete moonTexturePtr, moonTexturePtr = nullptr;
	if (marsTexturePtr) delete marsTexturePtr, marsTexturePtr = nullptr;
	if (shaderPtr) delete shaderPtr, shaderPtr = nullptr;
	if (earth) delete earth, earth = nullptr;
	if (moon) delete moon, moon = nullptr;
	if (mars) delete mars, mars = nullptr;
}
