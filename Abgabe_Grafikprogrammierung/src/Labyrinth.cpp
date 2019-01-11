#include "Labyrinth.h"
#include "Config.h"
#include <algorithm>			//std::find
#include <iostream>				//for cout



void Labyrinth::GenerateLabyrinth(int _x, int _y, SDL_Window *Window)
{
	//funktion die für jedes gridtile nachbarn zur�ckgibt(kooridinaten)
	//jedem tile muss random richtung zugeordnet werden

	myLab = GridTiles<Tile*>(_x, _y);
	//grid mit tiles füllen(absPos) dann pairs durch tiles ersetzen
	for(int i = 0; i <= GRIDSIZE; i++)
		for (int j = 0; j <= GRIDSIZE; j++)
		{
			myLab.Ref(i, j)->gridPosX = i;
			myLab.Ref(i, j)->gridPosY = j;
		}

	std::vector<Tile*> todo;
	
	int randX = rand() % GRIDSIZE + 1;
	int randY = rand() % GRIDSIZE + 1; 

	todo.push_back(myLab.Ref(0, 0));

	while (!todo.empty())
	{
		Tile* currentTile = todo.back();
		currentTile->visited = true; 

		std::vector<EDirections> directions;

		Tile* nextTile = nullptr;
		
		while (directions.size() > 0) {
			EDirections randomDirection = directions[rand() % directions.size() + 1];
			int xInBounds = currentTile->gridPosX + GetDirectionX(directions[randomDirection]); 
			int yInBounds = currentTile->gridPosY + GetDirectionY(directions[randomDirection]);

			if (xInBounds >= 0 && xInBounds < GRIDSIZE && yInBounds >= 0 && yInBounds < GRIDSIZE)
			{
				Tile* tempTile(myLab.Ref(xInBounds, yInBounds));
				if (!tempTile->visited) 
				{
					nextTile = tempTile;
					break;
				}
			}

			if (nextTile != nullptr)
			{
				todo.push_back(nextTile);
				//Carve
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


int Labyrinth::GetDirectionX(EDirections _direction)
{
	switch (_direction) {
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

int Labyrinth::GetDirectionY(EDirections _direction)
{
	switch (_direction) {
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


Labyrinth::EDirections Labyrinth::GetOppositeDirection(EDirections _direction)
{
	switch (_direction) {
	case DOWN:
		return UP;
		break;
	case UP:
		return DOWN;
		break;
	case LEFT:
		return RIGHT;
		break;
	case RIGHT:
		return LEFT;
		break;
	default:
		break;
	}
}

void Labyrinth::Carve(Tile* _source, Tile* _target, EDirections _direction)
{
	//TODO
}
	
