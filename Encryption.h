#if !defined(AFX_ENCRYPTION_H__A1D48CD0_7BBD_4F19_92D4_9F9FDE5172E1__INCLUDED_)
#define AFX_ENCRYPTION_H__A1D48CD0_7BBD_4F19_92D4_9F9FDE5172E1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Encryption.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Encryption dialog
extern char g_cPwd[52];

class Encryption : public CDialog
{
// Construction
public:
	Encryption(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Encryption)
	enum { IDD = IDD_ENCRYPTION_DIALOG };
	CString m_strPwdData;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Encryption)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Encryption)
	virtual void OnCancel();
	virtual void OnOK();
	afx_msg void OnKillfocusPwdData();
	virtual BOOL OnInitDialog();
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENCRYPTION_H__A1D48CD0_7BBD_4F19_92D4_9F9FDE5172E1__INCLUDED_)
