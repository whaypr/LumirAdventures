#pragma once

#include "Math.hpp"
#include "Tile.hpp"

#include <vector>
#include <memory>

class CollisionChecker {
public:
	std::vector< std::pair<char, Vector2> > checkCollision ( Vector2 pos, int w, int h );
};
