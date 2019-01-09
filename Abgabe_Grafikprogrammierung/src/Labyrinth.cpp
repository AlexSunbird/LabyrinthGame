#include "Labyrinth.h"
#include "Config.h"
#include <algorithm>			//std::find
#include <iostream>				//for cout



void Labyrinth::GenerateLabyrinth(int _x, int _y, SDL_Window *Window)
{
	//funktion die für jedes gridtile nachbarn zurückgibt(kooridinaten)
	//jedem tile muss random richtung zugeordnet werden

	myLab = GridTiles<Tile>(_x, _y);

	std::vector<std::pair<int, int>> todo;
	
	int randX = rand() % GRIDSIZE + 1;
	int randY = rand() % GRIDSIZE + 1; 

	todo.push_back(std::pair<int, int>(0, 0));

	while (!todo.empty())
	{
		std::pair<int, int> currentTile = todo.back();

		std::vector<EDirections> directions;

		std::pair<int, int> nextTile = std::pair<int, int>(NULL, NULL);
		
		while (directions.size() > 0) {
			EDirections randomDirection = directions[rand() % directions.size() + 1];
			int xInBounds = currentTile.first + GetDirectionX(directions[randomDirection]); 
			int yInBounds = currentTile.second + GetDirectionY(directions[randomDirection]);

			if (xInBounds >= 0 && xInBounds < GRIDSIZE && yInBounds >= 0 && yInBounds < GRIDSIZE)
			{
				std::pair<int, int> tempTile(xInBounds, yInBounds);
				if (!TileIsVisited(todo, tempTile)) 
				{
					nextTile = tempTile;
					break;
				}
			}

			if (nextTile != std::pair<int, int>(NULL, NULL))
			{
				todo.push_back(nextTile);

			}
		}
	}
	//for (int i = 0; i < _x; i++)
	//	for (int j = 0; j < _y; j++)
	//	{
	//		myLab.Set(i, j, RandomNum());
	//	}
}

void Labyrinth::RenderLabyrinth(int _x, int _y, SDL_Window *Window)
{
	//for (int i = 0; i < myLab.Width(); i++)
	//	for (int j = 0; j < myLab.Height(); j++)
	//	{
	//		SDL_Rect WallTile;
	//		WallTile.x = i * _x;
	//		WallTile.y = j * _y;
	//		WallTile.w = _x;
	//		WallTile.h = _y;
	//		ColourLabyrinth = COLOUR_WALL;
	//		if (myLab.Get(i, j) < 1)
	//		{
	//			SDL_FillRect(SDL_GetWindowSurface(Window), &WallTile, ColourLabyrinth);
	//		}
	//	}
}

int Labyrinth::RandomNum()
{
	int randomval = rand() % 2;
	return randomval;
}

bool Labyrinth::TileIsVisited(std::vector<std::pair<int, int>> _vectorOfTiles, std::pair<int, int> _pairToCheck)
{
	bool visited; 
	if (std::find(_vectorOfTiles.begin(), _vectorOfTiles.end(), _pairToCheck) == _vectorOfTiles.end())
	{
		visited = true;
	}
	else {
		visited = false;
	}
	return visited;
}

int Labyrinth::GetDirectionX(EDirections direction)
{
	switch (direction) {
	case LEFT:
		return -1;
		break;
	case RIGHT:
		return 1;
		break;
	default:
		break;
	}
}

int Labyrinth::GetDirectionY(EDirections direction)
{
	switch (direction) {
	case DOWN:
		return 1;
		break;
	case UP:
		return -1;
		break;
	default:
		break;
	}
}
