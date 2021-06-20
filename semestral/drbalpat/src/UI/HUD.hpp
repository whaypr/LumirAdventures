#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <map>
#include <string>

class HUD {
public:
	HUD ();
	~HUD ();

	void render ();

	void SetHp ( int hp, int max_hp );
	void SetAmmo ( int val );
	void SetScore ( int val );

private:
	TTF_Font * font;

	// hp
	SDL_Rect hpPos;
	std::string hpText;
	SDL_Texture * hpTexture;

	// ammo
	SDL_Rect ammoPos;
	std::string ammoText;
	SDL_Texture * ammoTexture;

	// score
	SDL_Rect scorePos;
	std::string scoreText;
	SDL_Texture * scoreTexture;
};
