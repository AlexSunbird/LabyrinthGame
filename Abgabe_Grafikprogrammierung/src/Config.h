#pragma once

//Define Grid Tiles
#define GRIDSIZE 45
#define TILESIZE 16
#define SCREENSIZE GRIDSIZE*TILESIZE

//Define Colours
#define COLOUR_BODY 0x2E8585
#define COLOUR_FACE 0x7A0011
#define COLOUR_BACKGROUND 0xC79723
#define COLOUR_WALL 0xBD2136

namespace Directions
{
	enum EDirections {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};
}