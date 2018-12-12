#include "SDL.h"		//for Colour

class Player 
{
public:
	int m_iPlayerPosX;
	int m_iPlayerPosY;
	Uint32 ColourBody;
	Uint32 ColourFace;

	Player(int _fPlayerX, int _fPlayerY);

	void CreatePlayer(SDL_Window *Window);
	void MovePlayer(SDL_Event _Movement);

	
};