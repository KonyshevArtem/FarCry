////////////////////////////////////////////////////////////////////////////
//
//  Crytek Engine Source File.
//  Copyright (C), Crytek Studios, 2004.
// -------------------------------------------------------------------------
//  File name:   Linux32Specific.h
//  Version:     v1.00
//  Created:     05/03/2004 by MarcoK.
//  Compilers:   Visual Studio.NET, GCC 3.2
//  Description: Specific to Linux declarations, inline functions etc.
// -------------------------------------------------------------------------
//  History:
//
////////////////////////////////////////////////////////////////////////////
#ifndef _CRY_COMMON_LINUX64_SPECIFIC_HDR_
#define _CRY_COMMON_LINUX64_SPECIFIC_HDR_

#include "LinuxSpecific.h"
#include </usr/include/stdint.h>


typedef uint64							DWORD_PTR;
typedef intptr_t INT_PTR, *PINT_PTR;
typedef uintptr_t UINT_PTR, *PUINT_PTR;
typedef char *LPSTR, *PSTR;
typedef unsigned long long __uint64;
typedef signed long long __int64;

typedef long long						UINT64;

typedef UINT_PTR 						WPARAM;
#define PLARGE_INTEGER LARGE_INTEGER*
typedef const char *LPCSTR, *PCSTR;
typedef	ULONG_PTR						SIZE_T;

#endif //_CRY_COMMON_LINUX64_SPECIFIC_HDR_
