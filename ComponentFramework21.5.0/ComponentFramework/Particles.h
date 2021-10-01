#ifndef PARTICLES_H
#define PARTICLES_H
#include <glew.h>
#include <vector>
#include "Vector.h"
using namespace MATH;

class Particles
{
private:
	std::vector<Vec3> pos;
	std::vector<Vec3> vel;
	std::vector<Vec4> color;
	void setupParticles();
	GLuint vao;
	GLuint vbo;
public:
	Particles();
	~Particles();
	void Render() const;
};
#endif
