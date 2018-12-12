#include "Tile.h"		
#include "Config.h"		//for Tilesize

void Tile::draw()
{
	
}

Tile::Tile(int _posX, int _posY)
{
	posX = _posX;
	posY = _posY;
	absPosX = _posX * TILESIZE;
	absPosY = _posY * TILESIZE;
}

