//////////////////////////////////////////////////////////////////////
//
//	Crytek Network source code
//	
//	File: crynetwork.cpp
//  Description: dll entry point
//
//	History:
//	-July 25,2001:Created by Alberto Demichelis
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "CNP.h"
#include "Client.h"
#include "Server.h"
#include "Network.h"

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

#if !defined(XBOX) && !defined(FAR_CRY_STATIC_LIBS)
_ACCESS_POOL;
#if !defined(LINUX)

BOOL APIENTRY DllMain( HANDLE hModule, 
                       DWORD  ul_reason_for_call, 
                       LPVOID lpReserved
					 )
{


    return TRUE;
}
#endif
#endif

#if !defined(_XBOX) && !defined(FAR_CRY_STATIC_LIBS)
CRYNETWORK_API INetwork *CreateNetwork(ISystem *pSystem)
#else
INetwork *CreateNetwork(ISystem *pSystem)
#endif
{
#if defined(FAR_CRY_STATIC_LIBS)
    SetISystem(pSystem);
#else
	gISystem = pSystem;
#endif
	CNetwork *pNetwork=new CNetwork;

	if(!pNetwork->Init(pSystem->GetIScriptSystem()))
	{
		delete pNetwork;
		return NULL;
	}
	return pNetwork;
}

#include <CrtDebugStats.h>

