#version 460
in  vec3 vertDir;
out vec4 fragColor;
uniform sampler3D noiseTexture;
uniform vec3 offset;

void main() { 
	vec4 color1 = vec4(0.8, 0.7, 0.0, 0.0);
	vec4 color2 = vec4(0.6, 0.1, 0.0, 0.0);

	vec4 noisevec = texture(noiseTexture, (vertDir * 5) + offset);

	float intensity = abs(noisevec[0] - 0.25) +
			     abs(noisevec[1] - 0.125) + 
			     abs(noisevec[2] - 0.0625) + 
			     abs(noisevec[3] - 0.03125);
	
	intensity = clamp(intensity * 2.0, 0.0, 1.0);
	gl_FragColor = mix(color1, color2, intensity);
} 

