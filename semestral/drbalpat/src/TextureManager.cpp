#include "TextureManager.hpp"
#include "Game.hpp"

#include <SDL2/SDL_image.h>

SDL_Texture * TextureManager::LoadTexture ( const char * texturePath ) {
	SDL_Surface * tmpSurface = IMG_Load( texturePath );
	SDL_Texture * tex = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return tex;
}
