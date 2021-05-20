#pragma once

#include "../Math/Math.hpp"

#include <SDL2/SDL.h>

class Camera {
public:
	static Camera * getCamera ( int w = 1600, int h = 960 ) { return camera = camera ? camera : new Camera( w, h ); }	

	void setTarget ( Vector2 * t ) { target = t; }
	void setMapSize ( int w, int h ) { mapW = w; mapH = h; }
	void update ();

	SDL_Rect getView ()  { return view; }
	Vector2 getPos ()  { return pos; }

private:
	Camera ( int w, int h ) { view = {0, 0, w, h}; }
	static Camera * camera;

	Vector2 * target, pos;
	int mapW, mapH;
	SDL_Rect view;
};