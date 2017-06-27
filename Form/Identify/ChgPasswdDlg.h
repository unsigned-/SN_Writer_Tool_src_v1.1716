#if !defined(AFX_CHGPASSWDDLG_H__7B9C3FD9_0992_4009_884C_A2F7C33BDFD2__INCLUDED_)
#define AFX_CHGPASSWDDLG_H__7B9C3FD9_0992_4009_884C_A2F7C33BDFD2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ChgPasswdDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CChgPasswdDlg dialog

#include "Common.h"

class CChgPasswdDlg : public CDialog
{
// Construction
public:
	CChgPasswdDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CChgPasswdDlg)
	enum { IDD = IDD_CHANGE_PASSWD_DIALOG };
	CString	m_strOldPasswd;
	CString	m_strNewPasswd;
	CString	m_strConfirmPasswd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChgPasswdDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CChgPasswdDlg)
	afx_msg void OnChgPasswdCancel();
	afx_msg void OnChgPasswdOk();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    //char m_strNewPasswd[LOGIN_PASSWORD_MAX];

public:
    bool VerifyOldPasswd();
    bool ConfirmNewPasswd();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHGPASSWDDLG_H__7B9C3FD9_0992_4009_884C_A2F7C33BDFD2__INCLUDED_)
