#include "Map.hpp"
#include "../TextureManager/TextureManager.hpp"
#include "../Camera/Camera.hpp"

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>
#include <libxml/xmlmemory.h>

#include <cstdlib>
#include <iostream>

std::vector< std::shared_ptr<Tile> > Map::tiles = {};

Map::Map () {
	backgroud = TextureManager::LoadTexture("assets/images/background/country-platform-back.png");
	forest = TextureManager::LoadTexture("assets/images/background/country-platform-forest.png");

	srcR.x = srcR.y = 0;
	srcR.w = srcR.h = 64;

	dstR.w = dstR.h = 64;

	if ( ! loadMap( "assets/map3.tmx" ) )
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
	LIBXML_TEST_VERSION

	xmlDoc * doc = xmlReadFile(filePath, NULL, 0);
	if ( ! doc )
	   return false;

	// load actual map
	xmlXPathObjectPtr path = xmlXPathEval( (const xmlChar*)"/map/layer/data", xmlXPathNewContext(doc) );

	unsigned char * map = path->nodesetval->nodeTab[0]->children->content;

	std::string row;
    int rowsCnt = -1, colsCnt = 0;

	for ( int i = 0; map[i]; i++ ) {
		std::string path = "assets/images/tiles/";

		if ( map[i] == '\n' ) {
			rowsCnt++;
			colsCnt = 0;
			continue;
		} else if ( map[i] == '0' ) {
			colsCnt++;
			continue;
		} else if ( map[i] == '1' )
			path += "ground.png";
		else if ( map[i] == '2' )
			path += "ground-top.png";
		else
			continue;

		tiles.emplace_back(
				std::make_shared<Tile>( path.c_str(), Vector2(64 * colsCnt, 64 * rowsCnt) )
			);

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
