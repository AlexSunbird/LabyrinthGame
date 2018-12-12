#include "SDL.h"		//for Colour
#include "Array2d.h"

class Labyrinth
{
public:
	Uint32 ColourLabyrinth;
	int RandomNum();

	GridTiles<int> myLab;

	void GenerateLabyrinth(int _xSize, int _ySize, SDL_Window *Window);
	void RenderLabyrinth(int _xPos, int _yPos, SDL_Window *Window);
};