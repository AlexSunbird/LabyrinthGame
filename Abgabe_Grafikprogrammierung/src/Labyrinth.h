#pragma once
#include "SDL.h"		//for Colour
#include "Array2d.h"	//for GridTiles
#include "Tile.h"

class Labyrinth
{
public:
	Uint32 ColourLabyrinth;
	int RandomNum();

	enum EDirections {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	bool TileIsVisited(std::vector<std::pair<int, int>> _vectorOfTiles, std::pair<int, int> _pairToCheck);

	int GetDirectionX(EDirections direction);
	int GetDirectionY(EDirections direction);

	GridTiles<Tile> myLab;

	void GenerateLabyrinth(int _xSize, int _ySize, SDL_Window *Window);
	void RenderLabyrinth(int _xPos, int _yPos, SDL_Window *Window);
};