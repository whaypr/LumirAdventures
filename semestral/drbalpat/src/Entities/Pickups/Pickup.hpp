#pragma once

#include "../Moving.hpp"

class Pickup : public Moving {
public:
	Pickup ( const char * texturePath, Vector2 pos );
};
