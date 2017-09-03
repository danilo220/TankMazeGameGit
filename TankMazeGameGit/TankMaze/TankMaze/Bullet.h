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
	SDL_Rect bulletRect;
	void bulletMoveW(int speedW);
	void bulletMoveD(int speedD);
	void bulletMoveA(int speedA);
	void bulletMoveS(int speedS);
	void bulletMoveWD(int speedWD);
	void bulletMoveSD(int speedSD);
	void bulletMoveSA(int speedSA);
	void bulletMoveWA(int speedWA);
};

