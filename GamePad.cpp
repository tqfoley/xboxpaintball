#include "gamepad.h"

c_GamePads::c_GamePads()
{ 
	XInitDevices( 0, 0);

	// Get a mask of all currently available devices
	DWORD dwDeviceMask = XGetDevices( XDEVICE_TYPE_GAMEPAD );

	// Open the devices
	for( DWORD i=0; i < XGetPortCount(); i++ )
	{
		//TFZeroMemory( &m_InputStates[i], sizeof(XINPUT_STATE) );
		ZeroMemory( &m_Gamepads[i], sizeof(XBGamePad) );
		if( dwDeviceMask & (1<<i) ) 
		{
			// Get a handle to the device
			m_Gamepads[i].hDevice = XInputOpen( XDEVICE_TYPE_GAMEPAD, i, 
				XDEVICE_NO_SLOT, NULL );

			// Store capabilities of the device
			XInputGetCapabilities( m_Gamepads[i].hDevice, &m_Gamepads[i].caps );
		}
	}

	pGP1 = &(m_Gamepads[0].m_InputStates.Gamepad);
	pGP2 = &(m_Gamepads[1].m_InputStates.Gamepad);
	pGP3 = &(m_Gamepads[2].m_InputStates.Gamepad);
	pGP4 = &(m_Gamepads[3].m_InputStates.Gamepad);
}

void c_GamePads::GetInput( )
{
	pXBGamePad pGamepads = m_Gamepads;

	// TCR 3-21 Controller Discovery
	// Get status about gamepad insertions and removals. Note that, in order to
	// not miss devices, we will check for removed device BEFORE checking for
	// insertions
	DWORD dwInsertions, dwRemovals;
	XGetDeviceChanges( XDEVICE_TYPE_GAMEPAD, &dwInsertions, &dwRemovals );

	// Loop through all gamepads
	for( DWORD i=0; i < XGetPortCount(); i++ )
	{
		// Handle removed devices.
		pGamepads[i].bRemoved = ( dwRemovals & (1<<i) ) ? TRUE : FALSE;
		if( pGamepads[i].bRemoved )
		{
			// if the controller was removed after XGetDeviceChanges but before
			// XInputOpen, the device handle will be NULL
			if( pGamepads[i].hDevice )
				XInputClose( pGamepads[i].hDevice );
			pGamepads[i].hDevice = NULL;
			pGamepads[i].Feedback.Rumble.wLeftMotorSpeed  = 0;
			pGamepads[i].Feedback.Rumble.wRightMotorSpeed = 0;
		}

		// Handle inserted devices
		pGamepads[i].bInserted = ( dwInsertions & (1<<i) ) ? TRUE : FALSE;
		if( pGamepads[i].bInserted ) 
		{
			// TCR 1-14 Device Types
			pGamepads[i].hDevice = XInputOpen( XDEVICE_TYPE_GAMEPAD, i, 
				XDEVICE_NO_SLOT, NULL );

			// if the controller is removed after XGetDeviceChanges but before
			// XInputOpen, the device handle will be NULL
			if( pGamepads[i].hDevice )
				XInputGetCapabilities( pGamepads[i].hDevice, &pGamepads[i].caps );
		}

		// If we have a valid device, poll it's state and track button changes
		if( pGamepads[i].hDevice )
		{
			// Read the input state
			XInputGetState( pGamepads[i].hDevice, &(pGamepads[i].m_InputStates) );
		}
	}
}