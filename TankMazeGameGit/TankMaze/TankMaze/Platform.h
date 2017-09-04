#pragma once
#include <SDL.h>
class Platform
{
public:
	Platform(SDL_Renderer *renderer, int platX, int platY, int platH, int platW);
	~Platform();
	SDL_Rect platformRect;
	void platDraw(SDL_Renderer *renderer);
};

