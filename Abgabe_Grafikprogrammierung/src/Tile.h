#pragma once
#include <SDL.h>
#include "Config.h"		//for Tilesize and Directoins

using namespace Directions;

class Tile 
{
public:
	Tile * up;
	Tile * down;
	Tile * left;
	Tile * right;
	Tile * invalid; 
	
	int gridPosX;
	int gridPosY;
	int absPosX;
	int absPosY;

	SDL_Rect UpTile;
	SDL_Rect DownTile;
	SDL_Rect LeftTile;
	SDL_Rect RightTile;

	Tile(int _posX, int _posY);
	bool visited;
	bool changed;
	bool isStart;
	bool isEnd;

	void CreateTile(SDL_Rect _Tile, SDL_Window *Window);
	void draw(SDL_Window *Window);

	void setDirection(EDirections _direction, Tile* _tile);
	Tile getDirection(EDirections _direction);

};