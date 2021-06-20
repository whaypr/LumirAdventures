#pragma once

#include <list>

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
