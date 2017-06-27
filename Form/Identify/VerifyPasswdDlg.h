#if !defined(AFX_VERIFYPASSWDDLG_H__E0BE42C5_909F_419F_8421_1C77651A0F4D__INCLUDED_)
#define AFX_VERIFYPASSWDDLG_H__E0BE42C5_909F_419F_8421_1C77651A0F4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VerifyPasswdDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVerifyPasswdDlg dialog

class CVerifyPasswdDlg : public CDialog
{
// Construction
public:
	CVerifyPasswdDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CVerifyPasswdDlg)
	enum { IDD = IDD_IDENTIFY_VERIFY_DIALOG };
	CString	m_strOldPasswd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVerifyPasswdDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CVerifyPasswdDlg)
	afx_msg void OnBtnVerifyOk();
	afx_msg void OnBtnVerifyCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
    bool IsVerifyPasswdPass();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VERIFYPASSWDDLG_H__E0BE42C5_909F_419F_8421_1C77651A0F4D__INCLUDED_)
