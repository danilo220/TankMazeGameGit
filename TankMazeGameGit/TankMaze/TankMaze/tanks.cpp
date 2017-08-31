#include "tanks.h"
#include "SDL.h"

tanks::tanks(SDL_Renderer *renderer)
{
	//creating tanks
	tanksRect.x = 0;
	tanksRect.y = 600;
	tanksRect.h = 40;
	tanksRect.w = 40;
}
tanks::~tanks()
{
}