#include "MainGame.h"

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
	//enemies
	tanksEnemy tankEnemies(renderer, 0, 200, 50, 50, "enemyTank.png");
	tanksEnemy tankEnemies2(renderer, 200, 300, 50, 50, "enemyTank.png");
	tanksEnemy tankEnemies3(renderer, 600, 200, 50, 50, "enemyTank.png");
	tanksEnemy tankEnemies4(renderer, 1400, 500, 50, 50, "enemyTank.png");
	tanksEnemy tankEnemies5(renderer, 900, 0, 50, 50, "enemyTank.png");
	tanksEnemy tankEnemies6(renderer, 500, 720, 50, 50, "enemyTank.png");


	//player
	playerTank player(renderer, 0, 720, 50, 50, "playerTank.png");

	//platform
	//bottom ones
	Platform platformBYL(renderer, 100, 630, 10, 580); //SDL_Renderer *renderer, int platX, int platY, int platH, int platW
	Platform platformBYR(renderer, 820, 630, 10, 580);
	Platform platformBXL(renderer, 100, 450, 180, 10);
	Platform platformBXR(renderer, 1400, 450, 190, 10);

	//top one
	Platform platformTYL(renderer, 100, 150, 10, 580);
	Platform platformTYR(renderer, 820, 150, 10, 580);
	Platform platformTXL(renderer, 100, 150, 180, 10);
	Platform platformTXR(renderer, 1400, 150, 180, 10);

	//center one
	Platform platformCY(renderer, 650, 500, 10, 150);
	Platform platformCL(renderer, 650, 350, 150, 10);
	Platform platformCR(renderer, 800, 350, 160, 10);
	
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

		//drawing enemy
		tankEnemies.drawTanks(renderer);
		tankEnemies2.drawTanks(renderer);
		tankEnemies3.drawTanks(renderer);
		tankEnemies4.drawTanks(renderer);
		tankEnemies5.drawTanks(renderer);
		tankEnemies6.drawTanks(renderer);

		//draw platform
		platformBYL.platDraw(renderer);
		platformTYL.platDraw(renderer);
		platformBXL.platDraw(renderer);
		platformTXL.platDraw(renderer);
		platformTXR.platDraw(renderer);
		platformBXR.platDraw(renderer);
		platformBYR.platDraw(renderer);
		platformTYR.platDraw(renderer);
		platformCY.platDraw(renderer);
		platformCL.platDraw(renderer);
		platformCR.platDraw(renderer);


		//Platform platformBYL(renderer, 100, 630, 10, 600); //SDL_Renderer *renderer, int platX, int platY, int platH, int platW
		//Platform platformBYR(renderer, 800, 630, 10, 600);
		//Platform platformBXL(renderer, 100, 430, 200, 10);
		//Platform platformBXR(renderer, 1400, 430, 210, 10);

		//Platform platformTYL(renderer, 100, 150, 10, 580);
		//Platform platformTYR(renderer, 820, 150, 10, 580);
		//Platform platformTXL(renderer, 100, 150, 180, 10);
		//Platform platformTXR(renderer, 1400, 150, 180, 10);

		//playerPlatForm Collision
		
		//Y Ones
		SDL_bool CplatformBYL = SDL_HasIntersection(&platformBYL.platformRect, &player.playerPosition);
		SDL_bool CplatformBYR = SDL_HasIntersection(&platformBYR.platformRect, &player.playerPosition);
		SDL_bool CplatformTYL = SDL_HasIntersection(&platformTYL.platformRect, &player.playerPosition);
		SDL_bool CplatformTYR = SDL_HasIntersection(&platformTYR.platformRect, &player.playerPosition);

		if (CplatformBYL || CplatformBYR || CplatformTYL || CplatformTYR)
		{
			//bottom W
			if (player.w && (CplatformBYL || CplatformBYR))
			{
				player.playerPosition.y = platformBYR.platformRect.y - -10;
			}
			//botton S
			if (player.s && (CplatformBYL || CplatformBYR))
			{
				player.playerPosition.y = platformBYL.platformRect.y - player.playerPosition.h;
			}
			//top W
			if (player.w && (CplatformTYL || CplatformTYR))
			{
				player.playerPosition.y = platformTYL.platformRect.y - -10;
			}
			//top S
			if (player.s && (CplatformTYL || CplatformTYR))
			{
				player.playerPosition.y = platformTYL.platformRect.y - player.playerPosition.h;
			}
		}


		//plat1
		//SDL_bool collisionPlat1 = SDL_HasIntersection(&platformBY.platformRect, &player.playerPosition);
		//if (collisionPlat1)
		//{
		//	if (player.w)
		//	{
		//		player.playerPosition.y = platformBY.platformRect.y - -10;
		//	}
		//	if (player.s)
		//	{
		//		player.playerPosition.y = platformBY.platformRect.y - player.playerPosition.h;
		//	}
		//}

		////plat2
		//SDL_bool collisionPlat2 = SDL_HasIntersection(&platformTY.platformRect, &player.playerPosition);
		//if (collisionPlat2)
		//{
		//	if (player.a)
		//	{
		//		player.playerPosition.x = platformTY.platformRect.x - -10;
		//	}
		//	if (player.d)
		//	{
		//		player.playerPosition.x = platformTY.platformRect.x - player.playerPosition.w;
		//	}
		//}


	
		//platform collision
		//D
		//for (int i = 0; i < player.bulletVecD.size(); i++)
		//{
		//	SDL_bool collisionTwo = SDL_HasIntersection(&platform2.platformRect, &player.bulletVecD.at(i).bulletRect);
		//	if (collisionTwo)
		//	{
		//		/*player.dShoot = false;*/

		//		/*player.bulletVecD.at(i).bulletMoveD(0);*/
		//		player.bulletVecD.at(i).~Bullet();
		//		player.bulletVecD.at(i).bulletMoveD(8);
		//		/*player.bulletVecD.at(i).bulletRect.x -= 100;*/
		//		/*player.bulletVecWD.at(i).bulletRect.y -= 50;*/ 
		//	}
		//}

		////WD
		//for (int i = 0; i < player.bulletVecWD.size(); i++)
		//{
		//	SDL_bool collisionOne = SDL_HasIntersection(&platform.platformRect, &player.bulletVecWD.at(i).bulletRect);
		//	if (collisionOne)
		//	{
		//		/*player.bulletVecWD.at(i).bulletRect.x += 3;*/
		//		player.bulletVecWD.at(i).~Bullet();
		//		player.bulletVecWD.at(i).bulletRect.y += 50;
		//	}

		//	SDL_bool collisionTwo = SDL_HasIntersection(&platform2.platformRect, &player.bulletVecWD.at(i).bulletRect);
		//	if (collisionTwo)
		//	{
		//		player.bulletVecWD.at(i).~Bullet();
		//		//player.bulletVecWD.at(i).bulletRect.x -= 30;
		//		//player.bulletVecWD.at(i).bulletRect.y -= 30;
		//	}
		//}

		//bullet collision
		//W collision
		for (int i = 0; i < player.bulletVecW.size(); i++) 
		{
			SDL_bool collisionOne = SDL_HasIntersection(&tankEnemies.enemyTanksRectPosition, &player.bulletVecW.at(i).bulletRect);
			if (collisionOne)
			{
				tankEnemies.~tanksEnemy();
			}
			SDL_bool collisionTwo = SDL_HasIntersection(&tankEnemies2.enemyTanksRectPosition, &player.bulletVecW.at(i).bulletRect);
			if (collisionTwo)
			{
				tankEnemies2.~tanksEnemy();
			}
			SDL_bool collisionThree = SDL_HasIntersection(&tankEnemies3.enemyTanksRectPosition, &player.bulletVecW.at(i).bulletRect);
			if (collisionThree)
			{
				tankEnemies3.~tanksEnemy();
			}

			SDL_bool collisionFour = SDL_HasIntersection(&tankEnemies4.enemyTanksRectPosition, &player.bulletVecW.at(i).bulletRect);
			if (collisionFour)
			{
				tankEnemies4.~tanksEnemy();
			}

			SDL_bool collisionFive = SDL_HasIntersection(&tankEnemies5.enemyTanksRectPosition, &player.bulletVecW.at(i).bulletRect);
			if (collisionFive)
			{
				tankEnemies5.~tanksEnemy();
			}

			SDL_bool collisionSix = SDL_HasIntersection(&tankEnemies6.enemyTanksRectPosition, &player.bulletVecW.at(i).bulletRect);
			if (collisionSix)
			{
				tankEnemies6.~tanksEnemy();
			}


		}

		//A collision
		for (int i = 0; i < player.bulletVecA.size(); i++)
		{
			SDL_bool collisionOne = SDL_HasIntersection(&tankEnemies.enemyTanksRectPosition, &player.bulletVecA.at(i).bulletRect);
			if (collisionOne)
			{
				tankEnemies.~tanksEnemy();
			}
			SDL_bool collisionTwo = SDL_HasIntersection(&tankEnemies2.enemyTanksRectPosition, &player.bulletVecA.at(i).bulletRect);
			if (collisionTwo)
			{
				tankEnemies2.~tanksEnemy();
			}
			SDL_bool collisionThree = SDL_HasIntersection(&tankEnemies3.enemyTanksRectPosition, &player.bulletVecA.at(i).bulletRect);
			if (collisionThree)
			{
				tankEnemies3.~tanksEnemy();
			}

			SDL_bool collisionFour = SDL_HasIntersection(&tankEnemies4.enemyTanksRectPosition, &player.bulletVecA.at(i).bulletRect);
			if (collisionFour)
			{
				tankEnemies4.~tanksEnemy();
			}

			SDL_bool collisionFive = SDL_HasIntersection(&tankEnemies5.enemyTanksRectPosition, &player.bulletVecA.at(i).bulletRect);
			if (collisionFive)
			{
				tankEnemies5.~tanksEnemy();
			}

			SDL_bool collisionSix = SDL_HasIntersection(&tankEnemies6.enemyTanksRectPosition, &player.bulletVecA.at(i).bulletRect);
			if (collisionSix)
			{
				tankEnemies6.~tanksEnemy();
			}
		}

		//S collision
		for (int i = 0; i < player.bulletVecS.size(); i++)
		{
			SDL_bool collisionOne = SDL_HasIntersection(&tankEnemies.enemyTanksRectPosition, &player.bulletVecS.at(i).bulletRect);
			if (collisionOne)
			{
				tankEnemies.~tanksEnemy();
			}
			SDL_bool collisionTwo = SDL_HasIntersection(&tankEnemies2.enemyTanksRectPosition, &player.bulletVecS.at(i).bulletRect);
			if (collisionTwo)
			{
				tankEnemies2.~tanksEnemy();
			}
			SDL_bool collisionThree = SDL_HasIntersection(&tankEnemies3.enemyTanksRectPosition, &player.bulletVecS.at(i).bulletRect);
			if (collisionThree)
			{
				tankEnemies3.~tanksEnemy();
			}

			SDL_bool collisionFour = SDL_HasIntersection(&tankEnemies4.enemyTanksRectPosition, &player.bulletVecS.at(i).bulletRect);
			if (collisionFour)
			{
				tankEnemies4.~tanksEnemy();
			}

			SDL_bool collisionFive = SDL_HasIntersection(&tankEnemies5.enemyTanksRectPosition, &player.bulletVecS.at(i).bulletRect);
			if (collisionFive)
			{
				tankEnemies5.~tanksEnemy();
			}

			SDL_bool collisionSix = SDL_HasIntersection(&tankEnemies6.enemyTanksRectPosition, &player.bulletVecS.at(i).bulletRect);
			if (collisionSix)
			{
				tankEnemies6.~tanksEnemy();
			}
		}

		//D collision
		for (int i = 0; i < player.bulletVecD.size(); i++)
		{
			SDL_bool collisionOne = SDL_HasIntersection(&tankEnemies.enemyTanksRectPosition, &player.bulletVecD.at(i).bulletRect);
			if (collisionOne)
			{
				tankEnemies.~tanksEnemy();
			}
			SDL_bool collisionTwo = SDL_HasIntersection(&tankEnemies2.enemyTanksRectPosition, &player.bulletVecD.at(i).bulletRect);
			if (collisionTwo)
			{
				tankEnemies2.~tanksEnemy();
			}
			SDL_bool collisionThree = SDL_HasIntersection(&tankEnemies3.enemyTanksRectPosition, &player.bulletVecD.at(i).bulletRect);
			if (collisionThree)
			{
				tankEnemies3.~tanksEnemy();
			}

			SDL_bool collisionFour = SDL_HasIntersection(&tankEnemies4.enemyTanksRectPosition, &player.bulletVecD.at(i).bulletRect);
			if (collisionFour)
			{
				tankEnemies4.~tanksEnemy();
			}

			SDL_bool collisionFive = SDL_HasIntersection(&tankEnemies5.enemyTanksRectPosition, &player.bulletVecD.at(i).bulletRect);
			if (collisionFive)
			{
				tankEnemies5.~tanksEnemy();
			}

			SDL_bool collisionSix = SDL_HasIntersection(&tankEnemies6.enemyTanksRectPosition, &player.bulletVecD.at(i).bulletRect);
			if (collisionSix)
			{
				tankEnemies6.~tanksEnemy();
			}
		}

		//WA collision
		for (int i = 0; i < player.bulletVecWA.size(); i++)
		{
			SDL_bool collisionOne = SDL_HasIntersection(&tankEnemies.enemyTanksRectPosition, &player.bulletVecWA.at(i).bulletRect);
			if (collisionOne)
			{
				tankEnemies.~tanksEnemy();
			}
			SDL_bool collisionTwo = SDL_HasIntersection(&tankEnemies2.enemyTanksRectPosition, &player.bulletVecWA.at(i).bulletRect);
			if (collisionTwo)
			{
				tankEnemies2.~tanksEnemy();
			}
			SDL_bool collisionThree = SDL_HasIntersection(&tankEnemies3.enemyTanksRectPosition, &player.bulletVecWA.at(i).bulletRect);
			if (collisionThree)
			{
				tankEnemies3.~tanksEnemy();
			}

			SDL_bool collisionFour = SDL_HasIntersection(&tankEnemies4.enemyTanksRectPosition, &player.bulletVecWA.at(i).bulletRect);
			if (collisionFour)
			{
				tankEnemies4.~tanksEnemy();
			}

			SDL_bool collisionFive = SDL_HasIntersection(&tankEnemies5.enemyTanksRectPosition, &player.bulletVecWA.at(i).bulletRect);
			if (collisionFive)
			{
				tankEnemies5.~tanksEnemy();
			}

			SDL_bool collisionSix = SDL_HasIntersection(&tankEnemies6.enemyTanksRectPosition, &player.bulletVecWA.at(i).bulletRect);
			if (collisionSix)
			{
				tankEnemies6.~tanksEnemy();
			}

		}

		//WD collision
		for (int i = 0; i < player.bulletVecWD.size(); i++)
		{
			SDL_bool collisionOne = SDL_HasIntersection(&tankEnemies.enemyTanksRectPosition, &player.bulletVecWD.at(i).bulletRect);
			if (collisionOne)
			{
				tankEnemies.~tanksEnemy();
			}
			SDL_bool collisionTwo = SDL_HasIntersection(&tankEnemies2.enemyTanksRectPosition, &player.bulletVecWD.at(i).bulletRect);
			if (collisionTwo)
			{
				tankEnemies2.~tanksEnemy();
			}
			SDL_bool collisionThree = SDL_HasIntersection(&tankEnemies3.enemyTanksRectPosition, &player.bulletVecWD.at(i).bulletRect);
			if (collisionThree)
			{
				tankEnemies3.~tanksEnemy();
			}

			SDL_bool collisionFour = SDL_HasIntersection(&tankEnemies4.enemyTanksRectPosition, &player.bulletVecWD.at(i).bulletRect);
			if (collisionFour)
			{
				tankEnemies4.~tanksEnemy();
			}

			SDL_bool collisionFive = SDL_HasIntersection(&tankEnemies5.enemyTanksRectPosition, &player.bulletVecWD.at(i).bulletRect);
			if (collisionFive)
			{
				tankEnemies5.~tanksEnemy();
			}

			SDL_bool collisionSix = SDL_HasIntersection(&tankEnemies6.enemyTanksRectPosition, &player.bulletVecWD.at(i).bulletRect);
			if (collisionSix)
			{
				tankEnemies6.~tanksEnemy();
			}
		}

		for (int i = 0; i < player.bulletVecSA.size(); i++)
		{
			SDL_bool collisionOne = SDL_HasIntersection(&tankEnemies.enemyTanksRectPosition, &player.bulletVecSA.at(i).bulletRect);
			if (collisionOne)
			{
				tankEnemies.~tanksEnemy();
			}
			SDL_bool collisionTwo = SDL_HasIntersection(&tankEnemies2.enemyTanksRectPosition, &player.bulletVecSA.at(i).bulletRect);
			if (collisionTwo)
			{
				tankEnemies2.~tanksEnemy();
			}
			SDL_bool collisionThree = SDL_HasIntersection(&tankEnemies3.enemyTanksRectPosition, &player.bulletVecSA.at(i).bulletRect);
			if (collisionThree)
			{
				tankEnemies3.~tanksEnemy();
			}

			SDL_bool collisionFour = SDL_HasIntersection(&tankEnemies4.enemyTanksRectPosition, &player.bulletVecSA.at(i).bulletRect);
			if (collisionFour)
			{
				tankEnemies4.~tanksEnemy();
			}

			SDL_bool collisionFive = SDL_HasIntersection(&tankEnemies5.enemyTanksRectPosition, &player.bulletVecSA.at(i).bulletRect);
			if (collisionFive)
			{
				tankEnemies5.~tanksEnemy();
			}

			SDL_bool collisionSix = SDL_HasIntersection(&tankEnemies6.enemyTanksRectPosition, &player.bulletVecSA.at(i).bulletRect);
			if (collisionSix)
			{
				tankEnemies6.~tanksEnemy();
			}
		}

		for (int i = 0; i < player.bulletVecSD.size(); i++)
		{
			SDL_bool collisionOne = SDL_HasIntersection(&tankEnemies.enemyTanksRectPosition, &player.bulletVecSD.at(i).bulletRect);
			if (collisionOne)
			{
				tankEnemies.~tanksEnemy();
			}
			SDL_bool collisionTwo = SDL_HasIntersection(&tankEnemies2.enemyTanksRectPosition, &player.bulletVecSD.at(i).bulletRect);
			if (collisionTwo)
			{
				tankEnemies2.~tanksEnemy();
			}
			SDL_bool collisionThree = SDL_HasIntersection(&tankEnemies3.enemyTanksRectPosition, &player.bulletVecSD.at(i).bulletRect);
			if (collisionThree)
			{
				tankEnemies3.~tanksEnemy();
			}

			SDL_bool collisionFour = SDL_HasIntersection(&tankEnemies4.enemyTanksRectPosition, &player.bulletVecSD.at(i).bulletRect);
			if (collisionFour)
			{
				tankEnemies4.~tanksEnemy();
			}

			SDL_bool collisionFive = SDL_HasIntersection(&tankEnemies5.enemyTanksRectPosition, &player.bulletVecSD.at(i).bulletRect);
			if (collisionFive)
			{
				tankEnemies5.~tanksEnemy();
			}

			SDL_bool collisionSix = SDL_HasIntersection(&tankEnemies6.enemyTanksRectPosition, &player.bulletVecSD.at(i).bulletRect);
			if (collisionSix)
			{
				tankEnemies6.~tanksEnemy();
			}
		}

		SDL_RenderPresent(renderer);
	}
	//SDL_Delay(3000);
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	window = nullptr;
	renderer = nullptr;
	SDL_Quit();
}