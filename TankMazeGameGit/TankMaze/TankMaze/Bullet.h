#pragma once
#include <SDL.h>
#include <vector>
class Bullet
{
public:
	Bullet(int bulletH, int bulletW);
	~Bullet();
	void bulletPosition(int bulletX, int bulletY, bool xPos, bool yPos);
	void bulletDraw(SDL_Renderer *renderer);
	void bulletMove(int speedBullet, bool a, bool w, bool d, bool s);
	SDL_Rect bulletRect;
	void bulletMoveW(int speedW);
	void bulletMoveD(int speedD);
	void bulletMoveA(int speedA);
	void bulletMoveS(int speedS);
	//d = w = false;
};

