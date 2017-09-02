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
void Bullet::bulletMove(int speedBullet)
{
	bulletRect.x += speedBullet;
}