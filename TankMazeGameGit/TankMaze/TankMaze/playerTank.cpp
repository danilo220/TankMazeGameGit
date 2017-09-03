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

	//creating tank
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
	SDL_RenderCopyEx(renderer, texture, &windowRect, &playerPosition, angle, center, flipType);
}

void playerTank::playerMove(const Uint8 *keyState, int normalMov, int diagonalMov)
{
	//keep making boolean of the buttons pressed to false
	d = false;
	s = false;
	a = false;
	w = false;
	aShoot = wShoot = dShoot = sShoot = wdShoot = sdShoot = waShoot = saShoot = false;

	//moving player
	if (keyState[SDL_SCANCODE_D])
	{
		playerPosition.x += normalMov;
		if (playerPosition.x + playerPosition.w > 1500) //right wall collision
		{
			playerPosition.x = 1500 - playerPosition.w;
		}
		angle = -90;
		flipType = SDL_FLIP_HORIZONTAL;
		d = true;
		dShoot = true;
		xPos = true;
	}
	if (keyState[SDL_SCANCODE_A])
	{
		playerPosition.x -= normalMov;
		if(playerPosition.x < 0) //left wall colision
		{
			playerPosition.x = 0;
		}
		angle = 90;
		flipType = SDL_FLIP_HORIZONTAL;
		a = true;
		aShoot = true;
		xPos = true;
	}
	if (keyState[SDL_SCANCODE_W]) 
	{
		playerPosition.y -= normalMov;
		if (playerPosition.y + playerPosition.h < 50) //ceiling collision
		{
			playerPosition.y =  50 - playerPosition.h;
		}
		angle = 0.0;
		flipType = SDL_FLIP_VERTICAL;
		w = true;
		wShoot = true;
		yPos = true;
	}

	if (keyState[SDL_SCANCODE_S])
	{
		playerPosition.y += normalMov;
		if (playerPosition.y + playerPosition.h > 779) //floor colission
		{
			playerPosition.y = 779 - playerPosition.h;
		}
		angle = 0.0;
		flipType = SDL_FLIP_NONE;
		s = true;
		sShoot = true;
		yPos = true;
	}

	//diagonal moviment
	if (s && d)
	{
		angle = -32;
		playerPosition.y -= diagonalMov;
		playerPosition.x -= diagonalMov;
		sdShoot = true;
		sShoot = false;
		dShoot = false;
	}
	if (s && a)
	{
		angle = 32;
		playerPosition.y -= diagonalMov;
		playerPosition.x += diagonalMov;
		saShoot = true;
		sShoot = false;
		aShoot = false;
	}
	if (w && d)
	{
		flipType = SDL_FLIP_HORIZONTAL;
		angle = -132;
		playerPosition.y += diagonalMov;
		playerPosition.x -= diagonalMov;
		wdShoot = true;
		wShoot = false;
		dShoot = false;
	}
	if (w && a)
	{
		flipType = SDL_FLIP_HORIZONTAL;
		angle = 132;
		playerPosition.y += diagonalMov;
		playerPosition.x += diagonalMov;
		waShoot = true;
		wShoot = false;
		aShoot = false;
	}
}

void playerTank::playerShot(const Uint8 *keyState, SDL_Renderer *renderer) //shooting with space
{
	if (keyState[SDL_SCANCODE_SPACE] == SDL_PRESSED)
	{
		shoot = true;

	}
	if (shoot == true && keyState[SDL_SCANCODE_SPACE] == SDL_RELEASED) //make new bullets for each direction the player is facing
	{
		if (dShoot)
		{
			
			Bullet newBulletD(10, 10);
			newBulletD.bulletPosition(playerPosition.x, playerPosition.y, xPos, yPos);
			bulletVecD.push_back(newBulletD);
			shoot = false;
		}
		if (wShoot)
		{

			Bullet newBulletW(10, 10);
			newBulletW.bulletPosition(playerPosition.x, playerPosition.y, xPos, yPos);
			bulletVecW.push_back(newBulletW);
			shoot = false;
		}
		if (aShoot)
		{
			Bullet newBulletA(10, 10);
			newBulletA.bulletPosition(playerPosition.x, playerPosition.y, xPos, yPos);
			bulletVecA.push_back(newBulletA);
			shoot = false;
		}

		if (sShoot)
		{
			Bullet newBulletS(10, 10);
			newBulletS.bulletPosition(playerPosition.x, playerPosition.y, xPos, yPos);
			bulletVecS.push_back(newBulletS);
			shoot = false;
		}

		//diagonal shooting
		if (wdShoot)
		{
			Bullet newBulletWD(10, 10);
			newBulletWD.bulletPosition(playerPosition.x, playerPosition.y, xPos, yPos);
			bulletVecWD.push_back(newBulletWD);
			shoot = false;
		}
		if (sdShoot)
		{
			Bullet newBulletSD(10, 10);
			newBulletSD.bulletPosition(playerPosition.x, playerPosition.y, xPos, yPos);
			bulletVecSD.push_back(newBulletSD);
			shoot = false;
		}

		if (saShoot)
		{
			Bullet newBulletSA(10, 10);
			newBulletSA.bulletPosition(playerPosition.x, playerPosition.y, xPos, yPos);
			bulletVecSA.push_back(newBulletSA);
			shoot = false;
		}

		if (waShoot)
		{
			Bullet newBulletWA(10, 10);
			newBulletWA.bulletPosition(playerPosition.x, playerPosition.y, xPos, yPos);
			bulletVecWA.push_back(newBulletWA);
			shoot = false;
		}
	}
	//moving the bullets across the screen 
	for (int i = 0; i < bulletVecD.size(); i++)
	{
		bulletVecD[i].bulletDraw(renderer);
		bulletVecD[i].bulletMoveD(3);
	}

	for (int k = 0; k < bulletVecW.size(); k++)
	{
		bulletVecW[k].bulletDraw(renderer);
		bulletVecW[k].bulletMoveW(3);
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

	for (int p = 0; p < bulletVecWD.size(); p++)
	{
		bulletVecWD[p].bulletDraw(renderer);
		bulletVecWD[p].bulletMoveWD(3);
	}

	for (int sd = 0; sd < bulletVecSD.size(); sd++)
	{
		bulletVecSD[sd].bulletDraw(renderer);
		bulletVecSD[sd].bulletMoveSD(3);
	}

	for (int sa = 0; sa < bulletVecSA.size(); sa++)
	{
		bulletVecSA[sa].bulletDraw(renderer);
		bulletVecSA[sa].bulletMoveSA(3);
	}

	for (int wa = 0; wa < bulletVecWA.size(); wa++)
	{
		bulletVecWA[wa].bulletDraw(renderer);
		bulletVecWA[wa].bulletMoveWA(3);
	}
}