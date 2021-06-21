/**
* \brief Creating head-up display with information about player's health points, ammo and score.
*/

#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <map>
#include <string>

class HUD {
public:
	HUD ();
	~HUD ();

	void render () const;


	/**
	* Set displayed HP and MAX_HP.
	* @param hp new HP value
	* @param max_hp new MAX_HP value
	*/
	void SetHp ( int hp, int maxHp );
	/**
	* Set displayed ammo.
	* @param val new ammo value
	*/
	void SetAmmo ( int val );
	/**
	* Set displayed score.
	* @param val new score value
	*/
	void SetScore ( int score, int bestScore );

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
