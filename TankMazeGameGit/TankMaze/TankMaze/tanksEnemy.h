#pragma once
#include <SDL.h>
#include <string>

class tanksEnemy
{
public:
	tanksEnemy(SDL_Renderer *renderer, int enemyX, int enemyY, int enemyW, int enemyH, std::string filePath);
	~tanksEnemy();
	void drawTanks(SDL_Renderer *renderer);
	void enemyMove();
	SDL_Rect enemyTanksRectPosition;
private:
	SDL_Texture *texture;
	SDL_Rect windowRect;
	SDL_Surface *enemyTanksBMP;
	

};