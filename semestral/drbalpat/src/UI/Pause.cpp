#include "Pause.hpp"
#include "../Game/Game.hpp"
#include "../TextureManager/TextureManager.hpp"

Pause * Pause::pause = nullptr;

Pause::Pause() {
	std::string s = "PAUSED";
	SDL_Surface * surf =  TTF_RenderText_Blended( TTF_OpenFont("assets/fonts/basic.ttf", 80), s.c_str(), {255, 255, 255} );
	title = SDL_CreateTextureFromSurface( Game::renderer, surf );
	SDL_FreeSurface( surf );

	SDL_QueryTexture( title, nullptr, nullptr, &titlePos.w, &titlePos.h );
	titlePos.x = Game::width / 2 - titlePos.w / 2;
	titlePos.y = Game::height / 2 - titlePos.h / 2;

	background = TextureManager::LoadTexture("assets/images/background/pause.png");
	SDL_SetTextureBlendMode( background, SDL_BLENDMODE_BLEND);
}

Pause::~Pause () {
	SDL_DestroyTexture(title);
	SDL_DestroyTexture(background);
}

void Pause::render () {
	SDL_RenderCopy(Game::renderer, title, NULL, &titlePos);
	SDL_RenderCopy(Game::renderer, background, NULL, NULL);
}
