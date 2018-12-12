#include "Player.h"
#include "Config.h"


void Player::CreatePlayer(SDL_Window *Window)
{
	//BodyParts
	SDL_Rect PlayerBody;
	SDL_Rect PlayerHead;
	SDL_Rect PlayerEyeLeft;
	SDL_Rect PlayerEyeRight;

	//Body
	PlayerBody.x = m_iPlayerPosX + 4;
	PlayerBody.y = m_iPlayerPosY;
	PlayerBody.w = 8;
	PlayerBody.h = TILESIZE/*16*/;

	//Head
	PlayerHead.x = m_iPlayerPosX;
	PlayerHead.y = m_iPlayerPosY;
	PlayerHead.w = TILESIZE/*16*/;
	PlayerHead.h = 11;

	//Face
	PlayerEyeLeft.x = m_iPlayerPosX + 3;
	PlayerEyeLeft.y = m_iPlayerPosY + 2;
	PlayerEyeLeft.w = 4;
	PlayerEyeLeft.h = 5;
	PlayerEyeRight.x = m_iPlayerPosX + 9;
	PlayerEyeRight.y = m_iPlayerPosY + 2;
	PlayerEyeRight.w = 4;
	PlayerEyeRight.h = 5;


	SDL_FillRect(SDL_GetWindowSurface(Window), &PlayerBody, ColourBody);
	SDL_FillRect(SDL_GetWindowSurface(Window), &PlayerHead, ColourBody);
	SDL_FillRect(SDL_GetWindowSurface(Window), &PlayerEyeLeft, ColourFace);
	SDL_FillRect(SDL_GetWindowSurface(Window), &PlayerEyeRight, ColourFace);

}


void Player::MovePlayer(SDL_Event _Movement)
{
	if (_Movement.type == SDL_KEYDOWN)
	{
		switch (_Movement.key.keysym.sym)
		{
		case SDLK_a:
			m_iPlayerPosX -= TILESIZE;
			break;
		case SDLK_d:
			m_iPlayerPosX += TILESIZE;
			break;
		case SDLK_w:
			m_iPlayerPosY -= TILESIZE;
			break;
		case SDLK_s:
			m_iPlayerPosY += TILESIZE;
			break;
		default:
			break;
		}
	}
}
