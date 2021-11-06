#include "button.h"

button::button() {

	buttonBox.x = 0;
	buttonBox.y = 0;
	buttonBox.w = 0;
	buttonBox.h = 0;
	textColor = SDL_Color{ 0, 0, 0 };
	text = "Default Text";
	texture = nullptr;
}

button::button(int x, int y, int w, int h, Vec3 textColor2, const char* text_)
{
	buttonBox.x = x; buttonBox.y = y; buttonBox.w = w; buttonBox.h = h; texture = nullptr;
	textColor.r = textColor2.x; textColor.g = textColor2.y; textColor.b = textColor2.z; text = text_;

	textBox = buttonBox;
	textBox.x += 15;
	//textBox.y += 10;
	textBox.w -= 30;
	textBox.h -= 5;
}

button::~button()
{
	
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

bool button::setImage(const char* path, SDL_Renderer* renderer)
{
	SDL_Surface* tempSurface = IMG_Load(path);
	SDL_Texture* tempTexture = SDL_CreateTextureFromSurface(renderer, tempSurface);
	if (tempTexture == nullptr) printf("%s\n", SDL_GetError());
	if (tempSurface == nullptr) {
		std::cerr << "Can't open the image" << std::endl;
		return false;
	}
	else {
		texture = tempTexture;
		SDL_FreeSurface(tempSurface);
	}
	return true;
}

void button::Update()
{
	int x, y;
	Uint32 buttons;
	buttons = SDL_GetMouseState(&x, &y);

	if ((x > buttonBox.x) && (x < buttonBox.x + buttonBox.w) && (y > buttonBox.y) && (y < buttonBox.y + buttonBox.h))
	{
		//setImage();
	}
	else { 

	}
}

void button::Render(SDL_Renderer* renderer)
{
	SDL_RenderCopyEx(renderer, texture, nullptr, &buttonBox, 0.0, nullptr, SDL_FLIP_NONE);
	
	Text buttonText;
	buttonText.writeText(text, SDL_Color{ textColor }, textBox, renderer);
}

