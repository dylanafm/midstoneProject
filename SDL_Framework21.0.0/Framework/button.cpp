#include "button.h"

button::button() {

	buttonBox.x = 0;
	buttonBox.y = 0;
	buttonBox.w = 0;
	buttonBox.h = 0;
	textColor = SDL_Color{ 0, 0, 0 };
	text = "Default Text";
	textureOriginal = nullptr;
	textureHovered = nullptr;
	texture = nullptr;
	

}

button::button(int x, int y, int w, int h, Vec3 textColor2, const char* text_)
{
	buttonBox.x = x; buttonBox.y = y; buttonBox.w = w; buttonBox.h = h; textureOriginal = nullptr; textureHovered = nullptr; texture = nullptr;
	textColor.r = textColor2.x; textColor.g = textColor2.y; textColor.b = textColor2.z; text = text_;

	textBox = buttonBox;
	textBox.x += buttonBox.w / 25.0;
	textBox.w -= buttonBox.w / 12.5;
	textBox.y -= buttonBox.h / 20;
	click = new Sfx("SFX/menuSelect.wav", 10);

}

button::~button()
{
	//delete text;
	delete click;
	SDL_DestroyTexture(textureOriginal);
	SDL_DestroyTexture(textureHovered);
	SDL_DestroyTexture(texture);
}





bool button::buttonClicked(SDL_Event event_)
{
	int x, y;
	Uint32 buttons;
	buttons = SDL_GetMouseState(&x, &y);
	
	if (event_.button.button == SDL_BUTTON_LEFT && event_.type == SDL_MOUSEBUTTONDOWN)
	{
		//Get the mouse offsets
		x = event_.button.x;
		y = event_.button.y;

		//If the mouse is over the levels button
		if ((x > buttonBox.x) && (x < buttonBox.x + buttonBox.w) && (y > buttonBox.y) && (y < buttonBox.y + buttonBox.h))
		{

			return true;
		}
	}
	return false;
}

bool button::setImage(const char* pathOriginal, const char* pathHovered, SDL_Renderer* renderer)
{
	SDL_Surface* tempSurface = IMG_Load(pathOriginal);
	SDL_Texture* tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	if (tempTexture == nullptr) printf("%s\n", SDL_GetError());
	if (tempSurface == nullptr) {
		std::cerr << "Can't open the original image" << std::endl;
		return false;
	}
	else {
		textureOriginal = tempTexture;
		SDL_FreeSurface(tempSurface);
	}

	tempSurface = IMG_Load(pathHovered);
	tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	if (tempTexture == nullptr) printf("%s\n", SDL_GetError());
	if (tempSurface == nullptr) {
		std::cerr << "Can't open the hoover image" << std::endl;
		return false;
	}
	else {
		textureHovered = tempTexture;
		SDL_FreeSurface(tempSurface);
	}
	texture = textureOriginal;

	return true;
}

void button::Update()
{
	int x, y;
	Uint32 buttons;
	buttons = SDL_GetMouseState(&x, &y);

	if ((x > buttonBox.x) && (x < buttonBox.x + buttonBox.w) && (y > buttonBox.y) && (y < buttonBox.y + buttonBox.h))
	{
		texture = textureHovered;
	}
	else { 
		texture = textureOriginal;
	}
}

void button::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopyEx(renderer, texture, nullptr, &buttonBox, 0.0, nullptr, SDL_FLIP_NONE);
	
	Text buttonText;
	buttonText.writeText(text, SDL_Color{ textColor }, textBox, renderer);
}

