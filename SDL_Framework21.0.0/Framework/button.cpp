#include "button.h"

button::button() {

	NewButton.x = 0; 
	NewButton.y = 0;
	NewButton.w = 0; 
	NewButton.h = 0; 
	colorBase = Vec3(0,0,0); 
	colorHighlighted = Vec3(0, 0, 0);
	textColor = SDL_Color{ 0, 0, 0 };
	text = "Default Text";
}

button::button(int x, int y, int w, int h, Vec3 colorBase_, Vec3 colorHighlighted_, Vec3 textColor2, const char* text_)
{
	NewButton.x = x; NewButton.y = y; NewButton.w = w; NewButton.h = h; colorBase = colorBase_; 
	colorHighlighted = colorHighlighted_; textColor.r = textColor2.x; textColor.g = textColor2.y; textColor.b = textColor2.z; text = text_;
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
		if ((x > NewButton.x) && (x < NewButton.x + NewButton.w) && (y > NewButton.y) && (y < NewButton.y + NewButton.h))
		{
			return true;

		}
	}
	return false;
}

void button::Update()
{
	int x, y;
	Uint32 buttons;
	buttons = SDL_GetMouseState(&x, &y);

	if ((x > NewButton.x) && (x < NewButton.x + NewButton.w) && (y > NewButton.y) && (y < NewButton.y + NewButton.h))
	{
		currentColor = colorHighlighted;

	}
	else { currentColor = colorBase; }
}

void button::Render(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, currentColor.x, currentColor.y, currentColor.z, 255);
	SDL_RenderFillRect(renderer, &NewButton);
	SDL_Rect textBox;

	if (NewButton.w > 600) {
		textBox.x = NewButton.x + 300;
		textBox.w = NewButton.w - 600;
	}
	else {
		textBox.x = NewButton.x;
		textBox.w = NewButton.w;
	}
	textBox.y = NewButton.y;
	textBox.h = NewButton.h;
	
	Text buttonText;
	buttonText.writeText(text, SDL_Color{ textColor }, textBox, renderer);
}

