#include "musicPlayer.h"

musicPlayer::musicPlayer(const char* fileName) {
	song = Mix_LoadMUS(fileName);
	if (!song) {
		printf("Mix_LoadMUS(\"%s\"): %s\n", fileName, Mix_GetError());
		// this might be a critical error...
	}
	
	volume = 2;
	
	
}
musicPlayer::~musicPlayer() {
	Mix_FreeMusic(song);
	song = nullptr;

}
void musicPlayer::playSong() {

	
	
	Mix_PlayMusic(song, -1);
	Mix_VolumeMusic(volume);
	if (song == nullptr) { cout << "Song is Null" << endl; }

}
void musicPlayer::stopSong(){

	Mix_HaltMusic();
	song = nullptr;

}