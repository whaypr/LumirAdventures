#include "Map.hpp"
#include "../TextureManager/TextureManager.hpp"

#include <string>

std::vector< std::shared_ptr<Tile> > Map::tiles = {};

Map::Map () {
	backgroud = TextureManager::LoadTexture("assets/images/background/country-platform-back.png");
	forest = TextureManager::LoadTexture("assets/images/background/country-platform-forest.png");

	srcR.x = srcR.y = 0;
	srcR.w = srcR.h = 64;

	dstR.w = dstR.h = 64;

	// load map tiles and store them in a vector
	for ( int i = 0; i < 35; ++i )
		for ( int j = 0; j < 25; ++j ) {
			int id = m[j][i];
			std::string path = "assets/images/tiles/";

			if ( id == 1 )
				path += "ground.png";
			else if ( id == 2 ) 
				path += "ground-top.png";
			else
				continue;

			tiles.emplace_back(
				std::make_shared<Tile>( path.c_str(), Vector2(64 * i, 64 * j) )
			);
		}
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