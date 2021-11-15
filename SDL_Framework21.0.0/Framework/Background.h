#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "LTexture.h"

using namespace std;
class Background
{
public:

	Background(SDL_Renderer* r);
	~Background();
	void Scroll();

	void Render(SDL_Renderer* render);
	
	float getProg() { return progress; }

private:
	
	bool scrolling;
	float progress;
	int scrollOffset;
	int seaOffset;
	int waveOffset;
	int mOffset;
	int rockOffset;
	int groundOffset;
	
	LTexture sea;
	LTexture wave;
	LTexture mountain;
	LTexture rock;
	LTexture ground;




};


#endif // !BACKGROUND_H


