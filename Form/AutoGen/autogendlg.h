#if !defined(AFX_AUTOGENDLG_H__8900AB0B_C86B_4919_8DC6_81BFEA6B4058__INCLUDED_)
#define AFX_AUTOGENDLG_H__8900AB0B_C86B_4919_8DC6_81BFEA6B4058__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// autogendlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAutoGenDlg dialog

#include "ShadeButtonST.h"

class CAutoGenDlg : public CDialog
{
// Construction
public:
	CAutoGenDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAutoGenDlg)
	enum { IDD = IDD_AUTOGEN_DIALOG };
	CComboBox	m_cDRMKeyMCIDStep;
	CComboBox	m_cEthernetStep;
	CComboBox	m_cBarcStep;
	CComboBox	m_cWifiStep;
	CComboBox	m_cIMEIStep;
	CComboBox	m_cBTStep;
	BOOL	m_bAutoGenBarc;
	BOOL	m_bAutoGenBT;
	BOOL	m_bAutoGenIMEI;
	BOOL	m_bAutoGenWifi;
	CString	m_strBarcEnd;
	CString	m_strBarcNext;
	CString	m_strBTEnd;
	CString	m_strBTNext;
	CString	m_strBTStart;
	CString	m_strIMEIEnd;
	CString	m_strIMEINext;
	CString	m_strIMEIStart;
	CString	m_strWifiEnd;
	CString	m_strWifiNext;
	CString	m_strWifiStart;
	CString	m_strBarcStart;
	BOOL	m_bAutoGenEthernet;
	CString	m_strEthernetEnd;
	CString	m_strEthernetNext;
	CString	m_strEthernetStart;
	CString	m_strDRMKeyMCIDEnd;
	CString	m_strDRMKeyMCIDNext;
	CString	m_strDRMKeyMCIDStart;
	BOOL	m_bAutoGenDRMKeyMCID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoGenDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAutoGenDlg)
	afx_msg void OnBtnAutogenCancel();
	afx_msg void OnBtnAutogenOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnEditchangeBarcAutogenStep();
	afx_msg void OnSelchangeBarcAutogenStep();
	afx_msg void OnEditchangeBtAutogenStep();
	afx_msg void OnSelchangeBtAutogenStep();
	afx_msg void OnEditchangeImeiAutogenStep();
	afx_msg void OnSelchangeImeiAutogenStep();
	afx_msg void OnEditchangeWifiAutogenStep();
	afx_msg void OnSelchangeWifiAutogenStep();
	afx_msg void OnAutogenBarcCheck();
	afx_msg void OnAutogenBtCheck();
	afx_msg void OnAutogenImeiCheck();
	afx_msg void OnAutogenWifiCheck();
	afx_msg void OnAutogenEthernetCheck();
	afx_msg void OnEditchangeEthernetAutogenStep();
	afx_msg void OnSelchangeEthernetAutogenStep();
	afx_msg void OnAutogenDrmkeyMcidCheck();
	afx_msg void OnEditchangeDrmkeyMcidAutogenStep();
	afx_msg void OnSelchangeDrmkeyMcidAutogenStep();
	afx_msg void OnDenaryIncrease();
	afx_msg void OnHexIncrease();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

protected:
    void UpdateUIComponent();
    void CollectUIComponent();
    bool CheckSetupValid();
    bool CmpSetupString(const char* strStart, const char* strEnd, const char* strNext, int refLength, const char* pDataType);

private:
    bool m_bEnableAutoGen;
    CShadeButtonST m_AutoGenCancelBTN;
    CShadeButtonST m_AutoGenOKBTN;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOGENDLG_H__8900AB0B_C86B_4919_8DC6_81BFEA6B4058__INCLUDED_)
