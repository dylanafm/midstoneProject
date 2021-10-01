#version 460
layout (location = 0) in  vec4 vVertex;
layout (location = 1) in  vec4 vNormal;

out vec3 vertNormal;
out vec3 vertDir; 

layout(location = 0) uniform mat4 projectionMatrix;
layout(location = 1) uniform mat4 viewMatrix;
layout(location = 2) uniform mat4 modelMatrix;
layout(location = 3) uniform mat3 normalMatrix;
uniform vec3 offset;
uniform sampler3D noiseTexture;

void main() {
	vertNormal = normalize(normalMatrix * vNormal.xyz); /// Rotate the normal to the correct orientation 
	vec3 vertPos = vec3(viewMatrix * modelMatrix * vVertex); /// This is the position of the vertex from the origin
	vertDir = normalize(vertPos);
	vec3 vertex = vec3(vVertex);
	vec4 noiseVec = texture(noiseTexture, (vertex * 0.05) + (0.01 * offset));
	gl_Position =  projectionMatrix * viewMatrix * modelMatrix * (vVertex + noiseVec);
}

