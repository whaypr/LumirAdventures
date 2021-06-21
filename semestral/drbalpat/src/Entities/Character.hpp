/**
* \brief Class representing character entities.
*
* Extends Moving by health related methods, info about groundation and animations.
*/

#pragma once

#include "Moving.hpp"

class Character : public Moving {
public:
	Character ( const char * texturePath, Vector2 pos );

	/**
	* * Update character's looking direction.
	* * Check collisions with tiles and make the character stop when colliding with them.
	* * Update position.
	* * Update animation.
	*/
	void update() override;


	/**
	* Get info about whether entity is staying on the ground or not.
	* @return is grounded?
	*/
	bool grounded () const { return isGrounded; }
	/**
	* Get entity max health points.
	* @return max health points
	*/
	int getMaxHp () const { return max_hp; }
	/**
	* Get entity current health points.
	* @return current health points
	*/
	int getHp () const { return hp; }
	/**
	* Apply new hp value to the current hp.
	* @param val value to be added
	*/
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
