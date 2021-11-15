#ifndef LTEXTURE_H
#define LTEXTURE_H
#include <SDL.h>	
#include <SDL_image.h>

#include <string>




class LTexture
{
public:
	//Initializes variables
	LTexture();

	//Deallocates memory
	~LTexture();

	bool loadFromFile(std::string path, SDL_Renderer* r);

	//Loads image at specified path

#if defined(SDL_TTF_MAJOR_VERSION)
	//Creates image from font string
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor);
#endif

	//Deallocates texture
	void free();

	//Set color modulation
	void setColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//Set alpha modulation
	void setAlpha(Uint8 alpha);

	void render(SDL_Renderer* r, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip);


	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};

#endif // !LTEXTURE_H
