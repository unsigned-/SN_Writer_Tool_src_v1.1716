// SystemConfig.cpp : implementation file
//

#include "stdafx.h"
#include "SN Writer.h"
#include "SN WriterDlg.h"
#include "SystemConfig.h"

#include <shlwapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSystemConfig dialog


CSystemConfig::CSystemConfig(CWnd* pParent /*=NULL*/)
: CDialog(CSystemConfig::IDD, pParent)
{
    //{{AFX_DATA_INIT(CSystemConfig)
    //***********C2K *************
    m_strMeidHD = _T("");
    m_strEsnHD  = _T("");
    //***********C2K *************
    m_strLogDir = _T("");
    m_strWifiHD = _T("");
    m_strMD_2_DBPath = _T("");
    m_strMD_1_DBPath = _T("");
    m_strIMEI_4_HD = _T("");
    m_strIMEI_3_HD = _T("");
    m_strIMEI_2_HD = _T("");
    m_strIMEI_1_HD = _T("");
    m_strBTHD = _T("");
    m_strBarcHD = _T("");
    m_strAPDbPath = _T("");
    m_strTemp = _T("");
    m_bWriteEthernetMac = FALSE;
    m_bCheckEthernetHD = FALSE;
    m_strEthernetHD = _T("");
    m_bCheckDrmkeyMCID_HD = FALSE;
    m_strDrmkeyMCID_HD = _T("");
    m_bWriteDrmkeyMCID = FALSE;
    m_bWriteSerialNo = FALSE;
    m_bCheckSerialNoHD = FALSE;
    m_strSerialNoHD = _T("");
    m_bDBFromDUT = FALSE;
    //}}AFX_DATA_INIT
    m_pToolTip = NULL;
}


void CSystemConfig::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CSystemConfig)
    //*************C2K***************
    DDX_Text(pDX, IDC_MEID_HEADER_STR, m_strMeidHD);
    DDV_MaxChars(pDX, m_strMeidHD, 8);
    DDX_Text(pDX, IDC_ESN_HEADER_STR, m_strEsnHD);
    DDV_MaxChars(pDX, m_strEsnHD, 6);
    DDX_Check(pDX, IDC_MEID_HEADER_CHECK, m_bCheckMeidHD);
    DDX_Check(pDX, IDC_ESN_HEADER_CHECK, m_bCheckEsnHD);
    DDX_Check(pDX, IDC_WRITE_MEID_CHECK, m_bWriteMeid);
    DDX_Check(pDX, IDC_WRITE_ESN_CHECK, m_bWriteEsn);
    //*************C2K***************
    DDX_Text(pDX, IDC_LOG_DIR, m_strLogDir);
    DDX_Text(pDX, IDC_WIFI_HEADER_STR, m_strWifiHD);
    DDV_MaxChars(pDX, m_strWifiHD, 8);
    DDX_Text(pDX, IDC_MD_2_DBFILE_PATH, m_strMD_2_DBPath);
    DDV_MaxChars(pDX, m_strMD_2_DBPath, 256);
    DDX_Text(pDX, IDC_MD_1_DBFILE_PATH, m_strMD_1_DBPath);
    DDV_MaxChars(pDX, m_strMD_1_DBPath, 256);
    DDX_Text(pDX, IDC_IMEI_4_HEADER_STR, m_strIMEI_4_HD);
    DDV_MaxChars(pDX, m_strIMEI_4_HD, 8);
    DDX_Text(pDX, IDC_IMEI_3_HEADER_STR, m_strIMEI_3_HD);
    DDV_MaxChars(pDX, m_strIMEI_3_HD, 8);
    DDX_Text(pDX, IDC_IMEI_2_HEADER_STR, m_strIMEI_2_HD);
    DDV_MaxChars(pDX, m_strIMEI_2_HD, 8);
    DDX_Text(pDX, IDC_IMEI_1_HEADER_STR, m_strIMEI_1_HD);
    DDV_MaxChars(pDX, m_strIMEI_1_HD, 8);
    DDX_Text(pDX, IDC_BT_HEADER_STR, m_strBTHD);
    DDV_MaxChars(pDX, m_strBTHD, 8);
    DDX_Text(pDX, IDC_BARC_HEADER_STR, m_strBarcHD);
    DDV_MaxChars(pDX, m_strBarcHD, 8);
    DDX_Text(pDX, IDC_AP_DBFILE_PATH, m_strAPDbPath);
    DDV_MaxChars(pDX, m_strAPDbPath, 256);
    DDX_Text(pDX,IDC_TEMPERATURE,m_strTemp);
    DDV_MaxChars(pDX, m_strTemp, 4);
    DDX_Check(pDX, IDC_BARC_HEADER_CHECK, m_bCheckBarcHD);
    DDX_Check(pDX, IDC_BT_HEADER_CHECK, m_bCheckBTHD);
    DDX_Check(pDX, IDC_IMEI_1_HEADER_CHECK, m_bCheckIMEI_1_HD);
    DDX_Check(pDX, IDC_IMEI_2_HEADER_CHECK, m_bCheckIMEI_2_HD);
    DDX_Check(pDX, IDC_IMEI_3_HEADER_CHECK, m_bCheckIMEI_3_HD);
    DDX_Check(pDX, IDC_IMEI_4_HEADER_CHECK, m_bCheckIMEI_4_HD);
    DDX_Check(pDX, IDC_DUAL_IMEI, m_bDualIMEI);
    DDX_Check(pDX, IDC_DUAL_IMEI_SAME, m_bDualIMEISame);
    DDX_Check(pDX, IDC_FOUR_IMEI, m_bFourIMEI);
    DDX_Check(pDX, IDC_IMEI_CHECKSUM, m_bIMEICheckSum);
    DDX_Check(pDX, IDC_THREE_IMEI, m_bThreeIMEI);
    DDX_Check(pDX, IDC_CURRENT_TEMPERATURE, m_bWriteTemperature);
    DDX_Check(pDX, IDC_WIFI_HEADER_CHECK, m_bCheckWifiHD);
    DDX_Check(pDX, IDC_WRITE_BARC_CHECK, m_bWriteBarc);
    DDX_Check(pDX, IDC_WRITE_BT_CHECK, m_bWriteBTAddr);
    DDX_Check(pDX, IDC_WRITE_IMEI_CHECK, m_bWriteIMEI);
    DDX_Check(pDX, IDC_WRITE_WIFI_CHECK, m_bWriteWifi);
    DDX_Check(pDX, IDC_IMEI_LOCK, m_bIMEILock);
    DDX_Check(pDX, IDC_WRITE_ETHERNET_MAC_CHECK, m_bWriteEthernetMac);
    DDX_Check(pDX, IDC_ETHERNET_HEADER_CHECK, m_bCheckEthernetHD);
    DDX_Text(pDX, IDC_ETHERNET_HEADER_STR, m_strEthernetHD);
    DDV_MaxChars(pDX, m_strEthernetHD, 8);
    DDX_Check(pDX, IDC_DRMKEY_MCID_HEADER_CHECK, m_bCheckDrmkeyMCID_HD);
    DDX_Text(pDX, IDC_DRMKEY_MCID_HEADER_STR, m_strDrmkeyMCID_HD);
    DDV_MaxChars(pDX, m_strDrmkeyMCID_HD, 8);
    DDX_Check(pDX, IDC_WRITE_DRMKEY_MCID_CHECK, m_bWriteDrmkeyMCID);
    DDX_Check(pDX, IDC_WRITE_SERIAL_NO_CHECK, m_bWriteSerialNo);
    DDX_Check(pDX, IDC_SERIAL_NO_HEADER_CHECK, m_bCheckSerialNoHD);
    DDX_Text(pDX, IDC_SERIAL_NO_HEADER_STR, m_strSerialNoHD);
    //	DDX_Check(pDX, IDC_EXTERN_MD_DOWNLOAD, m_bExternMDDownload);
    DDV_MaxChars(pDX, m_strSerialNoHD, 8);
    //}}AFX_DATA_MAP

    DDX_Check(pDX, IDC_DB_FROM_DUT_CHECK, m_bDBFromDUT);
    DDX_Control(pDX, IDC_BTN_MD1, m_Load_MD1DB_BTN);
    DDX_Control(pDX, IDC_BTN_MD2, m_Load_MD2DB_BTN);
    DDX_Control(pDX, IDC_BTN_AP, m_Load_APDB_BTN);
    DDX_Control(pDX, IDC_BTN_LOG, m_LogDir_BTN);
    DDX_Control(pDX, IDC_BTN_SAVE, m_SaveBTN);
}


BEGIN_MESSAGE_MAP(CSystemConfig, CDialog)
    //{{AFX_MSG_MAP(CSystemConfig)
    ON_BN_CLICKED(IDC_BARC_HEADER_CHECK, OnBarcHeaderCheck)
    ON_BN_CLICKED(IDC_BT_HEADER_CHECK, OnBtHeaderCheck)
    ON_BN_CLICKED(IDC_BTN_AP, OnBtnAp)
    ON_BN_CLICKED(IDC_BTN_MD1, OnBtnMd1)
    ON_BN_CLICKED(IDC_BTN_MD2, OnBtnMd2)
    ON_BN_CLICKED(IDC_DUAL_IMEI, OnDualImei)
    ON_BN_CLICKED(IDC_DUAL_IMEI_SAME, OnDualImeiSame)
    ON_BN_CLICKED(IDC_FOUR_IMEI, OnFourImei)
    ON_BN_CLICKED(IDC_IMEI_1_HEADER_CHECK, OnImei1HeaderCheck)
    ON_BN_CLICKED(IDC_IMEI_2_HEADER_CHECK, OnImei2HeaderCheck)
    ON_BN_CLICKED(IDC_IMEI_3_HEADER_CHECK, OnImei3HeaderCheck)
    ON_BN_CLICKED(IDC_IMEI_4_HEADER_CHECK, OnImei4HeaderCheck)
    ON_BN_CLICKED(IDC_IMEI_CHECKSUM, OnImeiChecksum)
    ON_BN_CLICKED(IDC_IMEI_LOCK, OnImeiLock)
    ON_BN_CLICKED(IDC_THREE_IMEI, OnThreeImei)
    ON_BN_CLICKED(IDC_WIFI_HEADER_CHECK, OnWifiHeaderCheck)
    ON_BN_CLICKED(IDC_WRITE_BARC_CHECK, OnWriteBarcCheck)
    ON_BN_CLICKED(IDC_WRITE_BT_CHECK, OnWriteBtCheck)
    ON_BN_CLICKED(IDC_WRITE_IMEI_CHECK, OnWriteImeiCheck)
    ON_BN_CLICKED(IDC_WRITE_WIFI_CHECK, OnWriteWifiCheck)
    ON_BN_CLICKED(IDC_BTN_SAVE, OnBtnSave)
    ON_BN_CLICKED(IDC_CURRENT_TEMPERATURE, OnCurrentTemperature)
    ON_BN_CLICKED(IDC_WRITE_ETHERNET_MAC_CHECK, OnWriteEthernetMacCheck)
    ON_BN_CLICKED(IDC_WRITE_DRMKEY_MCID_CHECK, OnWriteDrmkeyMcidCheck)
    ON_BN_CLICKED(IDC_DRMKEY_MCID_HEADER_CHECK, OnDrmkeyMcidHeaderCheck)
    ON_EN_KILLFOCUS(IDC_TEMPERATURE, OnKillfocusTemperature)
    ON_BN_CLICKED(IDC_WRITE_SERIAL_NO_CHECK, OnWriteSerialNoCheck)
    ON_BN_CLICKED(IDC_SERIAL_NO_HEADER_CHECK, OnSerialNoHeaderCheck)
    //C2K 
    ON_BN_CLICKED(IDC_WRITE_MEID_CHECK, OnWriteMeidCheck)
    ON_BN_CLICKED(IDC_WRITE_ESN_CHECK, OnWriteEsnCheck)
    ON_BN_CLICKED(IDC_MEID_HEADER_CHECK, OnMeidHeaderCheck)
    ON_BN_CLICKED(IDC_ESN_HEADER_CHECK, OnEsnHeaderCheck)
    ON_BN_CLICKED(IDC_ETHERNET_HEADER_CHECK, OnEthernetHeaderCheck)

    ON_BN_CLICKED(IDC_DB_FROM_DUT_CHECK, OnDBFromDUTCheck)
    ON_BN_CLICKED(IDC_BTN_LOG, OnLogDir)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSystemConfig message handlers

BOOL CSystemConfig::OnInitDialog() 
{
    CDialog::OnInitDialog();

    // TODO: Add extra initialization here
    m_Load_MD1DB_BTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_Load_MD2DB_BTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_Load_APDB_BTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_LogDir_BTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_SaveBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);

    if (g_sMetaComm.eTargetType == SMART_PHONE_DUALMODEM)
    {
        g_sMetaComm.sIMEIOption.bDualIMEI = true;
        g_sMetaComm.sIMEIOption.iImeiNums = DUAL_IMEI;
    }

    if(!g_sMetaComm.EnableSerialNo)
    {
        GetDlgItem(IDC_WRITE_SERIAL_NO_CHECK)->ShowWindow(FALSE);
        g_sMetaComm.sWriteOption.bWriteSerialNo = false;
    }

    if (g_sMetaComm.eTargetType != SMART_PHONE)
    {
        g_sMetaComm.sDBFileOption.bDBFromDUT = false;
    }

    UpdateConfigUIOption();

    // Tool Tip
    m_pToolTip = new CToolTipCtrl;
    m_pToolTip->Create(this, TTS_NOPREFIX);
    m_pToolTip->SetDelayTime(TTDT_INITIAL, 50);
    m_pToolTip->SetDelayTime(TTDT_AUTOPOP, 2000);
    m_pToolTip->AddTool(GetDlgItem(IDC_DB_FROM_DUT_CHECK), _T("Only support mt6750/55/97/57 etc. new platforms."));

    return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CSystemConfig::PreTranslateMessage(MSG* pMsg) 
{
    // TODO: Add your specialized code here and/or call the base class

    // ToolTip
    if (m_pToolTip != NULL && m_pToolTip->m_hWnd != NULL)
        m_pToolTip->RelayEvent(pMsg);

    // not close dialog on press "Return" On "Esc" key
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
        return TRUE;

    return CDialog::PreTranslateMessage(pMsg);
}

void CSystemConfig::OnBarcHeaderCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sBarcHeader_Option.bCheckHeader = (m_bCheckBarcHD == TRUE);
    ((CWnd*)GetDlgItem(IDC_BARC_HEADER_STR))->EnableWindow(m_bCheckBarcHD);
}

void CSystemConfig::OnBtHeaderCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sBTHeader_Option.bCheckHeader = (m_bCheckBTHD == TRUE);
    ((CWnd*)GetDlgItem(IDC_BT_HEADER_STR))->EnableWindow(m_bCheckBTHD);
}

void CSystemConfig::OnWifiHeaderCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sWifiHeader_Option.bCheckHeader = (m_bCheckWifiHD == TRUE);
    ((CWnd*)GetDlgItem(IDC_WIFI_HEADER_STR))->EnableWindow(m_bCheckWifiHD);
}

void CSystemConfig::OnBtnAp() 
{
    // TODO: Add your control notification handler code here
    char szFilter[]="Database files(*.*)|*.*||";

    CFileDialog dlg(TRUE, NULL, NULL,
        OFN_FILEMUSTEXIST|OFN_EXPLORER|OFN_ENABLESIZING|0x10000000/*OFN_FORCESHOWHIDDEN*/,
        szFilter, this);  
    dlg.m_ofn.lpstrTitle = _T("Select AP database file...");
    if(dlg.DoModal() == IDOK)
    {
        g_sMetaComm.sDBFileOption.bDBInitAP = false;
        m_strAPDbPath = dlg.GetPathName();
    }

    CEdit* pEdit = (CEdit*)GetDlgItem(IDC_AP_DBFILE_PATH);
    pEdit->SetWindowText(m_strAPDbPath);
}

void CSystemConfig::OnBtnMd1() 
{
    // TODO: Add your control notification handler code here
    char szFilter[]="Database files(*.*)|*.*";

    CFileDialog dlg(TRUE, NULL, NULL,
        OFN_FILEMUSTEXIST|OFN_EXPLORER|OFN_ENABLESIZING|0x10000000/*OFN_FORCESHOWHIDDEN*/,
        szFilter, this); 
    dlg.m_ofn.lpstrTitle = _T("Select Modem_1 database file...");
    if(dlg.DoModal() == IDOK)
    {
        g_sMetaComm.sDBFileOption.bDBInitModem_1 = false;
        m_strMD_1_DBPath = dlg.GetPathName();
    }

    CEdit* pEdit = (CEdit*)GetDlgItem(IDC_MD_1_DBFILE_PATH);
    pEdit->SetWindowText(m_strMD_1_DBPath);
}

void CSystemConfig::OnBtnMd2() 
{
    // TODO: Add your control notification handler code here
    char szFilter[]="Database files(*.*)|*.*";

    CFileDialog dlg(TRUE, NULL, NULL,
        OFN_FILEMUSTEXIST|OFN_EXPLORER|OFN_ENABLESIZING|0x10000000/*OFN_FORCESHOWHIDDEN*/,
        szFilter, this);
    dlg.m_ofn.lpstrTitle = _T("Select Modem_2 database file...");
    if(dlg.DoModal()==IDOK) 
    {
        g_sMetaComm.sDBFileOption.bDBInitModem_2 = false;
        m_strMD_2_DBPath = dlg.GetPathName();
    }

    CEdit* pEdit = (CEdit*)GetDlgItem(IDC_MD_2_DBFILE_PATH);
    pEdit->SetWindowText(m_strMD_2_DBPath);
}

void CSystemConfig::OnDualImei() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sIMEIOption.bDualIMEI = (m_bDualIMEI == TRUE);
    if(m_bDualIMEI)
    {
        g_sMetaComm.sIMEIOption.iImeiNums  = DUAL_IMEI;
        g_sMetaComm.sIMEIOption.bDualIMEI  = true;
        g_sMetaComm.sIMEIOption.bThreeIMEI = false;
        g_sMetaComm.sIMEIOption.bFourIMEI  = false;
        CheckDlgButton(IDC_THREE_IMEI, FALSE);
        CheckDlgButton(IDC_FOUR_IMEI, FALSE);
        ((CWnd*)GetDlgItem(IDC_DUAL_IMEI_SAME))->EnableWindow(TRUE);
        UpDateIMEIHeaderOption(DUAL_IMEI, TRUE);
    }
    else
    {
        g_sMetaComm.sIMEIOption.iImeiNums = ONE_IMEI;
        g_sMetaComm.sIMEIOption.bDualIMEI = false;
        ((CWnd*)GetDlgItem(IDC_DUAL_IMEI_SAME))->EnableWindow(FALSE);
        UpDateIMEIHeaderOption(DUAL_IMEI, FALSE);
    }
}

void CSystemConfig::OnDualImeiSame() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sIMEIOption.bDualIMEISame = (m_bDualIMEISame == TRUE);
    (CWnd*)GetDlgItem(IDC_IMEI_2_HEADER_STR)->EnableWindow(m_bCheckIMEI_2_HD);
    (CWnd*)GetDlgItem(IDC_IMEI_2_HEADER_CHECK)->EnableWindow(!m_bDualIMEISame);
}


void CSystemConfig::OnFourImei() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sIMEIOption.bFourIMEI = (m_bFourIMEI == TRUE);
    if(IsDlgButtonChecked(IDC_FOUR_IMEI))
    {
        g_sMetaComm.sIMEIOption.iImeiNums = FOUR_IMEI;
        g_sMetaComm.sIMEIOption.bDualIMEI = false;
        g_sMetaComm.sIMEIOption.bDualIMEISame = false;
        g_sMetaComm.sIMEIOption.bThreeIMEI = false;
        g_sMetaComm.sIMEIOption.bFourIMEI = true;
        CheckDlgButton(IDC_THREE_IMEI, FALSE);
        CheckDlgButton(IDC_DUAL_IMEI, FALSE);
        ((CWnd*)GetDlgItem(IDC_DUAL_IMEI_SAME))->EnableWindow(FALSE);
        UpDateIMEIHeaderOption(FOUR_IMEI, TRUE);
    }
    else
    {
        g_sMetaComm.sIMEIOption.iImeiNums = ONE_IMEI;
        g_sMetaComm.sIMEIOption.bFourIMEI = false;
        //UpDateIMEIHeaderOption(ONE_IMEI, TRUE);
        UpDateIMEIHeaderOption(FOUR_IMEI, FALSE);
    }
}

void CSystemConfig::OnImei1HeaderCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sIMEIHeader_Option[0].bCheckHeader = (m_bCheckIMEI_1_HD == TRUE);
    ((CWnd*)GetDlgItem(IDC_IMEI_1_HEADER_STR))->EnableWindow(m_bCheckIMEI_1_HD);
}

void CSystemConfig::OnImei2HeaderCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sIMEIHeader_Option[1].bCheckHeader = (m_bCheckIMEI_2_HD == TRUE);
    ((CWnd*)GetDlgItem(IDC_IMEI_2_HEADER_STR))->EnableWindow(m_bCheckIMEI_2_HD);
}

void CSystemConfig::OnImei3HeaderCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sIMEIHeader_Option[2].bCheckHeader = (m_bCheckIMEI_3_HD == TRUE);
    ((CWnd*)GetDlgItem(IDC_IMEI_3_HEADER_STR))->EnableWindow(m_bCheckIMEI_3_HD);
}

void CSystemConfig::OnImei4HeaderCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sIMEIHeader_Option[3].bCheckHeader = (m_bCheckIMEI_4_HD == TRUE);
    ((CWnd*)GetDlgItem(IDC_IMEI_4_HEADER_STR))->EnableWindow(m_bCheckIMEI_4_HD);
}

void CSystemConfig::OnImeiChecksum() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sIMEIOption.bCheckSum = (m_bIMEICheckSum == TRUE); 
}

void CSystemConfig::OnImeiLock() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sIMEIOption.bLockIMEI = (m_bIMEILock == TRUE); 
}

void CSystemConfig::OnThreeImei() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sIMEIOption.bThreeIMEI = (m_bThreeIMEI == TRUE);
    if(IsDlgButtonChecked(IDC_THREE_IMEI))
    {
        g_sMetaComm.sIMEIOption.iImeiNums = THREE_IMEI;
        g_sMetaComm.sIMEIOption.bDualIMEI = false;
        g_sMetaComm.sIMEIOption.bDualIMEISame = false;
        g_sMetaComm.sIMEIOption.bThreeIMEI = true;
        g_sMetaComm.sIMEIOption.bFourIMEI = false;
        CheckDlgButton(IDC_DUAL_IMEI, FALSE);
        CheckDlgButton(IDC_FOUR_IMEI, FALSE);
        ((CWnd*)GetDlgItem(IDC_DUAL_IMEI_SAME))->EnableWindow(FALSE);
        UpDateIMEIHeaderOption(THREE_IMEI, TRUE);
    }
    else
    {
        g_sMetaComm.sIMEIOption.iImeiNums = ONE_IMEI;
        g_sMetaComm.sIMEIOption.bThreeIMEI = false;
        UpDateIMEIHeaderOption(THREE_IMEI, FALSE);
    }
}


void CSystemConfig::OnWriteBarcCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sWriteOption.bWriteBarcode = (m_bWriteBarc == TRUE);
    ((CWnd*)GetDlgItem(IDC_BARC_HEADER_CHECK))->EnableWindow(m_bWriteBarc);
    if (m_bWriteBarc)
    {
        ((CWnd*)GetDlgItem(IDC_BARC_HEADER_STR))->EnableWindow(m_bCheckBarcHD);
        //		((CWnd*)GetDlgItem(IDC_EXTERN_MD_DOWNLOAD))->EnableWindow(TRUE);
    }
    else
    {
        ((CWnd*)GetDlgItem(IDC_BARC_HEADER_STR))->EnableWindow(FALSE);
        //		((CWnd*)GetDlgItem(IDC_EXTERN_MD_DOWNLOAD))->EnableWindow(FALSE);
    }
}

void CSystemConfig::OnWriteBtCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sWriteOption.bWriteBT = (m_bWriteBTAddr == TRUE);
    ((CWnd*)GetDlgItem(IDC_BT_HEADER_CHECK))->EnableWindow(m_bWriteBTAddr);
    if (m_bWriteBTAddr)
    {
        ((CWnd*)GetDlgItem(IDC_BT_HEADER_STR))->EnableWindow(m_bCheckBTHD);
    }
    else
    {
        ((CWnd*)GetDlgItem(IDC_BT_HEADER_STR))->EnableWindow(FALSE);
    }
}

void CSystemConfig::OnWriteImeiCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sWriteOption.bWriteIMEI = (m_bWriteIMEI == TRUE);
    UpDateIMEIOption(m_bWriteIMEI);

    if(g_sMetaComm.sWriteOption.bWriteIMEI)
    {
        if(g_sMetaComm.sIMEIOption.bDualIMEI)
        {
            UpDateIMEIHeaderOption(DUAL_IMEI, TRUE); 
        }
        else if(g_sMetaComm.sIMEIOption.bThreeIMEI)
        {
            UpDateIMEIHeaderOption(THREE_IMEI, TRUE); 
        }
        else if(g_sMetaComm.sIMEIOption.bFourIMEI)
        {
            UpDateIMEIHeaderOption(FOUR_IMEI, TRUE); 
        }
        else
        {
            UpDateIMEIHeaderOption(ONE_IMEI, TRUE);   
        }
    }
    else
    {
        UpDateIMEIHeaderOption(NONE_IMEI, FALSE); 
    }
}

void CSystemConfig::OnWriteWifiCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sWriteOption.bWriteWifi = (m_bWriteWifi == TRUE);
    ((CWnd*)GetDlgItem(IDC_WIFI_HEADER_CHECK))->EnableWindow(m_bWriteWifi);
    if (m_bWriteWifi)
    {
        ((CWnd*)GetDlgItem(IDC_WIFI_HEADER_STR))->EnableWindow(m_bCheckWifiHD);
    }
    else
    {
        ((CWnd*)GetDlgItem(IDC_WIFI_HEADER_STR))->EnableWindow(FALSE);
    }
}

#if 0
void CSystemConfig::OnExternMDDLCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sBarcodeOption.bExtMdDl = m_bExternMDDownload;
}
#endif
void CSystemConfig::GetUIEditData()
{
    UpdateData(TRUE);

    //C2K
    strncpy(g_sMetaComm.sMeidHeader_Option.strHeader,(LPCTSTR)m_strMeidHD,strlen(m_strMeidHD)+1);
    strncpy(g_sMetaComm.sEsnHeader_Option.strHeader,(LPCTSTR)m_strEsnHD,strlen(m_strEsnHD)+1);

    strncpy(g_sMetaComm.sBarcHeader_Option.strHeader,(LPCTSTR)m_strBarcHD,strlen(m_strBarcHD)+1);
    strncpy(g_sMetaComm.sIMEIHeader_Option[0].strHeader,(LPCTSTR)m_strIMEI_1_HD,strlen(m_strIMEI_1_HD)+1);
    strncpy(g_sMetaComm.sIMEIHeader_Option[1].strHeader,(LPCTSTR)m_strIMEI_2_HD,strlen(m_strIMEI_2_HD)+1);
    strncpy(g_sMetaComm.sIMEIHeader_Option[2].strHeader,(LPCTSTR)m_strIMEI_3_HD,strlen(m_strIMEI_3_HD)+1);
    strncpy(g_sMetaComm.sIMEIHeader_Option[3].strHeader,(LPCTSTR)m_strIMEI_4_HD,strlen(m_strIMEI_4_HD)+1);
    strncpy(g_sMetaComm.sSerialNoHeader_Option.strHeader,(LPCTSTR)m_strSerialNoHD,strlen(m_strSerialNoHD)+1);
    strncpy(g_sMetaComm.sEthernetMacHeader_Option.strHeader,(LPCTSTR)m_strEthernetHD,strlen(m_strEthernetHD)+1);
    strncpy(g_sMetaComm.sDrmkeyMCIDHeader_Option.strHeader,(LPCTSTR)m_strDrmkeyMCID_HD,strlen(m_strDrmkeyMCID_HD)+1);
    strncpy(g_sMetaComm.sBTHeader_Option.strHeader,(LPCTSTR)m_strBTHD,strlen(m_strBTHD)+1);
    strncpy(g_sMetaComm.sWifiHeader_Option.strHeader,(LPCTSTR)m_strWifiHD,strlen(m_strWifiHD)+1);
    g_sMetaComm.sDBFileOption.bDBFromDUT = (m_bDBFromDUT == TRUE);
    strncpy(g_sMetaComm.sDBFileOption.strMD1Dbpath,(LPCTSTR)m_strMD_1_DBPath,strlen(m_strMD_1_DBPath)+1);
    strncpy(g_sMetaComm.sDBFileOption.strMD2Dbpath,(LPCTSTR)m_strMD_2_DBPath,strlen(m_strMD_2_DBPath)+1);
    strncpy(g_sMetaComm.sDBFileOption.strAPDbpath,(LPCTSTR)m_strAPDbPath,strlen(m_strAPDbPath)+1);
    strncpy(g_sMetaComm.sIMEIOption.Temp_Option.strTemperatureData,(LPCTSTR)m_strTemp,strlen(m_strTemp)+1);

    strcpy(g_sMetaComm.strLogDir, m_strLogDir);

    if (m_bWriteIMEI && m_bWriteTemperature)
    {
        CheckTempDataValid();
    }
}

void CSystemConfig::UpDateIMEIHeaderOption(E_IMEI_NUM iIMEINums, BOOL bEnable)
{
    if (bEnable == TRUE)
    {
        g_sMetaComm.sIMEIOption.iImeiNums = iIMEINums;
    }
    else if(g_sMetaComm.sWriteOption.bWriteIMEI)
    {
        g_sMetaComm.sIMEIOption.iImeiNums = ONE_IMEI;
        iIMEINums = ONE_IMEI;
    }

    ((CWnd*)GetDlgItem(IDC_IMEI_1_HEADER_CHECK))->EnableWindow(FALSE);
    ((CWnd*)GetDlgItem(IDC_IMEI_2_HEADER_CHECK))->EnableWindow(FALSE);
    ((CWnd*)GetDlgItem(IDC_IMEI_3_HEADER_CHECK))->EnableWindow(FALSE);
    ((CWnd*)GetDlgItem(IDC_IMEI_4_HEADER_CHECK))->EnableWindow(FALSE);

    ((CWnd*)GetDlgItem(IDC_IMEI_1_HEADER_STR))->EnableWindow(FALSE);
    ((CWnd*)GetDlgItem(IDC_IMEI_2_HEADER_STR))->EnableWindow(FALSE);
    ((CWnd*)GetDlgItem(IDC_IMEI_3_HEADER_STR))->EnableWindow(FALSE);
    ((CWnd*)GetDlgItem(IDC_IMEI_4_HEADER_STR))->EnableWindow(FALSE);

    switch (iIMEINums)
    {
    case NONE_IMEI:

        ((CWnd*)GetDlgItem(IDC_IMEI_1_HEADER_CHECK))->EnableWindow(FALSE);
        ((CWnd*)GetDlgItem(IDC_IMEI_2_HEADER_CHECK))->EnableWindow(FALSE);
        ((CWnd*)GetDlgItem(IDC_IMEI_3_HEADER_CHECK))->EnableWindow(FALSE);
        ((CWnd*)GetDlgItem(IDC_IMEI_4_HEADER_CHECK))->EnableWindow(FALSE);

        ((CWnd*)GetDlgItem(IDC_IMEI_1_HEADER_STR))->EnableWindow(FALSE);
        ((CWnd*)GetDlgItem(IDC_IMEI_2_HEADER_STR))->EnableWindow(FALSE);
        ((CWnd*)GetDlgItem(IDC_IMEI_3_HEADER_STR))->EnableWindow(FALSE);
        ((CWnd*)GetDlgItem(IDC_IMEI_4_HEADER_STR))->EnableWindow(FALSE);
        break;

    case ONE_IMEI:

        ((CWnd*)GetDlgItem(IDC_IMEI_1_HEADER_CHECK))->EnableWindow(TRUE);
        if (g_sMetaComm.sIMEIHeader_Option[0].bCheckHeader)
        {
            ((CWnd*)GetDlgItem(IDC_IMEI_1_HEADER_STR))->EnableWindow(bEnable);
        }      
        break;

    case DUAL_IMEI:

        ((CWnd*)GetDlgItem(IDC_IMEI_1_HEADER_CHECK))->EnableWindow(bEnable);
        ((CWnd*)GetDlgItem(IDC_IMEI_2_HEADER_CHECK))->EnableWindow(bEnable);
        if (g_sMetaComm.sIMEIHeader_Option[0].bCheckHeader)
        {
            ((CWnd*)GetDlgItem(IDC_IMEI_1_HEADER_STR))->EnableWindow(bEnable);
        }  

        if (g_sMetaComm.sIMEIHeader_Option[1].bCheckHeader)
        {
            ((CWnd*)GetDlgItem(IDC_IMEI_2_HEADER_STR))->EnableWindow(bEnable);
        }     
        break;

    case THREE_IMEI:

        ((CWnd*)GetDlgItem(IDC_IMEI_1_HEADER_CHECK))->EnableWindow(bEnable);
        ((CWnd*)GetDlgItem(IDC_IMEI_2_HEADER_CHECK))->EnableWindow(bEnable);
        ((CWnd*)GetDlgItem(IDC_IMEI_3_HEADER_CHECK))->EnableWindow(bEnable);

        if (g_sMetaComm.sIMEIHeader_Option[0].bCheckHeader)
        {
            ((CWnd*)GetDlgItem(IDC_IMEI_1_HEADER_STR))->EnableWindow(bEnable);
        } 

        if (g_sMetaComm.sIMEIHeader_Option[1].bCheckHeader)
        {
            ((CWnd*)GetDlgItem(IDC_IMEI_2_HEADER_STR))->EnableWindow(bEnable);
        }  

        if (g_sMetaComm.sIMEIHeader_Option[2].bCheckHeader)
        {
            ((CWnd*)GetDlgItem(IDC_IMEI_3_HEADER_STR))->EnableWindow(bEnable);
        } 
        break;

    case FOUR_IMEI:

        ((CWnd*)GetDlgItem(IDC_IMEI_1_HEADER_CHECK))->EnableWindow(bEnable);
        ((CWnd*)GetDlgItem(IDC_IMEI_2_HEADER_CHECK))->EnableWindow(bEnable);
        ((CWnd*)GetDlgItem(IDC_IMEI_3_HEADER_CHECK))->EnableWindow(bEnable);
        ((CWnd*)GetDlgItem(IDC_IMEI_4_HEADER_CHECK))->EnableWindow(bEnable);
        if (g_sMetaComm.sIMEIHeader_Option[0].bCheckHeader)
        {
            ((CWnd*)GetDlgItem(IDC_IMEI_1_HEADER_STR))->EnableWindow(bEnable);
        } 

        if (g_sMetaComm.sIMEIHeader_Option[1].bCheckHeader)
        {
            ((CWnd*)GetDlgItem(IDC_IMEI_2_HEADER_STR))->EnableWindow(bEnable);
        }     
        if (g_sMetaComm.sIMEIHeader_Option[2].bCheckHeader)
        {
            ((CWnd*)GetDlgItem(IDC_IMEI_3_HEADER_STR))->EnableWindow(bEnable);
        }                
        if (g_sMetaComm.sIMEIHeader_Option[3].bCheckHeader)
        {
            ((CWnd*)GetDlgItem(IDC_IMEI_4_HEADER_STR))->EnableWindow(bEnable);
        } 
        break;
    }  
}

void CSystemConfig::UpDateIMEIOption(BOOL bWriteIMEIEnable)
{
    ((CWnd*)GetDlgItem(IDC_IMEI_CHECKSUM))->EnableWindow(bWriteIMEIEnable);
    if(g_sMetaComm.ImeiLockHidden == true)
    {
        ((CWnd*)GetDlgItem(IDC_IMEI_LOCK))->EnableWindow(FALSE);
        ((CWnd*)GetDlgItem(IDC_IMEI_LOCK))->ShowWindow(false);
    }
    else
    {
        ((CWnd*)GetDlgItem(IDC_IMEI_LOCK))->EnableWindow(bWriteIMEIEnable);
    }
    ((CWnd*)GetDlgItem(IDC_DUAL_IMEI))->EnableWindow(bWriteIMEIEnable);
    ((CWnd*)GetDlgItem(IDC_DUAL_IMEI_SAME))->EnableWindow(bWriteIMEIEnable);
    ((CWnd*)GetDlgItem(IDC_THREE_IMEI))->EnableWindow(bWriteIMEIEnable);
    ((CWnd*)GetDlgItem(IDC_FOUR_IMEI))->EnableWindow(bWriteIMEIEnable);
    ((CWnd*)GetDlgItem(IDC_CURRENT_TEMPERATURE))->EnableWindow(bWriteIMEIEnable);
    ((CWnd*)GetDlgItem(IDC_TEMPERATURE))->EnableWindow(bWriteIMEIEnable);	
}

void CSystemConfig::UpdateConfigUIOption()
{
    m_bDBFromDUT     = g_sMetaComm.sDBFileOption.bDBFromDUT;
    m_strMD_1_DBPath = g_sMetaComm.sDBFileOption.strMD1Dbpath;
    m_strMD_2_DBPath = g_sMetaComm.sDBFileOption.strMD2Dbpath;
    m_strAPDbPath    = g_sMetaComm.sDBFileOption.strAPDbpath;

    m_bWriteBarc     = g_sMetaComm.sWriteOption.bWriteBarcode;
    m_bWriteIMEI     = g_sMetaComm.sWriteOption.bWriteIMEI;  
    m_bWriteSerialNo = g_sMetaComm.sWriteOption.bWriteSerialNo; 
    m_bWriteBTAddr   = g_sMetaComm.sWriteOption.bWriteBT;
    m_bWriteWifi     = g_sMetaComm.sWriteOption.bWriteWifi;
    m_bWriteEthernetMac = g_sMetaComm.sWriteOption.bWriteEthernetMac;
    m_bWriteDrmkeyMCID = g_sMetaComm.sWriteOption.bWriteDrmkeyMCID;
    //C2K
    m_bWriteMeid     = g_sMetaComm.sWriteOption.bWriteMeid;
    m_bWriteEsn      = g_sMetaComm.sWriteOption.bWriteEsn;

    m_bIMEICheckSum  = g_sMetaComm.sIMEIOption.bCheckSum;
    m_bIMEILock      = g_sMetaComm.sIMEIOption.bLockIMEI;
    m_bDualIMEI      = g_sMetaComm.sIMEIOption.bDualIMEI;
    m_bDualIMEISame  = g_sMetaComm.sIMEIOption.bDualIMEISame;
    m_bThreeIMEI      = g_sMetaComm.sIMEIOption.bThreeIMEI;
    m_bFourIMEI       = g_sMetaComm.sIMEIOption.bFourIMEI;
    m_bWriteTemperature    = g_sMetaComm.sIMEIOption.Temp_Option.bWriteTemperature;
    //m_bWriteTemperature  = true;

    m_bCheckIMEI_1_HD = g_sMetaComm.sIMEIHeader_Option[0].bCheckHeader;
    m_bCheckIMEI_2_HD = g_sMetaComm.sIMEIHeader_Option[1].bCheckHeader;
    m_bCheckIMEI_3_HD = g_sMetaComm.sIMEIHeader_Option[2].bCheckHeader;
    m_bCheckIMEI_4_HD = g_sMetaComm.sIMEIHeader_Option[3].bCheckHeader;    
    m_strIMEI_1_HD  = g_sMetaComm.sIMEIHeader_Option[0].strHeader;
    m_strIMEI_2_HD  = g_sMetaComm.sIMEIHeader_Option[1].strHeader;
    m_strIMEI_3_HD  = g_sMetaComm.sIMEIHeader_Option[2].strHeader;
    m_strIMEI_4_HD  = g_sMetaComm.sIMEIHeader_Option[3].strHeader;

    m_bCheckSerialNoHD   = g_sMetaComm.sSerialNoHeader_Option.bCheckHeader;
    m_strSerialNoHD  = g_sMetaComm.sSerialNoHeader_Option.strHeader;

    m_bCheckEthernetHD = g_sMetaComm.sEthernetMacHeader_Option.bCheckHeader;
    m_strEthernetHD = g_sMetaComm.sEthernetMacHeader_Option.strHeader;

    m_bCheckBarcHD   = g_sMetaComm.sBarcHeader_Option.bCheckHeader;
    m_strBarcHD      = g_sMetaComm.sBarcHeader_Option.strHeader;

    //C2K
    m_bCheckMeidHD   = g_sMetaComm.sMeidHeader_Option.bCheckHeader;
    m_strMeidHD      = g_sMetaComm.sMeidHeader_Option.strHeader;

    m_bCheckEsnHD   = g_sMetaComm.sEsnHeader_Option.bCheckHeader;
    m_strEsnHD      = g_sMetaComm.sEsnHeader_Option.strHeader;

    m_bCheckBTHD     = g_sMetaComm.sBTHeader_Option.bCheckHeader;
    m_strBTHD        = g_sMetaComm.sBTHeader_Option.strHeader;
    m_strTemp        = g_sMetaComm.sIMEIOption.Temp_Option.strTemperatureData;
    //m_strTemp.Format("%0.1f", g_sMetaComm.sIMEIOption.Temp_Option.strTemperatureData);


    m_bCheckWifiHD   = g_sMetaComm.sWifiHeader_Option.bCheckHeader;
    m_strWifiHD      = g_sMetaComm.sWifiHeader_Option.strHeader;

    m_bCheckDrmkeyMCID_HD   = g_sMetaComm.sDrmkeyMCIDHeader_Option.bCheckHeader;
    m_strDrmkeyMCID_HD      = g_sMetaComm.sDrmkeyMCIDHeader_Option.strHeader;

    //	m_bExternMDDownload   = g_sMetaComm.sBarcodeOption.bExtMdDl;

    m_bUsbEnable     = g_sMetaComm.bUsbEnable;

    m_strLogDir      = g_sMetaComm.strLogDir;

    //Synchronization to UI
    UpdateData(FALSE);

    OnWriteBarcCheck();
    OnWriteImeiCheck();
    OnWriteSerialNoCheck();
    OnWriteBtCheck();
    OnWriteWifiCheck();
    OnWriteEthernetMacCheck();
    OnWriteDrmkeyMcidCheck();
    OnWriteMeidCheck();
    OnWriteEsnCheck();
    EnableDBFileOption();
}

void CSystemConfig::CheckTempDataValid()
{
    float minTemp = 20.0;
    float maxTemp = 30.0;
    float curTemp = 0.0;
    curTemp = atof(m_strTemp);

    if(!((minTemp <= curTemp) && (curTemp <= maxTemp)))
    {
        char strMsg[100] = {0};
        sprintf(strMsg, "CurTemperature[%.1f] must be between 20.0~30.0, please input correct temperature data!", curTemp);
        MessageBox(strMsg, "Warning", MB_ICONWARNING);
        m_strTemp = "0.0";
    } 
}

void CSystemConfig::EnableDBFileOption()
{
    switch(g_sMetaComm.eTargetType)
    {
    case FEATURE_PHONE:
        GetDlgItem(IDC_DB_FROM_DUT_CHECK)->EnableWindow(FALSE);
        (CWnd*)GetDlgItem(IDC_MD_1_DBFILE_PATH)->EnableWindow(TRUE);
        (CWnd*)GetDlgItem(IDC_BTN_MD1)->EnableWindow(TRUE);
        (CWnd*)GetDlgItem(IDC_MD_2_DBFILE_PATH)->EnableWindow(FALSE);
        (CWnd*)GetDlgItem(IDC_BTN_MD2)->EnableWindow(FALSE);
        (CWnd*)GetDlgItem(IDC_AP_DBFILE_PATH)->EnableWindow(FALSE);
        (CWnd*)GetDlgItem(IDC_BTN_AP)->EnableWindow(FALSE);
        break;

    case TABLET_WIFI_ONLY:
        GetDlgItem(IDC_DB_FROM_DUT_CHECK)->EnableWindow(FALSE);
        (CWnd*)GetDlgItem(IDC_MD_1_DBFILE_PATH)->EnableWindow(FALSE);
        (CWnd*)GetDlgItem(IDC_BTN_MD1)->EnableWindow(FALSE);
        (CWnd*)GetDlgItem(IDC_MD_2_DBFILE_PATH)->EnableWindow(FALSE);
        (CWnd*)GetDlgItem(IDC_BTN_MD2)->EnableWindow(FALSE);
        (CWnd*)GetDlgItem(IDC_AP_DBFILE_PATH)->EnableWindow(TRUE);
        (CWnd*)GetDlgItem(IDC_BTN_AP)->EnableWindow(TRUE);
        break;

    case SMART_PHONE_DUALMODEM:
        GetDlgItem(IDC_DB_FROM_DUT_CHECK)->EnableWindow(FALSE);
        (CWnd*)GetDlgItem(IDC_MD_1_DBFILE_PATH)->EnableWindow(TRUE);
        (CWnd*)GetDlgItem(IDC_BTN_MD1)->EnableWindow(TRUE);
        (CWnd*)GetDlgItem(IDC_MD_2_DBFILE_PATH)->EnableWindow(TRUE);
        (CWnd*)GetDlgItem(IDC_BTN_MD2)->EnableWindow(TRUE);
        (CWnd*)GetDlgItem(IDC_AP_DBFILE_PATH)->EnableWindow(TRUE);
        (CWnd*)GetDlgItem(IDC_BTN_AP)->EnableWindow(TRUE);
        break;

    case RNDIG_DONGLE:
        GetDlgItem(IDC_DB_FROM_DUT_CHECK)->EnableWindow(FALSE);
    case SMART_PHONE:
        (CWnd*)GetDlgItem(IDC_MD_1_DBFILE_PATH)->EnableWindow(TRUE);
        (CWnd*)GetDlgItem(IDC_BTN_MD1)->EnableWindow(TRUE);
        (CWnd*)GetDlgItem(IDC_MD_2_DBFILE_PATH)->EnableWindow(FALSE);
        (CWnd*)GetDlgItem(IDC_BTN_MD2)->EnableWindow(FALSE);
        (CWnd*)GetDlgItem(IDC_AP_DBFILE_PATH)->EnableWindow(TRUE);
        (CWnd*)GetDlgItem(IDC_BTN_AP)->EnableWindow(TRUE);
        break;
    }
}

BOOL CSystemConfig::DestroyWindow() 
{
    GetUIEditData();

    if (g_sMetaComm.eTargetType == SMART_PHONE_DUALMODEM)
    {
        g_sMetaComm.sIMEIOption.bDualIMEI = true;
        g_sMetaComm.sIMEIOption.iImeiNums = DUAL_IMEI;
    }
    SaveParaToSetupFile();

    // release ToolTip Control
    if (m_pToolTip != NULL)
    {
        m_pToolTip->DestroyToolTipCtrl();
        //delete m_pToolTip; // destroy has delete it
        m_pToolTip = NULL;
    }

    return CDialog::DestroyWindow();
}

void CSystemConfig::OnBtnSave() 
{
    // TODO: Add your control notification handler code here
    CDialog::OnOK();
}

void CSystemConfig::OnCurrentTemperature() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sIMEIOption.Temp_Option.bWriteTemperature = (m_bWriteTemperature == TRUE);
    if(m_bWriteTemperature)
    {
        g_sMetaComm.sIMEIOption.Temp_Option.bWriteTemperature = true;
        ((CWnd*)GetDlgItem(IDC_TEMPERATURE))->EnableWindow(TRUE);
    }
    else
    {
        g_sMetaComm.sIMEIOption.Temp_Option.bWriteTemperature = false;
        ((CWnd*)GetDlgItem(IDC_TEMPERATURE))->EnableWindow(FALSE);
    }
}

void CSystemConfig::OnWriteEthernetMacCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sWriteOption.bWriteEthernetMac =  (m_bWriteEthernetMac == TRUE);

    ((CWnd*)GetDlgItem(IDC_ETHERNET_HEADER_CHECK))->EnableWindow(m_bWriteEthernetMac);   
    if (m_bWriteEthernetMac)
    {
        ((CWnd*)GetDlgItem(IDC_ETHERNET_HEADER_STR))->EnableWindow(m_bCheckEthernetHD);
    }
    else
    {
        ((CWnd*)GetDlgItem(IDC_ETHERNET_HEADER_STR))->EnableWindow(FALSE);
    }
}

void CSystemConfig::OnEthernetHeaderCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sEthernetMacHeader_Option.bCheckHeader = (m_bCheckEthernetHD == TRUE);
    ((CWnd*)GetDlgItem(IDC_ETHERNET_HEADER_STR))->EnableWindow(m_bCheckEthernetHD);
}

void CSystemConfig::OnWriteDrmkeyMcidCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sWriteOption.bWriteDrmkeyMCID = (m_bWriteDrmkeyMCID == TRUE);

    ((CWnd*)GetDlgItem(IDC_DRMKEY_MCID_HEADER_CHECK))->EnableWindow(m_bWriteDrmkeyMCID);   
    if (m_bWriteDrmkeyMCID)
    {
        ((CWnd*)GetDlgItem(IDC_DRMKEY_MCID_HEADER_STR))->EnableWindow(m_bCheckDrmkeyMCID_HD);
    }
    else
    {
        ((CWnd*)GetDlgItem(IDC_DRMKEY_MCID_HEADER_STR))->EnableWindow(FALSE);
    }
}

void CSystemConfig::OnDrmkeyMcidHeaderCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sDrmkeyMCIDHeader_Option.bCheckHeader = (m_bCheckDrmkeyMCID_HD == TRUE);
    ((CWnd*)GetDlgItem(IDC_DRMKEY_MCID_HEADER_STR))->EnableWindow(m_bCheckDrmkeyMCID_HD);
}

void CSystemConfig::OnWriteSerialNoCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sWriteOption.bWriteSerialNo = (m_bWriteSerialNo == TRUE);

    GetDlgItem(IDC_SERIAL_NO_HEADER_CHECK)->EnableWindow(m_bWriteSerialNo);   
    if (m_bWriteSerialNo)
    {
        GetDlgItem(IDC_SERIAL_NO_HEADER_STR)->EnableWindow(m_bCheckSerialNoHD);
        if(g_sMetaComm.SerialNumFromIMEI == true)
        {
            ((CButton *)GetDlgItem(IDC_WRITE_IMEI_CHECK))->SetCheck(TRUE);
            m_bWriteIMEI = TRUE;
            g_sMetaComm.sWriteOption.bWriteIMEI = true;
            OnWriteImeiCheck();
        }
    }
    else
    {
        GetDlgItem(IDC_SERIAL_NO_HEADER_STR)->EnableWindow(FALSE);
    }
}

void CSystemConfig::OnSerialNoHeaderCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sSerialNoHeader_Option.bCheckHeader = (m_bCheckSerialNoHD == TRUE);
    ((CWnd*)GetDlgItem(IDC_SERIAL_NO_HEADER_STR))->EnableWindow(m_bCheckSerialNoHD);
}

void CSystemConfig::OnKillfocusTemperature() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    if (m_bWriteIMEI && m_bWriteTemperature)
    {
        CheckTempDataValid();
    }   
}

void CSystemConfig::OnWriteMeidCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sWriteOption.bWriteMeid = (m_bWriteMeid == TRUE);

    ((CWnd*)GetDlgItem(IDC_MEID_HEADER_CHECK))->EnableWindow(m_bWriteMeid);
    if (m_bWriteMeid)
    {
        ((CWnd*)GetDlgItem(IDC_WRITE_ESN_CHECK))->EnableWindow(FALSE);
        g_sMetaComm.sWriteOption.bWriteEsn = FALSE;
        ((CButton *)GetDlgItem(IDC_WRITE_ESN_CHECK))->SetCheck(BST_UNCHECKED);
        ((CWnd*)GetDlgItem(IDC_MEID_HEADER_STR))->EnableWindow(m_bCheckMeidHD);
    }
    else
    {
        ((CWnd*)GetDlgItem(IDC_WRITE_ESN_CHECK))->EnableWindow(TRUE);
        ((CWnd*)GetDlgItem(IDC_MEID_HEADER_STR))->EnableWindow(FALSE);
    }

}

void CSystemConfig::OnMeidHeaderCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sMeidHeader_Option.bCheckHeader = (m_bCheckMeidHD == TRUE);
    ((CWnd*)GetDlgItem(IDC_MEID_HEADER_STR))->EnableWindow(m_bCheckMeidHD);

}

void CSystemConfig::OnEsnHeaderCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sEsnHeader_Option.bCheckHeader = (m_bCheckEsnHD == TRUE);
    ((CWnd*)GetDlgItem(IDC_ESN_HEADER_STR))->EnableWindow(m_bCheckEsnHD);
}

void CSystemConfig::OnWriteEsnCheck() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.sWriteOption.bWriteEsn = (m_bWriteEsn == TRUE);
    ((CWnd*)GetDlgItem(IDC_ESN_HEADER_CHECK))->EnableWindow(m_bWriteEsn);
    if (m_bWriteEsn)
    {
        ((CWnd*)GetDlgItem(IDC_WRITE_MEID_CHECK))->EnableWindow(FALSE);
        g_sMetaComm.sWriteOption.bWriteMeid = FALSE;
        ((CButton *)GetDlgItem(IDC_WRITE_MEID_CHECK))->SetCheck(BST_UNCHECKED);
        ((CWnd*)GetDlgItem(IDC_ESN_HEADER_STR))->EnableWindow(m_bCheckEsnHD);
    }
    else
    {
        ((CWnd*)GetDlgItem(IDC_WRITE_MEID_CHECK))->EnableWindow(TRUE);
        ((CWnd*)GetDlgItem(IDC_ESN_HEADER_STR))->EnableWindow(FALSE);
    }
}

void CSystemConfig::OnDBFromDUTCheck()
{
    // current only md1 db
    g_sMetaComm.sDBFileOption.bDBInitModem_1 = false;

    memset(g_sMetaComm.sDBFileOption.strAPDbPath_DUT, 0, sizeof(g_sMetaComm.sDBFileOption.strAPDbPath_DUT));
    memset(g_sMetaComm.sDBFileOption.strMD1DbPath_DUT, 0, sizeof(g_sMetaComm.sDBFileOption.strMD1DbPath_DUT));
}

void CSystemConfig::OnLogDir()
{
    TCHAR szFolderPath[MAX_PATH] = {0};

    BROWSEINFO sInfo;
    LPITEMIDLIST lpidlBrowse;

    memset(&sInfo, 0, sizeof(sInfo));
    sInfo.hwndOwner = GetSafeHwnd();
    sInfo.pidlRoot   = 0;
    sInfo.lpszTitle  = "Please select Log Root folder...";
    sInfo.ulFlags    = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_EDITBOX | 0x41/*BIF_NEWDIALOGSTYLE*/;
    sInfo.lpfn       = NULL;

    // popup directory browser dialog
    lpidlBrowse = ::SHBrowseForFolder(&sInfo);
    if (lpidlBrowse == NULL)
        return;

    // get folder path name
    if (::SHGetPathFromIDList(lpidlBrowse, szFolderPath) == TRUE)
    {
        ::PathAddBackslash(szFolderPath);
        m_strLogDir = szFolderPath;
        SetDlgItemText(IDC_LOG_DIR, szFolderPath);
    }

    ::CoTaskMemFree(lpidlBrowse);
}
