/**
* \brief Class representing moving entities.
*
* Extends Entity by gravity, velocity and speed.
*/

#pragma once

#include "Entity.hpp"

class Moving : public Entity {
public:
	Moving ( const char * texturePath, Vector2 pos, bool enableGravity = true );


	/**
	* Apply gravity if enabled.
	*/
	void update() override;


	/**
	* Apply new velocity vector to the current velocity.
	* @param newVelocity new velocity to be applied
	*/
	void changeVelocity ( Vector2 newVelocity );
	/**
	* Get current entity speed.
	* @return current speed
	*/
	int getSpeed () const { return speed; }

protected:
	const float gravity = .7;
	bool gravityEnabled;

	Vector2 velocity;
	int speed = 4;
};
