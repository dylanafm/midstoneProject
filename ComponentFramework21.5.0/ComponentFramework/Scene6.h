#ifndef SCENE6_H
#define SCENE6_H
#include "Scene.h"
#include "Vector.h"

using namespace MATH;
#include "Particles.h"
/// Forward declarations 
union SDL_Event;
class Camera;
class Shader;

class Scene6 : public Scene {
private:
	Camera *camera;
	Shader *shader;
	Particles* particles;
	float totalTime;
public:
	explicit Scene6();
	virtual ~Scene6();

	virtual bool OnCreate() override;
	virtual void OnDestroy() override;
	virtual void Update(const float deltaTime) override;
	virtual void Render() const override;
	virtual void HandleEvents(const SDL_Event &sdlEvent) override;
};


#endif // SCENE4_H