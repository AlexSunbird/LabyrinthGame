#include "Tile.h"		
#include "Config.h"		//for Tilesize

void Tile::draw()
{
	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr; 


	if (up == nullptr)
	{

	}
	//TODO 1 tile 9x9, dann ground rauszeichnen/draufzeichnen oder 9x9 ground und dann wänder drüber zeichnen
	//if (this.north == null)
	//{
	//	line(this.absPosX, this.absPosY, this.absPosX + offset, this.absPosY);
	//}
}

Tile::Tile(int _posX, int _posY)
{
	posX = _posX;
	posY = _posY;
	absPosX = _posX * TILESIZE;
	absPosY = _posY * TILESIZE;
}

