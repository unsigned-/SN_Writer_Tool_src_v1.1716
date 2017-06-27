// ScanData.cpp : implementation file
//

#include "stdafx.h"
#include "SN Writer.h"
#include "SN WriterDlg.h"
#include "ScanData.h"
#include "Common.h"
#include "AutoGen.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CScanData dialog

//Need to scan edit id
int   g_iNeedScanCtrlNum;
int   g_iScanEditID[MAX_SCANDATA_NUMS];

//Need to scan write option flag
bool  g_bNeedScanItem[MAX_SCANDATA_NUMS];
ScanControlID_struct g_sCtrlIDInfo[MAX_SCANDATA_NUMS];
ScanControlID_struct g_sAllCtrlIDInfo[MAX_SCANDATA_NUMS];
extern CSNWriterDlg *g_pMainDlg;

CScanData::CScanData(CWnd* pParent /*=NULL*/)
	: CDialog(CScanData::IDD, pParent)
{
	//{{AFX_DATA_INIT(CScanData)
	m_strBarcData = _T("");
	m_strIMEI1Data = _T("");
	m_strIMEI2Data = _T("");
	m_strIMEI3Data = _T("");
	m_strIMEI4Data = _T("");
	m_strWifiData = _T("");
	m_strBtData = _T("");
	m_strEthernetMacData = _T("");
	m_strDrmkeyMCIDData = _T("");
	m_strSerialNoData = _T("");
	//C2K modem
	m_strMeidData = _T("");
	m_strEsnData = _T("");
	//}}AFX_DATA_INIT

    m_bNeedBackupIMEI = false;
    memset(m_strSerinalNoByIMEI, 0, (sizeof(char) * IMEI_ARRAY_LEN));
}


void CScanData::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CScanData)
	DDX_Text(pDX, IDC_BARCODE_DATA, m_strBarcData);
	DDV_MaxChars(pDX, m_strBarcData, BARCODE_MAX_LENGTH);
	DDX_Text(pDX, IDC_IMEI_1_DATA, m_strIMEI1Data);
	DDV_MaxChars(pDX, m_strIMEI1Data, 15);
	DDX_Text(pDX, IDC_IMEI_2_DATA, m_strIMEI2Data);
	DDV_MaxChars(pDX, m_strIMEI2Data, 15);
	DDX_Text(pDX, IDC_IMEI_3_DATA, m_strIMEI3Data);
	DDV_MaxChars(pDX, m_strIMEI3Data, 15);
	DDX_Text(pDX, IDC_IMEI_4_DATA, m_strIMEI4Data);
	DDV_MaxChars(pDX, m_strIMEI4Data, 15);
	DDX_Text(pDX, IDC_WIFI_DATA, m_strWifiData);
	DDV_MaxChars(pDX, m_strWifiData, 12);
	DDX_Text(pDX, IDC_BT_DATA, m_strBtData);
	DDV_MaxChars(pDX, m_strBtData, 12);
	DDX_Text(pDX, IDC_ETHERNET_MAC_DATA, m_strEthernetMacData);
	DDV_MaxChars(pDX, m_strEthernetMacData, 12);
	DDX_Text(pDX, IDC_DRMKEY_MCID_DATA, m_strDrmkeyMCIDData);
	DDV_MaxChars(pDX, m_strDrmkeyMCIDData, 32);
	DDX_Text(pDX, IDC_SERIAL_NO_DATA, m_strSerialNoData);
	DDV_MaxChars(pDX, m_strSerialNoData, SERIAL_NO_LEN);
	// C2K modem
	DDX_Text(pDX, IDC_MEID_DATA, m_strMeidData);
	DDV_MaxChars(pDX, m_strMeidData, 14);
	DDX_Text(pDX, IDC_ESN_DATA, m_strEsnData);
	DDV_MaxChars(pDX, m_strEsnData, 8);
	//}}AFX_DATA_MAP

    DDX_Control(pDX, IDC_BTN_SCAN_CANCEL, m_ScanCancelBTN);
    DDX_Control(pDX, IDC_BTN_SCAN_OK, m_ScanOKBTN);
}


BEGIN_MESSAGE_MAP(CScanData, CDialog)
	//{{AFX_MSG_MAP(CScanData)
	ON_EN_KILLFOCUS(IDC_BT_DATA, OnKillfocusBtData)
	ON_EN_KILLFOCUS(IDC_BARCODE_DATA, OnKillfocusBarcodeData)
	ON_EN_KILLFOCUS(IDC_IMEI_1_DATA, OnKillfocusImei1Data)
	ON_EN_KILLFOCUS(IDC_IMEI_2_DATA, OnKillfocusImei2Data)
	ON_EN_KILLFOCUS(IDC_IMEI_3_DATA, OnKillfocusImei3Data)
	ON_EN_KILLFOCUS(IDC_IMEI_4_DATA, OnKillfocusImei4Data)
	ON_EN_KILLFOCUS(IDC_WIFI_DATA, OnKillfocusWifiData)
	ON_BN_CLICKED(IDC_BTN_SCAN_OK, OnBtnScanOk)
	ON_BN_CLICKED(IDC_BTN_SCAN_CANCEL, OnBtnScanCancel)
	ON_WM_SHOWWINDOW()
	ON_EN_KILLFOCUS(IDC_ETHERNET_MAC_DATA, OnKillfocusEthernetMacData)
	ON_EN_KILLFOCUS(IDC_DRMKEY_MCID_DATA, OnKillfocusDrmkeyMcidData)
	ON_EN_KILLFOCUS(IDC_SERIAL_NO_DATA, OnKillfocusSerialNoData)
	//C2K Modem
	ON_EN_KILLFOCUS(IDC_MEID_DATA, OnKillfocusMeidData)
	ON_EN_KILLFOCUS(IDC_ESN_DATA, OnKillfocusEsnData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CScanData message handlers

BOOL CScanData::OnInitDialog() 
{
    CDialog::OnInitDialog();
    
    // TODO: Add extra initialization here
    
    m_ScanCancelBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_ScanOKBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    
    InitScanUI();
    
    GotoDlgCtrl(GetDlgItem(g_iScanEditID[0]));
    return FALSE;
    //return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}


BOOL CScanData::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
    
    int currentID;
    int nextID;
    bool bCheckPass = false;
    
    UpdateData(TRUE);
    if ( pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN )
    {           
        currentID = GetFocus()->GetDlgCtrlID();
        nextID = GetNextScanID(currentID);
        
        if (currentID != IDC_BTN_SCAN_OK)
        {        
            switch (currentID)
            {
            case IDC_BARCODE_DATA:
                bCheckPass = CheckScanDataByIndex(Barcode_Index);
                break;
                
            case IDC_BT_DATA:
                bCheckPass = CheckScanDataByIndex(Bt_Index);
                break;
                
            case IDC_WIFI_DATA:
                bCheckPass = CheckScanDataByIndex(Wifi_Index);
                break;
                
            case IDC_IMEI_1_DATA:
                bCheckPass = CheckScanDataByIndex(Imei_1_Index);
                break;
                
            case IDC_IMEI_2_DATA:
                bCheckPass = CheckScanDataByIndex(Imei_2_Index);
                break;
                
            case IDC_IMEI_3_DATA:
                bCheckPass = CheckScanDataByIndex(Imei_3_Index);
                break;
                
            case IDC_IMEI_4_DATA:
                bCheckPass = CheckScanDataByIndex(Imei_4_Index);
                break;

            case IDC_SERIAL_NO_DATA:
                bCheckPass = CheckScanDataByIndex(SerialNo_Index);
                break;
                
            case IDC_ETHERNET_MAC_DATA:
                bCheckPass = CheckScanDataByIndex(Ethernet_Index);
                break;
                
            case IDC_DRMKEY_MCID_DATA:
                bCheckPass = CheckScanDataByIndex(DRMKey_MCID_Index);
                break;

			//C2K modem
			case IDC_MEID_DATA:
				bCheckPass = CheckScanDataByIndex(Meid_Index);
				break;

			case IDC_ESN_DATA:
				bCheckPass = CheckScanDataByIndex(Esn_Index);
				break;
            }
            
            if (bCheckPass)
            {
                if (nextID != IDC_BTN_SCAN_OK)
                {
                    GotoDlgCtrl(GetDlgItem(nextID));
                    return false;
                }               
                else
                {
                    if(!CheckAllScanData())
                    {
                        GotoDlgCtrl(GetDlgItem(g_iScanEditID[0]));
                        return false;
                    }
                }
            }
            else
            {
                GotoDlgCtrl(GetDlgItem(currentID));
                SetDlgItemText(currentID, "");
                
                return false;
            }
        }
    }
    
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam ==VK_ESCAPE)
    {
        return true;
    }
    
	return CDialog::PreTranslateMessage(pMsg);
}

void CScanData::OnKillfocusBtData() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);  
    m_pstrScanItem = "BT Addr";
    bool bCheckPass = false;
    
    strncpy(g_sMetaComm.sScanData.strBTAddr, (LPCTSTR)m_strBtData, strlen(m_strBtData)+1);
    bCheckPass = CheckScanData(g_sMetaComm.sBTHeader_Option.strHeader, g_sMetaComm.sBTHeader_Option.bCheckHeader, m_strBtData, BT);
    
    if (!bCheckPass)
    {
        SetDlgItemText(IDC_BT_DATA, "");
    }
}

void CScanData::OnKillfocusBarcodeData() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE); 
    m_pstrScanItem = "Barcode";
    bool bCheckPass = false;
    
    strncpy(g_sMetaComm.sScanData.strBarcode, (LPCTSTR)m_strBarcData, strlen(m_strBarcData)+1); 
    bCheckPass = CheckScanData(g_sMetaComm.sBarcHeader_Option.strHeader, g_sMetaComm.sBarcHeader_Option.bCheckHeader, m_strBarcData, Barcode);
    
    if (!bCheckPass)
    {
        SetDlgItemText(IDC_BARCODE_DATA, "");
    }
}

void CScanData::OnKillfocusImei1Data() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE); 
    m_pstrScanItem = "IMEI_1";
    bool bCheckPass = false;
    
    strncpy(g_sMetaComm.sScanData.strIMEI[0], (LPCTSTR)m_strIMEI1Data, strlen(m_strIMEI1Data)+1);
    bCheckPass = CheckScanData(g_sMetaComm.sIMEIHeader_Option[0].strHeader, g_sMetaComm.sIMEIHeader_Option[0].bCheckHeader, m_strIMEI1Data, Imei);
    
    if (!bCheckPass)
    {
        SetDlgItemText(IDC_IMEI_1_DATA, "");
    }
}

void CScanData::OnKillfocusImei2Data() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE); 
    m_pstrScanItem = "IMEI_2";
    bool bCheckPass = false;
    
    strncpy(g_sMetaComm.sScanData.strIMEI[1], (LPCTSTR)m_strIMEI2Data, strlen(m_strIMEI2Data)+1);
    bCheckPass = CheckScanData(g_sMetaComm.sIMEIHeader_Option[1].strHeader, g_sMetaComm.sIMEIHeader_Option[1].bCheckHeader, m_strIMEI2Data, Imei);
    
    if (!bCheckPass)
    {
        SetDlgItemText(IDC_IMEI_2_DATA, "");
    }
}

void CScanData::OnKillfocusImei3Data() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE); 
    m_pstrScanItem = "IMEI_3";
    bool bCheckPass = false;
    
    strncpy(g_sMetaComm.sScanData.strIMEI[2], (LPCTSTR)m_strIMEI3Data, strlen(m_strIMEI3Data)+1);
    bCheckPass = CheckScanData(g_sMetaComm.sIMEIHeader_Option[2].strHeader, g_sMetaComm.sIMEIHeader_Option[2].bCheckHeader, m_strIMEI3Data, Imei);
    
    if (!bCheckPass)
    {
        SetDlgItemText(IDC_IMEI_3_DATA, "");
    }
}

void CScanData::OnKillfocusImei4Data() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE); 
    m_pstrScanItem = "IMEI_4";
    bool bCheckPass = false;
    
    strncpy(g_sMetaComm.sScanData.strIMEI[3], (LPCTSTR)m_strIMEI4Data, strlen(m_strIMEI4Data)+1);
    bCheckPass = CheckScanData(g_sMetaComm.sIMEIHeader_Option[3].strHeader, g_sMetaComm.sIMEIHeader_Option[3].bCheckHeader, m_strIMEI4Data, Imei);
    
    if (!bCheckPass)
    {
        SetDlgItemText(IDC_IMEI_4_DATA, "");
    }
}

void CScanData::OnKillfocusWifiData() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE); 
    m_pstrScanItem = "Wifi Addr";
    bool bCheckPass = false;
    
    strncpy(g_sMetaComm.sScanData.strWifiAddr, (LPCTSTR)m_strWifiData, strlen(m_strWifiData)+1);  
    bCheckPass = CheckScanData(g_sMetaComm.sWifiHeader_Option.strHeader, g_sMetaComm.sWifiHeader_Option.bCheckHeader, m_strWifiData, Wifi);
    if (!bCheckPass)
    {
        SetDlgItemText(IDC_WIFI_DATA, "");
    }
}

void CScanData::OnKillfocusEthernetMacData() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE); 
    m_pstrScanItem = "Ethernet_Mac";
    bool bCheckPass = false;
    
    strncpy(g_sMetaComm.sScanData.strEthernetMac, (LPCTSTR)m_strEthernetMacData, strlen(m_strEthernetMacData)+1);  
    bCheckPass = CheckScanData(g_sMetaComm.sEthernetMacHeader_Option.strHeader, g_sMetaComm.sEthernetMacHeader_Option.bCheckHeader, m_strEthernetMacData, Ethernet_mac);
    if (!bCheckPass)
    {
        SetDlgItemText(IDC_ETHERNET_MAC_DATA, "");
    }
}

void CScanData::OnKillfocusDrmkeyMcidData() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE); 
    m_pstrScanItem = "DRMKey_MCID";
    bool bCheckPass = false;
    
    strncpy(g_sMetaComm.sScanData.strDrmkeyMCID, (LPCTSTR)m_strDrmkeyMCIDData, strlen(m_strDrmkeyMCIDData)+1);  
    bCheckPass = CheckScanData(g_sMetaComm.sDrmkeyMCIDHeader_Option.strHeader, g_sMetaComm.sDrmkeyMCIDHeader_Option.bCheckHeader, m_strDrmkeyMCIDData, DRMKey_MCID);
    if (!bCheckPass)
    {
        SetDlgItemText(IDC_DRMKEY_MCID_DATA, "");
    }
}

void CScanData::OnKillfocusSerialNoData() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE); 
    m_pstrScanItem = "Serial No.";
    bool bCheckPass = false;
    
    strncpy(g_sMetaComm.sScanData.strSerialNo, (LPCTSTR)m_strSerialNoData, strlen(m_strSerialNoData)+1);  
    bCheckPass = CheckScanData(g_sMetaComm.sSerialNoHeader_Option.strHeader, g_sMetaComm.sSerialNoHeader_Option.bCheckHeader, m_strSerialNoData, SerialNo);
    if (!bCheckPass)
    {
        SetDlgItemText(IDC_SERIAL_NO_DATA, "");
    }
}

void CScanData::OnKillfocusMeidData()
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    m_pstrScanItem = "Meid";
    bool bCheckPass = false;

    strncpy(g_sMetaComm.sScanData.strMeid, (LPCTSTR)m_strMeidData, strlen(m_strMeidData) + 1);
    bCheckPass = CheckScanData(g_sMetaComm.sMeidHeader_Option.strHeader, g_sMetaComm.sMeidHeader_Option.bCheckHeader, m_strMeidData, Meid);
    if (!bCheckPass)
    {
        SetDlgItemText(IDC_MEID_DATA, "");
    }
}

void CScanData::OnKillfocusEsnData()
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    m_pstrScanItem = "Esn";
    bool bCheckPass = false;

    strncpy(g_sMetaComm.sScanData.strEsn, (LPCTSTR)m_strEsnData, strlen(m_strEsnData) + 1);
    bCheckPass = CheckScanData(g_sMetaComm.sEsnHeader_Option.strHeader, g_sMetaComm.sEsnHeader_Option.bCheckHeader, m_strEsnData, Esn);
    if (!bCheckPass)
    {
        SetDlgItemText(IDC_ESN_DATA, "");
    }
}

void CScanData::OnBtnScanOk()
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    if (CheckAllScanData())
    {
        CDialog::OnOK();
    }
    else
    {
        GotoDlgCtrl(GetDlgItem(g_iScanEditID[0]));
    }
}

void CScanData::OnBtnScanCancel() 
{
    // TODO: Add your control notification handler code here
#ifdef _AUTO_GEN_FEATURE_
    if (m_bNeedBackupIMEI)
    {
        strncpy(g_AutoGenData.sIMEI.Next, m_strBackupIMEI, strlen(m_strBackupIMEI) + 1);
    }
#endif

    CDialog::OnCancel();
}

void CScanData::SetNextFocus(int iCurrentID, bool bCheckPass)
{
    int  nextID;
    nextID = GetNextScanID(iCurrentID);

    if (bCheckPass)
    {
        if (nextID != IDC_BTN_SCAN_OK)
        {
            //GotoDlgCtrl(GetDlgItem(nextID));
        }
    }
    else
    {
        //GotoDlgCtrl(GetDlgItem(iCurrentID));
        SetDlgItemText(iCurrentID, "");
    }
}

bool CScanData::CheckAllScanData()
{
    bool bCheckAllDataPass = true;
    bool bCheckPass = false;

    int  j = 0;  // new scan edit control id index
    int  k = 0;  // old scan edit control id index
    for (int i = Barcode_Index; i < MAX_SCANDATA_NUMS - 1; i++) // MAX_SCANDATA_NUMS - 1 for remove BTN_OK
    {
        if (g_bNeedScanItem[i])
        {
            bCheckPass = CheckScanDataByIndex(i);
            if (!bCheckPass)
            {
                bCheckAllDataPass = false;
                g_iScanEditID[j] = g_iScanEditID[k]; //Update need scan edit control id
                j += 1;
                break;
            }
            k += 1;
        }
    }

    if (g_sMetaComm.sWriteOption.bWriteSerialNo)
    {
        if (g_sMetaComm.SerialNumFromIMEI == true)
        {
            GenSerialNoFirstStep(g_sMetaComm.sScanData.strIMEI[0]);
            GenSerialNoSecondStep();

            if (CheckSerialNoMatchWithIMEI(m_strSerialNoData) == false)
            {
                bCheckAllDataPass = false;
                char pScanMsg[256] = {0};
                sprintf(pScanMsg, "Serial No.[%s] not match with IMEI[%s] ->[%s]!", m_strSerialNoData, m_strIMEI1Data, m_strSerinalNoByIMEI);
                SetDlgItemText(IDC_SCAN_MSG, pScanMsg);

                g_iScanEditID[j] = IDC_SERIAL_NO_DATA;
                j += 1;
            }
        }
    }

    g_iScanEditID[j] = IDC_BTN_SCAN_OK;

    return bCheckAllDataPass;
}

bool CScanData::CheckScanDataByIndex(int index)
{
    bool bCheckPass = false;
    switch (index)
    {
    case Barcode_Index:
        m_pstrScanItem = "Barcode";
        strncpy(g_sMetaComm.sScanData.strBarcode, (LPCTSTR)m_strBarcData, strlen(m_strBarcData) + 1);
        bCheckPass = CheckScanData(g_sMetaComm.sBarcHeader_Option.strHeader, g_sMetaComm.sBarcHeader_Option.bCheckHeader, m_strBarcData, Barcode);
        break;

    case Bt_Index:
        m_pstrScanItem = "BT Addr";
        m_strBtData.MakeUpper();
        strncpy(g_sMetaComm.sScanData.strBTAddr, (LPCTSTR)m_strBtData, strlen(m_strBtData) + 1);
        bCheckPass = CheckScanData(g_sMetaComm.sBTHeader_Option.strHeader, g_sMetaComm.sBTHeader_Option.bCheckHeader, m_strBtData, BT);
        break;

    case Wifi_Index:
        m_pstrScanItem = "Wifi Addr";
        m_strWifiData.MakeUpper();
        strncpy(g_sMetaComm.sScanData.strWifiAddr, (LPCTSTR)m_strWifiData, strlen(m_strWifiData) + 1);
        bCheckPass = CheckScanData(g_sMetaComm.sWifiHeader_Option.strHeader, g_sMetaComm.sWifiHeader_Option.bCheckHeader, m_strWifiData, Wifi);
        break;

    case Imei_1_Index:
        m_pstrScanItem = "IMEI_1";
        strncpy(g_sMetaComm.sScanData.strIMEI[0], (LPCTSTR)m_strIMEI1Data, strlen(m_strIMEI1Data) + 1);
        bCheckPass = CheckScanData(g_sMetaComm.sIMEIHeader_Option[0].strHeader, g_sMetaComm.sIMEIHeader_Option[0].bCheckHeader, m_strIMEI1Data, Imei);
        break;

    case Imei_2_Index:
        m_pstrScanItem = "IMEI_2";
        strncpy(g_sMetaComm.sScanData.strIMEI[1], (LPCTSTR)m_strIMEI2Data, strlen(m_strIMEI2Data) + 1);
        bCheckPass = CheckScanData(g_sMetaComm.sIMEIHeader_Option[1].strHeader, g_sMetaComm.sIMEIHeader_Option[1].bCheckHeader, m_strIMEI2Data, Imei);
        break;

    case Imei_3_Index:
        m_pstrScanItem = "IMEI_3";
        strncpy(g_sMetaComm.sScanData.strIMEI[2], (LPCTSTR)m_strIMEI3Data, strlen(m_strIMEI3Data) + 1);
        bCheckPass = CheckScanData(g_sMetaComm.sIMEIHeader_Option[2].strHeader, g_sMetaComm.sIMEIHeader_Option[2].bCheckHeader, m_strIMEI3Data, Imei);
        break;

    case Imei_4_Index:
        m_pstrScanItem = "IMEI_4";
        strncpy(g_sMetaComm.sScanData.strIMEI[3], (LPCTSTR)m_strIMEI4Data, strlen(m_strIMEI4Data) + 1);
        bCheckPass = CheckScanData(g_sMetaComm.sIMEIHeader_Option[3].strHeader, g_sMetaComm.sIMEIHeader_Option[3].bCheckHeader, m_strIMEI4Data, Imei);
        break;

    case SerialNo_Index:
        m_pstrScanItem = "Serial No.";
        strncpy(g_sMetaComm.sScanData.strSerialNo, (LPCTSTR)m_strSerialNoData, strlen(m_strSerialNoData) + 1);
        bCheckPass = CheckScanData(g_sMetaComm.sSerialNoHeader_Option.strHeader, g_sMetaComm.sSerialNoHeader_Option.bCheckHeader, m_strSerialNoData, SerialNo);
        break;

    case Ethernet_Index:
        m_pstrScanItem = "Ethernet_Mac";
        m_strEthernetMacData.MakeUpper();
        strncpy(g_sMetaComm.sScanData.strEthernetMac, (LPCTSTR)m_strEthernetMacData, strlen(m_strEthernetMacData) + 1);
        bCheckPass = CheckScanData(g_sMetaComm.sEthernetMacHeader_Option.strHeader, g_sMetaComm.sEthernetMacHeader_Option.bCheckHeader, m_strEthernetMacData, Ethernet_mac);
        break;

    case DRMKey_MCID_Index:
        m_pstrScanItem = "DRMKey_MCID";
        strncpy(g_sMetaComm.sScanData.strDrmkeyMCID, (LPCTSTR)m_strDrmkeyMCIDData, strlen(m_strDrmkeyMCIDData) + 1);
        bCheckPass = CheckScanData(g_sMetaComm.sDrmkeyMCIDHeader_Option.strHeader, g_sMetaComm.sDrmkeyMCIDHeader_Option.bCheckHeader, m_strDrmkeyMCIDData, DRMKey_MCID);
        break;

    case Meid_Index:
        m_pstrScanItem = "Meid";
        strncpy(g_sMetaComm.sScanData.strMeid, (LPCTSTR)m_strMeidData, strlen(m_strMeidData) + 1);
        bCheckPass = CheckScanData(g_sMetaComm.sMeidHeader_Option.strHeader, g_sMetaComm.sMeidHeader_Option.bCheckHeader, m_strMeidData, Meid);
        break;

    case Esn_Index:
        m_pstrScanItem = "Esn";
        strncpy(g_sMetaComm.sScanData.strEsn, (LPCTSTR)m_strEsnData, strlen(m_strEsnData) + 1);
        bCheckPass = CheckScanData(g_sMetaComm.sEsnHeader_Option.strHeader, g_sMetaComm.sEsnHeader_Option.bCheckHeader, m_strEsnData, Esn);
        break;
    }

    return bCheckPass;
}

bool CScanData::CheckSerialNoMatchWithIMEI(const char* pSerialNoData)
{
    if (!pSerialNoData || strlen(pSerialNoData) != 15)
    {
        return false;
    }
    else
    {
        if (strnicmp(m_strSerinalNoByIMEI, pSerialNoData, 15) != 0)
        {
            return false; //No match imei
        }
        else
        {
            return true; //Match imei
        }
    }
   
}

void CScanData::GenSerialNoFirstStep(const char* pFirstIMEI)
{
    if (!pFirstIMEI || strlen(pFirstIMEI) != 15)
    {
        return;
    }

    memset(m_strSerinalNoByIMEI, 0, (sizeof(char) * IMEI_ARRAY_LEN));
    int i = 0;
    int n = 0;
    int iBaseNum = 15;
    for(i = 0; i < IMEI_MAX_LENGTH; i++)
    {
        n = 14 - ((i + 13) % iBaseNum);
        m_strSerinalNoByIMEI[iBaseNum - i - 1] = pFirstIMEI[n];
    }
}

void CScanData::GenSerialNoSecondStep()
{
    int n = 0;
    for(int i = 0; i < IMEI_MAX_LENGTH; i++)
    {
        n = (m_strSerinalNoByIMEI[i] - '0') * 2;
        if ( 0 <= n && n <= 9)
        {
            m_strSerinalNoByIMEI[i] = '0' + n;
        }
        else if(n >= 10)
        {
            m_strSerinalNoByIMEI[i] = 'A' + (n - 10);
        }
    }
}

bool CScanData::CheckScanData(const char *pStrHeader, bool bCheckHeader, const char *pInData, E_ScanData_Type dataType)
{
    char temp[4] = {0};
    long int value = 0;
    if (!pInData)
    {
        return false;
    }

    int dataLength = strlen(pInData);
    char pScanMsg[1024] = {0};

    switch (dataType)
    {
    case Barcode:
        if (dataLength > BARCODE_MAX_LENGTH || dataLength <= 0 )
        {
            sprintf(pScanMsg, "Barcode = \"%s\" length must be [1,%d]", pInData, BARCODE_MAX_LENGTH);
            SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
            return false;
        }
        else
        {
            if (g_AutoGenData.bEnableAutoGen && g_AutoGenData.bAutoGenBarcode)
            {
                if ((strnicmp(pInData, g_AutoGenData.sBarcode.End, dataLength) > 0))
                {
                    sprintf(pScanMsg, "Barcode = \"%s\" length must be less then End_Barcode[%s]!", pInData, g_AutoGenData.sBarcode.End);
                    SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                    return false;
                }
            }
        }
        break;

    case Imei:
        if (dataLength != 15)
        {
            if (g_sMetaComm.sIMEIOption.bCheckSum && (14 == dataLength))
            {
                if (g_AutoGenData.bEnableAutoGen && g_AutoGenData.bAutoGenIMEI )
                {
                    if ((strnicmp(pInData, g_AutoGenData.sIMEI.End, dataLength) > 0))
                    {
                        sprintf ( pScanMsg, "Error: IMEI[%s] should be less than End_IMEI[%s]", pInData, g_AutoGenData.sIMEI.End);
                        SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                        return false;
                    }
                }
                for (int i = 0; i < dataLength; i++)
                {
                    if ( pInData[i] > '9' || pInData[i] < '0')
                    {
                        sprintf(pScanMsg, "%s = \"%s\" isn`t all digit!!", m_pstrScanItem, pInData);
                        SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                        return false;
                    }
                }
            }
            else
            {
                sprintf(pScanMsg, "%s = \"%s\",Only when enable checksum, imei length can be 14 or 15 only!", m_pstrScanItem, pInData);
                SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                return false;
            }
        }
        else
        {
            if (g_AutoGenData.bEnableAutoGen && g_AutoGenData.bAutoGenIMEI )
            {
                if ((strnicmp(pInData, g_AutoGenData.sIMEI.End, dataLength) > 0))
                {
                    sprintf ( pScanMsg, "Error: IMEI[%s] should be less than End_IMEI[%s]", pInData, g_AutoGenData.sIMEI.End);
                    SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                    return false;
                }
            }

            for (int i = 0; i < dataLength; i++)
            {
                if ( pInData[i] > '9' || pInData[i] < '0')
                {
                    sprintf(pScanMsg, "%s = \"%s\" isn`t all digit!!", m_pstrScanItem, pInData);
                    SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                    return false;
                }
            }
        }
        break;

    case SerialNo:
        if (g_sMetaComm.SerialNumFromIMEI == true)
        {
            if (dataLength != 15)
            {
                sprintf(pScanMsg, "%s = \"%s\" length must be 15!", m_pstrScanItem, pInData);
                SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                return false;
            }
        }
        else
        {
            if (dataLength <= 0 || dataLength > SERIAL_NO_LEN)
            {
                sprintf(pScanMsg, "%s = \"%s\" length must not be longer than %d!", m_pstrScanItem, pInData, SERIAL_NO_LEN);
                SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                return false;
            }
        }
        break;

    case BT:
    case Wifi:
        if (dataLength != 12)
        {
            sprintf(pScanMsg, "%s = \"%s\" length must be 12!", m_pstrScanItem, pInData);
            SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
            return false;
        }
        else
        {
            if (dataType == BT)
            {
                //0x9E8B00~0X9E8B3F will be illegal
                strupr((char *)pInData);
                if (g_AutoGenData.bEnableAutoGen && g_AutoGenData.bAutoGenBT)
                {
                    if ((strnicmp(pInData, g_AutoGenData.sBtAddress.End, dataLength) > 0))
                    {
                        sprintf ( pScanMsg, "Error: BT[%s] should be less than End_BT[%s]", pInData, g_AutoGenData.sBtAddress.End);
                        SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                        return false;
                    }
                }

                if (g_sMetaComm.bCheckBTWifi)
                {
                    if (!memcmp((void *)pInData, "9E8B", 4))
                    {
                        memset(temp, 0, 4);
                        memcpy(temp, pInData + 4, 2);
                        value = strtol(temp, NULL, 16);
                        if (0 <= value && value <= 63)
                        {
                            sprintf(pScanMsg, "bt = \"%s\" illegal, use 'Identify->Engineer->Enable Check BtWifi' bypass this warning!!", pInData);
                            SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                            return false;
                        }
                    }
                }
            }

            if (dataType == Wifi)
            {
                if (g_AutoGenData.bEnableAutoGen && g_AutoGenData.bAutoGenWifi)
                {
                    if ((strnicmp(pInData, g_AutoGenData.sWifiAddress.End, dataLength) > 0))
                    {
                        sprintf ( pScanMsg, "Error: Wifi[%s] should be less than End_Wifi[%s]", pInData, g_AutoGenData.sWifiAddress.End);
                        SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                        return false;
                    }
                }

                if (g_sMetaComm.bCheckBTWifi)
                {
                    int iValue = 0;
                    if ('0' <= pInData[1] && pInData[1] <= '9')
                    {
                        iValue = pInData[1] - '0';
                    }
                    else if (pInData[1] <= 'F' && pInData[1] >= 'A' )
                    {
                        iValue = pInData[1] - 'A';
                    }
                    else if (pInData[1] <= 'f' && pInData[1] >= 'a' )
                    {
                        iValue = pInData[1] - 'a';
                    }

                    if (!(memcmp(pInData, "000000000000", 12)) || !(memcmp(pInData, "111111111111", 12)) || (iValue % 4 != 0))
                    {
                        sprintf(pScanMsg, "wifi = \"%s\" illegal, use 'Identify->Engineer->Enable Check BtWifi' bypass this warning!!", pInData);
                        SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                        return false;
                    }
                }
            }

            for (int i = 0; i < dataLength; i++)
            {
                if ( !((pInData[i] <= '9' && pInData[i] >= '0')
                        || (pInData[i] <= 'F' && pInData[i] >= 'A')
                        || (pInData[i] <= 'f' && pInData[i] >= 'a')))
                {
                    sprintf(pScanMsg, "%s = \"%s\" have some invalid characters!!", m_pstrScanItem, pInData);
                    SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                    return false;
                }
            }
        }
        break;

    case Ethernet_mac:
        if (dataLength != 12)
        {
            sprintf(pScanMsg, "%s = \"%s\" length must be 12!", m_pstrScanItem, pInData);
            SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
            return false;
        }
        else
        {
            if (g_AutoGenData.bAutoGenEthernet && (strnicmp(pInData, g_AutoGenData.sEthernetAddress.End, dataLength) > 0))
            {
                sprintf ( pScanMsg, "Error: Ethernet[%s] should be less than End_Ethernet[%s]", pInData, g_AutoGenData.sEthernetAddress.End);
                SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                return false;
            }
            for (int i = 0; i < dataLength; i++)
            {
                if ( !((pInData[i] <= '9' && pInData[i] >= '0')
                || (pInData[i] <= 'F' && pInData[i] >= 'A')
                || (pInData[i] <= 'f' && pInData[i] >= 'a')))
                {
                    sprintf(pScanMsg, "%s = \"%s\" have some invalid characters!!", m_pstrScanItem, pInData);
                    SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                    return false;
                }
            }
        }
        break;

    case DRMKey_MCID:
        if (dataLength != 32)
        {
            sprintf(pScanMsg, "%s = \"%s\" length must be 32!", m_pstrScanItem, pInData);
            SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
            return false;
        }
        else
        {
            if (g_AutoGenData.bAutoGenBarcode && (strnicmp(pInData, g_AutoGenData.sDRMKeyMCID.End, dataLength) > 0))
            {
                sprintf ( pScanMsg, "Error: MCID[%s] should be less than End_MCID[%s]", pInData, g_AutoGenData.sDRMKeyMCID.End);
                SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                return false;
            }
            for (int i = 0; i < dataLength; i++)
            {
                if ( !((pInData[i] <= '9' && pInData[i] >= '0')
                || (pInData[i] <= 'F' && pInData[i] >= 'A')
                || (pInData[i] <= 'f' && pInData[i] >= 'a')))
                {
                    sprintf(pScanMsg, "%s = \"%s\" have some invalid characters!!", m_pstrScanItem, pInData);
                    SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                    return false;
                }
            }
        }
        break;

    case Meid:
        if (dataLength != 14)
        {
            sprintf(pScanMsg, "%s = \"%s\" length must be 14!", m_pstrScanItem, pInData);
            SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
            return false;
        }
        else
        {
            for (int i = 0; i < dataLength; i++)
            {
                if ( !((pInData[i] <= '9' && pInData[i] >= '0')
                || (pInData[i] <= 'F' && pInData[i] >= 'A')
                || (pInData[i] <= 'f' && pInData[i] >= 'a')))
                {
                    sprintf(pScanMsg, "%s = \"%s\" have some invalid characters!!", m_pstrScanItem, pInData);
                    SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                    return false;
                }
            }
        }
        break;

    case Esn:
        if (dataLength != 8)
        {
            sprintf(pScanMsg, "%s = \"%s\" length must be 8!", m_pstrScanItem, pInData);
            SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
            return false;
        }
        else
        {
            for (int i = 0; i < dataLength; i++)
            {
                if ( !((pInData[i] <= '9' && pInData[i] >= '0')
                || (pInData[i] <= 'F' && pInData[i] >= 'A')
                || (pInData[i] <= 'f' && pInData[i] >= 'a')))
                {
                    sprintf(pScanMsg, "%s = \"%s\" have some invalid characters!!", m_pstrScanItem, pInData);
                    SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                    return false;
                }
            }
        }
        break;

    } // switch(dataType)

    if (bCheckHeader == true)
    {
        int headLength = 0;
        if (pStrHeader)
        {
            headLength = strlen(pStrHeader);
            if (strnicmp(pStrHeader, pInData, headLength) == 0)
            {
                SetDlgItemText(IDC_SCAN_MSG, "");
                return true;
            }
            else
            {
                sprintf(pScanMsg, "%s = \"%s\" previous %d bits not match \"%s\" header string!", m_pstrScanItem, pInData, headLength, pStrHeader);
                SetDlgItemText(IDC_SCAN_MSG, pScanMsg);
                return false;
            }
        }
        else
        {
            return false;
        }
    }

    SetDlgItemText(IDC_SCAN_MSG, "");
    return true;
}

int CScanData::GetNextScanID(const int currentID)
{
    int nextID;

    for (int i = 0; i < MAX_SCANDATA_NUMS; i++)
    {
        if (g_iScanEditID[i] == currentID)
        {
            nextID = g_iScanEditID[i + 1];
            break;
        }
    }

    return nextID;
}

void CScanData::CreateScanOrder()
{
    memset(g_iScanEditID, 0, (sizeof(int)*MAX_SCANDATA_NUMS));
    memset(g_bNeedScanItem, 0, (sizeof(bool)*MAX_SCANDATA_NUMS)) ;
    memset(g_sCtrlIDInfo, 0, (sizeof(ScanControlID_struct)*MAX_SCANDATA_NUMS));
    memset(g_sAllCtrlIDInfo, 0, (sizeof(ScanControlID_struct)*MAX_SCANDATA_NUMS));
    
    g_bNeedScanItem[Barcode_Index] = g_sMetaComm.sWriteOption.bWriteBarcode;
    g_bNeedScanItem[Bt_Index] = g_sMetaComm.sWriteOption.bWriteBT;
    g_bNeedScanItem[Wifi_Index] = g_sMetaComm.sWriteOption.bWriteWifi;
    g_bNeedScanItem[Imei_1_Index] = g_sMetaComm.sWriteOption.bWriteIMEI;
    g_bNeedScanItem[Imei_2_Index] = (g_sMetaComm.sWriteOption.bWriteIMEI 
        && ((g_sMetaComm.sIMEIOption.bDualIMEI && !g_sMetaComm.sIMEIOption.bDualIMEISame)
        || g_sMetaComm.sIMEIOption.bThreeIMEI
        || g_sMetaComm.sIMEIOption.bFourIMEI));
    g_bNeedScanItem[Imei_3_Index] = (g_sMetaComm.sWriteOption.bWriteIMEI && (g_sMetaComm.sIMEIOption.bThreeIMEI || g_sMetaComm.sIMEIOption.bFourIMEI));
    g_bNeedScanItem[Imei_4_Index] = (g_sMetaComm.sWriteOption.bWriteIMEI && g_sMetaComm.sIMEIOption.bFourIMEI);
    g_bNeedScanItem[SerialNo_Index] = g_sMetaComm.sWriteOption.bWriteSerialNo;
    g_bNeedScanItem[Ethernet_Index] = g_sMetaComm.sWriteOption.bWriteEthernetMac;
    g_bNeedScanItem[DRMKey_MCID_Index] = g_sMetaComm.sWriteOption.bWriteDrmkeyMCID;

	//C2K
	g_bNeedScanItem[Meid_Index] = g_sMetaComm.sWriteOption.bWriteMeid;
	g_bNeedScanItem[Esn_Index] = g_sMetaComm.sWriteOption.bWriteEsn;
    g_bNeedScanItem[OK_Index] = true;


    g_sAllCtrlIDInfo[Barcode_Index].editID = IDC_BARCODE_DATA;
    g_sAllCtrlIDInfo[Bt_Index].editID = IDC_BT_DATA;
    g_sAllCtrlIDInfo[Wifi_Index].editID = IDC_WIFI_DATA;
    g_sAllCtrlIDInfo[Imei_1_Index].editID = IDC_IMEI_1_DATA;
    g_sAllCtrlIDInfo[Imei_2_Index].editID = IDC_IMEI_2_DATA;
    g_sAllCtrlIDInfo[Imei_3_Index].editID = IDC_IMEI_3_DATA;
    g_sAllCtrlIDInfo[Imei_4_Index].editID = IDC_IMEI_4_DATA;
    g_sAllCtrlIDInfo[SerialNo_Index].editID = IDC_SERIAL_NO_DATA;
    g_sAllCtrlIDInfo[Ethernet_Index].editID = IDC_ETHERNET_MAC_DATA;
    g_sAllCtrlIDInfo[DRMKey_MCID_Index].editID = IDC_DRMKEY_MCID_DATA;

	//C2K
	g_sAllCtrlIDInfo[Meid_Index].editID = IDC_MEID_DATA;
	g_sAllCtrlIDInfo[Esn_Index].editID = IDC_ESN_DATA;
    g_sAllCtrlIDInfo[OK_Index].editID = IDC_BTN_SCAN_OK;
    
    g_sAllCtrlIDInfo[Barcode_Index].staticID = IDC_BARC_STATIC;
    g_sAllCtrlIDInfo[Bt_Index].staticID = IDC_BT_STATIC;
    g_sAllCtrlIDInfo[Wifi_Index].staticID = IDC_WIFI_STATIC;
    g_sAllCtrlIDInfo[Imei_1_Index].staticID = IDC_IMEI_1_STATIC;
    g_sAllCtrlIDInfo[Imei_2_Index].staticID = IDC_IMEI_2_STATIC;
    g_sAllCtrlIDInfo[Imei_3_Index].staticID = IDC_IMEI_3_STATIC;
    g_sAllCtrlIDInfo[Imei_4_Index].staticID = IDC_IMEI_4_STATIC;
    g_sAllCtrlIDInfo[SerialNo_Index].staticID = IDC_SERIAL_NO_STATIC;
    g_sAllCtrlIDInfo[Ethernet_Index].staticID = IDC_ETHERNET_STATIC;
    g_sAllCtrlIDInfo[DRMKey_MCID_Index].staticID = IDC_MCID_STATIC;
	//C2K
	g_sAllCtrlIDInfo[Meid_Index].staticID = IDC_MEID_STATIC;
	g_sAllCtrlIDInfo[Esn_Index].staticID = IDC_ESN_STATIC;
    
    g_sAllCtrlIDInfo[Barcode_Index].headerID = IDC_BARC_HEADER_SCAN;
    g_sAllCtrlIDInfo[Bt_Index].headerID = IDC_BT_HEADER_SCAN;
    g_sAllCtrlIDInfo[Wifi_Index].headerID = IDC_WIFI_HEADER_SCAN;
    g_sAllCtrlIDInfo[Imei_1_Index].headerID = IDC_IMEI_1_HEADER_SCAN;
    g_sAllCtrlIDInfo[Imei_2_Index].headerID = IDC_IMEI_2_HEADER_SCAN;
    g_sAllCtrlIDInfo[Imei_3_Index].headerID = IDC_IMEI_3_HEADER_SCAN;
    g_sAllCtrlIDInfo[Imei_4_Index].headerID = IDC_IMEI_4_HEADER_SCAN;
    g_sAllCtrlIDInfo[SerialNo_Index].headerID = IDC_SERIAL_NO_HEADER_SCAN;
    g_sAllCtrlIDInfo[Ethernet_Index].headerID = IDC_ETHERNET_HEADER_SCAN;
    g_sAllCtrlIDInfo[DRMKey_MCID_Index].headerID = IDC_DRMKEY_MCID_HEADER_SCAN;
	//C2K
	g_sAllCtrlIDInfo[Meid_Index].headerID = IDC_MEID_HEADER_SCAN;
	g_sAllCtrlIDInfo[Esn_Index].headerID = IDC_ESN_HEADER_SCAN;
  
    int i = 0;
    int j = 0;
    g_iNeedScanCtrlNum = 0;
    for (i = Barcode_Index; i < MAX_SCANDATA_NUMS - 1; i++)
    {
        if (g_bNeedScanItem[i])
        {
            g_iScanEditID[j] = g_sAllCtrlIDInfo[i].editID;
            g_sCtrlIDInfo[j].staticID = g_sAllCtrlIDInfo[i].staticID;
            g_sCtrlIDInfo[j].editID = g_sAllCtrlIDInfo[i].editID;
            g_sCtrlIDInfo[j].headerID = g_sAllCtrlIDInfo[i].headerID;
            g_iNeedScanCtrlNum += 1;
            j += 1;
        }
        else
        {
            ((CWnd*)GetDlgItem(g_sAllCtrlIDInfo[i].editID))->EnableWindow(FALSE); //disable don`t need scan edit control
        }      
    }
      
    g_iScanEditID[j] = IDC_BTN_SCAN_OK;
}

void CScanData::RemoveWindow()
{
    CRect dlgRect;       //scan dialog rect
    CRect editRect;      //scan edit control rect
    CRect editRect_2;    //scan edit control rect
    CRect staticRect;    //scan static rect
    CRect headerRect;    //scan static header rect
    CRect okBtnRect;     //scan ok btn rect
    CRect cancelBtnRect; //scan cancel btn rect
    CRect msgEditRect;   //scan msg rect

    GetWindowRect(&dlgRect);  
    
    GetDlgItem(IDC_BARC_STATIC)->GetWindowRect(&staticRect);
    GetDlgItem(IDC_BARCODE_DATA)->GetWindowRect(&editRect);  
    GetDlgItem(IDC_BARC_HEADER_SCAN)->GetWindowRect(&headerRect);
    GetDlgItem(IDC_IMEI_1_DATA)->GetWindowRect(&editRect_2);
    
    GetDlgItem(IDC_SCAN_MSG)->GetWindowRect(&msgEditRect);
    GetDlgItem(IDC_BTN_SCAN_OK)->GetWindowRect(&okBtnRect);
    GetDlgItem(IDC_BTN_SCAN_CANCEL)->GetWindowRect(&cancelBtnRect);

    ScreenToClient(&staticRect);  //获得相对于主窗体的坐标
    ScreenToClient(&editRect); 
    ScreenToClient(&headerRect);
    ScreenToClient(&editRect_2);
    
    ScreenToClient(&msgEditRect);
    ScreenToClient(&okBtnRect);
    ScreenToClient(&cancelBtnRect);
        
    int iStaticX = staticRect.left;
    int iStaticY = staticRect.top;
    int iStaticWidth = staticRect.Width();
    int iStaticHeigth = staticRect.Height();
    
    int iEditX = editRect.left;
    int iEditY = editRect.top;
    int iEditHeight = editRect.Height();
    int iEditWidth = editRect.Width();
    
    int iHeaderX = headerRect.left;
    int iHeaderY = headerRect.top;
    int iHeaderHeight = headerRect.Height();
    int iHeaderWidth = headerRect.Width();
    
    int iEditGap = editRect_2.top - editRect.top;

    int i=0;
    for (i=0; i<MAX_SCANDATA_NUMS - 1; i++)
    {
        GetDlgItem(g_sAllCtrlIDInfo[i].staticID)->ShowWindow(SW_HIDE);
        GetDlgItem(g_sAllCtrlIDInfo[i].editID)->ShowWindow(SW_HIDE);
        GetDlgItem(g_sAllCtrlIDInfo[i].headerID)->ShowWindow(SW_HIDE);
        
        SetDlgItemText(g_sAllCtrlIDInfo[i].editID, "");
        SetDlgItemText(g_sAllCtrlIDInfo[i].headerID, "");
    }
    
    UINT heightOffset = 0;
    for (i=0; i<g_iNeedScanCtrlNum; i++)
    {
        GetDlgItem(g_sCtrlIDInfo[i].staticID)->ShowWindow(SW_SHOW);
        GetDlgItem(g_sCtrlIDInfo[i].editID)->ShowWindow(SW_SHOW);
        GetDlgItem(g_sCtrlIDInfo[i].headerID)->ShowWindow(SW_SHOW);
        
        GetDlgItem(g_sCtrlIDInfo[i].staticID)->SetWindowPos(NULL, iStaticX, iStaticY+heightOffset, NULL, NULL, SWP_NOSIZE|SWP_NOZORDER);
        GetDlgItem(g_sCtrlIDInfo[i].editID)->SetWindowPos(NULL, iEditX, iEditY+heightOffset, NULL, NULL, SWP_NOSIZE|SWP_NOZORDER);
        GetDlgItem(g_sCtrlIDInfo[i].headerID)->SetWindowPos(NULL, iHeaderX, iHeaderY+heightOffset, NULL, NULL, SWP_NOSIZE|SWP_NOZORDER);
		
        heightOffset += iEditGap;
    }

    GetDlgItem(IDC_SCAN_MSG)->SetWindowPos(NULL, msgEditRect.left, iEditY+heightOffset, NULL, NULL, SWP_NOSIZE|SWP_NOZORDER);
    
    heightOffset = heightOffset + msgEditRect.Height();
    GetDlgItem(IDC_BTN_SCAN_CANCEL)->SetWindowPos(NULL, cancelBtnRect.left, iEditY+heightOffset, NULL, NULL, SWP_NOSIZE|SWP_NOZORDER);
    GetDlgItem(IDC_BTN_SCAN_OK)->SetWindowPos(NULL, okBtnRect.left, iEditY+heightOffset, NULL, NULL, SWP_NOSIZE|SWP_NOZORDER);
    
    int iDeltaHeight = iEditY+heightOffset - okBtnRect.top;
	dlgRect.top -= iDeltaHeight/2;
	dlgRect.bottom += iDeltaHeight/2;
    SetWindowPos(NULL, dlgRect.left, dlgRect.top, dlgRect.Width(), dlgRect.Height(), SWP_NOZORDER);

    SetDlgItemText(IDC_SCAN_MSG, "");
    GotoDlgCtrl(GetDlgItem(g_iScanEditID[0]));
}

void CScanData::InitScanUI()
{
    memset(g_sMetaComm.sScanData.strBarcode, 0, sizeof(g_sMetaComm.sScanData.strBarcode));
    memset(g_sMetaComm.sScanData.strBTAddr, 0, sizeof(g_sMetaComm.sScanData.strBTAddr));
    memset(g_sMetaComm.sScanData.strWifiAddr, 0, sizeof(g_sMetaComm.sScanData.strWifiAddr));
    memset(g_sMetaComm.sScanData.strIMEI[0], 0, sizeof(g_sMetaComm.sScanData.strIMEI[0]));
    memset(g_sMetaComm.sScanData.strIMEI[1], 0, sizeof(g_sMetaComm.sScanData.strIMEI[1]));
    memset(g_sMetaComm.sScanData.strIMEI[2], 0, sizeof(g_sMetaComm.sScanData.strIMEI[2]));
    memset(g_sMetaComm.sScanData.strIMEI[3], 0, sizeof(g_sMetaComm.sScanData.strIMEI[3]));
    memset(g_sMetaComm.sScanData.strSerialNo, 0, sizeof(g_sMetaComm.sScanData.strSerialNo));
    memset(g_sMetaComm.sScanData.strEthernetMac, 0, sizeof(g_sMetaComm.sScanData.strEthernetMac));
    memset(g_sMetaComm.sScanData.strDrmkeyMCID, 0, sizeof(g_sMetaComm.sScanData.strDrmkeyMCID));
    //c2k
	memset(g_sMetaComm.sScanData.strMeid, 0, sizeof(g_sMetaComm.sScanData.strMeid));
	memset(g_sMetaComm.sScanData.strEsn, 0, sizeof(g_sMetaComm.sScanData.strEsn));


    CreateScanOrder();
    RemoveWindow();

    if (g_sMetaComm.sBarcHeader_Option.bCheckHeader)
    {
        SetDlgItemText(IDC_BARC_HEADER_SCAN, g_sMetaComm.sBarcHeader_Option.strHeader);
    }
    
    if (g_sMetaComm.sBTHeader_Option.bCheckHeader)
    {
        SetDlgItemText(IDC_BT_HEADER_SCAN, g_sMetaComm.sBTHeader_Option.strHeader);
    }
    
    if (g_sMetaComm.sWifiHeader_Option.bCheckHeader)
    {
        SetDlgItemText(IDC_WIFI_HEADER_SCAN, g_sMetaComm.sWifiHeader_Option.strHeader);
    }

    if (g_sMetaComm.sSerialNoHeader_Option.bCheckHeader)
    {
        SetDlgItemText(IDC_SERIAL_NO_HEADER_SCAN, g_sMetaComm.sSerialNoHeader_Option.strHeader);
    }
    
    if (g_sMetaComm.sIMEIHeader_Option[0].bCheckHeader)
    {
        SetDlgItemText(IDC_IMEI_1_HEADER_SCAN, g_sMetaComm.sIMEIHeader_Option[0].strHeader);
    }
    
    if (g_sMetaComm.sIMEIHeader_Option[1].bCheckHeader)
    {
        SetDlgItemText(IDC_IMEI_2_HEADER_SCAN, g_sMetaComm.sIMEIHeader_Option[1].strHeader);
    }
    
    if (g_sMetaComm.sIMEIHeader_Option[2].bCheckHeader)
    {
        SetDlgItemText(IDC_IMEI_3_HEADER_SCAN, g_sMetaComm.sIMEIHeader_Option[2].strHeader);
    }
    
    if (g_sMetaComm.sIMEIHeader_Option[3].bCheckHeader)
    {
        SetDlgItemText(IDC_IMEI_4_HEADER_SCAN, g_sMetaComm.sIMEIHeader_Option[3].strHeader);
    }
    
    if (g_sMetaComm.sEthernetMacHeader_Option.bCheckHeader)
    {
        SetDlgItemText(IDC_ETHERNET_HEADER_SCAN, g_sMetaComm.sEthernetMacHeader_Option.strHeader);
    }
    
    if (g_sMetaComm.sDrmkeyMCIDHeader_Option.bCheckHeader)
    {
        SetDlgItemText(IDC_DRMKEY_MCID_HEADER_SCAN, g_sMetaComm.sDrmkeyMCIDHeader_Option.strHeader);
    }

	if (g_sMetaComm.sMeidHeader_Option.bCheckHeader)
	{
		SetDlgItemText(IDC_MEID_HEADER_SCAN, g_sMetaComm.sMeidHeader_Option.strHeader);
	}

	if (g_sMetaComm.sEsnHeader_Option.bCheckHeader)
	{
		SetDlgItemText(IDC_ESN_HEADER_SCAN, g_sMetaComm.sEsnHeader_Option.strHeader);
	}

#ifdef _AUTO_GEN_FEATURE_
    if (g_AutoGenData.bEnableAutoGen)
    {
        m_bNeedBackupIMEI = false;
        if (g_sMetaComm.sWriteOption.bWriteBarcode && g_AutoGenData.bAutoGenBarcode)
        {          
            SetDlgItemText(IDC_BARCODE_DATA, g_AutoGenData.sBarcode.Next);
        } 
        
        if (g_sMetaComm.sWriteOption.bWriteIMEI && g_AutoGenData.bAutoGenIMEI)
        {
            if (g_sMetaComm.sIMEIOption.iImeiNums >= 2)
            {
                strncpy(m_strBackupIMEI, g_AutoGenData.sIMEI.Next, strlen(g_AutoGenData.sIMEI.Next)+1);
                m_bNeedBackupIMEI = true;
            }

            AutoGenResult_e genResult = AutoGen_Success;
            SetDlgItemText(IDC_IMEI_1_DATA, g_AutoGenData.sIMEI.Next);

            if (!g_sMetaComm.sIMEIOption.bCheckSum)
            {
                if (g_sMetaComm.sIMEIOption.iImeiNums == 2)
                {
                    if(g_sMetaComm.sIMEIOption.bDualIMEISame == false)
                    {
                        genResult = AutoIncrease(AutoGen_IMEI, g_AutoGenData.sIMEI.iStep, g_AutoGenData.sIMEI.Next, IMEI_ARRAY_LEN);
                        if (genResult == AutoGen_Success)
                        {
                            SetDlgItemText(IDC_IMEI_2_DATA, g_AutoGenData.sIMEI.Next);
                        }   
                    }
                    else
                    {
                        SetDlgItemText(IDC_IMEI_2_DATA, g_AutoGenData.sIMEI.Next);
                    }
                } 
                else if(g_sMetaComm.sIMEIOption.iImeiNums == 3)
                {
                    genResult = AutoIncrease(AutoGen_IMEI, g_AutoGenData.sIMEI.iStep, g_AutoGenData.sIMEI.Next, IMEI_ARRAY_LEN);
                    if (genResult == AutoGen_Success)
                    {
                        SetDlgItemText(IDC_IMEI_2_DATA, g_AutoGenData.sIMEI.Next);
                    } 
                    genResult = AutoIncrease(AutoGen_IMEI, g_AutoGenData.sIMEI.iStep, g_AutoGenData.sIMEI.Next, IMEI_ARRAY_LEN);
                    if (genResult == AutoGen_Success)
                    {
                        SetDlgItemText(IDC_IMEI_3_DATA, g_AutoGenData.sIMEI.Next);
                    } 
                }
                else if(g_sMetaComm.sIMEIOption.iImeiNums == 4)
                {
                    genResult = AutoIncrease(AutoGen_IMEI, g_AutoGenData.sIMEI.iStep, g_AutoGenData.sIMEI.Next, IMEI_ARRAY_LEN);
                    if (genResult == AutoGen_Success)
                    {
                        SetDlgItemText(IDC_IMEI_2_DATA, g_AutoGenData.sIMEI.Next);
                    } 
                    
                    genResult = AutoIncrease(AutoGen_IMEI, g_AutoGenData.sIMEI.iStep, g_AutoGenData.sIMEI.Next, IMEI_ARRAY_LEN);
                    if (genResult == AutoGen_Success)
                    {
                        SetDlgItemText(IDC_IMEI_3_DATA, g_AutoGenData.sIMEI.Next);
                    } 
                    
                    genResult = AutoIncrease(AutoGen_IMEI, g_AutoGenData.sIMEI.iStep, g_AutoGenData.sIMEI.Next, IMEI_ARRAY_LEN);
                    if (genResult == AutoGen_Success)
                    {
                        SetDlgItemText(IDC_IMEI_4_DATA, g_AutoGenData.sIMEI.Next);
                    } 
                }
            } 
            else
            {
                if (g_sMetaComm.sIMEIOption.iImeiNums == 2)
                {
                    if(g_sMetaComm.sIMEIOption.bDualIMEISame == false)
                    {
                        genResult = AutoIncrease_Ex(AutoGen_IMEI, g_AutoGenData.sIMEI.iStep, g_AutoGenData.sIMEI.Next, IMEI_ARRAY_LEN, AutoGen_IMEI_CHECKSUM_OPTION);
                        if (genResult == AutoGen_Success)
                        {
                            SetDlgItemText(IDC_IMEI_2_DATA, g_AutoGenData.sIMEI.Next);
                        }   
                    }
                    else
                    {
                        SetDlgItemText(IDC_IMEI_2_DATA, g_AutoGenData.sIMEI.Next);
                    }
                } 
                else if(g_sMetaComm.sIMEIOption.iImeiNums == 3)
                {
                    genResult = AutoIncrease_Ex(AutoGen_IMEI, g_AutoGenData.sIMEI.iStep, g_AutoGenData.sIMEI.Next, IMEI_ARRAY_LEN, AutoGen_IMEI_CHECKSUM_OPTION);
                    if (genResult == AutoGen_Success)
                    {
                        SetDlgItemText(IDC_IMEI_2_DATA, g_AutoGenData.sIMEI.Next);
                    } 
                    genResult = AutoIncrease_Ex(AutoGen_IMEI, g_AutoGenData.sIMEI.iStep, g_AutoGenData.sIMEI.Next, IMEI_ARRAY_LEN, AutoGen_IMEI_CHECKSUM_OPTION);
                    if (genResult == AutoGen_Success)
                    {
                        SetDlgItemText(IDC_IMEI_3_DATA, g_AutoGenData.sIMEI.Next);
                    } 
                }
                else if(g_sMetaComm.sIMEIOption.iImeiNums == 4)
                {
                    genResult = AutoIncrease_Ex(AutoGen_IMEI, g_AutoGenData.sIMEI.iStep, g_AutoGenData.sIMEI.Next, IMEI_ARRAY_LEN, AutoGen_IMEI_CHECKSUM_OPTION);
                    if (genResult == AutoGen_Success)
                    {
                        SetDlgItemText(IDC_IMEI_2_DATA, g_AutoGenData.sIMEI.Next);
                    } 
                    
                    genResult = AutoIncrease_Ex(AutoGen_IMEI, g_AutoGenData.sIMEI.iStep, g_AutoGenData.sIMEI.Next, IMEI_ARRAY_LEN, AutoGen_IMEI_CHECKSUM_OPTION);
                    if (genResult == AutoGen_Success)
                    {
                        SetDlgItemText(IDC_IMEI_3_DATA, g_AutoGenData.sIMEI.Next);
                    } 
                    
                    genResult = AutoIncrease_Ex(AutoGen_IMEI, g_AutoGenData.sIMEI.iStep, g_AutoGenData.sIMEI.Next, IMEI_ARRAY_LEN, AutoGen_IMEI_CHECKSUM_OPTION);
                    if (genResult == AutoGen_Success)
                    {
                        SetDlgItemText(IDC_IMEI_4_DATA, g_AutoGenData.sIMEI.Next);
                    } 
                }
            }
            
        }  
        
        if (g_sMetaComm.sWriteOption.bWriteBT && g_AutoGenData.bAutoGenBT)
        {
            SetDlgItemText(IDC_BT_DATA, g_AutoGenData.sBtAddress.Next);
        }  
        
        if (g_sMetaComm.sWriteOption.bWriteWifi && g_AutoGenData.bAutoGenWifi)
        {
            SetDlgItemText(IDC_WIFI_DATA, g_AutoGenData.sWifiAddress.Next);
        }  

        if (g_sMetaComm.sWriteOption.bWriteEthernetMac && g_AutoGenData.bAutoGenEthernet)
        {
            SetDlgItemText(IDC_ETHERNET_MAC_DATA, g_AutoGenData.sEthernetAddress.Next);
        }

        if (g_sMetaComm.sWriteOption.bWriteDrmkeyMCID && g_AutoGenData.bAutoGenDRMKeyMCID)
        {
            SetDlgItemText(IDC_DRMKEY_MCID_DATA, g_AutoGenData.sDRMKeyMCID.Next);
        }
    }
#endif
}

void CScanData::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialog::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here
}
