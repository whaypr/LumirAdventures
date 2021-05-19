#pragma once

#include "../Game/Game.hpp"
#include "../Math/Math.hpp"

class Entity {
public:
	Entity ( const char * texturePath, Vector2 pos );

	virtual void update ();
	virtual void render ();

	void changeTexture ( const char * texturePath );
	Vector2 getPos () const { return pos; }
	SDL_Rect getRect () const { return dstR; }
	Vector2 * getOrigin () { return &origin; }

	Vector2 pos, origin;
protected:

	SDL_Texture * texture;
	SDL_Rect srcR, dstR;
};
