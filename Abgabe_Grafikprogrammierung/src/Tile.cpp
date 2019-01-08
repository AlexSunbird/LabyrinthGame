#include "Tile.h"		
#include "Config.h"		//for Tilesize

void Tile::draw(SDL_Window *Window)
{
	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;
	

	
	if (up == nullptr)
	{
		CreateTile(UpTile, Window);
		SDL_Rect UpWall;
		UpWall.x = absPosX;
		UpWall.y = absPosY;
		UpWall.h = TILESIZE * 0.5;
		UpWall.w = TILESIZE * 2;
	}

	if (down == nullptr)
	{
		CreateTile(DownTile, Window);
		SDL_Rect DownWall;
		DownWall.x = absPosX;
		DownWall.y = absPosY + TILESIZE * 1.5;
		DownWall.h = TILESIZE * 0.5;
		DownWall.w = TILESIZE * 2;
	}

	if (left == nullptr)
	{
		CreateTile(LeftTile, Window);
		SDL_Rect LeftWall;
		LeftWall.x = absPosX;
		LeftWall.y = absPosY;
		LeftWall.h = TILESIZE * 2;
		LeftWall.w = TILESIZE * 0.5;
	}

	if (right == nullptr)
	{
		CreateTile(RightTile, Window);
		SDL_Rect RightWall;
		RightWall.x = absPosX + TILESIZE * 1.5;
		RightWall.y = absPosY;
		RightWall.h = TILESIZE * 2;
		RightWall.w = TILESIZE * 0.5;
	}

}

Tile::Tile(int _posX, int _posY) : 
	gridPosX(_posX),
	gridPosY(_posY),
	absPosX(_posX * TILESIZE),
	absPosY(_posY * TILESIZE)
{
}

void Tile::CreateTile(SDL_Rect _Tile, SDL_Window *Window)
{
	_Tile.x = absPosX;
	_Tile.y = absPosY;
	_Tile.h = TILESIZE * 1.5;
	_Tile.w = TILESIZE * 1.5;

	SDL_FillRect(SDL_GetWindowSurface(Window), &_Tile, COLOUR_BACKGROUND);
}
