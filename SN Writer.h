// SN Writer.h : main header file for the SN WRITER application
//

#if !defined(AFX_SNWRITER_H__436CDCCF_5C03_42DF_A146_26926FBEB7C6__INCLUDED_)
#define AFX_SNWRITER_H__436CDCCF_5C03_42DF_A146_26926FBEB7C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSNWriterApp:
// See SN Writer.cpp for the implementation of this class
//

class CSNWriterApp : public CWinApp
{
public:
	CSNWriterApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSNWriterApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSNWriterApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNWRITER_H__436CDCCF_5C03_42DF_A146_26926FBEB7C6__INCLUDED_)
