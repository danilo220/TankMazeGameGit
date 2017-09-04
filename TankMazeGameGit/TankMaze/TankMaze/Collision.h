#pragma once
#include <SDL.h>
#include "tanksEnemy.h"
#include "playerTank.h"
#include <vector>
class Collision
{
public:
	Collision(SDL_Renderer *renderer);
	~Collision();
	//tanksEnemy tankEnemies9();
	void collisionClass(tanksEnemy tankEnemies7, playerTank player);
};

