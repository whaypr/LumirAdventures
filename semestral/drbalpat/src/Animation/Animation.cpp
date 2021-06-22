#include "Animation.hpp"

//---------------------------------------------------------------------------
void Animation::animate ( std::string id ) {
	std::vector<SDL_Rect> * frames;

	// do not animate if frame does not exist
	try {
		frames = &animationFrames.at( id );
	} catch (...) {
		return;
	}

	// check if it's new animation
	if ( id != lastID )
		currentFrame = lastTime = 0;

	lastID = id;

	if ( lastTime + frameRate < SDL_GetTicks() ) {
		currentFrame = ( currentFrame + 1 ) % animationFrames[id].size();
		lastTime = SDL_GetTicks();
	}

	srcRect->x = (*frames)[currentFrame].x;
	srcRect->y = (*frames)[currentFrame].y;
	srcRect->w = (*frames)[currentFrame].w;
	srcRect->h = (*frames)[currentFrame].h;

	dstRect->w = (*frames)[currentFrame].w;
	dstRect->h = (*frames)[currentFrame].h;
}
