#ifndef ANIMATION_H
#define ANIMATION_H
#include "LevelOne.h"


class Animation
{
public:
	Animation(SDL_Texture* animTex);
	~Animation();


	void PlayAnim(int beginFrame, int endFrame, int row, float frameSpeed);

	void SetUpAnim(int amountFrameX_, int amountFrameY_);

	SDL_Rect getCrop() { return crop; }
private:


	int currentFrame, animDelay, amountFrameX, amountFrameY, imageW, imageH;

	SDL_Rect crop;


};
#endif // !ANIMATION_H
