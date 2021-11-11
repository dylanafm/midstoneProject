#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "LevelOne.h"

class TextureManager
{

public:
	static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* renderer);
	static void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, SDL_Renderer* renderer);


};

#endif