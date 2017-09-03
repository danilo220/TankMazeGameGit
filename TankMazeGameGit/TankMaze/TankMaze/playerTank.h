#pragma once
#include "tanksEnemy.h"
#include "SDL.h"
#include <SDL_image.h>
#include <iostream>
#include <cmath>
#include <stdio.h>
#include <vector>
#include "Bullet.h"

class playerTank
{
public:
	playerTank(SDL_Renderer *renderer, int enemyX, int enemyY, int enemyW, int enemyH, std::string filePath);
	~playerTank();
	void drawPlayer(SDL_Renderer *renderer);
	void playerMove(const Uint8 *keyState, int normalMov, int diagonalMov);
	SDL_Rect playerPosition;
	void playerShot(const Uint8 *keyState, SDL_Renderer *renderer);
	void moveBullet(SDL_Renderer *renderer);
	std::vector<Bullet> bulletVecD;
	std::vector<Bullet> bulletVecW;
	std::vector<Bullet> bulletVecS;
	std::vector<Bullet> bulletVecA;
	std::vector<Bullet> bulletVecWD;
	std::vector<Bullet> bulletVecSD;
	std::vector<Bullet> bulletVecSA;
	std::vector<Bullet> bulletVecWA;

private:
	SDL_Texture *texture;
	SDL_Rect windowRect;
	SDL_Surface *playerBMP;
	SDL_RendererFlip flipType;
	SDL_Point* center = NULL;
	double angle = 0.0;
	bool d;
	bool s;
	bool a;
	bool w;
	bool dShoot = false;
	bool sShoot = false;
	bool aShoot = false;
	bool wShoot = false;
	/*bool shoot = false;*/
	//bool dShoot;
	//bool sShoot;
	//bool aShoot;
	//bool wShoot;
	bool shoot;
	bool wShootPressed;
	bool dShootPressed;
	/*Bullet newBulletW(5, 5);*/
	/*Bullet newOnek(20, 20);*/

	bool spacePressed = false;
	bool xPos = false;
	bool yPos = false;
	bool wdShoot = false;
	bool sdShoot = false;
	bool saShoot = false;
	bool waShoot = false;
};

