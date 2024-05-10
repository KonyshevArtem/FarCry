// CryInput.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#ifndef _XBOX 
_ACCESS_POOL;
#endif //_XBOX

#include <stdio.h>
#include <ILog.h>
#include <IInput.h>
#include "Input.h"
#include "ISystem.h"

#ifdef _DEBUG
static char THIS_FILE[] = __FILE__;
#define DEBUG_CLIENTBLOCK new( _NORMAL_BLOCK, THIS_FILE, __LINE__) 
#define new DEBUG_CLIENTBLOCK
#endif

//////////////////////////////////////////////////////////////////////////

#if !defined(FAR_CRY_STATIC_LIBS)
// Pointer to Global ISystem.
static ISystem* gISystem = 0;
ISystem* GetISystem()
{
	return gISystem;
}
#endif

//////////////////////////////////////////////////////////////////////////


#if !defined(_XBOX) && !defined(FAR_CRY_STATIC_LIBS)
BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{
    return TRUE;
}
#endif //_XBOX

IInput *CreateInput( ISystem *pSystem,void* hinst, void* hwnd, bool usedinput)
{
#if defined(FAR_CRY_STATIC_LIBS)
    SetISystem(pSystem);
#else
	gISystem = pSystem;
#endif
	CInput *pInput=new CInput;
	if (!pInput->Init(pSystem,(HINSTANCE)hinst,(HWND)hwnd,usedinput))
	{
		delete pInput;
		return NULL;
	}
	return pInput;
}

#include <CrtDebugStats.h>
