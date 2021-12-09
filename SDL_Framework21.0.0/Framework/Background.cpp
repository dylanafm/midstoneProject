#include "Background.h"
#include <iostream>

Background::Background(SDL_Renderer* r, int o1, const char* Layer1, int o2, const char* Layer2, int o3, const char* Layer3, int o4,
	const char* Layer4, int o5, const char* Layer5, int o6, const char* Layer6,
	int o7, const char* Layer7, int o8, const char* Layer8, float LevelSpeed_)
{
	if (!b1.loadFromFile(Layer1, r))
	{
		printf("Failed to load background texture!\n");

	}
	if (!b2.loadFromFile(Layer2, r))
	{
		printf("Failed to load background texture!\n");

	}
	if (!b3.loadFromFile(Layer3, r))
	{
		printf("Failed to load background texture!\n");

	}
	if (!b4.loadFromFile(Layer4, r))
	{
		printf("Failed to load background texture!\n");

	}
	if (!b5.loadFromFile(Layer5, r))
	{
		printf("Failed to load background texture!\n");

	}
	if (!b6.loadFromFile(Layer6, r))
	{
		printf("Failed to load background texture!\n");

	}if (!b7.loadFromFile(Layer7, r))
	{
		printf("Failed to load background texture!\n");

	}
	if (!b8.loadFromFile(Layer8, r))
	{
		printf("Failed to load background texture!\n");

	}






	LevelSpeed = LevelSpeed_;
	scrolling = true;
	scrollOffset = 0;
	b1Speed = o1;
	b2Speed = o2;
	b3Speed = o3;
	b4Speed = o4;
	b5Speed = o5;
	b6Speed = o6;
	b7Speed = o7;
	b8Speed = o8;

	b1Offset = 0;
	b2Offset = 0;
	b3Offset = 0;
	b4Offset = 0;
	b5Offset = 0;
	b6Offset = 0;
	b7Offset = 0;
	b8Offset = 0;

	progress = 0;
}

Background::~Background()
{
}

void Background::Scroll()
{
	if (scrolling == true) {
		progress = progress + LevelSpeed;
		//Layer 1
		b1Offset = b1Offset - b1Speed;
		if (b1Offset < -b1.getWidth())
		{
			b1Offset = 0;
		}
		//Waves
		b2Offset = b2Offset - b2Speed;
		if (b2Offset < -b2.getWidth())
		{
			b2Offset = 0;
		}

		//Mountain
		b3Offset = b3Offset - b3Speed;
		if (b3Offset < -b3.getWidth())
		{
			b3Offset = 0;
		}

		//Rock
		b4Offset = b4Offset - b4Speed;
		if (b4Offset < -b4.getWidth())
		{
			b4Offset = 0;
		}

		//Ground
		b5Offset = b5Offset - b5Speed;
		if (b5Offset < -b5.getWidth())
		{
			b5Offset = 0;
		}

		b6Offset = b6Offset - b6Speed;
		if (b6Offset < -b6.getWidth())
		{
			b6Offset = 0;
		}

		b7Offset = b7Offset - b7Speed;
		if (b7Offset < -b7.getWidth())
		{
			b7Offset = 0;
		}

		b8Offset = b8Offset - b8Speed;
		if (b8Offset < -b8.getWidth())
		{
			b8Offset = 0;
		}
	}

	if (progress >= 100.0f) {
		scrolling = false; //Stop scrolling at level progress %
	}
}

void Background::Render(SDL_Renderer* render)
{

	b1.render(render, b1Offset, 0, nullptr, 0, nullptr, SDL_FLIP_NONE);
	b1.render(render, b1Offset + b1.getWidth(), 0, nullptr, 0, nullptr, SDL_FLIP_NONE);

	b2.render(render, b2Offset, 0, nullptr, 0, nullptr, SDL_FLIP_NONE);
	b2.render(render, b2Offset + b2.getWidth(), 0, nullptr, 0, nullptr, SDL_FLIP_NONE);

	b3.render(render, b3Offset, 0, nullptr, 0, nullptr, SDL_FLIP_NONE);
	b3.render(render, b3Offset + b3.getWidth(), 0, nullptr, 0, nullptr, SDL_FLIP_NONE);

	b4.render(render, b4Offset, 0, nullptr, 0, nullptr, SDL_FLIP_NONE);
	b4.render(render, b4Offset + b4.getWidth(), 0, nullptr, 0, nullptr, SDL_FLIP_NONE);

	b5.render(render, b5Offset, 0, nullptr, 0, nullptr, SDL_FLIP_NONE);
	b5.render(render, b5Offset + b5.getWidth(), 0, nullptr, 0, nullptr, SDL_FLIP_NONE);

	b6.render(render, b6Offset, 0, nullptr, 0, nullptr, SDL_FLIP_NONE);
	b6.render(render, b6Offset + b6.getWidth(), 0, nullptr, 0, nullptr, SDL_FLIP_NONE);

	b7.render(render, b7Offset, 0, nullptr, 0, nullptr, SDL_FLIP_NONE);
	b7.render(render, b7Offset + b7.getWidth(), 0, nullptr, 0, nullptr, SDL_FLIP_NONE);

	b8.render(render, b8Offset, 0, nullptr, 0, nullptr, SDL_FLIP_NONE);
	b8.render(render, b8Offset + b8.getWidth(), 0, nullptr, 0, nullptr, SDL_FLIP_NONE);

	

}

