#pragma once
#include <SDL.h>

class tanks
{
public:
	tanks(SDL_Renderer *renderer);
	~tanks();
	void drawTanks(SDL_Renderer *renderer);
	void move(const Uint8 *keyState);
private:
	SDL_Rect tanksRect;

};