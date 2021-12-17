#include "TigerFish.h"
#include <iomanip>
TigerFish::TigerFish(SDL_Rect body_, float scrollSpeed, SDL_Renderer* renderer, const char* path, float radius_) :
	Enemy(body_, scrollSpeed, renderer, path, radius_){
	tigerFishAnim = new Animation(texture);
	tigerFishAnim->SetUpAnim(3, 1);
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
TigerFish::~TigerFish()
{
	delete tigerFishAnim;
}
void TigerFish::Render(SDL_Renderer* renderer)
{
	crop = tigerFishAnim->getCrop();

	SDL_RenderCopy(renderer, texture, &crop, &body);

}

void TigerFish::Move(float deltaTime_, float moveRange_)
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
