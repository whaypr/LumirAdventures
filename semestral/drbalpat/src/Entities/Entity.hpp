#pragma once

#include <SDL2/SDL.h>
#include "../Math/Math.hpp"

class Entity {
public:
	Entity ( const char * texturePath, Vector2 pos );
	virtual ~Entity ();

	virtual void update ();
	virtual void render ();

	void changeTexture ( const char * texturePath );
	Vector2 getPos () const { return pos; }
	SDL_Rect getRect () const { return dstR; }
	Vector2 * getOrigin () { return &origin; }

	bool destroyed () { return isDestroyed; }
protected:
	Vector2 pos, origin;

	SDL_Texture * texture;
	SDL_Rect srcR, dstR;

	bool isDestroyed = false;
};
