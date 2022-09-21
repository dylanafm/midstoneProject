#include "Sfx.h"

Sfx::Sfx(const char* fileName, int vol_)
{
	soundfx = Mix_LoadWAV(fileName);
	if (!soundfx) {
		printf("Mix_LoadWAV: %s\n", Mix_GetError());
		// handle error
	}

	vol = vol_;

}

Sfx::~Sfx()
{
	Mix_FreeChunk(soundfx);
}

void Sfx::playSFX()
{
	Mix_PlayChannel(-1, soundfx, 0);
	Mix_VolumeChunk(soundfx, vol);

}
