#include "Fish.h"

Fish::Fish(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_):
	Enemy(body_, scrollSpeed, renderer, path, radius_){
}
Fish::~Fish()
{
}

