#pragma once
#include "SDL.h"
#include <vector>
class playerBullets
{
public:
	playerBullets();
	~playerBullets();
	void drawBullets(SDL_Renderer *renderer);
	int bullets = 5;
	SDL_Rect playerBulletRect;
	void shooting();
	std::vector<playerBullets*> bullets2;
	bool shoot2 = false;
};
