#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <iostream>
#include <SDL_mixer.h>



using namespace std;

class musicPlayer
{
public:

	musicPlayer(const char* fileName);
	~musicPlayer();
	Mix_Music* song;
	void playSong();
private:
	

	//MixChunk for soundeffects


};

#endif