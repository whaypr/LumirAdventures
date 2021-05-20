#pragma once

#include "Entity.hpp"

class Moving : public Entity {
public:
	Moving ( const char * texturePath, Vector2 pos, bool enableGravity = true );

	void update() override;
	void changeVelocity ( Vector2 newVelocity );
	int getSpeed () { return speed; }

protected:
	const float gravity = .7;
	bool gravityEnabled;

	Vector2 velocity;
	int speed = 4;
};
