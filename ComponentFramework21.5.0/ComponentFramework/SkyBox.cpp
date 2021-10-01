#include "SkyBox.h"
#include "Mesh.h"
#include "ObjLoader.h"
#include "Shader.h"
#include <SDL_image.h>

SkyBox::SkyBox() : boxMesh(nullptr), shader(nullptr), skyboxTextureID(0) {}
SkyBox::~SkyBox() {
	OnDestroy();
}

bool SkyBox::loadSkyBox(const char* posX, const char* negX, const char* posY,
	const char* negY, const char* posZ, const char* negZ){
	glGenTextures(1, &skyboxTextureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxTextureID);

	SDL_Surface* textureSurface;
	int mode;

	textureSurface = IMG_Load(posX);
	if (textureSurface == nullptr) {
		return false;
	}
	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
	SDL_FreeSurface(textureSurface);

	textureSurface = IMG_Load(negX);
	if (textureSurface == nullptr) {
		return false;
	}
	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
	SDL_FreeSurface(textureSurface);

	textureSurface = IMG_Load(posY);
	if (textureSurface == nullptr) {
		return false;
	}
	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
	SDL_FreeSurface(textureSurface);

	textureSurface = IMG_Load(negY);
	if (textureSurface == nullptr) {
		return false;
	}
	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
	SDL_FreeSurface(textureSurface);

	textureSurface = IMG_Load(posZ);
	if (textureSurface == nullptr) {
		return false;
	}
	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
	SDL_FreeSurface(textureSurface);

	textureSurface = IMG_Load(negZ);
	if (textureSurface == nullptr) {
		return false;
	}
	mode = (textureSurface->format->BytesPerPixel == 4) ? GL_RGBA : GL_RGB;
	glTexImage2D(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, 0, mode, textureSurface->w, textureSurface->h, 0, mode, GL_UNSIGNED_BYTE, textureSurface->pixels);
	SDL_FreeSurface(textureSurface);

	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_2D, 0); /// Unbind the texture
	//glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	if (ObjLoader::loadOBJ("meshes/Cube.obj") == false) {
		return false;
	}
	boxMesh = new Mesh(GL_TRIANGLES, ObjLoader::vertices, ObjLoader::normals, ObjLoader::uvCoords);
	shader = new Shader("shaders/skyboxVert.glsl", "shaders/skyboxFrag.glsl");
	if (boxMesh == nullptr || shader == nullptr) return false;
	return true;
}

bool SkyBox::OnCreate() { 
	return true; 
}
void SkyBox::OnDestroy() {}
void SkyBox::Update(const float deltaTime) {}
void SkyBox::HandleEvents(const SDL_Event& event) {}
void SkyBox::Render() const {

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	glBindTexture(GL_TEXTURE_CUBE_MAP, skyboxTextureID);
	boxMesh->Render();
	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
}