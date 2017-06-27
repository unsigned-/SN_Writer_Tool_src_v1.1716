// autogendlg.cpp : implementation file
//

#include "stdafx.h"
//#include "..\..\SN Writer.h"
#include "SN Writer.h"
#include "autogendlg.h"
#include "Common.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoGenDlg dialog

#define MAX_STEP 9
#define Check_Pass 1
#define Check_Fail 0

CAutoGenDlg::CAutoGenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutoGenDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAutoGenDlg)
	m_bAutoGenBarc = FALSE;
	m_bAutoGenBT = FALSE;
	m_bAutoGenIMEI = FALSE;
	m_bAutoGenWifi = FALSE;
	m_strBarcEnd = _T("");
	m_strBarcNext = _T("");
	m_strBTEnd = _T("");
	m_strBTNext = _T("");
	m_strBTStart = _T("");
	m_strIMEIEnd = _T("");
	m_strIMEINext = _T("");
	m_strIMEIStart = _T("");
	m_strWifiEnd = _T("");
	m_strWifiNext = _T("");
	m_strWifiStart = _T("");
	m_strBarcStart = _T("");
	m_bAutoGenEthernet = FALSE;
	m_strEthernetEnd = _T("");
	m_strEthernetNext = _T("");
	m_strEthernetStart = _T("");
	m_strDRMKeyMCIDEnd = _T("");
	m_strDRMKeyMCIDNext = _T("");
	m_strDRMKeyMCIDStart = _T("");
	m_bAutoGenDRMKeyMCID = FALSE;
	//}}AFX_DATA_INIT

    m_bEnableAutoGen = false;
}


void CAutoGenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutoGenDlg)
	DDX_Control(pDX, IDC_DRMKEY_MCID_AUTOGEN_STEP, m_cDRMKeyMCIDStep);
	DDX_Control(pDX, IDC_ETHERNET_AUTOGEN_STEP, m_cEthernetStep);
	DDX_Control(pDX, IDC_BARC_AUTOGEN_STEP, m_cBarcStep);
	DDX_Control(pDX, IDC_WIFI_AUTOGEN_STEP, m_cWifiStep);
	DDX_Control(pDX, IDC_IMEI_AUTOGEN_STEP, m_cIMEIStep);
	DDX_Control(pDX, IDC_BT_AUTOGEN_STEP, m_cBTStep);
	DDX_Check(pDX, IDC_AUTOGEN_BARC_CHECK, m_bAutoGenBarc);
	DDX_Check(pDX, IDC_AUTOGEN_BT_CHECK, m_bAutoGenBT);
	DDX_Check(pDX, IDC_AUTOGEN_IMEI_CHECK, m_bAutoGenIMEI);
	DDX_Check(pDX, IDC_AUTOGEN_WIFI_CHECK, m_bAutoGenWifi);
	DDX_Text(pDX, IDC_BARC_END_STR, m_strBarcEnd);
	DDV_MaxChars(pDX, m_strBarcEnd, 64);
	DDX_Text(pDX, IDC_BARC_NEXT_STR, m_strBarcNext);
	DDV_MaxChars(pDX, m_strBarcNext, 64);
	DDX_Text(pDX, IDC_BT_END_STR, m_strBTEnd);
	DDV_MaxChars(pDX, m_strBTEnd, 12);
	DDX_Text(pDX, IDC_BT_NEXT_STR, m_strBTNext);
	DDV_MaxChars(pDX, m_strBTNext, 12);
	DDX_Text(pDX, IDC_BT_START_STR, m_strBTStart);
	DDV_MaxChars(pDX, m_strBTStart, 12);
	DDX_Text(pDX, IDC_IMEI_END_STR, m_strIMEIEnd);
	DDV_MaxChars(pDX, m_strIMEIEnd, 15);
	DDX_Text(pDX, IDC_IMEI_NEXT_STR, m_strIMEINext);
	DDV_MaxChars(pDX, m_strIMEINext, 15);
	DDX_Text(pDX, IDC_IMEI_START_STR, m_strIMEIStart);
	DDV_MaxChars(pDX, m_strIMEIStart, 15);
	DDX_Text(pDX, IDC_WIFI_END_STR, m_strWifiEnd);
	DDV_MaxChars(pDX, m_strWifiEnd, 12);
	DDX_Text(pDX, IDC_WIFI_NEXT_STR, m_strWifiNext);
	DDV_MaxChars(pDX, m_strWifiNext, 12);
	DDX_Text(pDX, IDC_WIFI_START_STR, m_strWifiStart);
	DDV_MaxChars(pDX, m_strWifiStart, 12);
	DDX_Text(pDX, IDC_BARC_START_STR, m_strBarcStart);
	DDV_MaxChars(pDX, m_strBarcStart, 64);
	DDX_Check(pDX, IDC_AUTOGEN_ETHERNET_CHECK, m_bAutoGenEthernet);
	DDX_Text(pDX, IDC_ETHERNET_END_STR, m_strEthernetEnd);
	DDV_MaxChars(pDX, m_strEthernetEnd, 12);
	DDX_Text(pDX, IDC_ETHERNET_NEXT_STR, m_strEthernetNext);
	DDV_MaxChars(pDX, m_strEthernetNext, 12);
	DDX_Text(pDX, IDC_ETHERNET_START_STR, m_strEthernetStart);
	DDV_MaxChars(pDX, m_strEthernetStart, 12);
	DDX_Text(pDX, IDC_DRMKEY_MCID_END_STR, m_strDRMKeyMCIDEnd);
	DDV_MaxChars(pDX, m_strDRMKeyMCIDEnd, 32);
	DDX_Text(pDX, IDC_DRMKEY_MCID_NEXT_STR, m_strDRMKeyMCIDNext);
	DDV_MaxChars(pDX, m_strDRMKeyMCIDNext, 32);
	DDX_Text(pDX, IDC_DRMKEY_MCID_START_STR, m_strDRMKeyMCIDStart);
	DDV_MaxChars(pDX, m_strDRMKeyMCIDStart, 32);
	DDX_Check(pDX, IDC_AUTOGEN_DRMKEY_MCID_CHECK, m_bAutoGenDRMKeyMCID);
	//}}AFX_DATA_MAP

    DDX_Control(pDX, IDC_BTN_AUTOGEN_CANCEL, m_AutoGenCancelBTN);
    DDX_Control(pDX, IDC_BTN_AUTOGEN_OK, m_AutoGenOKBTN);
}


BEGIN_MESSAGE_MAP(CAutoGenDlg, CDialog)
	//{{AFX_MSG_MAP(CAutoGenDlg)
	ON_BN_CLICKED(IDC_BTN_AUTOGEN_CANCEL, OnBtnAutogenCancel)
	ON_BN_CLICKED(IDC_BTN_AUTOGEN_OK, OnBtnAutogenOk)
	ON_CBN_EDITCHANGE(IDC_BARC_AUTOGEN_STEP, OnEditchangeBarcAutogenStep)
	ON_CBN_SELCHANGE(IDC_BARC_AUTOGEN_STEP, OnSelchangeBarcAutogenStep)
	ON_CBN_EDITCHANGE(IDC_BT_AUTOGEN_STEP, OnEditchangeBtAutogenStep)
	ON_CBN_SELCHANGE(IDC_BT_AUTOGEN_STEP, OnSelchangeBtAutogenStep)
	ON_CBN_EDITCHANGE(IDC_IMEI_AUTOGEN_STEP, OnEditchangeImeiAutogenStep)
	ON_CBN_SELCHANGE(IDC_IMEI_AUTOGEN_STEP, OnSelchangeImeiAutogenStep)
	ON_CBN_EDITCHANGE(IDC_WIFI_AUTOGEN_STEP, OnEditchangeWifiAutogenStep)
	ON_CBN_SELCHANGE(IDC_WIFI_AUTOGEN_STEP, OnSelchangeWifiAutogenStep)
	ON_BN_CLICKED(IDC_AUTOGEN_BARC_CHECK, OnAutogenBarcCheck)
	ON_BN_CLICKED(IDC_AUTOGEN_BT_CHECK, OnAutogenBtCheck)
	ON_BN_CLICKED(IDC_AUTOGEN_IMEI_CHECK, OnAutogenImeiCheck)
	ON_BN_CLICKED(IDC_AUTOGEN_WIFI_CHECK, OnAutogenWifiCheck)
	ON_BN_CLICKED(IDC_AUTOGEN_ETHERNET_CHECK, OnAutogenEthernetCheck)
	ON_CBN_EDITCHANGE(IDC_ETHERNET_AUTOGEN_STEP, OnEditchangeEthernetAutogenStep)
	ON_CBN_SELCHANGE(IDC_ETHERNET_AUTOGEN_STEP, OnSelchangeEthernetAutogenStep)
	ON_BN_CLICKED(IDC_AUTOGEN_DRMKEY_MCID_CHECK, OnAutogenDrmkeyMcidCheck)
	ON_CBN_EDITCHANGE(IDC_DRMKEY_MCID_AUTOGEN_STEP, OnEditchangeDrmkeyMcidAutogenStep)
	ON_CBN_SELCHANGE(IDC_DRMKEY_MCID_AUTOGEN_STEP, OnSelchangeDrmkeyMcidAutogenStep)
	ON_BN_CLICKED(IDC_DENARY_INCREASE, OnDenaryIncrease)
	ON_BN_CLICKED(IDC_HEX_INCREASE, OnHexIncrease)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoGenDlg message handlers

BOOL CAutoGenDlg::OnInitDialog() 
{
    CDialog::OnInitDialog();
    
    // TODO: Add extra initialization here
    m_AutoGenCancelBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_AutoGenOKBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);

    int i = 0;
    char strTmp[5] = {0};
    for (i = 0; i < MAX_STEP; i++ )
    {
        sprintf(strTmp, "%d", i+1);
        m_cBarcStep.InsertString(i, strTmp);
    }
    
    for (i = 0; i < MAX_STEP; i++ )
    {
        sprintf(strTmp, "%d", i+1);
        m_cIMEIStep.InsertString(i, strTmp);
    }
    
    for (i = 0; i < MAX_STEP; i++ )
    {
        sprintf(strTmp, "%d", i+1);
        m_cBTStep.InsertString(i, strTmp);
    }
    
    for (i = 0; i < MAX_STEP; i++ )
    {
        sprintf(strTmp, "%d", i+1);
        m_cWifiStep.InsertString(i, strTmp);
    }
    
    for (i = 0; i < MAX_STEP; i++ )
    {
        sprintf(strTmp, "%d", i+1);
        m_cEthernetStep.InsertString(i, strTmp);
    }

    for (i = 0; i < MAX_STEP; i++ )
    {
        sprintf(strTmp, "%d", i+1);
        m_cDRMKeyMCIDStep.InsertString(i, strTmp);
    }
    
    UpdateUIComponent();
    return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CAutoGenDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
    if ( pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE )
    {
        return TRUE;
    }
	return CDialog::PreTranslateMessage(pMsg);
}

bool CAutoGenDlg::CmpSetupString(const char* strStart, const char* strEnd, const char* strNext, int refLength, const char* pDataType)
{
    char strMsg[256] = {0};
    int iStartLength = strlen(strStart);
    int iEndLength = strlen(strEnd);
    int iNextLength = strlen(strNext);

    if (strnicmp("Barcode", pDataType, strlen(pDataType)) != 0)
    {
        if (iStartLength != refLength || iEndLength != refLength || iNextLength != refLength)
        {
            sprintf ( strMsg, "Error: %s data length should be %d", pDataType, refLength);
            MessageBox(strMsg, "Error");
            return Check_Fail;
        }
        else
        {
            if(strnicmp(strStart, strEnd, refLength) > 0)
            {
                sprintf ( strMsg, "Error: Star_%s(\"%s\") should be less than End_%s(\"%s\")", pDataType, strStart, pDataType, strEnd);
                MessageBox(strMsg, "Error");
                return Check_Fail;
            }
            
            if(strnicmp(strNext, strEnd, refLength) > 0)
            {
                sprintf ( strMsg, "Error: Next_%s(\"%s\") should be less than End_%s(\"%s\")", pDataType, strNext, pDataType, strEnd);
                MessageBox(strMsg, "Error");
                return Check_Fail;
            }
            
            if(strnicmp(strStart, strNext, refLength) > 0)
            {
                sprintf ( strMsg, "Error: Next_%s(\"%s\") should be not less than Start_%s(\"%s\")", pDataType, strNext, pDataType, strStart);
                MessageBox(strMsg, "Error");
                return Check_Fail;
            }
        }
    }
    else
    {
        if (iEndLength > iStartLength)
        {
            if (iNextLength > iStartLength && iNextLength < iEndLength)
            {
                return Check_Pass;
            }
            else 
            {
                if (iNextLength < iStartLength)
                {
                    sprintf ( strMsg, "Error: Next_%s(\"%s\") should be not less than Start_%s(\"%s\")", pDataType, strNext, pDataType, strStart);
                    MessageBox(strMsg, "Error");
                    return Check_Fail;
                }

                if(iNextLength > iEndLength)
                {
                    sprintf ( strMsg, "Error: Next_%s(\"%s\") should be less than End_%s(\"%s\")", pDataType, strNext, pDataType, strEnd);
                    MessageBox(strMsg, "Error");
                    return Check_Fail;
                }

                if (iNextLength == iStartLength)
                {
                    if(strnicmp(strStart, strNext, iNextLength) > 0)
                    {
                        sprintf ( strMsg, "Error: Next_%s(\"%s\") should be not less than Start_%s(\"%s\")", pDataType, strNext, pDataType, strStart);
                        MessageBox(strMsg, "Error");
                        return Check_Fail;
                    }
                }

                if (iNextLength == iEndLength)
                {
                    if(strnicmp(strNext, strEnd, iNextLength) > 0)
                    {
                        sprintf ( strMsg, "Error: Next_%s(\"%s\") should be less than End_%s(\"%s\")", pDataType, strNext, pDataType, strEnd);
                        MessageBox(strMsg, "Error");
                        return Check_Fail;
	                }
                }
            }
        }
        else if (iEndLength < iStartLength)
        {
            sprintf ( strMsg, "Error: Star_%s(\"%s\") should be less than End_%s(\"%s\")", pDataType, strStart, pDataType, strEnd);
            MessageBox(strMsg, "Error");
            return Check_Fail;
        }
    }

    return Check_Pass;
}

bool CAutoGenDlg::CheckSetupValid()
{
    bool bCheckFail = false;
    if (g_AutoGenData.bAutoGenBarcode == true)
    {       
        if(!CmpSetupString(g_AutoGenData.sBarcode.Start, g_AutoGenData.sBarcode.End, g_AutoGenData.sBarcode.Next, 64, "Barcode"))
        {
            g_AutoGenData.bAutoGenBarcode = false;
            bCheckFail = true;
        }       
    }
    
    if (g_AutoGenData.bAutoGenIMEI == true)
    {       
        if(!CmpSetupString(g_AutoGenData.sIMEI.Start, g_AutoGenData.sIMEI.End, g_AutoGenData.sIMEI.Next, 15, "Imei"))
        {
            g_AutoGenData.bAutoGenIMEI = false;
            bCheckFail = true;
        }
    }

    if (g_AutoGenData.bAutoGenBT == true)
    {       
        if(!CmpSetupString(g_AutoGenData.sBtAddress.Start, g_AutoGenData.sBtAddress.End, g_AutoGenData.sBtAddress.Next, 12, "BT"))
        {
            g_AutoGenData.bAutoGenBT = false;
            bCheckFail = true;
        }
    }

    if (g_AutoGenData.bAutoGenWifi == true)
    {       
        if(!CmpSetupString(g_AutoGenData.sWifiAddress.Start, g_AutoGenData.sWifiAddress.End, g_AutoGenData.sWifiAddress.Next, 12, "Wifi"))
        {
            g_AutoGenData.bAutoGenWifi = false;
            bCheckFail = true;
        }
    }

    if (g_AutoGenData.bAutoGenEthernet == true)
    {       
        if(!CmpSetupString(g_AutoGenData.sEthernetAddress.Start, g_AutoGenData.sEthernetAddress.End, g_AutoGenData.sEthernetAddress.Next, 12, "Ethernet"))
        {
            g_AutoGenData.bAutoGenEthernet = false;
            bCheckFail = true;
        }
    }

    if (g_AutoGenData.bAutoGenDRMKeyMCID == true)
    {       
        if(!CmpSetupString(g_AutoGenData.sDRMKeyMCID.Start, g_AutoGenData.sDRMKeyMCID.End, g_AutoGenData.sDRMKeyMCID.Next, 32, "DRMkeyMCID"))
        {
            g_AutoGenData.bAutoGenDRMKeyMCID = false;
            bCheckFail = true;
        }
    }

    if (bCheckFail == true)
    {
        m_bEnableAutoGen = false;
        return Check_Fail;
    }
    else
    {
        if (g_AutoGenData.bAutoGenBarcode == true
            || g_AutoGenData.bAutoGenIMEI == true
            || g_AutoGenData.bAutoGenBT == true
            || g_AutoGenData.bAutoGenWifi == true
            || g_AutoGenData.bAutoGenEthernet == true
            || g_AutoGenData.bAutoGenDRMKeyMCID == true)
        {
            m_bEnableAutoGen = true;
        }
        else
        {
            m_bEnableAutoGen = false;
        }
        return Check_Pass;
    }
    
}

void CAutoGenDlg::UpdateUIComponent()
{
    m_bAutoGenBarc = g_AutoGenData.bAutoGenBarcode;
    m_bAutoGenIMEI = g_AutoGenData.bAutoGenIMEI;
    m_bAutoGenBT = g_AutoGenData.bAutoGenBT;   
    m_bAutoGenWifi = g_AutoGenData.bAutoGenWifi;
    m_bAutoGenEthernet = g_AutoGenData.bAutoGenEthernet;
    m_bAutoGenDRMKeyMCID = g_AutoGenData.bAutoGenDRMKeyMCID;

    m_cBarcStep.SetCurSel(g_AutoGenData.sBarcode.iStep - 1);
    m_cIMEIStep.SetCurSel(g_AutoGenData.sIMEI.iStep - 1);
    m_cBTStep.SetCurSel(g_AutoGenData.sBtAddress.iStep - 1);
    m_cWifiStep.SetCurSel(g_AutoGenData.sWifiAddress.iStep - 1);
    m_cEthernetStep.SetCurSel(g_AutoGenData.sEthernetAddress.iStep - 1);
    m_cDRMKeyMCIDStep.SetCurSel(g_AutoGenData.sDRMKeyMCID.iStep - 1);

    m_strBarcStart = g_AutoGenData.sBarcode.Start;
    m_strBarcEnd = g_AutoGenData.sBarcode.End;
    m_strBarcNext = g_AutoGenData.sBarcode.Next;

    m_strIMEIStart = g_AutoGenData.sIMEI.Start;
    m_strIMEIEnd = g_AutoGenData.sIMEI.End;
    m_strIMEINext = g_AutoGenData.sIMEI.Next;

    m_strBTStart = g_AutoGenData.sBtAddress.Start;
    m_strBTEnd = g_AutoGenData.sBtAddress.End;
    m_strBTNext = g_AutoGenData.sBtAddress.Next;

    m_strWifiStart = g_AutoGenData.sWifiAddress.Start;
    m_strWifiEnd = g_AutoGenData.sWifiAddress.End;
    m_strWifiNext = g_AutoGenData.sWifiAddress.Next;

    m_strEthernetStart = g_AutoGenData.sEthernetAddress.Start;
    m_strEthernetEnd = g_AutoGenData.sEthernetAddress.End;
    m_strEthernetNext = g_AutoGenData.sEthernetAddress.Next;

    m_strDRMKeyMCIDStart = g_AutoGenData.sDRMKeyMCID.Start;
    m_strDRMKeyMCIDEnd = g_AutoGenData.sDRMKeyMCID.End;
    m_strDRMKeyMCIDNext = g_AutoGenData.sDRMKeyMCID.Next;

    if (g_AutoGenData.eIncreaseRadix == DENARY_RADIX)
    {
        ((CButton *)GetDlgItem(IDC_DENARY_INCREASE))->SetCheck(TRUE);
    } 
    else
    {
        ((CButton *)GetDlgItem(IDC_HEX_INCREASE))->SetCheck(TRUE);
    }

    UpdateData(FALSE);
    OnAutogenBarcCheck();
    OnAutogenImeiCheck();
    OnAutogenBtCheck();
    OnAutogenWifiCheck();
    OnAutogenEthernetCheck();
    OnAutogenDrmkeyMcidCheck();
}

void CAutoGenDlg::CollectUIComponent()
{
    UpdateData(TRUE);
    g_AutoGenData.bAutoGenBarcode = (m_bAutoGenBarc == TRUE);
    g_AutoGenData.bAutoGenIMEI = (m_bAutoGenIMEI == TRUE);
    g_AutoGenData.bAutoGenBT = (m_bAutoGenBT == TRUE);
    g_AutoGenData.bAutoGenWifi = (m_bAutoGenWifi == TRUE);
    g_AutoGenData.bAutoGenEthernet = (m_bAutoGenEthernet == TRUE);
    g_AutoGenData.bAutoGenDRMKeyMCID = (m_bAutoGenDRMKeyMCID == TRUE);
    
    strncpy(g_AutoGenData.sBarcode.Start, (LPCTSTR)m_strBarcStart,strlen(m_strBarcStart)+1);
    strncpy(g_AutoGenData.sBarcode.End, (LPCTSTR)m_strBarcEnd,strlen(m_strBarcEnd)+1);
    strncpy(g_AutoGenData.sBarcode.Next, (LPCTSTR)m_strBarcNext,strlen(m_strBarcNext)+1);
    
    strncpy(g_AutoGenData.sIMEI.Start, (LPCTSTR)m_strIMEIStart,strlen(m_strIMEIStart)+1);
    strncpy(g_AutoGenData.sIMEI.End, (LPCTSTR)m_strIMEIEnd,strlen(m_strIMEIEnd)+1);
    strncpy(g_AutoGenData.sIMEI.Next, (LPCTSTR)m_strIMEINext,strlen(m_strIMEINext)+1);
    
    strncpy(g_AutoGenData.sBtAddress.Start, (LPCTSTR)m_strBTStart,strlen(m_strBTStart)+1);
    strncpy(g_AutoGenData.sBtAddress.End, (LPCTSTR)m_strBTEnd,strlen(m_strBTEnd)+1);
    strncpy(g_AutoGenData.sBtAddress.Next, (LPCTSTR)m_strBTNext,strlen(m_strBTNext)+1);
    
    strncpy(g_AutoGenData.sWifiAddress.Start, (LPCTSTR)m_strWifiStart,strlen(m_strWifiStart)+1);
    strncpy(g_AutoGenData.sWifiAddress.End, (LPCTSTR)m_strWifiEnd,strlen(m_strWifiEnd)+1);
    strncpy(g_AutoGenData.sWifiAddress.Next, (LPCTSTR)m_strWifiNext,strlen(m_strWifiNext)+1);

    strncpy(g_AutoGenData.sEthernetAddress.Start, (LPCTSTR)m_strEthernetStart,strlen(m_strEthernetStart)+1);
    strncpy(g_AutoGenData.sEthernetAddress.End, (LPCTSTR)m_strEthernetEnd,strlen(m_strEthernetEnd)+1);
    strncpy(g_AutoGenData.sEthernetAddress.Next, (LPCTSTR)m_strEthernetNext,strlen(m_strEthernetNext)+1);

    strncpy(g_AutoGenData.sDRMKeyMCID.Start, (LPCTSTR)m_strDRMKeyMCIDStart,strlen(m_strDRMKeyMCIDStart)+1);
    strncpy(g_AutoGenData.sDRMKeyMCID.End, (LPCTSTR)m_strDRMKeyMCIDEnd,strlen(m_strDRMKeyMCIDEnd)+1);
    strncpy(g_AutoGenData.sDRMKeyMCID.Next, (LPCTSTR)m_strDRMKeyMCIDNext,strlen(m_strDRMKeyMCIDNext)+1);
}



void CAutoGenDlg::OnEditchangeBarcAutogenStep() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    CString strData;   
    m_cBarcStep.GetWindowText(strData); 
    g_AutoGenData.sBarcode.iStep = atoi(strData);
    if (g_AutoGenData.sBarcode.iStep > MAX_STEP || g_AutoGenData.sBarcode.iStep <= 0 )
    {
        char strMsg[256] = {0};
        sprintf(strMsg, "\"iStep = %d\" should be less than %d ", g_AutoGenData.sBarcode.iStep, MAX_STEP);
        g_AutoGenData.sBarcode.iStep = 1;
        MessageBox(strMsg, "Warning");
    }   
}

void CAutoGenDlg::OnSelchangeBarcAutogenStep() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_AutoGenData.sBarcode.iStep = m_cBarcStep.GetCurSel() + 1;
}

void CAutoGenDlg::OnEditchangeImeiAutogenStep() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    CString strData;   
    m_cIMEIStep.GetWindowText(strData); 
    g_AutoGenData.sIMEI.iStep = atoi(strData);
    if (g_AutoGenData.sIMEI.iStep > MAX_STEP || g_AutoGenData.sIMEI.iStep <= 0 )
    {
        char strMsg[256] = {0};
        sprintf(strMsg, "\"iStep = %d\" should be less than %d ", g_AutoGenData.sIMEI.iStep, MAX_STEP);
        g_AutoGenData.sIMEI.iStep = 1;
        MessageBox(strMsg, "Warning");
    }   
}

void CAutoGenDlg::OnSelchangeImeiAutogenStep() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_AutoGenData.sIMEI.iStep = m_cIMEIStep.GetCurSel() + 1;
}

void CAutoGenDlg::OnEditchangeBtAutogenStep() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    CString strData;   
    m_cBTStep.GetWindowText(strData); 
    g_AutoGenData.sBtAddress.iStep = atoi(strData);
    if (g_AutoGenData.sBtAddress.iStep > MAX_STEP || g_AutoGenData.sBtAddress.iStep <= 0 )
    {
        char strMsg[256] = {0};
        sprintf(strMsg, "\"iStep = %d\" should be less than %d ", g_AutoGenData.sBtAddress.iStep, MAX_STEP);
        g_AutoGenData.sBtAddress.iStep = 1;
        MessageBox(strMsg, "Warning");
    }  
}

void CAutoGenDlg::OnSelchangeBtAutogenStep() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_AutoGenData.sBtAddress.iStep = m_cBTStep.GetCurSel() + 1;
}

void CAutoGenDlg::OnEditchangeWifiAutogenStep() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    CString strData;   
    m_cWifiStep.GetWindowText(strData); 
    g_AutoGenData.sWifiAddress.iStep = atoi(strData);
    if (g_AutoGenData.sWifiAddress.iStep > MAX_STEP || g_AutoGenData.sWifiAddress.iStep <= 0 )
    {
        char strMsg[256] = {0};
        sprintf(strMsg, "\"iStep = %d\" should be less than %d ", g_AutoGenData.sWifiAddress.iStep, MAX_STEP);
        g_AutoGenData.sWifiAddress.iStep = 1;
        MessageBox(strMsg, "Warning");
    }  
}

void CAutoGenDlg::OnSelchangeWifiAutogenStep() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_AutoGenData.sWifiAddress.iStep = m_cWifiStep.GetCurSel() + 1;
}

void CAutoGenDlg::OnEditchangeEthernetAutogenStep() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    CString strData;   
    m_cEthernetStep.GetWindowText(strData); 
    g_AutoGenData.sEthernetAddress.iStep = atoi(strData);
    if (g_AutoGenData.sEthernetAddress.iStep > MAX_STEP || g_AutoGenData.sEthernetAddress.iStep <= 0 )
    {
        char strMsg[256] = {0};
        sprintf(strMsg, "\"iStep = %d\" should be less than %d ", g_AutoGenData.sEthernetAddress.iStep, MAX_STEP);
        g_AutoGenData.sEthernetAddress.iStep = 1;
        MessageBox(strMsg, "Warning");
    }  
}

void CAutoGenDlg::OnSelchangeEthernetAutogenStep() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_AutoGenData.sEthernetAddress.iStep = m_cEthernetStep.GetCurSel() + 1;
}

void CAutoGenDlg::OnEditchangeDrmkeyMcidAutogenStep() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    CString strData;   
    m_cDRMKeyMCIDStep.GetWindowText(strData); 
    g_AutoGenData.sDRMKeyMCID.iStep = atoi(strData);
    if (g_AutoGenData.sDRMKeyMCID.iStep > MAX_STEP || g_AutoGenData.sDRMKeyMCID.iStep <= 0 )
    {
        char strMsg[256] = {0};
        sprintf(strMsg, "\"iStep = %d\" should be less than %d ", g_AutoGenData.sDRMKeyMCID.iStep, MAX_STEP);
        g_AutoGenData.sDRMKeyMCID.iStep = 1;
        MessageBox(strMsg, "Warning");
    } 
}

void CAutoGenDlg::OnSelchangeDrmkeyMcidAutogenStep() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_AutoGenData.sDRMKeyMCID.iStep = m_cDRMKeyMCIDStep.GetCurSel() + 1;
}


void CAutoGenDlg::OnAutogenBarcCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    ((CWnd*)GetDlgItem(IDC_BARC_AUTOGEN_STEP))->EnableWindow(m_bAutoGenBarc);
    ((CWnd*)GetDlgItem(IDC_BARC_START_STR))->EnableWindow(m_bAutoGenBarc);
    ((CWnd*)GetDlgItem(IDC_BARC_END_STR))->EnableWindow(m_bAutoGenBarc);
    ((CWnd*)GetDlgItem(IDC_BARC_NEXT_STR))->EnableWindow(m_bAutoGenBarc);
    ((CWnd*)GetDlgItem(IDC_DENARY_INCREASE))->EnableWindow(m_bAutoGenBarc);
    ((CWnd*)GetDlgItem(IDC_HEX_INCREASE))->EnableWindow(m_bAutoGenBarc);
}

void CAutoGenDlg::OnAutogenImeiCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    ((CWnd*)GetDlgItem(IDC_IMEI_AUTOGEN_STEP))->EnableWindow(m_bAutoGenIMEI);
    ((CWnd*)GetDlgItem(IDC_IMEI_START_STR))->EnableWindow(m_bAutoGenIMEI);
    ((CWnd*)GetDlgItem(IDC_IMEI_END_STR))->EnableWindow(m_bAutoGenIMEI);
    ((CWnd*)GetDlgItem(IDC_IMEI_NEXT_STR))->EnableWindow(m_bAutoGenIMEI);
}

void CAutoGenDlg::OnAutogenBtCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    ((CWnd*)GetDlgItem(IDC_BT_AUTOGEN_STEP))->EnableWindow(m_bAutoGenBT);
    ((CWnd*)GetDlgItem(IDC_BT_START_STR))->EnableWindow(m_bAutoGenBT);
    ((CWnd*)GetDlgItem(IDC_BT_END_STR))->EnableWindow(m_bAutoGenBT);
    ((CWnd*)GetDlgItem(IDC_BT_NEXT_STR))->EnableWindow(m_bAutoGenBT);
}

void CAutoGenDlg::OnAutogenWifiCheck() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
    ((CWnd*)GetDlgItem(IDC_WIFI_AUTOGEN_STEP))->EnableWindow(m_bAutoGenWifi);
    ((CWnd*)GetDlgItem(IDC_WIFI_START_STR))->EnableWindow(m_bAutoGenWifi);
    ((CWnd*)GetDlgItem(IDC_WIFI_END_STR))->EnableWindow(m_bAutoGenWifi);
    ((CWnd*)GetDlgItem(IDC_WIFI_NEXT_STR))->EnableWindow(m_bAutoGenWifi);
}

void CAutoGenDlg::OnAutogenEthernetCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    ((CWnd*)GetDlgItem(IDC_ETHERNET_AUTOGEN_STEP))->EnableWindow(m_bAutoGenEthernet);
    ((CWnd*)GetDlgItem(IDC_ETHERNET_START_STR))->EnableWindow(m_bAutoGenEthernet);
    ((CWnd*)GetDlgItem(IDC_ETHERNET_END_STR))->EnableWindow(m_bAutoGenEthernet);
    ((CWnd*)GetDlgItem(IDC_ETHERNET_NEXT_STR))->EnableWindow(m_bAutoGenEthernet);
}

void CAutoGenDlg::OnAutogenDrmkeyMcidCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    ((CWnd*)GetDlgItem(IDC_DRMKEY_MCID_AUTOGEN_STEP))->EnableWindow(m_bAutoGenDRMKeyMCID);
    ((CWnd*)GetDlgItem(IDC_DRMKEY_MCID_START_STR))->EnableWindow(m_bAutoGenDRMKeyMCID);
    ((CWnd*)GetDlgItem(IDC_DRMKEY_MCID_END_STR))->EnableWindow(m_bAutoGenDRMKeyMCID);
    ((CWnd*)GetDlgItem(IDC_DRMKEY_MCID_NEXT_STR))->EnableWindow(m_bAutoGenDRMKeyMCID);
}


void CAutoGenDlg::OnBtnAutogenCancel() 
{
    // TODO: Add your control notification handler code here
    g_AutoGenData.bEnableAutoGen = false;
    CDialog::OnCancel();
}

void CAutoGenDlg::OnBtnAutogenOk() 
{
    // TODO: Add your control notification handler code here   
    
    CollectUIComponent();
    if (CheckSetupValid())
    {
        g_AutoGenData.bEnableAutoGen = m_bEnableAutoGen;
        SaveAutoGenParaToSetupFile();
        CDialog::OnOK();
    }   
}


void CAutoGenDlg::OnDenaryIncrease() 
{
	// TODO: Add your control notification handler code here
	g_AutoGenData.eIncreaseRadix = DENARY_RADIX;
}

void CAutoGenDlg::OnHexIncrease() 
{
	// TODO: Add your control notification handler code here
	g_AutoGenData.eIncreaseRadix = HEX_RADIX;
}
