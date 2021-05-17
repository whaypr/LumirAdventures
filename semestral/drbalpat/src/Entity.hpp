#pragma once

#include "Game.hpp"
#include "Math.hpp"

class Entity {
public:
	Entity ( const char * texturePath, Vector2 pos );

	virtual void update ();
	virtual void render ();

	void changeTexture ( const char * texturePath );
	const Vector2 & getPos () const { return pos; }
	const SDL_Rect & getRect () const { return dstR; }

protected:
	Vector2 pos;

	SDL_Texture * texture;
	SDL_Rect srcR, dstR;
};
