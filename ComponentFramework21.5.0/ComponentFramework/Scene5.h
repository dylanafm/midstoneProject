#ifndef SCENE5_H
#define SCENE5_H
#include "Scene.h"
#include "Vector.h"

using namespace MATH;
/// Forward declarations 
union SDL_Event;
class DemoObject;
class Camera;
class Mesh;
class Shader;

class Scene5 : public Scene {
private:
	DemoObject *sphere;
	Camera *camera;
	Mesh *sphereMesh;
	Shader *shader;
	float totalTime;
	Vec3 offset;
	GLuint noiseTextureID;
public:
	explicit Scene5();
	virtual ~Scene5();

	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime) override;
	virtual void Render() const override;
	virtual void HandleEvents(const SDL_Event &sdlEvent) override;
};


#endif // SCENE4_H