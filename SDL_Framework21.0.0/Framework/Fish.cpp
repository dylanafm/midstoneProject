#include "Fish.h"

Fish::Fish(SDL_Rect body_, SDL_Renderer* renderer, const char* path):
	Enemy(body_, renderer, path){
}
Fish::~Fish()
{
}

