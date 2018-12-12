#include "Labyrinth.h"
#include <vector>
#include <time.h>
#include <iostream>
#include <stdlib.h>


void Labyrinth::GenerateLabyrinth(int _x, int _y, SDL_Window *Window)
{
	myLab = GridTiles<int>(_x, _y, 0);
	for (int i = 0; i < _x; i++)
		for (int j = 0; j < _y; j++)
		{
			myLab.Set(i, j, RandomNum());
		}
}

void Labyrinth::RenderLabyrinth(int _x, int _y, SDL_Window *Window)
{
	for (int i = 0; i < myLab.Width(); i++)
		for (int j = 0; j < myLab.Height(); j++)
		{
			SDL_Rect WallTile;
			WallTile.x = i * _x;
			WallTile.y = j * _y;
			WallTile.w = _x;
			WallTile.h = _y;
			ColourLabyrinth = 0xBD2136;
			if (myLab.Get(i, j) < 1)
			{
				SDL_FillRect(SDL_GetWindowSurface(Window), &WallTile, ColourLabyrinth);
			}
		}
}

int Labyrinth::RandomNum()
{
	int randomval = rand() % 2;
	return randomval;
}
