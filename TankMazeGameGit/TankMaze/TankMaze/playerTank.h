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
	void playerMove(const Uint8 *keyState);
	SDL_Rect playerPosition;
	void playerShot(const Uint8 *keyState, SDL_Renderer *renderer);
	void moveBullet(SDL_Renderer *renderer);
	//SDL_Rect playerBullet;
	//void drawBullet(SDL_Renderer *renderer);
	//Uint8 *SDL_GetKeyState(int *numkeys);

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
	std::vector<Bullet> bulletVecD;
	std::vector<Bullet> bulletVecW;
	std::vector<Bullet> bulletVecS;
	std::vector<Bullet> bulletVecA;
	bool spacePressed = false;
	//Bullet newBullet(int f, int a);
	//Bullet newBullet();

};

