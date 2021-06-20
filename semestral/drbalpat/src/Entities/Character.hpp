#pragma once

#include "Moving.hpp"

class Character : public Moving {
public:
	Character ( const char * texturePath, Vector2 pos );

	void update() override;

	bool grounded () { return isGrounded; }
	int getMaxHp () { return max_hp; }
	int getHp () { return hp; }
	void changeHP ( int val );

protected:
	int max_hp = 100;
	int hp = max_hp;

	bool isLookingRight;
	bool isGrounded;

	// animation
	int currentFrame = 0;
	Uint64 frameRate = 150;
	int lastTime = 0;

};
