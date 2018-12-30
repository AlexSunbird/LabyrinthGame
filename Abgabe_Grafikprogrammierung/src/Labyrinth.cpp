#include "Labyrinth.h"
#include "Config.h"


void Labyrinth::GenerateLabyrinth(int _x, int _y, SDL_Window *Window)
{
	//funktion die für jedes gridtile nachbarn zurückgibt(kooridinaten)
	myLab = GridTiles<int>(_x, _y, 0);
	//std::vector<std::pair<int, int>> todo;
	//todo.push_back(myLab.Get(0, 0));
	//while (!todo.empty())
	//{
	//	todo
	//}
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
			ColourLabyrinth = COLOUR_WALL;
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


int Labyrinth::GetDirectionX(EDirections direction)
{
	switch (direction) {
	case LEFT:
		return 0;
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
	case UP:
		return 0;
		break;
	case DOWN:
		return 1;
		break;
	default:
		break;
	}
}
