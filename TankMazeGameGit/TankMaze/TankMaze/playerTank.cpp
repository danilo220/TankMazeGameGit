#include "playerTank.h"



playerTank::playerTank(SDL_Renderer *renderer, int enemyX, int enemyY, int enemyW, int enemyH, std::string filePath)
{
	//loading image
	playerBMP = IMG_Load(filePath.c_str());
	if (playerBMP == nullptr)
	{
		std::cout << "Image error" << SDL_GetError() << std::endl;
	}
	//creating texture
	texture = SDL_CreateTextureFromSurface(renderer, playerBMP);
	if (texture == nullptr)
	{
		std::cout << "texture error" << SDL_GetError() << std::endl;
	}
	SDL_FreeSurface(playerBMP);

	//creating tanks
	playerPosition.x = enemyX;
	playerPosition.y = enemyY;
	playerPosition.h = enemyH;
	playerPosition.w = enemyW;

	//windowRect
	windowRect.x = 0;
	windowRect.y = 0;
	windowRect.h = 780;
	windowRect.w = 1500;
}


playerTank::~playerTank()
{
	SDL_DestroyTexture(texture);
}

void playerTank::drawPlayer(SDL_Renderer *renderer)
{
	SDL_RenderCopy(renderer, texture, &windowRect, &playerPosition);
}

void playerTank::playerMove(const Uint8 *keyState)
{
	if (keyState[SDL_SCANCODE_D])
	{
		playerPosition.x += 5;
	}
	else if (keyState[SDL_SCANCODE_A])
	{
		playerPosition.x -= 5;
		if(playerPosition.x < 0)
		{
			playerPosition.x = 0;
		}
	}
	else if (keyState[SDL_SCANCODE_W])
	{
		playerPosition.y -= 5;
	}

	else if (keyState[SDL_SCANCODE_S])
	{
		playerPosition.y += 5;
	}
	else if (keyState[SDL_SCANCODE_D && SDL_SCANCODE_S])
	{
		playerPosition.x += 5;
		playerPosition.y += 5;
	}
	
}