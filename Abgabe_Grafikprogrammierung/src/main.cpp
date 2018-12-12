#include "SDL.h"
#include "Player.h"
#include "Labyrinth.h"
#include "Config.h"

#include <stdio.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int iPlayerPosX, iPlayerPosY;
int randomPos;

bool CheckIfPlayerOnGround(std::vector<std::pair<int, int>>& _wall, Player& _player)
{
	std::pair<int, int> PlayerPosPair(_player.m_iPlayerPosX / TILESIZE, _player.m_iPlayerPosY/ TILESIZE);
	auto it = std::find(_wall.begin(), _wall.end(), PlayerPosPair);

	if (it == _wall.end())
	{
		std::cout << "Player on Ground" << "\n";
		return true;
	}
	else
	{
		std::cout << "Player on Wall" << "\n";
		return false;
	}
}

int main(int, char **)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *Window = SDL_CreateWindow("The Labyrinth", 50, 50, SCREENSIZE, SCREENSIZE, SDL_WINDOW_SHOWN);

	//Generate Labyrinth
	Labyrinth myLabyrinth;
	myLabyrinth.GenerateLabyrinth(GRIDSIZE, GRIDSIZE, Window);

	//Get Labyrinth's Path and Wall
	std::vector<std::pair<int, int>> Ground;
	std::vector<std::pair<int, int>> Wall;
	for (int i = 0; i < myLabyrinth.myLab.Width(); i++)
		for (int j = 0; j < myLabyrinth.myLab.Height(); j++)
		{
			if (myLabyrinth.myLab.Get(i, j) >= 1)
			{
				Ground.push_back(std::pair<int, int>(i, j));
			}
			else
			{
				Wall.push_back(std::pair<int, int>(i, j));
			}
		}

	//Random Player Start Position
	srand(time(NULL));
	randomPos = rand() % Ground.size() + 0;
	iPlayerPosX = Ground[randomPos].first * TILESIZE;
	iPlayerPosY = Ground[randomPos].second * TILESIZE;
	Player myPlayer(iPlayerPosX, iPlayerPosY);

	//GAME LOOP//
	bool Running = true;
	while (Running)
	{
		int lastPlayerX = myPlayer.m_iPlayerPosX;
		int lastPlayerY = myPlayer.m_iPlayerPosY;

		SDL_Event Event;
		while (SDL_PollEvent(&Event))
		{
			switch (Event.type)
			{
			case SDL_KEYDOWN:
				myPlayer.MovePlayer(Event);
				break;
			case SDL_QUIT:
				Running = false;
				break;

			}
		}
		SDL_FillRect(SDL_GetWindowSurface(Window), 0, 0xC79723);
		myLabyrinth.RenderLabyrinth(TILESIZE, TILESIZE, Window);
		if (!(CheckIfPlayerOnGround(Wall, myPlayer)))
		{
			myPlayer.m_iPlayerPosX = lastPlayerX;
			myPlayer.m_iPlayerPosY = lastPlayerY;
		}
		myPlayer.CreatePlayer(Window);
		SDL_UpdateWindowSurface(Window);
	}

	SDL_DestroyWindow(Window);

	SDL_Quit();

	return 0;
}
