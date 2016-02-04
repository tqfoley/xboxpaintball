#include <xtl.h>

#ifndef GamePad
#define GamePad

typedef struct XBGamePad
{
	XINPUT_STATE m_InputStates;

	XINPUT_RUMBLE   Rumble;
	XINPUT_FEEDBACK Feedback;
	XINPUT_CAPABILITIES caps;
	HANDLE     hDevice;

	BOOL       bInserted;
	BOOL       bRemoved;
}*pXBGamePad;

typedef class c_GamePads
{
public:

	XBGamePad m_Gamepads[4];

	XINPUT_GAMEPAD *pGP1;
	XINPUT_GAMEPAD *pGP2;
	XINPUT_GAMEPAD *pGP3;
	XINPUT_GAMEPAD *pGP4;

	c_GamePads();
	void GetInput();
}*p_GamePads;

#endif