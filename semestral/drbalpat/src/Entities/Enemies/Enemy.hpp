/**
* \brief Class representing enemies.
*/

#pragma once

#include "../Character.hpp"

class Enemy : public Character {
public:
	Enemy ( const char * texturePath, Vector2 pos );


	/**
	* * If hp < 0, mark entity as destroyed.
	*/
	void update() override;


	/**
	* Get damage of the enemy.
	* @return enemy damage
	*/
	int getDamage() { return damage; }

private:
	int damage = 20;	
};
