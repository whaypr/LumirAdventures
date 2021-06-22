#include "Map.hpp"
#include "../Game/Game.hpp"
#include "../TextureManager/TextureManager.hpp"
#include "../Camera/Camera.hpp"
#include "../Entities/EntityManager/EntityManager.hpp"
#include "../Entities/Enemies/Enemy.hpp"

#include <libxml/xpath.h>

#include <cstdlib>
#include <iostream>

//---------------------------------------------------------------------------
Map::Map () {
	backgroud = TextureManager::LoadTexture("assets/images/background/country-platform-back.png");
	forest = TextureManager::LoadTexture("assets/images/background/country-platform-forest.png");

	if ( ! loadMap( "assets/map3.tmx" ) ) {
		SDL_DestroyTexture(backgroud);
		SDL_DestroyTexture(forest);

		throw "Failed to load the map!";
	}
}

//---------------------------------------------------------------------------
Map::~Map () {
	SDL_DestroyTexture(backgroud);
	SDL_DestroyTexture(forest);
}

//---------------------------------------------------------------------------
void Map::render () const {
	SDL_RenderCopy(Game::renderer, backgroud, NULL, NULL);
	SDL_RenderCopy(Game::renderer, forest, NULL, NULL);
}

//---------------------------------------------------------------------------
bool Map::loadMap ( const char * filePath ) {
	LIBXML_TEST_VERSION

	xmlDoc * doc = xmlReadFile(filePath, NULL, 0);
	if ( ! doc )
	   return false;

	// load actual map
	xmlXPathObjectPtr path = xmlXPathEval( (const xmlChar*)"/map/layer/data", xmlXPathNewContext(doc) );

	unsigned char * map = path->nodesetval->nodeTab[0]->children->content;

	// create game entities
	std::string row;
    int rowsCnt = -1, colsCnt = 0;

	for ( int i = 0; map[i]; i++ ) {
		if ( map[i] == '\n' ) {
			rowsCnt++;
			colsCnt = 0;
			continue;
		} else if ( map[i] == '0' ) {
			colsCnt++;
			continue;
		} else if ( map[i] == '1' )
			EntityManager::getInstance()->addEntity(
				"tile",
				std::make_shared<Tile>( "assets/images/tiles/ground.png", Vector2(64 * colsCnt, 64 * rowsCnt) )
			);
		else if ( map[i] == '2' )
			EntityManager::getInstance()->addEntity(
				"tile",
				std::make_shared<Tile>( "assets/images/tiles/ground-top.png", Vector2(64 * colsCnt, 64 * rowsCnt) )
			);
		else if ( map[i] == '3' )
			EntityManager::getInstance()->addEntity(
				"enemy",
				std::make_shared<Enemy>( "assets/images/enemies/slime.png", Vector2(64 * colsCnt, 64 * rowsCnt) )
			);
		else
			continue;

		colsCnt++;
	}

	path = xmlXPathEval( (const xmlChar*)"/map", xmlXPathNewContext(doc) );

	// get tiles width
	xmlChar * tileWidth_xml = xmlGetProp( path->nodesetval->nodeTab[0], (const xmlChar *)"tilewidth" );
		int tileWidth = atoi( (const char *)tileWidth_xml );
	xmlFree(tileWidth_xml);

	// get tiles height
	xmlChar * tileHeight_xml = xmlGetProp( path->nodesetval->nodeTab[0], (const xmlChar *)"tileheight" );
		int tileHeight = atoi( (const char *) tileHeight_xml );
	xmlFree(tileHeight_xml);

	// get map width
	xmlChar * colsCnt_xml = xmlGetProp( path->nodesetval->nodeTab[0], (const xmlChar *)"width" );
		int mapWidth = atoi( (const char *)colsCnt_xml ) * tileWidth;
	xmlFree(colsCnt_xml);

	// get map height
	xmlChar * rowsCnt_xml = xmlGetProp( path->nodesetval->nodeTab[0], (const xmlChar *)"height" );
		int mapHeight = atoi( (const char *)rowsCnt_xml ) * tileHeight;
	xmlFree(rowsCnt_xml);

	Camera::getCamera()->setMapSize( mapWidth, mapHeight );

	xmlFreeDoc(doc);
	xmlCleanupParser();
	return true;
}
