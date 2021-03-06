#pragma once
#include "SDL.h"		//for Colour
#include "Array2d.h"	//for GridTiles
#include "Tile.h"

class Labyrinth
{
public:
	Labyrinth();
	~Labyrinth();

	void GenerateLabyrinth(int _xSize, int _ySize, SDL_Window *Window);
	void RenderLabyrinth(int _xPos, int _yPos, SDL_Window *Window);

	void Carve(Tile* _source, Tile* _target, EDirections _direction);

	int GetDirectionX(EDirections _direction);
	int GetDirectionY(EDirections _direction);
	EDirections GetOppositeDirection(EDirections _direction);

private:
	Uint32 ColourLabyrinth;
	GridTiles<Tile*> myLab;
	int RandomNum();
};