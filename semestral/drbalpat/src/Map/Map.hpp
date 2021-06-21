/**
* \brief Loading map from a file, getting info about it and rendering background.
*/

#pragma once

#include "../Entities/Tiles/Tile.hpp"

class Map {
public:
	/**
	* Set background textures, load map with *loadMap()* private method.
	* @throw "Failed to load the map!" when map fails to load
	*/
	Map ();
	~Map ();

	/**
	* Render background textures.
	*/
	void render() const;

private:
	SDL_Texture *backgroud, *forest;

	/**
	* Load map from a file with libxml2, create entities accordingly and pass them to EntityManager, 
	* get map meta data and pass them to Camera.
	* @param filePath path to map file
	* @return success flag
	*/
	bool loadMap ( const char * filePath );
};
