#include <xtl.h>

#include "GamePad.h"
#include "Polyhedral.h"
#include "Player.h"
#include "Timer.h"
#include "xbsound.h"
#include "stdio.h"

#ifndef WORLD
#define WORLD

#define WOLRD_0	0.0f
#define WORLD_X	160.0f
#define WORLD_Y	80.0f
#define WORLD_Z 20.0f

#define SCREEN_CUT_X 32
#define SCREEN_CUT_Y 32

#define PLAYER_RADIUS	2.0f
#define BALL_RADIUS		0.19f
#define MAX_VERTEXES	20000
#define MAX_NUM_BOARDS	128
#define NUM_BALLS		150

#define AIM_HIGH		0.08f
#define AIM_SPREAD		0.014f

#define BALLSTATE_READY		0
#define BALLSTATE_INAIR		1
#define BALLSTATE_HITWALL	2
#define BALLSTATE_HITPLAYER	3

#define GRAVITY		32.0f
#define BALL_FPS	200.0f

typedef struct s_Board
{
	float x1, x2;
	float y1, y2;
	float z1, z2;
}t_Board, *p_Board;

typedef struct c_Ball
{
public:
	FLOAT translation_x, translation_y, translation_z;
	FLOAT vt_x, vt_y, vt_z;
	FLOAT velocity_x, velocity_y, velocity_z;
	DWORD State;
	DWORD player;
}t_Ball, *p_Ball;

typedef class c_World
{
public:
	LPDIRECT3DVERTEXBUFFER8 pD3DVertexBuffer;
	LPDIRECT3DDEVICE8 pD3DDevice;

	DWORD	firesound;
	DWORD	thwacksound;
	DWORD	ouchsound;
	CXBSound * fire[3];
	CXBSound * thwack[3];
	CXBSound * ouch[3];
	CXBSound * firstblood;
	CXBSound * doublekill;
	CXBSound * redwins;
	CXBSound * bluewins;
	CXBSound * rumble;

	LPDIRECT3DTEXTURE8 g_pD3DTextureFloor;
	LPDIRECT3DTEXTURE8 g_pD3DTextureWall;
	LPDIRECT3DTEXTURE8 g_pD3DTextureFaceRed;
	LPDIRECT3DTEXTURE8 g_pD3DTextureDeadRed;
	LPDIRECT3DTEXTURE8 g_pD3DTextureFaceBlue;
	LPDIRECT3DTEXTURE8 g_pD3DTextureDeadBlue;
	LPDIRECT3DTEXTURE8 g_pD3DTexturePBall;
	LPDIRECT3DTEXTURE8 g_pD3DTextureBoard;
	LPDIRECT3DTEXTURE8 g_pD3DTextureSky;

	p_GamePads	pGamePads;
	p_Timer		pTimer;

	int CurrBall;
	int CurrLevel;
	t_Ball Balls[NUM_BALLS];
	t_Board BoardsAll[5][MAX_NUM_BOARDS];
	t_Board* Boards;

	p_Player pPlayer[4];

	FLOAT random1;
	FLOAT random2;
	FLOAT random3;

	DWORD num_boards[5];
	DWORD vertexbufferoffsets[5];

	DWORD bfirstblood;

	DWORD wait;

	c_World(LPDIRECT3DDEVICE8 pD3DD, p_GamePads pGPs);
	void UpdateWorld();
	void c_World::BallCollided(int n);
	int c_World::TestCollisionP(	float px, float py1, float py2, float pz1, float pz2,
								float x1, float y1, float z1, float vx, float vy, float vz);
	int c_World::TestCollisionN(	float px, float py1, float py2, float pz1, float pz2,
								float x1, float y1, float z1, float vx, float vy, float vz);
	~c_World();
}t_World, *p_World;

#endif