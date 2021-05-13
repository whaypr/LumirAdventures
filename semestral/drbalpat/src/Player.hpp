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

	void changeVelocity ( float x, float y );
	bool grounded () { return isGrounded; }

private:
	bool isLookingRight;
	bool isGrounded;

	void checkCollision ( std::vector< std::unique_ptr<Tile> > & tiles );

	// anim
	int currentFrame = 0;
	Uint64 frameRate = 150;
	int lastTime = 0;
};
