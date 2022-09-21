#ifndef SFX_H
#define SFX_H
#include "musicPlayer.h"
#include <SDL_mixer.h>

class Sfx
{
public:

	int vol;
	Mix_Chunk* soundfx;
	Sfx(const char* fileName,int vol_);
	~Sfx();

	
	void playSFX();
	



};

#endif