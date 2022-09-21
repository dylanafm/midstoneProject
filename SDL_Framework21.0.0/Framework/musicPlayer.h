#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <iostream>
#include <SDL_mixer.h>



using namespace std;

class MusicPlayer
{
public:

	int volume;
	MusicPlayer(const char* fileName, int volume_);
	~MusicPlayer();
	Mix_Music* song;
	void playSong();
	void pauseSong();
	void stopSong();
private:
	

	//MixChunk for soundeffects


};

#endif