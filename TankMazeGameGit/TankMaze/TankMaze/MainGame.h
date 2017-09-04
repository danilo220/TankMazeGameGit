#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "tanksEnemy.h"
#include "playerTank.h"
#include "Platform.h"
#include <stdio.h>

class MainGame
{
public:
	MainGame();
	~MainGame();
	void runGame();
	bool dShootmain = false;

private:
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event eevent;
	const Uint8 *keyState;
	int screenHeight = 780;
	int screenWidth = 1500;
	void initSystems();
	void gameRunning();
};