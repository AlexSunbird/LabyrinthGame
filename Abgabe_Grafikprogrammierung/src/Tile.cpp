#include "Tile.h"	

void Tile::draw(SDL_Window *Window)
{
	up = nullptr;
	down = nullptr;
	left = nullptr;
	right = nullptr;

	if (up == nullptr)
	{
		CreateTile(UpTile, Window);
		SDL_Rect UpWall;
		UpWall.x = absPosX;
		UpWall.y = absPosY;
		UpWall.h = TILESIZE * 0.5;
		UpWall.w = TILESIZE * 2;
	}

	if (down == nullptr)
	{
		CreateTile(DownTile, Window);
		SDL_Rect DownWall;
		DownWall.x = absPosX;
		DownWall.y = absPosY + TILESIZE * 1.5;
		DownWall.h = TILESIZE * 0.5;
		DownWall.w = TILESIZE * 2;
	}

	if (left == nullptr)
	{
		CreateTile(LeftTile, Window);
		SDL_Rect LeftWall;
		LeftWall.x = absPosX;
		LeftWall.y = absPosY;
		LeftWall.h = TILESIZE * 2;
		LeftWall.w = TILESIZE * 0.5;
	}

	if (right == nullptr)
	{
		CreateTile(RightTile, Window);
		SDL_Rect RightWall;
		RightWall.x = absPosX + TILESIZE * 1.5;
		RightWall.y = absPosY;
		RightWall.h = TILESIZE * 2;
		RightWall.w = TILESIZE * 0.5;
	}

}

Tile::Tile(int _posX, int _posY) :
	gridPosX(_posX),
	gridPosY(_posY),
	absPosX(_posX * TILESIZE),
	absPosY(_posY * TILESIZE),
	visited(false),
	changed(false)
{
}

void Tile::CreateTile(SDL_Rect _Tile, SDL_Window *Window)
{
	_Tile.x = absPosX;
	_Tile.y = absPosY;
	_Tile.h = TILESIZE * 1.5;
	_Tile.w = TILESIZE * 1.5;

	SDL_FillRect(SDL_GetWindowSurface(Window), &_Tile, COLOUR_BACKGROUND);
}

//sets direction to go to from current Tile
void Tile::setDirection(EDirections _direction, Tile* _tile)
{
	switch (_direction) {
	case DOWN:
		this->down = _tile;
		break;
	case UP:
		this->up = _tile;
		break;
	case LEFT:
		this->left = _tile;
		break;
	case RIGHT:
		this->right = _tile;
		break;
	default:
		break;
	}
}

//gets directin to go to from current tile
Tile Tile::getDirection(EDirections _direction)
{
	switch (_direction) {
	case DOWN:
		return *this->down;
		break;
	case UP:
		return *this->up;
		break;
	case LEFT:
		return *this->left;
		break;
	case RIGHT:
		return *this->right;
		break;
	default:
		break;
	}
}