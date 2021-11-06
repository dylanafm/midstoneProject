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
	const char* text;

	Vec3 colorBase;
	SDL_Color textColor;

	SDL_Texture* texture;
	SDL_Rect buttonBox;
	SDL_Rect textBox;

public:
	
	button();
	button(int x, int y, int w, int h, Vec3 textColor2, const char* text_);
	~button();
	

	bool buttonClicked(SDL_Event event);
	bool setImage(const char* path, SDL_Renderer* renderer);

	void Update();
	void Render(SDL_Renderer* renderer);





};

#endif