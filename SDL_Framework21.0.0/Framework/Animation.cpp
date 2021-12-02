
#include "Animation.h"

Animation::Animation(SDL_Texture* animTex)
{
	SDL_QueryTexture(animTex, nullptr, nullptr, &imageW, &imageH);
	
	crop = SDL_Rect{ 0, 0, imageW, imageH };

	amountFrameX = 1;
	amountFrameY = 1;
	currentFrame = 1;

}

Animation::~Animation()
{


}
void Animation::SetUpAnim(int amountFrameX_, int amountFrameY_)
{

	amountFrameX = amountFrameX_;
	amountFrameY = amountFrameY_;

}

void Animation::PlayAnim(int beginFrame, int endFrame, int row, float frameSpeed)
{
	
	if (animDelay + frameSpeed < SDL_GetTicks()) {

		if (endFrame <= currentFrame)
		{
			currentFrame = beginFrame;
		}
		else {
			currentFrame++;
		}


		crop.x = currentFrame * imageW / amountFrameX;
		crop.y = row * (imageH / amountFrameY);
		crop.w = imageW / amountFrameX;
		crop.h = imageH / amountFrameY;

		animDelay = SDL_GetTicks();
	}
}



