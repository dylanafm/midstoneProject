#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H


#include <SDL_mixer.h>
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