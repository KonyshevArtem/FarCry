#ifndef _TINY_BROWSE_FOLDER_H_
#define _TINY_BROWSE_FOLDER_H_

#pragma once

#ifndef __TINY_MAIN_H__
#error "_TinyBrowseFolder require <_TinyMain.h>"
#endif

#include <Shlobj.h>
#include <windows.h>

// TODO

BOOL _TinyBrowseForFolder(char szPathOut[_MAX_PATH], _TinyWindow *pParent = NULL)
{
	BROWSEINFO sInfo;
	char szDisplayName[_MAX_PATH];
	ITEMIDLIST *pList = NULL;

	szPathOut[0] = '\0';

	sInfo.hwndOwner = (pParent == NULL) ? NULL : pParent->m_hWnd;
	sInfo.pidlRoot = NULL;
	sInfo.pszDisplayName = szDisplayName;
	sInfo.ulFlags = BIF_RETURNONLYFSDIRS;
	sInfo.lpfn = NULL;
	sInfo.lParam = 0;
	sInfo.iImage = 0;

	try
	{
		if (FAILED(CoInitialize(NULL)))
			throw;

		CoInitialize(NULL);
	
		SHBrowseForFolder(&sInfo);
		if ((pList = SHBrowseForFolder(&sInfo)) == NULL)
			throw;

		// SHGetPathFromIDList
	}
	catch(std::exception &_)
	{
		CoUninitialize();
	}
	
	return TRUE;
}

// char szTmp[_MAX_PATH];
// extern BOOL g_bTest = _TinyBrowseForFolder(szTmp);

#endif