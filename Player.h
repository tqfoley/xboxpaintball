#include <xtl.h>
#include "Timer.h"
#include "Gamepad.h"

#ifndef PLAYER
#define PLAYER

#define FOV_NORMAL_ANGLE	D3DX_PI/3.0f
#define FOV_ZOOMED_ANGLE	D3DX_PI/8.0f

#define FOV_SPEED	2.5f
#define FOV_NORMAL	0
#define FOV_NORMALC	1

#define FOV_ZOOM	10
#define FOV_ZOOMC	11

#define PLAYER_FIRE_SPEED	0.16f
#define PLAYER_RUN_SPEED	20.0f
#define DUCK_SPEED	10.0f

typedef class c_Player
{
public:
	p_Timer pTimer;

	XINPUT_GAMEPAD *pGamepad;

	FLOAT TransX;
	FLOAT TransY;
	FLOAT TransZ;

	FLOAT Theta;
	FLOAT Phi;

	FLOAT LookX;
	FLOAT LookY;
	FLOAT LookZ;

	FLOAT MovementVelocity;
	FLOAT MovementDirection;

	FLOAT vtX;
	FLOAT vtY;

	FLOAT NextShot;
	DWORD Firing;
	DWORD Dead;

	FLOAT FOV;
	DWORD FOVState;
	FLOAT InvertThumb;

	D3DVIEWPORT8 viewport;

	c_Player(p_Timer pTime, PXINPUT_GAMEPAD pGP, DWORD vpheight, DWORD vpwidth, DWORD vpx, DWORD vpy);
	void UpdatePlayer();
	~c_Player();
} *p_Player;


#endif