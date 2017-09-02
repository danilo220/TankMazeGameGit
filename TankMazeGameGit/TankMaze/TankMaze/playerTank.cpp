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

	//bullet
	//playerBullet[5].x = playerPosition.x;
	//playerBullet[5].y = playerPosition.y;
	//playerBullet.x = 50;
	//playerBullet.y = 50;
	//playerBullet.w = playerBullet.h = 10;

	//sShoot = false;
	//dShoot = false;
	//wShoot = false;
	//aShoot = false;
	/*std::vector<Bullet> bulletVec;*/
}


playerTank::~playerTank()
{
	SDL_DestroyTexture(texture);
}

void playerTank::drawPlayer(SDL_Renderer *renderer)
{
	SDL_RenderCopyEx(renderer, texture, &windowRect, &playerPosition, angle, center, flipType);
}

void playerTank::playerMove(const Uint8 *keyState)
{
	d = false;
	s = false;
	a = false;
	w = false;
	if (keyState[SDL_SCANCODE_D])
	{
		playerPosition.x += 2;
		angle = -90;
		flipType = SDL_FLIP_HORIZONTAL;
		d = true;
		dShoot = true;
	}
	if (keyState[SDL_SCANCODE_A])
	{
		playerPosition.x -= 2;
		if(playerPosition.x < 0)
		{
			playerPosition.x = 0;
		}
		angle = 90;
		flipType = SDL_FLIP_HORIZONTAL;
		a = true;
		aShoot = true;
	}
	if (keyState[SDL_SCANCODE_W])
	{
		playerPosition.y -= 2;
		angle = 0.0;
		flipType = SDL_FLIP_VERTICAL;
		w = true;
		wShoot = true;
	}

	if (keyState[SDL_SCANCODE_S])
	{
		playerPosition.y += 2;
		angle = 0.0;
		flipType = SDL_FLIP_NONE;
		s = true;
		sShoot = true;
	}
	if (s && d)
	{
		angle = -32;
		playerPosition.y -= 1;
		playerPosition.x -= 1;
	}
	if (s && a)
	{
		angle = 32;
		playerPosition.y -= 1;
		playerPosition.x += 1;
	}
	if (w && d)
	{
		flipType = SDL_FLIP_HORIZONTAL;
		angle = -132;
		playerPosition.y += 1;
		playerPosition.x -= 1;
	}
	if (w && a)
	{
		flipType = SDL_FLIP_HORIZONTAL;
		angle = 132;
		playerPosition.y += 1;
		playerPosition.x += 1;
	}
}

void playerTank::playerShot(const Uint8 *keyState, SDL_Renderer *renderer)
{
	//if (keyState[SDL_SCANCODE_SPACE])
	//{
	//	playerBullet.x = playerPosition.x +10;
	//	playerBullet.y = playerPosition.y +20;
	//	//playerBullet.x += 5;
	//	shoot = true;
	//}
	//if (shoot)
	//{
	//	if (aShoot)
	//	{
	//		//a = true;
	//		playerBullet.x -= 5;
	//		//aShoot = false;
	//	}

	//	if (dShoot)
	//	{
	//		//d = true;
	//		playerBullet.x += 5;
	//		//dShoot = false;
	//	}

	//	if (wShoot)
	//	{
	//		playerBullet.y -= 5;
	//		//wShoot = false;
	//	}

	//	if (sShoot)
	//	{
	//		playerBullet.y += 5;
	//		//sShoot = false;
	//	}
	//	//playerBullet.x += 5;
	//	//sShoot = false;
	//	//dShoot = false;
	//	//wShoot = false;
	//	//aShoot = false;
	//}
	//std::vector<Bullet> bulletVec;
	/*Bullet newBullet(10, 10);*/
	if (keyState[SDL_SCANCODE_SPACE])
	{
		//playerBullet.x = playerPosition.x +10;
		//playerBullet.y = playerPosition.y +20;
		////playerBullet.x += 5;
		//newBullet(10, 10);
		/*newBullet.bulletPosition(playerPosition.x, playerPosition.y);*/
		shoot = true;

	}
	if (shoot == true)
	{
		Bullet newBullet(10, 10);
		newBullet.bulletPosition(playerPosition.x, playerPosition.y);
		bulletVec.push_back(newBullet);
		//for (int i = 0; i < bulletVec.size(); i++)
		//{
		//	bulletVec[i].bulletDraw(renderer);
		//	bulletVec[i].bulletMove(3);
		//}
		shoot = false;
	}
	for (int i = 0; i < bulletVec.size(); i++)
	{
		bulletVec[i].bulletDraw(renderer);
		bulletVec[i].bulletMove(3);
	}
}
//void playerTank::moveBullet(SDL_Renderer *renderer)
//{
//	std::vector<Bullet> bulletVec;
//	if (shoot)
//	{
//		Bullet newBullet(10, 10);
//		newBullet.bulletPosition(playerPosition.x, playerPosition.y);
//		bulletVec.push_back(newBullet);
//		shoot = false;
//	}
//	for (int i = 0; i < bulletVec.size(); i++)
//	{
//		bulletVec[i].bulletDraw(renderer);
//		bulletVec[i].bulletMove(3);
//	}
//}
//void playerTank::drawBullet(SDL_Renderer *renderer)
//{
//	SDL_SetRenderDrawColor(renderer, 0, 162, 232, 1.0);
//	SDL_RenderFillRect(renderer, &playerBullet);
//}