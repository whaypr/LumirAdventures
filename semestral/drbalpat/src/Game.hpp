#pragma once

#include <SDL2/SDL.h>

class Game {
public:
	void init ( const char * title, int xpos, int ypos, int width, int height, bool fullscreen );
	void handleEvents ();
	void update ();
	void render ();
	void clean ();

	bool running() { return isRunning; }
	int getRefreshRate();

	static SDL_Renderer * renderer;
	static SDL_Event event;

private:
	bool isRunning;
	SDL_Window * window;
};
