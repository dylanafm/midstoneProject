#include "Camera.h"
#include "MMath.h"
#include "SkyBox.h"
#include "Shader.h"
#include "Mesh.h"
#include "Trackball.h"

using namespace MATH;

Camera::Camera() : skybox(nullptr), trackball(nullptr) {
	projectionMatrix = MMath::perspective(45.0f, (16.0f / 9.0f), 0.5f, 100.0f);
	viewMatrix = MMath::lookAt(Vec3(0.0f, 0.0f, 10.0f), Vec3(0.0f, 0.0f, 0.0f), Vec3(0.0f, 1.0f, 0.0f));
	skybox = new SkyBox();
	trackball = new Trackball();
}
Camera::~Camera() {
	delete skybox;
	delete trackball;
}
bool Camera::OnCreate() { return true; }
void Camera::OnDestroy() {}
void Camera::Update(const float deltaTime) {}
void Camera::HandleEvents(const SDL_Event& sdlEvent){
	trackball->HandleEvents(sdlEvent);
	skybox->HandleEvents(sdlEvent);
}
void Camera::Render() const{
	glUseProgram(skybox->getShader()->getProgram());
	glUniformMatrix4fv(skybox->getShader()->getUniformID("projectionMatrix"), 1, GL_FALSE, projectionMatrix);
	glUniformMatrix4fv(skybox->getShader()->getUniformID("cameraRotationMatrix"), 1, GL_FALSE, trackball->getMatrix4());
	skybox->Render();
	glUseProgram(0);
}
