#include <xtl.h>
#include <xgraphics.h>

//#include "wmastream.h"
#include "GamePad.h"
#include "World.h"
//#include "XVideo.h"

//#define  SCREEN_BLUE (__TIME__[7]%10)*25

LPDIRECT3D8 g_pD3D = NULL;
LPDIRECT3DDEVICE8 g_pD3DDevice = NULL;

p_GamePads		g_pGamePads;
p_World			g_pWorld;

FLOAT g_fMipMapLodBias = 0.08f;

void InitialiseD3D()
{

	g_pD3D = Direct3DCreate8(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp; 
	
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	
	d3dpp.BackBufferWidth = 640;
	d3dpp.BackBufferHeight = 480;
	d3dpp.BackBufferFormat = D3DFMT_LIN_X8R8G8B8;
	d3dpp.BackBufferCount = 1;
	d3dpp.EnableAutoDepthStencil = TRUE;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_pD3D->CreateDevice(0, D3DDEVTYPE_HAL, NULL, 
							D3DCREATE_HARDWARE_VERTEXPROCESSING, 
							&d3dpp, &g_pD3DDevice);

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, FALSE);
	g_pD3DDevice->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
	g_pD3DDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	g_pD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAOP,D3DTOP_SELECTARG1);
	g_pD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAARG1,D3DTA_DIFFUSE);

	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLORKEYOP, D3DTCOLORKEYOP_KILL);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_COLORKEYCOLOR, D3DCOLOR_XRGB( 150, 200, 250));

	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE,TRUE);


	g_pD3DDevice->SetTextureStageState(0,D3DTSS_MAGFILTER, D3DTEXF_ANISOTROPIC);
	g_pD3DDevice->SetTextureStageState(0,D3DTSS_MINFILTER, D3DTEXF_ANISOTROPIC);

	g_pD3DDevice->SetTextureStageState(0, D3DTSS_MAXANISOTROPY, 1 );

	g_pD3DDevice->SetTextureStageState(0, D3DTSS_MIPMAPLODBIAS, *((LPDWORD)(&g_fMipMapLodBias)));
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_MIPFILTER, D3DTEXF_LINEAR);
}

void ReBoot()
{
	LD_LAUNCH_DASHBOARD LaunchData = { XLD_LAUNCH_DASHBOARD_MAIN_MENU };
	XLaunchNewImage( NULL, (LAUNCH_DATA*)&LaunchData );
}

HRESULT CaptureScreen(LPDIRECT3DDEVICE8 pDevice, char cPath[])
{
	IDirect3DSurface8 *pFrontBuffer;
	pDevice->GetBackBuffer(-1,D3DBACKBUFFER_TYPE_MONO,&pFrontBuffer);
	return XGWriteSurfaceToFile(pFrontBuffer, cPath);
}

void __cdecl main()
{
	int screenshot = 0;
	InitialiseD3D();
	g_pGamePads = new c_GamePads();
	g_pWorld = new c_World(g_pD3DDevice, g_pGamePads);

	D3DVIEWPORT8 viewport;

	viewport.Height = 5000;
	viewport.Width = 5000;
	viewport.X = 0;
	viewport.Y = 0;
	viewport.MinZ = 0.0f;
	viewport.MaxZ = 1.0f;

	DWORD WinnerColor = D3DCOLOR_XRGB(0, 0, 100);


	g_pWorld->pPlayer[0]->Dead = 1;
	g_pWorld->pPlayer[1]->Dead = 1;

	//DWORD musicresult = 0;
	//CWMAFileStream music;
	//music.Initialize("D:\\song1.wma");


	//XVideo video;

	//video.LoadVideo("D:\\test.xmv");
	//video.PlayVideo();

	if(g_pWorld->pPlayer[0]->Dead != 0 && g_pWorld->pPlayer[1]->Dead != 0)
	{
		WinnerColor = D3DCOLOR_XRGB(150, 0, 0);
		g_pWorld->pPlayer[0]->Dead = 0;
		g_pWorld->pPlayer[0]->TransX = 2.5f;
		g_pWorld->pPlayer[0]->TransY = 5.0f;
		g_pWorld->pPlayer[0]->Theta = 3.1415f/2.0f;
		g_pWorld->pPlayer[0]->Phi = 3.1415f/2.0f;
		g_pWorld->pPlayer[0]->Firing = 0;


		g_pWorld->pPlayer[1]->Dead = 0;
		g_pWorld->pPlayer[1]->TransX = 2.5f;
		g_pWorld->pPlayer[1]->TransY = 80.0f - 5.0f;
		g_pWorld->pPlayer[1]->Theta = -3.1415f/2.0f;
		g_pWorld->pPlayer[1]->Phi = 3.1415f/2.0f;
		g_pWorld->pPlayer[1]->Firing = 0;

		g_pWorld->pPlayer[2]->Dead = 0;
		g_pWorld->pPlayer[2]->TransX = 180.0f - 2.5f;
		g_pWorld->pPlayer[2]->TransY = 5.0f;
		g_pWorld->pPlayer[2]->Theta = 3.1415f/2.0f;
		g_pWorld->pPlayer[2]->Phi = 3.1415f/2.0f;
		g_pWorld->pPlayer[2]->Firing = 0;

		g_pWorld->pPlayer[3]->Dead = 0;
		g_pWorld->pPlayer[3]->TransX = 180.0f - 2.5f;
		g_pWorld->pPlayer[3]->TransY = 80.0f - 5.0f;
		g_pWorld->pPlayer[3]->Theta = -3.1415f/2.0f;
		g_pWorld->pPlayer[3]->Phi = 3.1415f/2.0f;
		g_pWorld->pPlayer[3]->Firing = 0;

		g_pWorld->bfirstblood = 0;

		g_pWorld->rumble->Play(0);

		for(int i=0; i<150; i++)
		{
			g_pWorld->Balls[i].State = 0;
		}
		g_pWorld->wait = 1200;
	}
	while(true)
	{
		//music.Process(&musicresult);
		//DirectSoundDoWork();

		g_pGamePads->GetInput();

		if(	(g_pGamePads->pGP1->wButtons &  XINPUT_GAMEPAD_START) &&
			(g_pGamePads->pGP1->wButtons &  XINPUT_GAMEPAD_BACK) )
			ReBoot();

		if(g_pGamePads->pGP1->wButtons & XINPUT_GAMEPAD_DPAD_DOWN)
		{
			if(screenshot == 0)
			{
				screenshot = 1;
				CaptureScreen(g_pD3DDevice, "D:\\screen.bmp"); 
			}
		}
		if(g_pWorld->pPlayer[0]->Dead != 0 && g_pWorld->pPlayer[1]->Dead != 0)
		{
			WinnerColor = D3DCOLOR_XRGB(150, 0, 0);
			g_pWorld->pPlayer[0]->Dead = 0;
			g_pWorld->pPlayer[0]->TransX = 2.5f;
			g_pWorld->pPlayer[0]->TransY = 5.0f;
			g_pWorld->pPlayer[0]->Theta = 3.1415f/2.0f;
			g_pWorld->pPlayer[0]->Phi = 3.1415f/2.0f;
			g_pWorld->pPlayer[0]->Firing = 0;

			g_pWorld->pPlayer[1]->Dead = 0;
			g_pWorld->pPlayer[1]->TransX = 2.5f;
			g_pWorld->pPlayer[1]->TransY = 80.0f - 5.0f;
			g_pWorld->pPlayer[1]->Theta = -3.1415f/2.0f;
			g_pWorld->pPlayer[1]->Phi = 3.1415f/2.0f;
			g_pWorld->pPlayer[1]->Firing = 0;

			g_pWorld->pPlayer[2]->Dead = 0;
			g_pWorld->pPlayer[2]->TransX = 180.0f - 2.5f;
			g_pWorld->pPlayer[2]->TransY = 5.0f;
			g_pWorld->pPlayer[2]->Theta = 3.1415f/2.0f;
			g_pWorld->pPlayer[2]->Phi = 3.1415f/2.0f;
			g_pWorld->pPlayer[2]->Firing = 0;

			g_pWorld->pPlayer[3]->Dead = 0;
			g_pWorld->pPlayer[3]->TransX = 180.0f - 2.5f;
			g_pWorld->pPlayer[3]->TransY = 80.0f - 5.0f;
			g_pWorld->pPlayer[3]->Theta = -3.1415f/2.0f;
			g_pWorld->pPlayer[3]->Phi = 3.1415f/2.0f;
			g_pWorld->pPlayer[3]->Firing = 0;

			g_pWorld->bfirstblood = 0;

			g_pWorld->redwins->Play(0);
			(g_pWorld->CurrLevel)++;
			if(g_pWorld->CurrLevel == 5)
				g_pWorld->CurrLevel = 0;
			(g_pWorld->Boards) = &((g_pWorld->BoardsAll)[g_pWorld->CurrLevel][0]);

			for(int i=0; i<150; i++)
			{
				g_pWorld->Balls[i].State = 0;
			}
			g_pWorld->wait = 800;
		}
		
		if(g_pWorld->pPlayer[2]->Dead != 0 && g_pWorld->pPlayer[3]->Dead != 0)
		{
			WinnerColor = D3DCOLOR_XRGB(0, 0, 150);
			g_pWorld->pPlayer[0]->Dead = 0;
			g_pWorld->pPlayer[0]->TransX = 2.5f;
			g_pWorld->pPlayer[0]->TransY = 5.0f;
			g_pWorld->pPlayer[0]->Theta = 3.1415f/2.0f;
			g_pWorld->pPlayer[0]->Phi = 3.1415f/2.0f;
			g_pWorld->pPlayer[0]->Firing = 0;

			g_pWorld->pPlayer[1]->Dead = 0;
			g_pWorld->pPlayer[1]->TransX = 2.5f;
			g_pWorld->pPlayer[1]->TransY = 80.0f - 5.0f;
			g_pWorld->pPlayer[1]->Theta = -3.1415f/2.0f;
			g_pWorld->pPlayer[1]->Phi = 3.1415f/2.0f;
			g_pWorld->pPlayer[1]->Firing = 0;

			g_pWorld->pPlayer[2]->Dead = 0;
			g_pWorld->pPlayer[2]->TransX = 180.0f - 2.5f;
			g_pWorld->pPlayer[2]->TransY = 5.0f;
			g_pWorld->pPlayer[2]->Theta = 3.1415f/2.0f;
			g_pWorld->pPlayer[2]->Phi = 3.1415f/2.0f;
			g_pWorld->pPlayer[2]->Firing = 0;

			g_pWorld->pPlayer[3]->Dead = 0;
			g_pWorld->pPlayer[3]->TransX = 180.0f - 2.5f;
			g_pWorld->pPlayer[3]->TransY = 80.0f - 5.0f;
			g_pWorld->pPlayer[3]->Theta = -3.1415f/2.0f;
			g_pWorld->pPlayer[3]->Phi = 3.1415f/2.0f;
			g_pWorld->pPlayer[3]->Firing = 0;

			g_pWorld->bfirstblood = 0;

			g_pWorld->bluewins->Play(0);
		
			(g_pWorld->CurrLevel)++;
			if(g_pWorld->CurrLevel == 5)
				g_pWorld->CurrLevel = 0;
			(g_pWorld->Boards) = &((g_pWorld->BoardsAll)[g_pWorld->CurrLevel][0]);

			for(int i=0; i<150; i++)
			{
				g_pWorld->Balls[i].State = 0;
			}
			g_pWorld->wait = 800;
		}

		g_pD3DDevice->SetViewport(&viewport);

		g_pD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET|D3DCLEAR_ZBUFFER, WinnerColor, 0.0f, 0);

		g_pD3DDevice->BeginScene();

		g_pWorld->UpdateWorld();

		g_pD3DDevice->EndScene();

		g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
	}
}

