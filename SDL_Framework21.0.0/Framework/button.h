#ifndef BUTTON_H
#define BUTTON_H


#include "MMath.h"
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_TTF.h"

using namespace MATH;


class button
{
private:

	SDL_Event event;

	Vec3 colorBase;
	Vec3 colorHighlighted;
	Vec3 currentColor;

	SDL_Rect NewButton;
	SDL_Renderer* renderer;
public:

	button(SDL_Rect NewButton_, Vec3 colorBase_, Vec3 colorHighlighted_);
	~button();
	

	bool buttonClicked(SDL_Event event);

	void Update(const float time);
	void Render(SDL_Window* sdlWindow_);





};

#endif