#version 460
in  vec3 vertNormal;
in  vec3 vertDir;
out vec4 fragColor;

uniform samplerCube skyboxTexture;

void main() { 
	//Code for refraction mode
	//float ratio = 1.0 / 1.52;
	//vec3 refraction = refract(vertDir, vertNormal, ratio);

	vec3 reflection = reflect(vertDir, vertNormal);
	fragColor = texture(skyboxTexture, reflection);
} 

