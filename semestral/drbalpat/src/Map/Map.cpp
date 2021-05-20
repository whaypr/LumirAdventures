#include "Map.hpp"
#include "../TextureManager/TextureManager.hpp"

#include <iostream>
#include <fstream>

std::vector< std::shared_ptr<Tile> > Map::tiles = {};

Map::Map () {
	backgroud = TextureManager::LoadTexture("assets/images/background/country-platform-back.png");
	forest = TextureManager::LoadTexture("assets/images/background/country-platform-forest.png");

	srcR.x = srcR.y = 0;
	srcR.w = srcR.h = 64;

	dstR.w = dstR.h = 64;

	if ( ! loadMap( "assets/map.csv" ) )
		std::cout << "Failed to load the map!" << std::endl;

}

void Map::update () {
	for ( auto & t : tiles )
		t->update();
}

void Map::render () {
	SDL_RenderCopy(Game::renderer, backgroud, NULL, NULL);
	SDL_RenderCopy(Game::renderer, forest, NULL, NULL);

	for ( auto & t : tiles )
		t->render();
}

bool Map::loadMap ( const char * filePath ) {
	// load map tiles and store them in a vector

	std::ifstream mapFile( filePath );

	if ( mapFile.fail() )
		return false;

    
    std::string row;
    int rowCnt = 0;
  	while ( getline(mapFile, row) ) {
    	if ( row.empty() )
      		break;

      	int colCnt = 0;
      	for ( const char c : row ) {
      		std::string path = "assets/images/tiles/";

      		if ( c == '0' ) {
      			colCnt++;
      			continue;
      		} else if ( c == '1' )
				path += "ground.png";
			else if ( c == '2' )
				path += "ground-top.png";
			else
				continue;

			tiles.emplace_back(
				std::make_shared<Tile>( path.c_str(), Vector2(64 * colCnt, 64 * rowCnt) )
			);

			colCnt++;
      	}

      	rowCnt++;
	}

	return true;
}
