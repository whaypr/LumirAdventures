#pragma once

#include "../Math/Math.hpp"

#include <SDL2/SDL.h>

class Camera {
public:
	static Camera * getCamera () { return camera = camera ? camera : new Camera(); }

	void update ();

	void setTarget ( Vector2 * t ) { target = t; }
	void setView ( int w, int h ) { view = {0, 0, w, h}; }
	void setMapSize ( int w, int h ) { mapW = w; mapH = h; }

	SDL_Rect getView ()  { return view; }
	Vector2 getPos ()  { return pos; }

private:
	Camera () {}
	static Camera * camera;

	Vector2 * target, pos;
	int mapW, mapH;
	SDL_Rect view;
};