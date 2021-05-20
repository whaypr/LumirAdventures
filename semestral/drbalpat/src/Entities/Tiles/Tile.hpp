#pragma once

#include "../Entity.hpp"

class Tile : public Entity {
public:
	Tile ( const char * texturePath, Vector2 pos ) : Entity( texturePath, pos ) {}
};
