#version 460

in vec3 uvwCoords;
out vec4 fragColor;

uniform samplerCube skyboxTexture;

void main() { 
	fragColor = texture(skyboxTexture, uvwCoords);
}

