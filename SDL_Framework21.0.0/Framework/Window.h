#include <SDL_image.h>
class Window {
private:
	struct SDL_Window* window;   
	struct SDL_Surface* screenSurface;
	int width, height;
	
	
public:
	SDL_Surface* icon = IMG_Load("textures/icon.png");
	Window(int width_, int height_ );
	~Window();
	bool OnCreate();
	void OnDestroy();
	SDL_Window* GetSDL_Window();
};

