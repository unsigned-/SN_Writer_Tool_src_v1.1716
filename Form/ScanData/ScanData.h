#if !defined(AFX_SCANDATA_H__CD6976C2_87AB_4CD4_96F3_7E733406F5D1__INCLUDED_)
#define AFX_SCANDATA_H__CD6976C2_87AB_4CD4_96F3_7E733406F5D1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ScanData.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScanData dialog

#include "ShadeButtonST.h"


typedef enum
{
    Barcode_Index =  0,       
    Imei_1_Index,   
    Imei_2_Index, 
    Imei_3_Index,   
    Imei_4_Index,
    SerialNo_Index,
    Bt_Index,
    Wifi_Index,
    Ethernet_Index,
    DRMKey_MCID_Index,
	Meid_Index,
	Esn_Index,
    OK_Index
}E_ScanData_Index;


#define  MAX_SCANDATA_NUMS (OK_Index - Barcode_Index + 1)

typedef enum
{
    Barcode = 0,
    Imei,
    SerialNo,
    BT,
    Wifi,
    Ethernet_mac,
    DRMKey_MCID,
	Meid,
	Esn
}E_ScanData_Type;

typedef struct
{
    UINT staticID;
    UINT editID;
    UINT headerID;
}ScanControlID_struct;

class CScanData : public CDialog
{
// Construction
public:
	CScanData(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CScanData)
	enum { IDD = IDD_SCANDATA_DIALOG };
	CString	m_strBarcData;
	CString	m_strIMEI1Data;
	CString	m_strIMEI2Data;
	CString	m_strIMEI3Data;
	CString	m_strIMEI4Data;
	CString	m_strWifiData;
	CString	m_strBtData;
	CString	m_strEthernetMacData;
	CString	m_strDrmkeyMCIDData;
	CString	m_strSerialNoData;
	//C2K
	CString m_strMeidData;
	CString m_strEsnData;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScanData)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CScanData)
	afx_msg void OnKillfocusBtData();
	afx_msg void OnKillfocusBarcodeData();
	afx_msg void OnKillfocusImei1Data();
	afx_msg void OnKillfocusImei2Data();
	afx_msg void OnKillfocusImei3Data();
	afx_msg void OnKillfocusImei4Data();
	afx_msg void OnKillfocusWifiData();
	afx_msg void OnBtnScanOk();
	afx_msg void OnBtnScanCancel();
	virtual BOOL OnInitDialog();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	afx_msg void OnKillfocusEthernetMacData();
	afx_msg void OnKillfocusDrmkeyMcidData();
	afx_msg void OnKillfocusSerialNoData();
	afx_msg void OnKillfocusMeidData();
	afx_msg void OnKillfocusEsnData();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
    char m_strSerinalNoByIMEI[IMEI_ARRAY_LEN];
    bool m_bNeedBackupIMEI;
    char m_strBackupIMEI[16];
    char* m_pstrScanItem;
    CShadeButtonST m_ScanCancelBTN;
    CShadeButtonST m_ScanOKBTN;

protected:
    void GenSerialNoFirstStep(const char* pFirstIMEI);
    void GenSerialNoSecondStep();
    bool CheckSerialNoMatchWithIMEI(const char* pSerialNo);
    void InitScanUI();
    void RemoveWindow();
    void CreateScanOrder();
    void SetNextFocus(int iCurrentID, bool bCheckPass);
    bool CheckAllScanData();
    bool CheckScanData(const char *pStrHeader, bool bCheckHeader, const char *pInData, E_ScanData_Type dataType);
    bool CheckScanDataByIndex(int index);
    int  GetNextScanID(const int currentID);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCANDATA_H__CD6976C2_87AB_4CD4_96F3_7E733406F5D1__INCLUDED_)
