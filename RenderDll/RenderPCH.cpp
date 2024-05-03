/*=============================================================================
	RenderPC.cpp: Cry Render support precompiled header.
	Copyright 2001 Crytek Studios. All Rights Reserved.

	Revision history:
		* Created by Honitch Andrey

=============================================================================*/

#include "RenderPCH.h"

_inline void ProjectPoint(vec4_t pv, Vec3d& v3d, vec2_t v2d)
{
    v3d[0] = pv[0] / pv[3];
    v3d[1] = pv[1] / pv[3];
    v3d[2] = (pv[2] + pv[3]) / (pv[2] + pv[3] + pv[3]);

    v2d[0] = (float)QRound((v3d[0] + 1) * gRenDev->GetWidth()  * 0.5f);
    v2d[1] = (float)QRound((v3d[1] + 1) * gRenDev->GetHeight() * 0.5f);

    v2d[0] = (float)QRound(v2d[0]);
    v2d[1] = (float)QRound(v2d[1]);
}

inline void _text_to_log(char * format, ...)
{
    char buffer[MAX_PATH_LENGTH];
    va_list args;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);

    iLog->Log(buffer);
    if (gRenDev->CV_r_log == 3)
        gRenDev->Logv(SRendItem::m_RecurseLevel, buffer);
}

inline void _text_to_logPlus(char * format, ...)
{
    char buffer[MAX_PATH_LENGTH];
    va_list args;
    va_start(args, format);
    vsprintf(buffer, format, args);
    va_end(args);

    iLog->LogPlus(buffer);
    if (gRenDev->CV_r_log == 3)
        gRenDev->Logv(SRendItem::m_RecurseLevel, buffer);
}

inline void _UpdateLoadingScreen(const char * format, ...)
{
    if(format)
    {
        char buffer[MAX_PATH_LENGTH];
        va_list args;
        va_start(args, format);
        vsprintf(buffer, format, args);
        va_end(args);

        iLog->Log(buffer);
        if (gRenDev->CV_r_log == 3)
            gRenDev->Logv(SRendItem::m_RecurseLevel, buffer);
    }

    //iConsole->Update();
    //gRenDev->BeginFrame();
    //iConsole->Draw();
    //gRenDev->Update();
}

inline void _UpdateLoadingScreenPlus(const char * format, ...)
{
    if(format)
    {
        char buffer[MAX_PATH_LENGTH];
        va_list args;
        va_start(args, format);
        vsprintf(buffer, format, args);
        va_end(args);

        iLog->Log(buffer);
        if (gRenDev->CV_r_log == 3)
            gRenDev->Logv(SRendItem::m_RecurseLevel, buffer);
    }

    iConsole->Update();
    gRenDev->BeginFrame();
    iConsole->Draw();
    gRenDev->Update();
}

/*-----------------------------------------------------------------------------
	The End.
-----------------------------------------------------------------------------*/
