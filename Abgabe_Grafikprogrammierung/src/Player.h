#include "SDL.h"		//for Colour
#include "Array2d.h"
#include "Config.h"
//#include"Labyrinth.h"

class Player 
{
public:
	int m_iPlayerPosX;
	int m_iPlayerPosY;
	Uint32 ColourBody;
	Uint32 ColourFace;

	Player(int _fPlayerX, int _fPlayerY)
	{
		m_iPlayerPosX = _fPlayerX;
		m_iPlayerPosY = _fPlayerY;
		ColourBody = COLOUR_BODY;
		ColourFace = COLOUR_FACE;
	}

	void CreatePlayer(SDL_Window *Window);
	void MovePlayer(SDL_Event _Movement);

	
};