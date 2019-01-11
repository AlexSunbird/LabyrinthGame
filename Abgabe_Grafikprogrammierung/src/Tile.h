#pragma once
#include <SDL.h>

class Tile
{
public:
	Tile * up;
	Tile * down;
	Tile * left;
	Tile * right;
	
	int gridPosX;
	int gridPosY;
	int absPosX;
	int absPosY;

	SDL_Rect UpTile;
	SDL_Rect DownTile;
	SDL_Rect LeftTile;
	SDL_Rect RightTile;

	Tile(int _posX, int _posY);

	void CreateTile(SDL_Rect _Tile, SDL_Window *Window);
	void draw(SDL_Window *Window);
};