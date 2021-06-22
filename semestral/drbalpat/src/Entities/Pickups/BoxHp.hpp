#pragma once

#include "Pickup.hpp"

class BoxHp : public Pickup {
public:
	BoxHp ( const char * texturePath, Vector2 pos ) : Pickup( texturePath, pos ) {}
};
