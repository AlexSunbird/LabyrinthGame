#pragma once
#include "SDL.h"		//for Colour

class Player 
{
public:
	Player(int _fPlayerX, int _fPlayerY);
	~Player();
	int m_iPlayerPosX;
	int m_iPlayerPosY;

	void CreatePlayer(SDL_Window *Window);
	void MovePlayer(SDL_Event _Movement);

private:
	Uint32 ColourBody;
	Uint32 ColourFace;

	//BodyParts
	SDL_Rect PlayerBody;
	SDL_Rect PlayerHead;
	SDL_Rect PlayerEyeLeft;
	SDL_Rect PlayerEyeRight;
};