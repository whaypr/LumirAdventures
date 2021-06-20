#pragma once

#include <SDL2/SDL.h>

#include "../Entities/Player/Player.hpp"
#include "../Map/Map.hpp"
#include "../UI/HUD.hpp"

class Game {
public:
	Game ( const char * title, int xpos, int ypos, int w, int h, bool fullscreen );
	~Game ();

	void handleEvents ();
	void update ();
	void render ();

	bool running () { return isRunning; }
	bool stopped () { return isPaused; }
	int getRefreshRate ();

	static int width, height;
	static SDL_Renderer * renderer;
	static SDL_Event event;

private:
	bool isRunning;
	bool isPaused;

	bool esc_lock = false;
	bool left_lock = false;

	SDL_Window * window;
	Map * map;
	HUD *hud;

	Player * pl;
};
