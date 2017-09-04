#include "Collision.h"



Collision::Collision(SDL_Renderer *renderer)
{
}


Collision::~Collision()
{
}

void Collision::collisionClass(tanksEnemy tankEnemies7, playerTank player)
{
	//D collision
	for (int i = 0; i < player.bulletVecD.size(); i++)
	{
		SDL_bool collisionSix = SDL_HasIntersection(&tankEnemies7.enemyTanksRectPosition, &player.bulletVecD.at(i).bulletRect);
		if (collisionSix)
		{
			tankEnemies7.~tanksEnemy();
		}
	}
}