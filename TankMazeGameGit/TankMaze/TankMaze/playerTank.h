#pragma once
#include "tanksEnemy.h"
#include "SDL.h"
#include <SDL_image.h>
#include <iostream>
class playerTank
{
public:
	playerTank(SDL_Renderer *renderer, int enemyX, int enemyY, int enemyW, int enemyH, std::string filePath);
	~playerTank();
	void drawPlayer(SDL_Renderer *renderer);
	void playerMove(const Uint8 *keyState);
	SDL_Rect playerPosition;

private:
	SDL_Texture *texture;
	SDL_Rect windowRect;
	SDL_Surface *playerBMP;

};

