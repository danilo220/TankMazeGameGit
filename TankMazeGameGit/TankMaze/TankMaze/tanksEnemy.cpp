#include "tanksEnemy.h"
#include "SDL.h"
#include <SDL_image.h>
#include <iostream>

tanksEnemy::tanksEnemy(SDL_Renderer *renderer, int enemyX, int enemyY, int enemyW, int enemyH, std::string filePath)
{
	//loading image
	enemyTanksBMP = IMG_Load(filePath.c_str());
	if (enemyTanksBMP == nullptr)
	{
		std::cout << "Image error" << SDL_GetError() << std::endl;
	}
	//creating texture
	texture = SDL_CreateTextureFromSurface(renderer, enemyTanksBMP);
	if (texture == nullptr)
	{
		std::cout << "texture error" << SDL_GetError() << std::endl;
	}
	SDL_FreeSurface(enemyTanksBMP);

	//creating tanks
	enemyTanksRectPosition.x = enemyX;
	enemyTanksRectPosition.y = enemyY;
	enemyTanksRectPosition.h = enemyH;
	enemyTanksRectPosition.w = enemyW;

	//windowRect
	windowRect.x = 0;
	windowRect.y = 0;
	windowRect.h = 780;
	windowRect.w = 1500;
}
tanksEnemy::~tanksEnemy()
{
	SDL_DestroyTexture(texture);
}

void tanksEnemy::drawTanks(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, texture, &windowRect, &enemyTanksRectPosition);
}