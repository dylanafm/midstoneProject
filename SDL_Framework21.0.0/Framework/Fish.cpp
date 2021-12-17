#include "Fish.h"
#include <iomanip>
Fish::Fish(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_) :
	Enemy(body_, scrollSpeed, renderer, path, radius_){
	fishAnim = new Animation(texture);
	fishAnim->SetUpAnim(8, 1);
	startingY = pos.y;
	moveDir = 1;
	moveSpeed = 100.0f;
	
	if (pos.y < 350)
	{
		directionUp = false;

	}
	else {
		directionUp = true;
	}
}
Fish::~Fish()
{
	delete fishAnim;
}
void Fish::Render(SDL_Renderer* renderer)
{
	crop = fishAnim->getCrop();

	SDL_RenderCopy(renderer, texture, &crop, &body);

}

void Fish::Move(float deltaTime_, float moveRange_)
{
	deltaTime = deltaTime_;
	moveRange = moveRange_;

	if (directionUp) {
		if (pos.y <= startingY - moveRange)
		{
			vel.y = vel.y + moveSpeed * deltaTime;
		}
		else
		{
			vel.y = vel.y - moveSpeed * deltaTime;

		}
	}
	else
	{
		if (pos.y >= startingY + moveRange )
		{
			vel.y = vel.y - moveSpeed * deltaTime;
		}
		else
		{
			vel.y = vel.y + moveSpeed * deltaTime;

		}
	}



}
