#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "LevelOne.h"

class TextureManager
{
private:

	SDL_Texture* mTexture;
	int ImageW;
	int ImageH;

public:

	TextureManager();
	~TextureManager();
	bool loadFromFile(std::string path, SDL_Renderer* r);

	void free();
	static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);
	static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, SDL_Renderer* renderer);

	void render(SDL_Renderer* render, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip);

	int getWidth() { return ImageW; }
	int getHeight() { return ImageH; }
};

#endif