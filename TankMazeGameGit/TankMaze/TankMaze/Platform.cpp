#include "Platform.h"



Platform::Platform(SDL_Renderer *renderer, int platX, int platY, int platH, int platW)
{
	platformRect.x = platX;
	platformRect.y = platY;
	platformRect.h = platH;
	platformRect.w = platW;
}


Platform::~Platform()
{
}

void Platform::platDraw(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 192, 57, 43, 1.0);
	SDL_RenderFillRect(renderer, &platformRect);
}