#pragma once

#include "Pickup.hpp"

class BoxAmmo : public Pickup {
public:
	BoxAmmo ( const char * texturePath, Vector2 pos ) : Pickup( texturePath, pos ) {}
};
