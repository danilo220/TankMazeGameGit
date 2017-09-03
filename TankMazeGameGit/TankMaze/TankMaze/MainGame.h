#pragma once
#include <SDL.h>
#include <iostream>
#include <string>

class MainGame
{
public:
	MainGame();
	~MainGame();
	void runGame();

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