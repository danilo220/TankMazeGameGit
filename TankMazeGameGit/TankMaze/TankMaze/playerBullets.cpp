#include "playerBullets.h"
#include <vector>


playerBullets::playerBullets()
{
	//std::vector <playerBullets*> bullets;
	playerBulletRect.x = 50;
	playerBulletRect.y = 50;
	playerBulletRect.w = playerBulletRect.h = 10;	
	//playerBullets bulleting[10];
}


playerBullets::~playerBullets()
{
}

void playerBullets::shooting()
{
	playerBulletRect.x = 100;
	playerBulletRect.y = 50;
	shoot2 = true;
	if (shoot2)
	{
		playerBulletRect.x += 2;
	}
	//playerBulletRect.x += 2;
	//bullets2.push_back(new playerBullets);
}
void playerBullets::drawBullets(SDL_Renderer *renderer)
{
	/*bullets2.push_back(new playerBullets);
	for (int i = 0; i < bullets2.size(); i++)
	{
		SDL_SetRenderDrawColor(renderer, 0, 162, 232, 1.0);
		SDL_RenderFillRect(renderer, &playerBulletRect);
	}*/
	SDL_SetRenderDrawColor(renderer, 0, 162, 232, 1.0);
	SDL_RenderFillRect(renderer, &playerBulletRect);
}