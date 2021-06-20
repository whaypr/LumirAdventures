#pragma once

#include "../Moving.hpp"

class Bullet : public Moving {
public:
	Bullet ( const char * texturePath, Vector2 pos, int direction, bool enableGravity = false );

	void update() override;

private:
	int lifeSpan = 20;  // maximum life duration
	int timeLiving = 0; // current life duration

	int damage = 20;
};
