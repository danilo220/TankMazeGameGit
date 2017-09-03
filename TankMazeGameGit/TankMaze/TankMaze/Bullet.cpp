#include "Bullet.h"



Bullet::Bullet(int bulletH, int bulletW)
{
	bulletRect.h = bulletH;
	bulletRect.w = bulletW;
}


Bullet::~Bullet()
{
}

void Bullet::bulletPosition(int bulletX, int bulletY)
{
	bulletRect.x = bulletX;
	bulletRect.y = bulletY;
}
void Bullet::bulletDraw(SDL_Renderer *renderer)
{
	SDL_SetRenderDrawColor(renderer, 0, 162, 232, 1.0);
	SDL_RenderFillRect(renderer, &bulletRect);
}
void Bullet::bulletMove(int speedBullet,bool a, bool w, bool d, bool s)
{
	if (d)
	{
		bulletRect.x += speedBullet;
		/*d = false;*/
	}

	if (w)
	{
		bulletRect.y -= speedBullet;
		/*w = false;*/
	}
	/*d = w = false;*/
	/*bulletRect.x += speedBullet;*/
}

void Bullet::bulletMoveW(int speedW)
{
	bulletRect.y -= speedW;
}

void Bullet::bulletMoveD(int speedD)
{
	bulletRect.x += speedD;
}

void Bullet::bulletMoveA(int speedA)
{
	bulletRect.x -= speedA;
}

void Bullet::bulletMoveS(int speedS)
{
	bulletRect.y += speedS;
}
