#include "Fish.h"

Fish::Fish(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path):
	Enemy(body_, scrollSpeed, renderer, path){
}
Fish::~Fish()
{
}

