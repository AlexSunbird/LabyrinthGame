#include "Tile.h"		
#include "Config.h"		//for Tilesize
#include <SDL.h>

void Tile::draw()
{
	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;

	//SDL_Rect Tile;
	//
	//Tile.x = absPosX;
	//Tile.y = absPosY;
	//Tile.h = TILESIZE + TILESIZE / 2;
	//Tile.w = TILESIZE + TILESIZE / 2;
	
	if (up == nullptr)
	{
		
	}
	//TODO 1 tile 9x9, dann ground rauszeichnen/draufzeichnen (oder 9x9 ground und dann wänder drüber zeichnen)
	//if (this.north == null)
	//{
	//	line(this.absPosX, this.absPosY, this.absPosX + offset, this.absPosY);
	//}
}

Tile::Tile(int _posX, int _posY)
{
	gridPosX = _posX;
	gridPosY = _posY;
	absPosX = _posX * TILESIZE;
	absPosY = _posY * TILESIZE;
}

