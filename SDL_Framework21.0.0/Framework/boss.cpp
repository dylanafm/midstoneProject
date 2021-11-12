#include "boss.h"

boss::boss(SDL_Rect body_, SDL_Renderer* renderer, const char* path):
	Enemy(body_, renderer, path){
}

boss::~boss()
{
}
