// looper.h : main header file for the corelooper DLL
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CcorelooperApp
// See corelooper.cpp for the implementation of this class
//

class CcorelooperApp : public CWinApp
{
public:
	CcorelooperApp();

// Overrides
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
