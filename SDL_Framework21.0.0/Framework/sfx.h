#ifndef SFX_H
#define SFX_H
#include "musicPlayer.h"
#include <SDL_mixer.h>

class sfx
{
public:

	int vol;
	Mix_Chunk* soundfx;
	sfx(const char* fileName,int vol_);
	~sfx();

	
	void playSFX();
	



};

#endif