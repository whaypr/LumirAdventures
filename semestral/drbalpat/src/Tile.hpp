#pragma once

#include "Stationary.hpp"
#include "TextureManager.hpp"

class Tile : public Stationary {
public:
	Tile ( const char * texturePath, Vector2 pos ) : Stationary( texturePath, pos ) {}
};
