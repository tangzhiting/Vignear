// Vignear.h : main header file for the VIGNEAR application
//

#if !defined(AFX_VIGNEAR_H__FEA16DDB_4C63_4181_B700_9293B8496BAE__INCLUDED_)
#define AFX_VIGNEAR_H__FEA16DDB_4C63_4181_B700_9293B8496BAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVignearApp:
// See Vignear.cpp for the implementation of this class
//

class CVignearApp : public CWinApp
{
public:
	CVignearApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVignearApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVignearApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIGNEAR_H__FEA16DDB_4C63_4181_B700_9293B8496BAE__INCLUDED_)
