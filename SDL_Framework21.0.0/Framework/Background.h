#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "LTexture.h"

using namespace std;
class Background
{
public:

	Background(SDL_Renderer* r, int o1, const char* Layer1, int o2, const char* Layer2, int o3, const char* Layer3, int o4, 
		const char* Layer4, int o5, const char* Layer5, int o6, const char* Layer6, 
		int o7, const char* Layer7, int o8, const char* Layer8, float LevelSpeed_);
	~Background();
	void Scroll();

	void Render(SDL_Renderer* render);
	
	float getProg() { return progress; }

private:
	
	bool scrolling;
	float progress;
	float LevelSpeed;
	
	int scrollOffset;

	int b1Offset;
	int b2Offset;
	int b3Offset;
	int b4Offset;
	int b5Offset;
	int b6Offset;
	int b7Offset;
	int b8Offset;



	int b1Speed;
	int b2Speed;
	int b3Speed;
	int b4Speed;
	int b5Speed;
	int b6Speed;
	int b7Speed;
	int b8Speed;





	
	LTexture b1;
	LTexture b2;
	LTexture b3;
	LTexture b4;
	LTexture b5;
	LTexture b6;
	LTexture b7;
	LTexture b8;





};


#endif // !BACKGROUND_H


