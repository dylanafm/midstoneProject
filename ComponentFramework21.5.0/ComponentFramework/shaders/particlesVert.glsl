#version 460
layout (location = 0) in  vec4 pos;
layout (location = 1) in  vec4 vel;
layout (location = 2) in  vec4 color;

out vec4 vertColor;

uniform mat4 projectionMatrix;
uniform mat4 viewMatrix;
uniform float totalTime;

//uniform mat4 modelMatrix;

void main() {
	vertColor = color;
	vec4 newPos = pos + (vel * totalTime);
	//newPos.y += -2.0f * totalTime * totalTime;
	gl_Position = projectionMatrix * viewMatrix * newPos;
	gl_PointSize = 10.0;
}
