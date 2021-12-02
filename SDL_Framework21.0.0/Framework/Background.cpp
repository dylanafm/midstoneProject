#include "Background.h"
#include <iostream>

Background::Background(SDL_Renderer* r)
{
	if (!sea.loadFromFile("textures/layers/1.png", r))
	{
		printf("Failed to load background texture!\n");

	}
	if (!wave.loadFromFile("textures/layers/2.png", r))
	{
		printf("Failed to load background texture!\n");

	}
	if (!mountain.loadFromFile("textures/layers/3.png", r))
	{
		printf("Failed to load background texture!\n");

	}
	if (!rock.loadFromFile("textures/layers/4.png", r))
	{
		printf("Failed to load background texture!\n");

	}
	if (!ground.loadFromFile("textures/layers/5.png", r))
	{
		printf("Failed to load background texture!\n");

	}
	scrolling = true;
	scrollOffset = 0;
	seaOffset = 0;
	waveOffset = 0;
	mOffset = 0;
	rockOffset = 0;
	groundOffset = 0;
	progress = 0;
}

Background::~Background()
{
}

void Background::Scroll()
{
	if (scrolling == true) {
		progress = progress + 0.03f;
		//Sea
		seaOffset = seaOffset - 1;
		if (seaOffset < -sea.getWidth())
		{
			seaOffset = 0;
		}
		//Waves
		waveOffset = waveOffset - 1;
		if (waveOffset < -wave.getWidth())
		{
			waveOffset = 0;
		}

		//Mountain
		mOffset = mOffset - 4;
		if (mOffset < -mountain.getWidth())
		{
			mOffset = 0;
		}

		//Rock
		rockOffset = rockOffset - 3;
		if (rockOffset < -rock.getWidth())
		{
			rockOffset = 0;
		}

		//Ground
		scrollOffset = scrollOffset - 3;
		if (scrollOffset < -ground.getWidth())
		{
			scrollOffset = 0;
		}
	}

	if (progress >= 100.0f) {
		scrolling = false; //Stop scrolling at level progress %
	}
}

void Background::Render(SDL_Renderer* render)
{

	sea.render(render, seaOffset, 0, nullptr, 0, nullptr, SDL_FLIP_NONE);
	sea.render(render, seaOffset + sea.getWidth(), 0, nullptr, 0, nullptr, SDL_FLIP_NONE);

	wave.render(render, waveOffset, 0, nullptr, 0, nullptr, SDL_FLIP_NONE);
	wave.render(render, waveOffset + wave.getWidth(), 0, nullptr, 0, nullptr, SDL_FLIP_NONE);

	mountain.render(render, mOffset, 0, nullptr, 0, nullptr, SDL_FLIP_NONE);
	mountain.render(render, mOffset + mountain.getWidth(), 0, nullptr, 0, nullptr, SDL_FLIP_NONE);

	rock.render(render, rockOffset, 0, nullptr, 0, nullptr, SDL_FLIP_NONE);
	rock.render(render, rockOffset + rock.getWidth(), 0, nullptr, 0, nullptr, SDL_FLIP_NONE);

	ground.render(render, scrollOffset, 0, nullptr, 0, nullptr, SDL_FLIP_NONE);
	ground.render(render, scrollOffset + ground.getWidth(), 0, nullptr, 0, nullptr, SDL_FLIP_NONE);


}

