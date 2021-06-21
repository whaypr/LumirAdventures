#include "HUD.hpp"

#include "../Game/Game.hpp"

HUD::HUD () {
	font = TTF_OpenFont("assets/fonts/basic.ttf", 40);

	hpPos.x = 0;
	hpPos.y = 0;

	ammoPos.x = Game::width - 350;
	ammoPos.y = 0;

	scorePos.x = Game::width - 350;
	scorePos.y = Game::height - 50;
}

HUD::~HUD () {
	TTF_CloseFont( font );

	SDL_DestroyTexture( hpTexture );
	SDL_DestroyTexture( ammoTexture );
	SDL_DestroyTexture( scoreTexture );
}

//---------------------------------------------------------------------------
void HUD::render () const {
	SDL_RenderCopy( Game::renderer, hpTexture, nullptr, &hpPos );
	SDL_RenderCopy( Game::renderer, ammoTexture, nullptr, &ammoPos );
	SDL_RenderCopy( Game::renderer, scoreTexture, nullptr, &scorePos );
}

//---------------------------------------------------------------------------
void HUD::SetHp ( int hp, int maxHp ) {
	std::string s = "HP:" + std::to_string(hp) + "/" + std::to_string( maxHp );
	SDL_Surface * surf =  TTF_RenderText_Blended( font, s.c_str(), {216, 58, 86} );
	hpTexture = SDL_CreateTextureFromSurface( Game::renderer, surf );
	SDL_FreeSurface( surf );

	SDL_QueryTexture( hpTexture, nullptr, nullptr, &hpPos.w, &hpPos.h );
}

//---------------------------------------------------------------------------
void HUD::SetAmmo ( int val ) {
	std::string s = "AMMO:" + std::to_string( val );
	SDL_Surface * surf =  TTF_RenderText_Blended( font, s.c_str(), {52, 103, 81} );
	ammoTexture = SDL_CreateTextureFromSurface( Game::renderer, surf );
	SDL_FreeSurface( surf );

	SDL_QueryTexture( hpTexture, nullptr, nullptr, &ammoPos.w, &ammoPos.h );	
}

//---------------------------------------------------------------------------
void HUD::SetScore ( int score, int bestScore ) {
	std::string s = "SCORE:" + std::to_string( score ) + " (" + std::to_string( bestScore ) + ")";
	SDL_Surface * surf =  TTF_RenderText_Blended( font, s.c_str(), {245, 169, 98} );
	scoreTexture = SDL_CreateTextureFromSurface( Game::renderer, surf );
	SDL_FreeSurface( surf );

	SDL_QueryTexture( hpTexture, nullptr, nullptr, &scorePos.w, &scorePos.h );
}
