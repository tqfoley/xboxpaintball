#include "Player.h"

c_Player::c_Player(p_Timer pTime, XINPUT_GAMEPAD *pGP, DWORD vpheight, DWORD vpwidth, DWORD vpx, DWORD vpy)
{
	pTimer = pTime;

	pGamepad = pGP;

	TransX = 105.0f;
	TransY= 30.0f;
	TransZ= 5.5f;

	Theta = 0.0f;
	Phi = 3.1415f/2.0f;

	LookX = 1.0f;
	LookY = 1.0f;
	LookZ = 1.0f;

	viewport.Height = vpheight;
	viewport.Width = vpwidth;
	viewport.X = vpx;
	viewport.Y = vpy;
	viewport.MinZ = 0.0f;
	viewport.MaxZ = 1.0f;

	FOV = FOV_NORMAL_ANGLE;
	FOVState = FOV_NORMAL;
	
	MovementVelocity = 0.0f;
	MovementDirection = 0.0f;

	InvertThumb = 1.0f;

	NextShot = 0.0f;
	Firing = 0;
	Dead = 0;
}

void c_Player::UpdatePlayer()
{
	float x, y;

	if(FOVState/10 == 0)
	{
		if(pGamepad->sThumbRX > 8000)
		{
			x = (FLOAT)pGamepad->sThumbRX;
			x -= 7500.0f;
			Theta +=  x * pTimer->fElapsedTime * 0.00006f;
		}
		if(pGamepad->sThumbRX < -8000)
		{
			x = (FLOAT)pGamepad->sThumbRX;
			x += 7500.0f;
			Theta +=  x * pTimer->fElapsedTime * 0.00006f;
		}
		if(pGamepad->sThumbRY > 8000)
		{
			y = (FLOAT)pGamepad->sThumbRY;
			y -= 7500.0f;
			Phi -=  InvertThumb * y * pTimer->fElapsedTime * 0.00006f;
		}
		if(pGamepad->sThumbRY < -8000)
		{
			y = (FLOAT)pGamepad->sThumbRY;
			y += 7500.0f;
			Phi -=  InvertThumb * y * pTimer->fElapsedTime * 0.00006f;
		}

		LookX = cos(Theta)*sin(Phi);
		LookY = sin(Theta)*sin(Phi);
		LookZ = cos(Phi);
	}
	else
	{
		if(pGamepad->sThumbRX > 8000)
		{
			x = (FLOAT)pGamepad->sThumbRX;
			x -= 7500.0f;
			Theta +=  x * pTimer->fElapsedTime * 0.00003f;
		}
		if(pGamepad->sThumbRX < -8000)
		{
			x = (FLOAT)pGamepad->sThumbRX;
			x += 7500.0f;
			Theta +=  x * pTimer->fElapsedTime * 0.00003f;
		}
		if(pGamepad->sThumbRY > 8000)
		{
			y = (FLOAT)pGamepad->sThumbRY;
			y -= 7500.0f;
			Phi -=  InvertThumb * y * pTimer->fElapsedTime * 0.00003f;
		}
		if(pGamepad->sThumbRY < -8000)
		{
			y = (FLOAT)pGamepad->sThumbRY;
			y += 7500.0f;
			Phi -=  InvertThumb * y * pTimer->fElapsedTime * 0.00003f;
		}

		LookX = cos(Theta)*sin(Phi);
		LookY = sin(Theta)*sin(Phi);
		LookZ = cos(Phi);
	}

	if(Dead == 0)
	{
		vtX = 0.0f;
		vtY = 0.0f;

		if(pGamepad->sThumbLY > 20000.0f || pGamepad->sThumbLY < -20000.0f)
		{
			vtY = pGamepad->sThumbLY;
		}
		if(pGamepad->sThumbLX > 20000.0f || pGamepad->sThumbLX < -20000.0f)
		{
			vtX = pGamepad->sThumbLX;
		}

		if(vtY == 0.0f)
		{
			if(vtX == 0.0f)
			{
				MovementVelocity = 0.0f;
				MovementDirection = 0.0f;
			}
			else
			{
				MovementVelocity = PLAYER_RUN_SPEED;
				if(vtX > 0.0f)
                    MovementDirection = Theta + D3DX_PI/2.0f;
				else
					MovementDirection =  Theta - D3DX_PI/2.0f;

			}
		}
		else
		{
			MovementVelocity = PLAYER_RUN_SPEED;
			MovementDirection = atan(vtX/vtY) + Theta;
			if(vtY < 0.0f)
				MovementDirection += D3DX_PI;
			if(vtX == 0.0f)
			{
				if(vtY > 0.0f)
                    MovementDirection = Theta;
				else
					MovementDirection = Theta + D3DX_PI;
			}
		}


		vtX = pTimer->fElapsedTime * cos(MovementDirection) * MovementVelocity;
		vtY = pTimer->fElapsedTime * sin(MovementDirection) * MovementVelocity;
		TransX += vtX;
		TransY += vtY;

		if( (pGamepad->bAnalogButtons[XINPUT_GAMEPAD_LEFT_TRIGGER] > 100) )
		{
			TransZ -= DUCK_SPEED * pTimer->fElapsedTime;
			if(TransZ < 2.5f)
				TransZ = 2.5f;
		}
		else
		{
			TransZ += DUCK_SPEED * pTimer->fElapsedTime;
			if(TransZ > 5.5f)
				TransZ = 5.5f;
		}

		if( (pGamepad->bAnalogButtons[XINPUT_GAMEPAD_A] > 150) )
			InvertThumb = -1.0;

		if( (pGamepad->bAnalogButtons[XINPUT_GAMEPAD_B] > 150) )
			InvertThumb = 1.0;

		//Auto
		if( (pGamepad->bAnalogButtons[XINPUT_GAMEPAD_RIGHT_TRIGGER] > 100) && NextShot <= pTimer->fCurrTime)
		{
				Firing = 1;
				NextShot = pTimer->fCurrTime + PLAYER_FIRE_SPEED;
		}
		else
			Firing = 0;

		//Semi Auto
		/*if( (pGamepad->bAnalogButtons[XINPUT_GAMEPAD_RIGHT_TRIGGER] > 150) && NextShot == 0.0)
		{
				Firing = 1;
				NextShot = 1.0;
		}
		else
			Firing = 0;
		if( pGamepad->bAnalogButtons[XINPUT_GAMEPAD_RIGHT_TRIGGER] < 70)
		{
				NextShot = 0.0;
		}*/


		if(pGamepad->wButtons & XINPUT_GAMEPAD_RIGHT_THUMB)
		{
			if(FOVState%10 == 0)
			{
				if(FOVState == FOV_NORMAL)
				{
					FOVState = FOV_ZOOMC;
				}
				else
				{
					FOVState = FOV_NORMALC;
				}
			}
		}
		else
		{
			if(FOVState%10 == 1)
			{
				FOVState--;
			}
		}
		if(FOVState/10 == 0)
		{
			FOV += FOV_SPEED * pTimer->fElapsedTime;
			if(FOV > FOV_NORMAL_ANGLE)
				FOV = FOV_NORMAL_ANGLE;
		}
		else
		{
			FOV -= FOV_SPEED * pTimer->fElapsedTime;
			if(FOV < FOV_ZOOMED_ANGLE)
				FOV = FOV_ZOOMED_ANGLE;
		}
	}
	else
		Firing = 0;
}

c_Player::~c_Player()
{
}