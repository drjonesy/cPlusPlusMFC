
// Payroll.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CPayrollApp:
// See Payroll.cpp for the implementation of this class
//

class CPayrollApp : public CWinApp
{
public:
	CPayrollApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CPayrollApp theApp;