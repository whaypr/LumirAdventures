#pragma once

#include <list>

#include "../Character.hpp"

class Player : public Character {
public:
	Player ( const char * texturePath, Vector2 pos );

	void update () override;
	void render() override;


private:

};
