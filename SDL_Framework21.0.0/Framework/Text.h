#ifndef TEXT_H
#define TEXT_H

#include <SDL.h>
#include "SDL_TTF.h"

class Text {
private:
	TTF_Font* font;
	SDL_Surface* text;
	SDL_Texture* text_texture;
public:
	Text();
	~Text();

	void writeText(const char* message, SDL_Color color, SDL_Rect rect, SDL_Renderer* renderer);
};

#endif