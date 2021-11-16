#include "musicPlayer.h"

musicPlayer::musicPlayer(const char* fileName) {
	int Mix_VolumeMusic(7);
	song = Mix_LoadMUS(fileName);

}
musicPlayer::~musicPlayer() {
	Mix_FreeMusic(song);
	song = nullptr;

}
void musicPlayer::playSong() {
	Mix_PlayMusic(song, -1);
	if (song == nullptr) { cout << "Song is Null" << endl; }

}