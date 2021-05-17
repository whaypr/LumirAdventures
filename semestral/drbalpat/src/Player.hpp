#pragma once

#include "Moving.hpp"
#include "CollisionChecker.hpp"

class Player : public Moving {
public:
	Player ( const char * texturePath, Vector2 pos );

	void update () override;
	void render() override;

	bool grounded () { return isGrounded; }

private:
	bool isLookingRight;
	bool isGrounded;

	// anim
	int currentFrame = 0;
	Uint64 frameRate = 150;
	int lastTime = 0;

	CollisionChecker colCheck;
};
