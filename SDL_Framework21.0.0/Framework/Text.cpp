#include "Text.h"
#include <iostream>

Text::Text()
{
	text = nullptr;
	text_texture = nullptr;

	//TTF Initialization

	if (TTF_Init() < 0) {
		std::cout << "Error initializing SDL_ttf: " << TTF_GetError() << std::endl;
	}

	//TTF Loading

	font = TTF_OpenFont("MochiyPopOne-Regular.ttf", 128);
	if (!font) {
		std::cout << "Failed to load font: " << TTF_GetError() << std::endl;
	}
}

Text::~Text()
{
	TTF_CloseFont(font);
	TTF_Quit();
	//delete text;
	//SDL_FreeSurface(text);
	//SDL_DestroyTexture(text_texture);
}

void Text::writeText(const char* message, SDL_Color color, SDL_Rect rect, SDL_Renderer* renderer)
{
	text = TTF_RenderText_Solid(font, message, color);
	if (!text) {
		std::cout << "Failed to render text: " << TTF_GetError() << std::endl;
	}
	text_texture = SDL_CreateTextureFromSurface(renderer, text);

	SDL_RenderCopy(renderer, text_texture, NULL, &rect);

	SDL_DestroyTexture(text_texture);
	SDL_FreeSurface(text);
}
