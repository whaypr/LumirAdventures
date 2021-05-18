#include "Entity.hpp"
#include "TextureManager.hpp"
#include "Math.hpp"
#include "Camera.hpp"

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
	Vector2 cam = Camera::getCamera()->getPos();

	dstR.x = pos.x - cam.x;
	dstR.y = pos.y - cam.y;

	origin = { pos.x + dstR.w/2, pos.y + dstR.h/2 };
}


void Entity::render () {
	SDL_RenderCopy(Game::renderer, texture, &srcR, &dstR);
}

void Entity::changeTexture ( const char * texturePath ) {
	texture = TextureManager::LoadTexture(texturePath); 
}
