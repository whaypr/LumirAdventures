/**
* \brief Class representing tiles of which map is consisted and on which characters walk.
*/

#pragma once

#include "../Entity.hpp"

class Tile : public Entity {
public:
	Tile ( const char * texturePath, Vector2 pos ) : Entity( texturePath, pos ) {}
};
