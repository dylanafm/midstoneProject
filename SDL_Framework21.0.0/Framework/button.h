#ifndef BUTTON_H
#define BUTTON_H


#include "MMath.h"
#include "Text.h"	
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_TTF.h"

using namespace MATH;


class button
{
private:
	SDL_Event event;
	
	const char* text;

	Vec3 colorBase;
	Vec3 colorHighlighted;
	Vec3 currentColor;
	SDL_Color textColor;


	SDL_Rect NewButton;
	
	Text buttonText;
public:
	
	button();
	button(int x, int y, int w, int h, Vec3 colorBase_, Vec3 colorHighlighted_, Vec3 textColor2, const char* text_);
	~button();
	

	bool buttonClicked(SDL_Event event);

	void Update();
	void Render(SDL_Renderer* renderer);





};

#endif