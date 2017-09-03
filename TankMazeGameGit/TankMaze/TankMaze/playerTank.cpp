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
	aShoot = wShoot = dShoot = sShoot = false;
	wShootPressed = false;
	dShootPressed = false;
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
	if (dShoot)
	{
		dShootPressed = true;
		wShootPressed = false;
	}
	if (wShoot)
	{
		dShootPressed = false;
		wShootPressed = true;
	}
}

void playerTank::playerShot(const Uint8 *keyState, SDL_Renderer *renderer)
{
	if (keyState[SDL_SCANCODE_SPACE] == SDL_PRESSED)
	{
		/*aShoot = wShoot = dShoot = sShoot = false;*/
		shoot = true;

	}
	if (shoot == true && keyState[SDL_SCANCODE_SPACE] == SDL_RELEASED)
	{
		if (dShoot)
		{
			
			Bullet newBulletD(10, 10);
			newBulletD.bulletPosition(playerPosition.x, playerPosition.y);
			bulletVecD.push_back(newBulletD);
			shoot = false;
		}
		if (wShoot)
		{

			Bullet newBulletW(10, 10);
			newBulletW.bulletPosition(playerPosition.x, playerPosition.y);
			bulletVecW.push_back(newBulletW);
			shoot = false;
		}
		if (aShoot)
		{
			Bullet newBulletA(10, 10);
			newBulletA.bulletPosition(playerPosition.x, playerPosition.y);
			bulletVecA.push_back(newBulletA);
			shoot = false;
		}

		if (sShoot)
		{
			Bullet newBulletS(10, 10);
			newBulletS.bulletPosition(playerPosition.x, playerPosition.y);
			bulletVecS.push_back(newBulletS);
			shoot = false;
		}

		//Bullet newBullet(10, 10);
		//newBullet.bulletPosition(playerPosition.x, playerPosition.y);
		//bulletVec.push_back(newBullet);
		//shoot = false;
	}
	for (int i = 0; i < bulletVecD.size(); i++)
	{
		bulletVecD[i].bulletDraw(renderer);
		bulletVecD[i].bulletMoveD(3);
		//dShoot = false;
		//wShoot = false;
		/*bulletVec[i].bulletMove(3, aShoot, wShoot, dShoot, sShoot);*/
		/*bulletVec[i].bulletMove(3, aShoot, wShootPressed, dShootPressed, sShoot);*/
		/*aShoot = wShoot = dShoot = sShoot = false;*/
	}

	for (int k = 0; k < bulletVecW.size(); k++)
	{
		bulletVecW[k].bulletDraw(renderer);
		bulletVecW[k].bulletMoveW(3);
		//dShoot = false;
		//wShoot = false;
		/*bulletVec[i].bulletMove(3, aShoot, wShoot, dShoot, sShoot);*/
		/*bulletVec[i].bulletMove(3, aShoot, wShootPressed, dShootPressed, sShoot);*/
		/*aShoot = wShoot = dShoot = sShoot = false;*/
	}

	for (int l = 0; l < bulletVecS.size(); l++)
	{
		bulletVecS[l].bulletDraw(renderer);
		bulletVecS[l].bulletMoveS(3);
	}
	for (int n = 0; n < bulletVecA.size(); n++)
	{
		bulletVecA[n].bulletDraw(renderer);
		bulletVecA[n].bulletMoveA(3);
	}
	//dShoot = false;
	//wShoot = false;
	/*aShoot = wShoot = dShoot = sShoot = false;*/
}