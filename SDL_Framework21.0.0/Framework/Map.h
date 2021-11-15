#ifndef MAP_H
#define MAP_H
#include <SDL.h>
#include <SDL_image.h>
class Map
{
public:

	Map(SDL_Renderer* renderer, int stage);
	~Map();

	//Vec3 pos;

	void LoadMap(int arr[23][40]);
	void UpdateStage(int stage);
	void DrawMap(SDL_Renderer* renderer);
private:
	
	SDL_Rect src, dest;
	SDL_Texture* water;
	SDL_Texture* sand;
	SDL_Texture* coral;

	int map[23][40];

	int stageNum;




};

#endif