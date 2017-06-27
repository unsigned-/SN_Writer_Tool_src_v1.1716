// SN WriterDlg.h : header file
//

#if !defined(AFX_SNWRITERDLG_H__29A5423E_BA01_4A1E_BECC_1C25DBDFAC45__INCLUDED_)
#define AFX_SNWRITERDLG_H__29A5423E_BA01_4A1E_BECC_1C25DBDFAC45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSNWriterDlg dialog

#define _BITMAP_BTN_
//#undef  _BITMAP_BTN_

#include "FPexc.h"
#include "SPexc.h"
#include "ShadeButtonST.h"

class CSNWriterDlg : public CDialog
{
// Construction
public:
	CSNWriterDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSNWriterDlg)
	enum { IDD = IDD_SNWRITER_DIALOG };	
	CComboBox	m_cTargetTypeBox;
	CComboBox	m_cComPortBox;
	CProgressCtrl	m_ProgressSN;
	CString	m_strTotal;
	CString	m_strPass;
	CString	m_strFail;
	CString m_MainUIT1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSNWriterDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL DestroyWindow();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	// Generated message map functions
	//{{AFX_MSG(CSNWriterDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnStart();
	afx_msg void OnBtnQuit();
	afx_msg void OnBtnSysconfig();
	afx_msg void OnSelchangeComboComport();
	afx_msg void OnSelchangeComboTargetType();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnAboutSn();
	afx_msg void OnAtcmdMode();
	afx_msg void OnChangePasswd();
	afx_msg void OnEngToOperater();
	afx_msg void OnFpAuthFile();
	afx_msg void OnOptionAlreadyInMeta();
	afx_msg void OnMetaMode();
	afx_msg void OnOperatorToEng();
	afx_msg void OnOptionDrmkey();
	afx_msg void OnOptionExtmodem();
	afx_msg void OnOptionHdcp();
	afx_msg void OnOptionSecurityUsb();
	afx_msg void OnOptionSwitchtool();
	afx_msg void OnSpAuthFile();
	afx_msg void OnOptionHdcpdata();
	afx_msg void OnOptionUsbWithoutBattery();
	afx_msg void OnEnableAutogen();
	afx_msg void OnOptionCheckCalFlag();
	afx_msg void OnOptionCheckFtFlag();
	afx_msg void OnOptionSkipWriteProdinfo();
	afx_msg void OnCheckBtwifi();
	afx_msg void OnOptionCompositeDevice();
	afx_msg void OnBacknvTopc();
	afx_msg void OnFastbootOemLock();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
    void ParameterInit();
    void MenuItemInit();
    void EnableUIItem();
    void DisableUIItem();
    void SetUIItem();
    void GetComPortDynamiclly();
    void GetUIItem();
    void UpdateOperateResult(WriteNvram_Status_e eWriteStatus = NORMAL);
    void SwitchToEngineer();
    void SwitchToOperator();
    void GetIndicatorPos(CRect &rect);
    void PopupMsgBox(const char* strTilte, UINT uType, const char* strMsg, ...);
    void EnableStartBTN(bool bEnable = true);
	void ShowTemperatureOnUI();


private:
    HMENU m_hSNMenu;
    CMenu m_SNMenu;
    SmartPhoneSN m_spSN;
    FeaturePhoneSN m_fpSN;
    CShadeButtonST	m_StartBTN;
    CShadeButtonST	m_QuitBTN;
    CShadeButtonST  m_SystemCfgBTN;

#ifdef _BITMAP_BTN_
    CButton	m_InditeBTN;
#else
    CShadeButtonST	m_InditeBTN;
#endif

public:
    HBITMAP m_hBitmapPass;
    HBITMAP m_hBitmapFail;
	CFont m_font;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SNWRITERDLG_H__29A5423E_BA01_4A1E_BECC_1C25DBDFAC45__INCLUDED_)
