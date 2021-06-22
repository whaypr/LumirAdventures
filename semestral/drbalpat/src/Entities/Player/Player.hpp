/**
* \brief Class representing playable character controlled by the person playing the game.
*
* Player can move move, jump and shoot.
*
* Extends Character by shoot method and ammo related private variables.
*/

#pragma once

#include "../Character.hpp"
#include "../Bullet/Bullet.hpp"

class Player : public Character {
public:
	Player ( const char * texturePath, Vector2 pos );

	void update () override;
	void render() const override;


	/**
	* Get number of ammo player have.
	* @return number of ammo player have
	*/
	int getAmmo () const { return ammo; }
	/**
	* If enough ammo and gun is loaded, fire new bullet in player's current direction.
	*/
	void shoot();

private:
	int ammo = 42;
	int fireRate = 20;
	int fireCurrent = 0;
};
