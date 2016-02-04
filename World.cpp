#include "World.h"

c_World::c_World(LPDIRECT3DDEVICE8 pD3DD, p_GamePads pGPs)
{
	pD3DDevice = pD3DD;
	pGamePads = pGPs;

	pTimer = new c_Timer();
	pTimer->UpdateTime();

	p_CUSTOMVERTEX vbWorld;
	vbWorld = (p_CUSTOMVERTEX)malloc(sizeof(t_CUSTOMVERTEX) * MAX_VERTEXES);

	DWORD Num_VertexBuffer = 0;

	t_Board TempBoards[5][MAX_NUM_BOARDS];


	FILE* fh;
	for(DWORD levels = 0; levels < 5; levels++)
	{
		if(levels==0)
			fh = fopen("D:\\level1.txt","r");
		if(levels==1)
			fh = fopen("D:\\level2.txt","r");
		if(levels==2)
			fh = fopen("D:\\level3.txt","r");
		if(levels==3)
			fh = fopen("D:\\level4.txt","r");
		if(levels==4)
			fh = fopen("D:\\level5.txt","r");

		fscanf(fh, " %d ", &(num_boards[levels]));
		for(DWORD i=0; i<num_boards[levels]; i++)
		{
			fscanf(fh, " %f ", &(TempBoards[levels][i].x1));
			fscanf(fh, " %f ", &(TempBoards[levels][i].x2));
			fscanf(fh, " %f ", &(TempBoards[levels][i].y1));
			fscanf(fh, " %f ", &(TempBoards[levels][i].y2));
			fscanf(fh, " %f ", &(TempBoards[levels][i].z1));
			fscanf(fh, " %f ", &(TempBoards[levels][i].z2));
		}
		fclose(fh);


	}

	for(levels = 0; levels < 5; levels++)
	{
		memcpy(&(BoardsAll[levels][0]), &(TempBoards[levels][0]), sizeof(t_Board)*num_boards[levels]);
	}

	CreateNormalIcosahedron(0.0f,0.0f,0.0f,BALL_RADIUS+0.02f,&vbWorld[Num_VertexBuffer], &Num_VertexBuffer, 0xFFFFFFFF);
	CreateNormalIcosahedron(0.0f,0.0f,0.0f,BALL_RADIUS+0.02f,&vbWorld[Num_VertexBuffer], &Num_VertexBuffer, 0x5FFFFFFF);
	CreateNormalIcosahedron(0.0f,0.0f,0.0f,BALL_RADIUS+0.02f,&vbWorld[Num_VertexBuffer], &Num_VertexBuffer, 0x3FFFFFFF);
	CreateNormalIcosahedron(0.0f,0.0f,0.0f,BALL_RADIUS+0.02f,&vbWorld[Num_VertexBuffer], &Num_VertexBuffer, 0x1FFFFFFF);

	CreateNormalSphere80(0.0f,0.0f,0.0f,BALL_RADIUS,&vbWorld[Num_VertexBuffer], &Num_VertexBuffer);
	CreateNormalSphere80(0.0f,0.0f,0.0f,PLAYER_RADIUS,&vbWorld[Num_VertexBuffer], &Num_VertexBuffer);
	CreateNormalSphere180(0.0f,0.0f,0.0f,PLAYER_RADIUS,&vbWorld[Num_VertexBuffer], &Num_VertexBuffer);

	CreateInvertedBox2(	0.0f, WORLD_X,
						0.0f, WORLD_Y,
						0.0f, WORLD_Z,
						&vbWorld[Num_VertexBuffer], &Num_VertexBuffer);

	CreateInvertedHemisphere108(WORLD_X/2.0f, WORLD_Y/2.0f, -50.0f, 150.0f, &vbWorld[Num_VertexBuffer], &Num_VertexBuffer);

	DWORD sum = 0;
	for(levels=0; levels <5; levels++)
	{
		vertexbufferoffsets[levels] = sum;
		Boards = &(BoardsAll[levels][0]);
		sum += num_boards[levels]*36;
		for(DWORD i=0; i<num_boards[levels]; i++)
		{
			CreateNormalBox(	Boards[i].x1,	Boards[i].x2,
								Boards[i].y1,	Boards[i].y2,
								Boards[i].z1,	Boards[i].z2,
								&vbWorld[Num_VertexBuffer], &Num_VertexBuffer);
		}

	}

	pD3DDevice->CreateVertexBuffer(	sizeof(t_CUSTOMVERTEX) * MAX_VERTEXES,
									D3DUSAGE_WRITEONLY,
									D3DFVF_CUSTOMVERTEX,
									D3DPOOL_MANAGED,
									&pD3DVertexBuffer);

	unsigned char *vb_verts;
	pD3DVertexBuffer->Lock(0,0,&vb_verts,0);

	memcpy(vb_verts, vbWorld, sizeof(t_CUSTOMVERTEX) * MAX_VERTEXES);

	pD3DVertexBuffer->Unlock();

	pPlayer[0] = new c_Player(pTimer, pGamePads->pGP1, 240-SCREEN_CUT_Y-4, 320-SCREEN_CUT_X-4, SCREEN_CUT_X, SCREEN_CUT_Y);
	pPlayer[1] = new c_Player(pTimer, pGamePads->pGP2, 240-SCREEN_CUT_Y-4, 320-SCREEN_CUT_X-4, 320+4, SCREEN_CUT_Y);
	pPlayer[2] = new c_Player(pTimer, pGamePads->pGP3, 240-SCREEN_CUT_Y-4, 320-SCREEN_CUT_X-4, SCREEN_CUT_X, 240+4);
	pPlayer[3] = new c_Player(pTimer, pGamePads->pGP4, 240-SCREEN_CUT_Y-4, 320-SCREEN_CUT_X-4, 320+4, 240+4);

	CurrBall = 0;
	for(DWORD i=0; i<NUM_BALLS; i++)
	{
		Balls[i].State = BALLSTATE_READY;
	}

	D3DXCreateTextureFromFileA(pD3DDevice, "D:\\wall.bmp", &g_pD3DTextureWall);
	D3DXCreateTextureFromFileA(pD3DDevice, "D:\\redface.bmp", &g_pD3DTextureFaceRed);
	D3DXCreateTextureFromFileA(pD3DDevice, "D:\\reddead.bmp", &g_pD3DTextureDeadRed);
	D3DXCreateTextureFromFileA(pD3DDevice, "D:\\blueface.bmp", &g_pD3DTextureFaceBlue);
	D3DXCreateTextureFromFileA(pD3DDevice, "D:\\bluedead.bmp", &g_pD3DTextureDeadBlue);
	D3DXCreateTextureFromFileA(pD3DDevice, "D:\\Floor.bmp", &g_pD3DTextureFloor);
	D3DXCreateTextureFromFileA(pD3DDevice, "D:\\PBall.bmp", &g_pD3DTexturePBall);
	D3DXCreateTextureFromFileA(pD3DDevice, "D:\\Board.bmp", &g_pD3DTextureBoard);
	D3DXCreateTextureFromFileA(pD3DDevice, "D:\\Sky.bmp", &g_pD3DTextureSky);

	firesound = 0;
	fire[0] = new CXBSound();
	fire[0]->Create("D:\\fire.wav",0);
	fire[1] = new CXBSound();
	fire[1]->Create("D:\\fire.wav",0);
	fire[2] = new CXBSound();
	fire[2]->Create("D:\\fire.wav",0);

	thwacksound = 0;
	thwack[0] = new CXBSound();
	thwack[0]->Create("D:\\thwack.wav",0);
	thwack[1] = new CXBSound();
	thwack[1]->Create("D:\\thwack.wav",0);
	thwack[2] = new CXBSound();
	thwack[2]->Create("D:\\thwack.wav",0);


	ouchsound = 0;
	ouch[0] = new CXBSound();
	ouch[0]->Create("D:\\ouch.wav",0);
	ouch[1] = new CXBSound();
	ouch[1]->Create("D:\\ouch.wav",0);
	ouch[2] = new CXBSound();
	ouch[2]->Create("D:\\ouch.wav",0);

	bfirstblood = 0;
	firstblood = new CXBSound();
	firstblood->Create("D:\\firstblood.wav",0);

	redwins = new CXBSound();
	redwins->Create("D:\\redwins.wav",0);

	bluewins = new CXBSound();
	bluewins->Create("D:\\bluewins.wav",0);

	rumble = new CXBSound();
	rumble->Create("D:\\rumble.wav",0);


	CurrLevel = 1;
	Boards = &(BoardsAll[CurrLevel][0]);
}

void c_World::BallCollided(int n)
{
	for(DWORD i=0; i<NUM_BALLS; i++)
	{
		if(n != i)
		{
			if(Balls[i].State == BALLSTATE_HITWALL)
			{
				if(	((Balls[i].translation_x - Balls[n].translation_x) <  0.4f) && 
					((Balls[i].translation_x - Balls[n].translation_x) > -0.4f) &&
					((Balls[i].translation_y - Balls[n].translation_y) <  0.4f) && 
					((Balls[i].translation_y - Balls[n].translation_y) > -0.4f) &&
					((Balls[i].translation_z - Balls[n].translation_z) <  0.4f) && 
					((Balls[i].translation_z - Balls[n].translation_z) > -0.4f))
				{
					Balls[i].State = BALLSTATE_READY;
				}
			}
		}
	}
}
void c_World::UpdateWorld()
{
	pTimer->UpdateTime();
	float r;
	float xd, yd, zd, t;
	float a, b, c;
	int collision;

	random1 = ((FLOAT)(rand()%2000)) / 1000.0f - 1.0f;
	random2 = ((FLOAT)(rand()%2000)) / 1000.0f - 1.0f;
	random3 = ((FLOAT)(rand()%2000)) / 1000.0f - 1.0f;

	for(DWORD i=0; i<NUM_BALLS; i++)
	{
		if(Balls[i].State == BALLSTATE_INAIR)
		{
			Balls[i].velocity_z -= GRAVITY * pTimer->fElapsedTime;
			Balls[i].vt_x = Balls[i].velocity_x * pTimer->fElapsedTime;
			Balls[i].vt_y = Balls[i].velocity_y * pTimer->fElapsedTime;
			Balls[i].vt_z = Balls[i].velocity_z * pTimer->fElapsedTime;

			for(DWORD j=0; j<4; j++)
			{
				if(Balls[i].player != j)
				{
					xd = Balls[i].translation_x - pPlayer[j]->TransX;
					yd = Balls[i].translation_y - pPlayer[j]->TransY;
					zd = Balls[i].translation_z - pPlayer[j]->TransZ;
					if( (xd*xd + yd*yd + zd*zd) < 4.0f)
					{
						a = (Balls[i].vt_x * Balls[i].vt_x + Balls[i].vt_y * Balls[i].vt_y + Balls[i].vt_z * Balls[i].vt_z);
						b = 2.0f * (Balls[i].vt_x * xd + Balls[i].vt_y * yd + Balls[i].vt_z * zd);
						c = xd*xd + yd*yd + zd*zd - 4.0f;
						t = (-1.0f * b - sqrt(b*b - 4.0f*a*c)) / (2.0f * a);

						Balls[i].translation_x = t * Balls[i].vt_x + Balls[i].translation_x;
						Balls[i].translation_y = t * Balls[i].vt_y + Balls[i].translation_y;
						Balls[i].translation_z = t * Balls[i].vt_z + Balls[i].translation_z;

						BallCollided(i);
						pPlayer[j]->Dead = 1;
						
						ouch[ouchsound]->Play(0);
						ouchsound++;
						if(ouchsound == 3)
							ouchsound = 0;

						if(bfirstblood == 0)
						{
							bfirstblood = 1;
							firstblood->Play(0);
						}
						Balls[i].State = BALLSTATE_HITWALL;
					}
					else
					{
						t = -1.0f * (Balls[i].vt_x * xd + Balls[i].vt_y * yd + Balls[i].vt_z * zd) / 
							(Balls[i].vt_x * Balls[i].vt_x + Balls[i].vt_y * Balls[i].vt_y + Balls[i].vt_z * Balls[i].vt_z);
						if( (t > 0.0f) && (t < 1.0f) )
						{
							// recycle variables and find minimum point
							xd = t * Balls[i].vt_x + Balls[i].translation_x;
							yd = t * Balls[i].vt_y + Balls[i].translation_y;
							zd = t * Balls[i].vt_z + Balls[i].translation_z;
							if(	(xd - pPlayer[j]->TransX) * (xd - pPlayer[j]->TransX) + 
								(yd - pPlayer[j]->TransY) * (yd - pPlayer[j]->TransY) + 
								(zd - pPlayer[j]->TransZ) * (zd - pPlayer[j]->TransZ) < 4.0f)
							{
								Balls[i].translation_x = xd;
								Balls[i].translation_y = yd;
								Balls[i].translation_z = zd;

								xd = xd - pPlayer[j]->TransX;
								yd = yd - pPlayer[j]->TransY;
								zd = zd - pPlayer[j]->TransZ;

								a = (Balls[i].vt_x * Balls[i].vt_x + Balls[i].vt_y * Balls[i].vt_y + Balls[i].vt_z * Balls[i].vt_z);
								b = 2.0f * (Balls[i].vt_x * xd + Balls[i].vt_y * yd + Balls[i].vt_z * zd);
								c = xd*xd + yd*yd + zd*zd - 4.0f;
								t = (-1.0f * b - sqrt(b*b - 4.0f*a*c)) / (2.0f * a);

								Balls[i].translation_x = t * Balls[i].vt_x + Balls[i].translation_x;
								Balls[i].translation_y = t * Balls[i].vt_y + Balls[i].translation_y;
								Balls[i].translation_z = t * Balls[i].vt_z + Balls[i].translation_z;

								BallCollided(i);

								ouch[ouchsound]->Play(0);
								ouchsound++;
								if(ouchsound == 3)
									ouchsound = 0;

								if(bfirstblood == 0)
								{
									bfirstblood = 1;
									firstblood->Play(0);
								}
								pPlayer[j]->Dead = 1;
								Balls[i].State = BALLSTATE_HITWALL;
							}
						}
					}
				}
			}

			for(j=0; j<num_boards[CurrLevel]; j++)
			{
				if(Balls[i].vt_x > 0.0f)
				{
					if(TestCollisionP(Boards[j].x1, Boards[j].y1, Boards[j].y2, Boards[j].z1, Boards[j].z2,
						Balls[i].translation_x, Balls[i].translation_y, Balls[i].translation_z,
						Balls[i].vt_x, Balls[i].vt_y, Balls[i].vt_z))
					{

						thwack[thwacksound]->Play(0);
						thwacksound++;
						if(thwacksound == 3)
							thwacksound = 0;

						Balls[i].State = BALLSTATE_HITWALL;
						r = (Balls[i].translation_x - Boards[j].x1) / Balls[i].vt_x;
						Balls[i].translation_x = Boards[j].x1;
						Balls[i].translation_y -= r * Balls[i].vt_y;
						Balls[i].translation_z -= r * Balls[i].vt_z;
						BallCollided(i);
					}
				}
				else
				{
					if(TestCollisionN(Boards[j].x2, Boards[j].y1, Boards[j].y2, Boards[j].z1, Boards[j].z2,
						Balls[i].translation_x, Balls[i].translation_y, Balls[i].translation_z,
						Balls[i].vt_x, Balls[i].vt_y, Balls[i].vt_z))
					{
						thwack[thwacksound]->Play(0);
						thwacksound++;
						if(thwacksound == 3)
							thwacksound = 0;
						Balls[i].State = BALLSTATE_HITWALL;
						r = (Balls[i].translation_x - Boards[j].x2) / Balls[i].vt_x;
						Balls[i].translation_x = Boards[j].x2;
						Balls[i].translation_y -= r * Balls[i].vt_y;
						Balls[i].translation_z -= r * Balls[i].vt_z;
						BallCollided(i);
					}
				}
				if(Balls[i].vt_y > 0.0f)
				{
					if(TestCollisionP(Boards[j].y1, Boards[j].x1, Boards[j].x2, Boards[j].z1, Boards[j].z2,
						Balls[i].translation_y, Balls[i].translation_x, Balls[i].translation_z,
						Balls[i].vt_y, Balls[i].vt_x, Balls[i].vt_z))
					{
						thwack[thwacksound]->Play(0);
						thwacksound++;
						if(thwacksound == 3)
							thwacksound = 0;

						Balls[i].State = BALLSTATE_HITWALL;
						r = (Balls[i].translation_y - Boards[j].y1) / Balls[i].vt_y;
						Balls[i].translation_y = Boards[j].y1;
						Balls[i].translation_x -= r * Balls[i].vt_x;
						Balls[i].translation_z -= r * Balls[i].vt_z;
						BallCollided(i);
					}
				}
				else
				{
					if(TestCollisionN(Boards[j].y2, Boards[j].x1, Boards[j].x2, Boards[j].z1, Boards[j].z2,
						Balls[i].translation_y, Balls[i].translation_x, Balls[i].translation_z,
						Balls[i].vt_y, Balls[i].vt_x, Balls[i].vt_z))
					{
						thwack[thwacksound]->Play(0);
						thwacksound++;
						if(thwacksound == 3)
							thwacksound = 0;

						Balls[i].State = BALLSTATE_HITWALL;
						r = (Balls[i].translation_y - Boards[j].y2) / Balls[i].vt_y;
						Balls[i].translation_y = Boards[j].y2;
						Balls[i].translation_x -= r * Balls[i].vt_x;
						Balls[i].translation_z -= r * Balls[i].vt_z;
						BallCollided(i);
					}
				}
								if(Balls[i].vt_y > 0.0f)
				{
				if(TestCollisionP(Boards[j].z1, Boards[j].x1, Boards[j].x2, Boards[j].y1, Boards[j].y2,
						Balls[i].translation_z, Balls[i].translation_x, Balls[i].translation_y,
						Balls[i].vt_z, Balls[i].vt_x, Balls[i].vt_y))
					{
						thwack[thwacksound]->Play(0);
						thwacksound++;
						if(thwacksound == 3)
							thwacksound = 0;

						Balls[i].State = BALLSTATE_HITWALL;
						r = (Balls[i].translation_z - Boards[j].z1) / Balls[i].vt_z;
						Balls[i].translation_z = Boards[j].z1;
						Balls[i].translation_x -= r * Balls[i].vt_x;
						Balls[i].translation_y -= r * Balls[i].vt_y;
						BallCollided(i);
					}
				}
				else
				{
					if(TestCollisionN(Boards[j].z2, Boards[j].x1, Boards[j].x2, Boards[j].y1, Boards[j].y2,
						Balls[i].translation_z, Balls[i].translation_x, Balls[i].translation_y,
						Balls[i].vt_z, Balls[i].vt_x, Balls[i].vt_y))
					{
						thwack[thwacksound]->Play(0);
						thwacksound++;
						if(thwacksound == 3)
							thwacksound = 0;

						Balls[i].State = BALLSTATE_HITWALL;
						r = (Balls[i].translation_z - Boards[j].z2) / Balls[i].vt_z;
						Balls[i].translation_z = Boards[j].z2;
						Balls[i].translation_x -= r * Balls[i].vt_x;
						Balls[i].translation_y -= r * Balls[i].vt_y;
						BallCollided(i);
					}
				}
			}
			if(Balls[i].State == BALLSTATE_INAIR)
			{
				Balls[i].translation_x += Balls[i].vt_x;
				Balls[i].translation_y += Balls[i].vt_y;
				Balls[i].translation_z += Balls[i].vt_z;
			}

			if(Balls[i].translation_x < WOLRD_0)
			{
						thwack[thwacksound]->Play(0);
						thwacksound++;
						if(thwacksound == 3)
							thwacksound = 0;

				Balls[i].State = BALLSTATE_HITWALL;
				r = Balls[i].translation_x / Balls[i].vt_x;
				Balls[i].translation_x = WOLRD_0;
				Balls[i].translation_y -= r * Balls[i].vt_y;
				Balls[i].translation_z -= r * Balls[i].vt_z;
				BallCollided(i);
			}
			if(Balls[i].translation_x > WORLD_X)
			{
						thwack[thwacksound]->Play(0);
						thwacksound++;
						if(thwacksound == 3)
							thwacksound = 0;

				Balls[i].State = BALLSTATE_HITWALL;
				r = (Balls[i].translation_x - WORLD_X) / Balls[i].vt_x;
				Balls[i].translation_x = WORLD_X;
				Balls[i].translation_y -= r * Balls[i].vt_y;
				Balls[i].translation_z -= r * Balls[i].vt_z;
				BallCollided(i);
			}
			if(Balls[i].translation_z < WOLRD_0)
			{
						thwack[thwacksound]->Play(0);
						thwacksound++;
						if(thwacksound == 3)
							thwacksound = 0;

				Balls[i].State = BALLSTATE_HITWALL;
				r = Balls[i].translation_z / Balls[i].vt_z;
				Balls[i].translation_z = WOLRD_0;
				Balls[i].translation_y -= r * Balls[i].vt_y;
				Balls[i].translation_x -= r * Balls[i].vt_x;
				BallCollided(i);
			}
			if(Balls[i].translation_z > WORLD_Z)
			{
						thwack[thwacksound]->Play(0);
						thwacksound++;
						if(thwacksound == 3)
							thwacksound = 0;

				Balls[i].State = BALLSTATE_HITWALL;
				r = (Balls[i].translation_z - WORLD_Z) / Balls[i].vt_z;
				Balls[i].translation_z = WORLD_Z;
				Balls[i].translation_y -= r * Balls[i].vt_y;
				Balls[i].translation_x -= r * Balls[i].vt_x;
				BallCollided(i);
			}
			if(Balls[i].translation_y < WOLRD_0)
			{
						thwack[thwacksound]->Play(0);
						thwacksound++;
						if(thwacksound == 3)
							thwacksound = 0;

				Balls[i].State = BALLSTATE_HITWALL;
				r = Balls[i].translation_y / Balls[i].vt_y;
				Balls[i].translation_y = WOLRD_0;
				Balls[i].translation_x -= r * Balls[i].vt_x;
				Balls[i].translation_z -= r * Balls[i].vt_z;
				BallCollided(i);
			}
			if(Balls[i].translation_y > WORLD_Y)
			{
						thwack[thwacksound]->Play(0);
						thwacksound++;
						if(thwacksound == 3)
							thwacksound = 0;

				Balls[i].State = BALLSTATE_HITWALL;
				r = (Balls[i].translation_y - WORLD_Y) / Balls[i].vt_y;
				Balls[i].translation_y = WORLD_Y;
				Balls[i].translation_x -= r * Balls[i].vt_x;
				Balls[i].translation_z -= r * Balls[i].vt_z;
				BallCollided(i);

			}
		}
	}

	for(i=0; i<4; i++)
	{
		pPlayer[i]->UpdatePlayer();

		if(pPlayer[i]->Firing == 1)
		{
						fire[firesound]->Play(0);
						firesound++;
						if(firesound == 3)
							firesound = 0;

			CurrBall++;
			if(CurrBall == NUM_BALLS)
				CurrBall = 0;

			Balls[CurrBall].player = i;
			Balls[CurrBall].State = BALLSTATE_INAIR;
			Balls[CurrBall].translation_x = pPlayer[i]->TransX;
			Balls[CurrBall].translation_y = pPlayer[i]->TransY;
			Balls[CurrBall].translation_z = pPlayer[i]->TransZ + 1.0f;

			FLOAT theta = pPlayer[i]->Theta + random1 * AIM_SPREAD;
			FLOAT phi = pPlayer[i]->Phi + random2 * AIM_SPREAD - AIM_HIGH;

			Balls[CurrBall].velocity_x = cos(theta)*sin(phi);
			Balls[CurrBall].velocity_y = sin(theta)*sin(phi);
			Balls[CurrBall].velocity_z = cos(phi);

			// USED TO PREVENT BULLETS somethgin or other
			/*Balls[CurrBall].translation_x += Balls[CurrBall].velocity_x * random3 * 5.0f;
			Balls[CurrBall].translation_y += Balls[CurrBall].velocity_y * random3 * 5.0f;
			Balls[CurrBall].translation_z += Balls[CurrBall].velocity_z * random3 * 5.0f;
*/

			Balls[CurrBall].velocity_x *= BALL_FPS;
			Balls[CurrBall].velocity_y *= BALL_FPS;
			Balls[CurrBall].velocity_z *= BALL_FPS;

		}

		if(pPlayer[i]->TransX < 2.0)
				pPlayer[i]->TransX = 2.0f;
		if(pPlayer[i]->TransX > WORLD_X - 2.0)
				pPlayer[i]->TransX = WORLD_X - 2.0;

		if(pPlayer[i]->TransY < 2.0)
				pPlayer[i]->TransY = 2.0f;
		if(pPlayer[i]->TransY > WORLD_Y - 2.0)
				pPlayer[i]->TransY = WORLD_Y - 2.0;

		for(DWORD k=1; k<30; k++)
		{
			collision = 0;
			for(DWORD j=0; j<num_boards[CurrLevel]; j++)
			{
				if(	(Boards[j].x1 - pPlayer[i]->TransX) * (Boards[j].x1 - pPlayer[i]->TransX) + 
					(Boards[j].y1 - pPlayer[i]->TransY) * (Boards[j].y1 - pPlayer[i]->TransY) < 4.0f )
					collision = 1;

				if(	(Boards[j].x1 - pPlayer[i]->TransX) * (Boards[j].x1 - pPlayer[i]->TransX) + 
					(Boards[j].y2 - pPlayer[i]->TransY) * (Boards[j].y2 - pPlayer[i]->TransY) < 4.0f )
					collision = 1;

				if(	(Boards[j].x2 - pPlayer[i]->TransX) * (Boards[j].x2 - pPlayer[i]->TransX) + 
					(Boards[j].y1 - pPlayer[i]->TransY) * (Boards[j].y1 - pPlayer[i]->TransY) < 4.0f )
					collision = 1;

				if(	(Boards[j].x2 - pPlayer[i]->TransX) * (Boards[j].x2 - pPlayer[i]->TransX) + 
					(Boards[j].y2 - pPlayer[i]->TransY) * (Boards[j].y2 - pPlayer[i]->TransY) < 4.0f )
					collision = 1;

				if(pPlayer[i]->vtX > 0)
				{
					if(pPlayer[i]->TransX < Boards[j].x1 && pPlayer[i]->TransX + 2.0f > Boards[j].x1)
					{
						if(pPlayer[i]->TransY > Boards[j].y1 && pPlayer[i]->TransY < Boards[j].y2)
						{
							collision = 1;
						}
					}
				}
				else
				{
					if(pPlayer[i]->TransX > Boards[j].x2 && pPlayer[i]->TransX - 2.0f < Boards[j].x2)
					{
						if(pPlayer[i]->TransY > Boards[j].y1 && pPlayer[i]->TransY < Boards[j].y2)
						{
							collision = 1;
						}
					}
				}
				if(pPlayer[i]->vtY > 0)
				{
					if(pPlayer[i]->TransY < Boards[j].y1 && pPlayer[i]->TransY + 2.0f > Boards[j].y1)
					{
						if(pPlayer[i]->TransX > Boards[j].x1 && pPlayer[i]->TransX < Boards[j].x2)
						{
							collision = 1;
						}
					}
				}
				else
				{
					if(pPlayer[i]->TransY > Boards[j].y2 && pPlayer[i]->TransY - 2.0f < Boards[j].y2)
					{
						if(pPlayer[i]->TransX > Boards[j].x1 && pPlayer[i]->TransX < Boards[j].x2)
						{
							collision = 1;
						}
					}
				}
			}
			if(collision == 1)
			{
				pPlayer[i]->TransY -= pPlayer[i]->vtY;
				pPlayer[i]->TransX -= pPlayer[i]->vtX;

				float temp = (float)(k)*D3DX_PI/60.0f;

				if(k%3 == 0)
				{
					pPlayer[i]->vtX = cos(pPlayer[i]->MovementDirection) * cos(temp) * pTimer->fElapsedTime * pPlayer[i]->MovementVelocity;
					pPlayer[i]->vtY = sin(pPlayer[i]->MovementDirection) * cos(temp) * pTimer->fElapsedTime * pPlayer[i]->MovementVelocity;
				}
				else if(k%3 == 1)
				{
					pPlayer[i]->vtX = cos(pPlayer[i]->MovementDirection+temp) * cos(temp) * pTimer->fElapsedTime * pPlayer[i]->MovementVelocity;
					pPlayer[i]->vtY = sin(pPlayer[i]->MovementDirection+temp) * cos(temp) * pTimer->fElapsedTime * pPlayer[i]->MovementVelocity;
				}
				else
				{
					pPlayer[i]->vtX = cos(pPlayer[i]->MovementDirection-temp) * cos(temp) * pTimer->fElapsedTime * pPlayer[i]->MovementVelocity;
					pPlayer[i]->vtY = sin(pPlayer[i]->MovementDirection-temp) * cos(temp) * pTimer->fElapsedTime * pPlayer[i]->MovementVelocity;
				}

				pPlayer[i]->TransY += pPlayer[i]->vtY;
				pPlayer[i]->TransX += pPlayer[i]->vtX;
			}
		}
		if(collision == 1)
		{
			pPlayer[i]->TransY -= pPlayer[i]->vtY;
			pPlayer[i]->TransX -= pPlayer[i]->vtX;
		}
	}

	for(i=0; i<4; i++)
	{
		if(pPlayer[i]->Dead == 0)
		{
			pD3DDevice->SetViewport(&(pPlayer[i]->viewport));
			pD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(0, 100, 255), 1.0f, 0);

			D3DXMATRIX view_matrix, matProj;
			D3DXMatrixLookAtLH(&view_matrix,
				&D3DXVECTOR3( pPlayer[i]->TransX, pPlayer[i]->TransY, pPlayer[i]->TransZ + 2.0f),
				&D3DXVECTOR3( pPlayer[i]->TransX+pPlayer[i]->LookX, pPlayer[i]->TransY+pPlayer[i]->LookY , pPlayer[i]->TransZ+pPlayer[i]->LookZ + 2.0f),
				&D3DXVECTOR3( 0.0f, 0.0f, 1.0f ));

			pD3DDevice->SetTransform(D3DTS_VIEW,&view_matrix);
			D3DXMatrixPerspectiveFovLH(&matProj, pPlayer[i]->FOV, (640.0f/480.0f), 1.5f, 300.0f);
			pD3DDevice->SetTransform( D3DTS_PROJECTION, &matProj );


			pD3DDevice->SetVertexShader(D3DFVF_CUSTOMVERTEX);
			pD3DDevice->SetStreamSource(0,pD3DVertexBuffer,sizeof(t_CUSTOMVERTEX));

			D3DXMATRIX trans_matrix;
			D3DXMatrixTranslation(&trans_matrix, 0.0f, 0.0f, 0.0f);
			pD3DDevice->SetTransform(D3DTS_WORLD, &trans_matrix);

			//pD3DDevice->SetTexture(0, g_pD3DTextureSky);
			//pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,360*3,NUM_BOARDS*12+12);

			pD3DDevice->SetTexture(0, g_pD3DTextureWall);
			pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,420*3,8);
			pD3DDevice->SetTexture(0, g_pD3DTextureFloor);
			pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,420*3+24,2);
			
			pD3DDevice->SetTexture(0, g_pD3DTextureSky);
			pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,420*3+36,108);

			pD3DDevice->SetTexture(0, g_pD3DTextureBoard);
			pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,420*3+36+324+vertexbufferoffsets[CurrLevel],num_boards[CurrLevel]*12);

			for(int j=0; j<4; j++)
			{
				if(i != j)
				{
					D3DXMATRIX trans_matrix;
					D3DXMATRIX rot_matrix;
					D3DXMATRIX rot_matrix2;

					D3DXMatrixTranslation(&trans_matrix, pPlayer[j]->TransX, pPlayer[j]->TransY, pPlayer[j]->TransZ);

					D3DXMatrixRotationY(&rot_matrix2, pPlayer[j]->Phi-D3DX_PI/2.0f);
					D3DXMatrixRotationZ(&rot_matrix, pPlayer[j]->Theta);
					D3DXMatrixMultiply(&rot_matrix, &rot_matrix2, &rot_matrix);

					D3DXMatrixMultiply(&trans_matrix, &rot_matrix, &trans_matrix);
					pD3DDevice->SetTransform(D3DTS_WORLD, &trans_matrix);

					if(pPlayer[j]->Dead == 1)
					{
						if(j == 0 || j == 1)
                            pD3DDevice->SetTexture(0, g_pD3DTextureDeadBlue);
						else
							pD3DDevice->SetTexture(0, g_pD3DTextureDeadRed);
					}
					else
					{
						if(j == 0 || j == 1)
                            pD3DDevice->SetTexture(0, g_pD3DTextureFaceBlue);
						else
							pD3DDevice->SetTexture(0, g_pD3DTextureFaceRed);
					}
					if(	(pPlayer[i]->TransX - pPlayer[j]->TransX) * (pPlayer[i]->TransX - pPlayer[j]->TransX) +
						(pPlayer[i]->TransY - pPlayer[j]->TransY) * (pPlayer[i]->TransY - pPlayer[j]->TransY) +
						(pPlayer[i]->TransZ - pPlayer[j]->TransZ) * (pPlayer[i]->TransZ - pPlayer[j]->TransZ) < 1000)
						pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,240*3,180);
					else
    	                pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,160*3,80);
				}
			}

			pD3DDevice->SetTexture(0, g_pD3DTexturePBall);
			for(j=0; j<NUM_BALLS; j++)
			{
				if(Balls[j].State == BALLSTATE_HITPLAYER)
				{
					Balls[j].translation_x = pPlayer[Balls[j].player]->TransX + Balls[j].velocity_x;
					Balls[j].translation_y = pPlayer[Balls[j].player]->TransY + Balls[j].velocity_y;
					Balls[j].translation_z = pPlayer[Balls[j].player]->TransZ + Balls[j].velocity_z;
				}
				if(Balls[j].State != BALLSTATE_READY)
				{
					D3DXMATRIX trans_matrix;

					D3DXMatrixTranslation(&trans_matrix, Balls[j].translation_x, Balls[j].translation_y, Balls[j].translation_z);
					pD3DDevice->SetTransform(D3DTS_WORLD, &trans_matrix);

					if(Balls[j].State != BALLSTATE_INAIR)
					{
						if(	(pPlayer[i]->TransX - Balls[j].translation_x) * (pPlayer[i]->TransX - Balls[j].translation_x) +
							(pPlayer[i]->TransY - Balls[j].translation_y) * (pPlayer[i]->TransY - Balls[j].translation_y) +
							(pPlayer[i]->TransZ - Balls[j].translation_z) * (pPlayer[i]->TransZ - Balls[j].translation_z) < 200.0f)
							pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,80*3,80);
						else
							pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,0,20);
					}
					else
					{
						pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,0,20);

						D3DXMatrixTranslation(&trans_matrix,	Balls[j].translation_x - Balls[j].velocity_x*0.002f,
																Balls[j].translation_y - Balls[j].velocity_y*0.002f,
																Balls[j].translation_z - Balls[j].velocity_z*0.002f);
						pD3DDevice->SetTransform(D3DTS_WORLD, &trans_matrix);
						pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,60,20);

						D3DXMatrixTranslation(&trans_matrix,	Balls[j].translation_x - Balls[j].velocity_x*0.004f,
																Balls[j].translation_y - Balls[j].velocity_y*0.004f,
																Balls[j].translation_z - Balls[j].velocity_z*0.004f);
						pD3DDevice->SetTransform(D3DTS_WORLD, &trans_matrix);
						pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,60,20);

						D3DXMatrixTranslation(&trans_matrix,	Balls[j].translation_x - Balls[j].velocity_x*0.006f,
																Balls[j].translation_y - Balls[j].velocity_y*0.006f,
																Balls[j].translation_z - Balls[j].velocity_z*0.006f);
						pD3DDevice->SetTransform(D3DTS_WORLD, &trans_matrix);
						pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,120,20);

						D3DXMatrixTranslation(&trans_matrix,	Balls[j].translation_x - Balls[j].velocity_x*0.008f,
																Balls[j].translation_y - Balls[j].velocity_y*0.008f,
																Balls[j].translation_z - Balls[j].velocity_z*0.008f);
						pD3DDevice->SetTransform(D3DTS_WORLD, &trans_matrix);
						pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,120,20);

						D3DXMatrixTranslation(&trans_matrix,	Balls[j].translation_x - Balls[j].velocity_x*0.010f,
																Balls[j].translation_y - Balls[j].velocity_y*0.010f,
																Balls[j].translation_z - Balls[j].velocity_z*0.010f);
						pD3DDevice->SetTransform(D3DTS_WORLD, &trans_matrix);
						pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,180,20);

						D3DXMatrixTranslation(&trans_matrix,	Balls[j].translation_x - Balls[j].velocity_x*0.012f,
																Balls[j].translation_y - Balls[j].velocity_y*0.012f,
																Balls[j].translation_z - Balls[j].velocity_z*0.012f);
						pD3DDevice->SetTransform(D3DTS_WORLD, &trans_matrix);
						pD3DDevice->DrawPrimitive(D3DPT_TRIANGLELIST,180,20);
					}
				}
			}
		}
	}
}

int c_World::TestCollisionP(	float px, float py1, float py2, float pz1, float pz2,
								float x1, float y1, float z1, float vx, float vy, float vz)
{
	float x2 = x1 + vx;
	float y2 = y1 + vy;
	float z2 = z1 + vz;

	float yy1, yz1, yx1;
	float yy2, yz2, yx2;

	float zy1, zz1, zx1;
	float zy2, zz2, zx2;

	float temp;
	int NoHit = 0;

	if(	(x1 < px) &&
		(x2 > px))   // Test if crossed the x plane
	{
		if(	(y1 < py1) &&  // test if y is out of bounds
			(y2 < py1) )
			NoHit = 1;
		if(	(y1 > py2) &&  // test if y is out of bounds
			(y2 > py2) )
			NoHit = 1;

		if(	(z1 < pz1) &&  // test if z is out of bounds
			(z2 < pz1) )
			NoHit = 1;
		if(	(z1 > pz2) &&  // test if z is out of bounds
			(z2 > pz2) )
			NoHit = 1;

		if(NoHit == 0)  // if y and z are both in bounds at some point
		{
			// Y1
			if(y1 < py1)  // if y1 is out at the lower bounds
			{
				yy1 = py1;  // Compute yx1 and yz1 according to y
				temp = (y2 - yy1) / (vy);
				yx1 = x2 - temp * vx;
				yz1 = z2 - temp * vz;
			}
			else if(y1 > py2)  // if y1 is out at the upper bounds
			{
				yy1 = py2;  // Compute yx1 and yz1 according to y
				temp = (y2 - yy1) / (vy);
				yx1 = x2 - temp * vx;
				yz1 = z2 - temp * vz;
			}
			else  // if y1 is in the bounds just copy the coords
			{
				yx1 = x1;
				yy1 = y1;
				yz1 = z1;
			}
			// END Y1


			// Y2
			if(y2 < py1)  // if y2 is out at the lower bounds
			{
				yy2 = py1;  // Compute yx2 and yz2 according to y
				temp = (yy2 - y1) / (vy);
				yx2 = x1 + temp * vx;
				yz2 = z1 + temp * vz;
			}
			else if(y2 > py2)  // if y2 is out at the upper bounds
			{
				yy2 = py2;  // Compute yx2 and yz2 according to y
				temp = (yy2 - y1) / (vy);
				yx2 = x1 + temp * vx;
				yz2 = z1 + temp * vz;
			}
			else  // if y2 is in the bounds just copy the coords
			{
				yx2 = x2;
				yy2 = y2;
				yz2 = z2;
			}
			// END Y2


			// Z1
			if(z1 < pz1)  // if z1 is out at the lower bounds
			{
				zz1 = pz1;  // Compute zx1 and zy1 according to z
				temp = (z2 - zz1) / (vz);
				zx1 = x2 - temp * vx;
				zy1 = y2 - temp * vy;
			}
			else if(z1 > pz2)  // if z1 is out at the upper bounds
			{
				zz1 = pz2;  // Compute zx1 and zz1 according to z
				temp = (z2 - zz1) / (vz);
				zx1 = x2 - temp * vx;
				zy1 = y2 - temp * vy;
			}
			else  // if z1 is in the bounds just copy the coords
			{
				zx1 = x1;
				zy1 = y1;
				zz1 = z1;
			}
			// END Z1


			// Z2
			if(z2 < pz1)  // if z2 is out at the lower bounds
			{
				zz2 = pz1;  // Compute zx2 and zy2 according to z
				temp = (zz2 - z1) / (vz);
				zx2 = x1 + temp * vx;
				zy2 = y1 + temp * vy;
			}
			else if(z2 > pz2)  // if z2 one is out at the upper bounds
			{
				zz2 = pz2;  // Compute zx2 and yz2 according to z
				temp = (zz2 - z1) / (vz);
				zx2 = x1 + temp * vx;
				zy2 = y1 + temp * vy;
			}
			else  // if z2 is in the bounds just copy the coords
			{
				zx2 = x2;
				zy2 = y2;
				zz2 = z2;
			}
			// END Z2

			if(vy > 0)
			{
				if( (yy2 < zy1) || (zy2 < yy1) )
					NoHit = 1;
				else
				{
					if(yy1 < zy1)
					{
						x1 = zx1;
						y1 = zy1;
						z1 = zz1;
					}
					else
					{
						x1 = yx1;
						y1 = yy1;
						z1 = yz1;
					}
					if(yy2 > zy2)
					{
						x2 = zx2;
						y2 = zy2;
						z2 = zz2;
					}
					else
					{
						x2 = yx2;
						y2 = yy2;
						z2 = yz2;
					}
				}
			}
			else
			{
				if( (yy2 > zy1) || (zy2 > yy1) )
					NoHit = 1;
				else
				{
					if(yy1 > zy1)
					{
						x1 = zx1;
						y1 = zy1;
						z1 = zz1;
					}
					else
					{
						x1 = yx1;
						y1 = yy1;
						z1 = yz1;
					}
					if(yy2 < zy2)
					{
						x2 = zx2;
						y2 = zy2;
						z2 = zz2;
					}
					else
					{
						x2 = yx2;
						y2 = yy2;
						z2 = yz2;
					}
				}
			}
		}

		if(NoHit == 0)
		{
			// Now that we might have new coordinates test X plane again
			if(	(x1 < px) &&
				(x2 > px))   // Test if crossed the x plane
			{
				return 1;
			}
		}
	}
	return 0;
}

int c_World::TestCollisionN(	float px, float py1, float py2, float pz1, float pz2,
								float x1, float y1, float z1, float vx, float vy, float vz)
{
	float x2 = x1 + vx;
	float y2 = y1 + vy;
	float z2 = z1 + vz;

	float yy1, yz1, yx1;
	float yy2, yz2, yx2;

	float zy1, zz1, zx1;
	float zy2, zz2, zx2;

	float temp;
	int NoHit = 0;

	if(	(x1 > px) &&
		(x2 < px))   // Test if crossed the x plane
	{
		if(	(y1 < py1) &&  // test if y is out of bounds
			(y2 < py1) )
			NoHit = 1;
		if(	(y1 > py2) &&  // test if y is out of bounds
			(y2 > py2) )
			NoHit = 1;

		if(	(z1 < pz1) &&  // test if z is out of bounds
			(z2 < pz1) )
			NoHit = 1;
		if(	(z1 > pz2) &&  // test if z is out of bounds
			(z2 > pz2) )
			NoHit = 1;

		if(NoHit == 0)  // if y and z are both in bounds at some point
		{
			// Y1
			if(y1 < py1)  // if y1 is out at the lower bounds
			{
				yy1 = py1;  // Compute yx1 and yz1 according to y
				temp = (y2 - yy1) / (vy);
				yx1 = x2 - temp * vx;
				yz1 = z2 - temp * vz;
			}
			else if(y1 > py2)  // if y1 is out at the upper bounds
			{
				yy1 = py2;  // Compute yx1 and yz1 according to y
				temp = (y2 - yy1) / (vy);
				yx1 = x2 - temp * vx;
				yz1 = z2 - temp * vz;
			}
			else  // if y1 is in the bounds just copy the coords
			{
				yx1 = x1;
				yy1 = y1;
				yz1 = z1;
			}
			// END Y1


			// Y2
			if(y2 < py1)  // if y2 is out at the lower bounds
			{
				yy2 = py1;  // Compute yx2 and yz2 according to y
				temp = (yy2 - y1) / (vy);
				yx2 = x1 + temp * vx;
				yz2 = z1 + temp * vz;
			}
			else if(y2 > py2)  // if y2 is out at the upper bounds
			{
				yy2 = py2;  // Compute yx2 and yz2 according to y
				temp = (yy2 - y1) / (vy);
				yx2 = x1 + temp * vx;
				yz2 = z1 + temp * vz;
			}
			else  // if y2 is in the bounds just copy the coords
			{
				yx2 = x2;
				yy2 = y2;
				yz2 = z2;
			}
			// END Y2


			// Z1
			if(z1 < pz1)  // if z1 is out at the lower bounds
			{
				zz1 = pz1;  // Compute zx1 and zy1 according to z
				temp = (z2 - zz1) / (vz);
				zx1 = x2 - temp * vx;
				zy1 = y2 - temp * vy;
			}
			else if(z1 > pz2)  // if z1 is out at the upper bounds
			{
				zz1 = pz2;  // Compute zx1 and zz1 according to z
				temp = (z2 - zz1) / (vz);
				zx1 = x2 - temp * vx;
				zy1 = y2 - temp * vy;
			}
			else  // if z1 is in the bounds just copy the coords
			{
				zx1 = x1;
				zy1 = y1;
				zz1 = z1;
			}
			// END Z1


			// Z2
			if(z2 < pz1)  // if z2 is out at the lower bounds
			{
				zz2 = pz1;  // Compute zx2 and zy2 according to z
				temp = (zz2 - z1) / (vz);
				zx2 = x1 + temp * vx;
				zy2 = y1 + temp * vy;
			}
			else if(z2 > pz2)  // if z2 one is out at the upper bounds
			{
				zz2 = pz2;  // Compute zx2 and yz2 according to z
				temp = (zz2 - z1) / (vz);
				zx2 = x1 + temp * vx;
				zy2 = y1 + temp * vy;
			}
			else  // if z2 is in the bounds just copy the coords
			{
				zx2 = x2;
				zy2 = y2;
				zz2 = z2;
			}
			// END Z2

			if(vy > 0)
			{
				if( (yy2 < zy1) || (zy2 < yy1) )
					NoHit = 1;
				else
				{
					if(yy1 < zy1)
					{
						x1 = zx1;
						y1 = zy1;
						z1 = zz1;
					}
					else
					{
						x1 = yx1;
						y1 = yy1;
						z1 = yz1;
					}
					if(yy2 > zy2)
					{
						x2 = zx2;
						y2 = zy2;
						z2 = zz2;
					}
					else
					{
						x2 = yx2;
						y2 = yy2;
						z2 = yz2;
					}
				}
			}
			else
			{
				if( (yy2 > zy1) || (zy2 > yy1) )
					NoHit = 1;
				else
				{
					if(yy1 > zy1)
					{
						x1 = zx1;
						y1 = zy1;
						z1 = zz1;
					}
					else
					{
						x1 = yx1;
						y1 = yy1;
						z1 = yz1;
					}
					if(yy2 < zy2)
					{
						x2 = zx2;
						y2 = zy2;
						z2 = zz2;
					}
					else
					{
						x2 = yx2;
						y2 = yy2;
						z2 = yz2;
					}
				}
			}
		}

		if(NoHit == 0)
		{
			// Now that we might have new coordinates test X plane again
			if(	(x1 > px) &&
				(x2 < px))   // Test if crossed the x plane
			{
				return 1;
			}
		}
	}
	return 0;
}
