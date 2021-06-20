#pragma once

#include "../Character.hpp"

class Enemy : public Character {
public:
	Enemy ( const char * texturePath, Vector2 pos );

	void update() override;

private:
	
};
