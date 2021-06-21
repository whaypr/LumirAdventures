/**
* \brief Class used for loading and creating textures.
*/

#pragma once

#include <SDL2/SDL.h>

class TextureManager {
public:
	/**
	* Load texture from file, create *SDL_Texture\** object from it and return it.
	* @param texturePath path to texture file
	* @return pointer to the new texture object
	*/
	static SDL_Texture * LoadTexture ( const char * texturePath );
};
