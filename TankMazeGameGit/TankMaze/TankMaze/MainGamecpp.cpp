#include "SDL.h"
#include "SDL_image.h"
#include "MainGame.h"
#include "tanksEnemy.h"
#include "playerTank.h"
#include <stdio.h>

MainGame::MainGame()
{

}

MainGame::~MainGame()
{

}

void MainGame::runGame()
{
	initSystems();
	gameRunning();
}

void MainGame::initSystems()
{
	//window
	window = SDL_CreateWindow("Tank Maze", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_SHOWN); //SDL_WINDOWPOS_UNDEFINED
	if (window == NULL)
	{
		std::cout << "WindowError" << SDL_GetError() << std::endl;
	}
	//renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		std::cout << "RendererError" << SDL_GetError() << std::endl;
	}

}

void MainGame::gameRunning()
{
	tanksEnemy tankEnemies(renderer, 0, 200, 50, 50, "enemyTank.png");
	tanksEnemy tankEnemies2(renderer, 200, 300, 50, 50, "enemyTank.png");
	tanksEnemy tankEnemies3(renderer, 600, 200, 50, 50, "enemyTank.png");
	playerTank player(renderer, 0, 720, 50, 50, "playerTank.png");
	//Bullet bullets(NULL, NULL);
	bool running = true;
	while (running)
	{
		while (SDL_PollEvent(&eevent) != 0)
		{
			if (eevent.type == SDL_QUIT)
			{
				running = false;
			}
		}
		SDL_SetRenderDrawColor(renderer, 178, 174, 254, 1); //background 178, 174, 254, 1)
		SDL_RenderClear(renderer); //clearrender
		//key state
		keyState = SDL_GetKeyboardState(NULL);
		//player
		player.drawPlayer(renderer);
		player.playerMove(keyState, 3, 1);
		player.playerShot(keyState, renderer);

		//tank 1
		tankEnemies.drawTanks(renderer);
		//tank 2
		tankEnemies2.drawTanks(renderer);
		//tank 3
		tankEnemies3.drawTanks(renderer);

		//SDL_bool collisionOne = SDL_HasIntersection(&tankEnemies.enemyTanksRectPosition, &player.playerPosition);
		//if (collisionOne)
		//{
		//	//std::cout << "enemy killed" << std::endl;
		//	tankEnemies.~tanksEnemy();
		//}

		//SDL_bool collisionOne = SDL_HasIntersection(&tankEnemies.enemyTanksRectPosition, &bullets.bulletRect);
		//if (collisionOne)
		//{
		//	//std::cout << "enemy killed" << std::endl;
		//	tankEnemies.~tanksEnemy();
		//}

		
		

		SDL_RenderPresent(renderer);
	}
	//SDL_Delay(3000);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	window = nullptr;
	renderer = nullptr;
	SDL_Quit();
}