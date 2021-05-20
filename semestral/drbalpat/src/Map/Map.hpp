#pragma once

#include "../Entities/Stationary/Tile/Tile.hpp"

#include <vector>
#include <memory>
#include <libxml/parser.h>

class Map {
public:
	Map ();

	void update();
	void render();

	static std::vector< std::shared_ptr<Tile> > & getTiles () { return tiles; }

private:
	static std::vector< std::shared_ptr<Tile> > tiles;

	SDL_Texture *backgroud, *forest;
	SDL_Rect srcR, dstR;

	bool loadMap ( const char * filePath );
};
