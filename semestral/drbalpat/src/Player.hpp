#pragma once

#include "Moving.hpp"
#include "Tile.hpp"
#include <vector>
#include <memory>

class Player : public Moving {
public:
	Player ( const char * texturePath, Vector2 pos = {0,0} );

	//void update () override;
	void update ( std::vector< std::unique_ptr<Tile> > & tiles );
	void render() override;

private:
	bool isLookingRight;

	//temp
	int cnt = 0;
};
