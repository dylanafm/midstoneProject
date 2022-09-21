#ifndef BUTTON_H
#define BUTTON_H


#include "MMath.h"
#include "Text.h"	
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_TTF.h"
#include "Sfx.h"

using namespace MATH;


class Button
{
private:
	const char* text;
	
	Vec3 colorBase;
	SDL_Color textColor;

	SDL_Texture* textureOriginal;
	SDL_Texture* textureHovered;
	SDL_Texture* texture;
	SDL_Rect buttonBox;
	SDL_Rect textBox;
public:
	Sfx* click;

	Button();
	Button(int x, int y, int w, int h, Vec3 textColor2, const char* text_);
	~Button();
	

	bool buttonClicked(SDL_Event event);
	bool setImage(const char* pathOriginal, const char* pathHovered, SDL_Renderer* renderer);

	void Update();
	void Render(SDL_Renderer* renderer);

	




};

#endif