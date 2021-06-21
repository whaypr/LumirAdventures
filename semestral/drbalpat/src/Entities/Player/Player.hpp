/**
* \brief Class representing playable character controlled by the person playing the game.
*
* Player can move move, jump and shoot.
*
* Extends Character by shoot method and ammo related private variables.
*/

#include <list>
#pragma once

#include "../Character.hpp"
#include "../Bullet/Bullet.hpp"

class Player : public Character {
public:
	Player ( const char * texturePath, Vector2 pos );

	void update () override;
	void render() override;

	int getAmmo () { return ammo; }
	void shoot();

private:
	int ammo = 42;
	int fireRate = 20;
	int fireCurrent = 0;

	std::list<Bullet*> bullets;
};
