#ifndef CAMERA_H
#define CAMERA_H
#include "GameObject.h"
#include "Matrix.h"
#include "Trackball.h"
class SkyBox;
class Trackball;
using namespace MATH;
class Camera: public GameObject{
private:
	Matrix4 projectionMatrix;
	Matrix4 viewMatrix;
	SkyBox *skybox;
	Trackball *trackball;
public:
	Camera();
	~Camera();
	bool OnCreate() override;
	void OnDestroy() override;
	void Update(const float deltaTime) override;
	void HandleEvents(const SDL_Event& event) override;
	void Render() const override;
	Matrix4 getProjectionMatrix() { return projectionMatrix; }
	Matrix4 getViewMatrix() { return viewMatrix; }
	SkyBox* getSkyBox() { return skybox; }
	Trackball* getTrackball() { return trackball; }
	Matrix4 getTrackballMatrix4() { return trackball->getMatrix4(); }
};
#endif
