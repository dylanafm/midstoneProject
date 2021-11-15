#include "boss.h"

boss::boss(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path):
	Enemy(body_, scrollSpeed, renderer, path){
}

boss::~boss()
{
}
