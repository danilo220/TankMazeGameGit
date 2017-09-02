#pragma once
#include <SDL.h>
#include <vector>
class Bullet
{
public:
	Bullet(int bulletH, int bulletW);
	~Bullet();
	void bulletPosition(int bulletX, int bulletY);
	void bulletDraw(SDL_Renderer *renderer);
	void bulletMove(int speedBullet);
	SDL_Rect bulletRect;
};

