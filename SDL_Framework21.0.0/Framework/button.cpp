#include "button.h"

button::button(SDL_Rect NewButton_, Vec3 colorBase_, Vec3 colorHighlighted_)
{
	NewButton = NewButton_; colorBase = colorBase_; colorHighlighted = colorHighlighted_;
}

button::~button()
{
}





bool button::buttonClicked(SDL_Event event_)
{
	int x, y; \
		Uint32 buttons;
	buttons = SDL_GetMouseState(&x, &y);
	
	if (event.button.button == SDL_BUTTON_LEFT)
	{

		//Get the mouse offsets
		x = event.button.x;
		y = event.button.y;

		//If the mouse is over the levels button
		if ((x > NewButton.x) && (x < NewButton.x + NewButton.w) && (y > NewButton.y) && (y < NewButton.y + NewButton.h))
		{
			return true;

		}
	}
		return false;
	
}

void button::Update(const float time)
{
	if (SDL_PollEvent(&event))
	{

		int x, y; \
			Uint32 buttons;
		buttons = SDL_GetMouseState(&x, &y);

		if ((x > NewButton.x) && (x < NewButton.x + NewButton.w) && (y > NewButton.y) && (y < NewButton.y + NewButton.h))
		{
			currentColor = colorHighlighted;

		}
		else { currentColor = colorBase; }

	}


}

void button::Render(SDL_Window* sdlWindow_)
{
	renderer = SDL_CreateRenderer(sdlWindow_, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, currentColor.x, currentColor.y, currentColor.z, 255);
	SDL_RenderFillRect(renderer, &NewButton);
}

