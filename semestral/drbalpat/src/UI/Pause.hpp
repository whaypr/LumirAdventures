#pragma once

#include <SDL2/SDL.h>

class Pause {
public:
	static Pause * getPause () { return pause = pause ? pause : new Pause(); }	
	~Pause ();

	void render ();

private:
	Pause ();
	static Pause * pause;

	SDL_Texture * title;
	SDL_Texture * background;

	SDL_Rect titlePos;
};
