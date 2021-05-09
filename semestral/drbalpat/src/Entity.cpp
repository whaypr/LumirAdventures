#include "Entity.hpp"
#include "TextureManager.hpp"

Entity::Entity ( const char * texturePath, Vector2 pos ) : pos ( pos ) {
	texture = TextureManager::LoadTexture(texturePath);

	srcR.x = srcR.y = 0;

	dstR.x = pos.x;
	dstR.y = pos.y;

	// get whole size of the texture
	SDL_QueryTexture(texture, NULL, NULL, &srcR.w, &srcR.h);

	dstR.w = srcR.w;
	dstR.h = srcR.h;
}

void Entity::update () {
	dstR.x = pos.x;
	dstR.y = pos.y;
}


void Entity::render () {
	SDL_RenderCopy(Game::renderer, texture, &srcR, &dstR);
}

void Entity::changeTexture ( const char * texturePath ) {
	texture = TextureManager::LoadTexture(texturePath); 
}
