#if !defined(AFX_SYSTEMCONFIG_H__0B5BBA83_CFA5_489F_9D8D_C92966F38DF0__INCLUDED_)
#define AFX_SYSTEMCONFIG_H__0B5BBA83_CFA5_489F_9D8D_C92966F38DF0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SystemConfig.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSystemConfig dialog

#include "ShadeButtonST.h"
#include "Common.h"

class CSystemConfig : public CDialog
{
    // Construction
public:
    CSystemConfig(CWnd* pParent = NULL);   // standard constructor

    // Dialog Data
    //{{AFX_DATA(CSystemConfig)
    enum { IDD = IDD_SYSTEM_CONFIG_DIALOG };
    //************C2K PARA START************//
    CString m_strMeidHD;
    CString m_strEsnHD;
    BOOL    m_bCheckMeidHD;
    BOOL    m_bCheckEsnHD;
    BOOL    m_bWriteMeid;
    BOOL    m_bWriteEsn;
    //************C2K PARA END************//

    CString m_strLogDir;
    CString	m_strWifiHD;
    CString	m_strMD_2_DBPath;
    CString	m_strMD_1_DBPath;
    CString	m_strIMEI_4_HD;
    CString	m_strIMEI_3_HD;
    CString	m_strIMEI_2_HD;
    CString	m_strIMEI_1_HD;
    CString	m_strBTHD;
    CString	m_strBarcHD;
    CString	m_strAPDbPath;
    CString m_strTemp;
    BOOL	m_bCheckBarcHD;
    BOOL	m_bCheckBTHD;
    BOOL	m_bCheckIMEI_1_HD;
    BOOL	m_bCheckIMEI_2_HD;
    BOOL	m_bCheckIMEI_3_HD;
    BOOL	m_bCheckIMEI_4_HD;
    BOOL	m_bDualIMEI;
    BOOL	m_bDualIMEISame;
    BOOL	m_bFourIMEI;
    BOOL	m_bIMEICheckSum;
    BOOL	m_bThreeIMEI;
    BOOL    m_bWriteTemperature;
    BOOL	m_bCheckWifiHD;
    BOOL	m_bWriteBarc;
    BOOL	m_bWriteBTAddr;
    BOOL	m_bWriteIMEI;
    BOOL	m_bWriteWifi;
    BOOL	m_bIMEILock;
    BOOL	m_bUsbEnable;
    BOOL	m_bWriteEthernetMac;
    BOOL	m_bCheckEthernetHD;
    CString	m_strEthernetHD;
    BOOL	m_bCheckDrmkeyMCID_HD;
    CString	m_strDrmkeyMCID_HD;
    BOOL	m_bWriteDrmkeyMCID;
    BOOL	m_bWriteSerialNo;
    BOOL	m_bCheckSerialNoHD;
    //BOOL  m_bExternMDDownload;
    CString	m_strSerialNoHD;
    BOOL    m_bDBFromDUT;
    //}}AFX_DATA


    // Overrides
    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CSystemConfig)
public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    virtual BOOL DestroyWindow();
protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support	
    //    void GetIndicatorWD(CRect &rect);
    //}}AFX_VIRTUAL

    // Implementation
protected:

    // Generated message map functions
    //{{AFX_MSG(CSystemConfig)
    afx_msg void OnBarcHeaderCheck();
    afx_msg void OnBtHeaderCheck();
    afx_msg void OnBtnAp();
    afx_msg void OnBtnMd1();
    afx_msg void OnBtnMd2();
    afx_msg void OnDualImei();
    afx_msg void OnDualImeiSame();
    afx_msg void OnFourImei();
    afx_msg void OnImei1HeaderCheck();
    afx_msg void OnImei2HeaderCheck();
    afx_msg void OnImei3HeaderCheck();
    afx_msg void OnImei4HeaderCheck();
    afx_msg void OnImeiChecksum();
    afx_msg void OnImeiLock();
    afx_msg void OnThreeImei();
    afx_msg void OnWifiHeaderCheck();
    afx_msg void OnWriteBarcCheck();
    afx_msg void OnWriteBtCheck();
    afx_msg void OnWriteImeiCheck();
    afx_msg void OnWriteWifiCheck();
    virtual BOOL OnInitDialog();
    afx_msg void OnBtnSave();
    afx_msg void OnCurrentTemperature();
    afx_msg void OnWriteEthernetMacCheck();
    afx_msg void OnWriteDrmkeyMcidCheck();
    afx_msg void OnDrmkeyMcidHeaderCheck();
    afx_msg void OnKillfocusTemperature();
    afx_msg void OnWriteSerialNoCheck();
    afx_msg void OnSerialNoHeaderCheck();
    afx_msg void OnWriteMeidCheck();
    afx_msg void OnWriteEsnCheck();
    afx_msg void OnMeidHeaderCheck();
    afx_msg void OnEsnHeaderCheck();
    afx_msg void OnEthernetHeaderCheck();
    afx_msg void OnDBFromDUTCheck();
    afx_msg void OnLogDir();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

protected:
    void GetUIEditData();
    void UpDateIMEIHeaderOption(E_IMEI_NUM iIMEINums, BOOL bEnable);
    void UpDateIMEIOption(BOOL bWriteIMEIEnable);
    void UpdateConfigUIOption();
    void EnableDBFileOption();
    void CheckTempDataValid();

private:
    CShadeButtonST m_Load_MD1DB_BTN;
    CShadeButtonST m_Load_MD2DB_BTN;
    CShadeButtonST m_Load_APDB_BTN;
    CShadeButtonST m_LogDir_BTN;
    CShadeButtonST m_SaveBTN;

    CToolTipCtrl * m_pToolTip;

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSTEMCONFIG_H__0B5BBA83_CFA5_489F_9D8D_C92966F38DF0__INCLUDED_)
