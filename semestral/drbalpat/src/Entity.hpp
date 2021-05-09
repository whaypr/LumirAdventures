#pragma once

#include "Game.hpp"
#include "Math.hpp"

class Entity {
public:
	Entity ( const char * texturePath, Vector2 pos );

	virtual void update ();
	virtual void render ();

	void changeTexture ( const char * texturePath );
	Vector2 & getPos () { return pos; }

protected:
	Vector2 pos;

	SDL_Texture * texture;
	SDL_Rect srcR, dstR;
};
