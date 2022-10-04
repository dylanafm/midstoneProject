#include "Fish.h"
#include <iomanip>

Fish::Fish(SDL_Rect body_, float scrollSpeed_, SDL_Renderer* renderer, const char* path, float radius_, int frames) :
	Enemy(body_, renderer, path, radius_)
{
	scrollSpeed = scrollSpeed_;
	fishAnim = new Animation(texture);
	fishAnim->SetUpAnim(frames, 1);

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

void Fish::Scroll()
{
	pos.x = pos.x - scrollSpeed;
}