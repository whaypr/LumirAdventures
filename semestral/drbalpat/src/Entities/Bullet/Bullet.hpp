/**
* \brief Class representing bullets shot by player and certain enemies.
*/

#pragma once

#include "../Moving.hpp"

class Bullet : public Moving {
public:
	Bullet ( const char * texturePath, Vector2 pos, int direction, bool enableGravity = false );


	/**
	* * Mark bullet destroyed if reached its life span.
	* * Check collision with tiles.
	* * Check collision with enemies and if occurs, deal damage to them.
	*/
	void update() override;

private:
	int lifeSpan = 20;  // maximum life duration
	int timeLiving = 0; // current life duration

	int damage = 20;
};
