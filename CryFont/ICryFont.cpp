//////////////////////////////////////////////////////////////////////
//
//  CryFont Source Code
//
//  File: ICryFont.cpp
//  Description: Create the font interface.
//
//  History:
//  - August 17, 2001: Created by Alberto Demichelis
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"

#ifndef _XBOX
_ACCESS_POOL;
#endif //_XBOX

#include "CryFont.h"

#if !defined(FAR_CRY_STATIC_LIBS)
ISystem *gISystem = 0;
//! Get the system interface 
ISystem	*GetISystem()
{
	return gISystem;
}
#endif

///////////////////////////////////////////////
extern "C" ICryFont* CreateCryFontInterface(ISystem *pSystem)
{
#if defined(FAR_CRY_STATIC_LIBS)
    SetISystem(pSystem);
#else
    gISystem = pSystem;
#endif
	return new CCryFont(pSystem);
}

///////////////////////////////////////////////
#if !defined(_XBOX) && !defined(PS2) && !defined(FAR_CRY_STATIC_LIBS)
BOOL APIENTRY DllMain(HANDLE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    return TRUE;
}
#endif