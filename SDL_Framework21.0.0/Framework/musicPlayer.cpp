#include "MusicPlayer.h"

MusicPlayer::MusicPlayer(const char* fileName, int volume_) {
	song = Mix_LoadMUS(fileName);
	if (!song) {
		printf("Mix_LoadMUS(\"%s\"): %s\n", fileName, Mix_GetError());
		// this might be a critical error...
	}
	
	volume = volume_;
	
	
}
MusicPlayer::~MusicPlayer() {
	Mix_FreeMusic(song);
	song = nullptr;
	delete song;
}
void MusicPlayer::playSong() {

	
	Mix_PlayMusic(song, -1);
	Mix_VolumeMusic(volume);
	if (song == nullptr) { cout << "Song is Null" << endl; }

}
void MusicPlayer::stopSong(){

	Mix_HaltMusic();
	song = nullptr;

}

void MusicPlayer::pauseSong()
{
	Mix_PauseMusic();

}
