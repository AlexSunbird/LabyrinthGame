#pragma once
#include <SDL.h>
#include "Config.h"		//for Tilesize and Directoins

using namespace Directions;

class Tile 
{
public:
	Tile(int _posX, int _posY);
	~Tile();

	void CreateTile(SDL_Rect _Tile, SDL_Window *Window);
	void draw(SDL_Window *Window);

	void setDirection(EDirections _direction, Tile* _tile);
	Tile getDirection(EDirections _direction);

	int gridPosX;
	int gridPosY;
	int absPosX;
	int absPosY;

	bool visited;
	bool changed;

private:
	Tile * up;
	Tile * down;
	Tile * left;
	Tile * right;
	Tile * invalid; 

	SDL_Rect UpTile;
	SDL_Rect DownTile;
	SDL_Rect LeftTile;
	SDL_Rect RightTile;

	bool isStart;
	bool isEnd;
};