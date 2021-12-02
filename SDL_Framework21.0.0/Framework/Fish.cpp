#include "Fish.h"

Fish::Fish(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_):
	Enemy(body_, scrollSpeed, renderer, path, radius_){
	fishAnim = new Animation(texture);
	fishAnim->SetUpAnim(8, 1);
}
Fish::~Fish()
{
}
void Fish::Render(SDL_Renderer* renderer)
{
	crop = fishAnim->getCrop();

	SDL_RenderCopy(renderer, texture, &crop, &body);

}
