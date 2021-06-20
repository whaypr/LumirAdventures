#pragma once

#include "../Entities/Tiles/Tile.hpp"

class Map {
public:
	Map ();
	~Map ();

	void render();

private:
	SDL_Texture *backgroud, *forest;
	SDL_Rect srcR, dstR;

	bool loadMap ( const char * filePath );
};
