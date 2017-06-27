// SN WriterDlg.cpp : implementation file
//

#include "StdAfx.h"
#include "SN Writer.h"
#include "SN WriterDlg.h"
#include "SystemConfig.h"
#include "ScanData.h"
#include "Common.h"
#include "Com_Enum.h"
#include "SNBase.h"
#include "BtnST.h"
#include "AboutSNDlg.h"
#include "ChgPasswdDlg.h"
#include "VerifyPasswdDlg.h"
#include "FileSelDlg.h"
#include "AutoGenDlg.h"
#include "HdcpEncryption.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About
#define  MAX_COMPORT_COUNT 255
unsigned short g_iTotalComPort = MAX_COMPORT_COUNT;
unsigned short g_iComportArray[MAX_COMPORT_COUNT] = {0};

const char *g_strToolVersion = "SN Writer V1.1716.00";

extern CSNWriterDlg *g_pMainDlg;

/*
class CAboutDlg : public CDialog
{
public:
CAboutDlg();

// Dialog Data
//{{AFX_DATA(CAboutDlg)
enum { IDD = IDD_ABOUTBOX };
//}}AFX_DATA

// ClassWizard generated virtual function overrides
//{{AFX_VIRTUAL(CAboutDlg)
protected:
virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//}}AFX_VIRTUAL

// Implementation
protected:
//{{AFX_MSG(CAboutDlg)
//}}AFX_MSG
DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
//{{AFX_DATA_INIT(CAboutDlg)
//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
CDialog::DoDataExchange(pDX);
//{{AFX_DATA_MAP(CAboutDlg)
//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
//{{AFX_MSG_MAP(CAboutDlg)
// No message handlers
//}}AFX_MSG_MAP
END_MESSAGE_MAP()

*/

/////////////////////////////////////////////////////////////////////////////
// CSNWriterDlg dialog

CSNWriterDlg::CSNWriterDlg(CWnd* pParent /*=NULL*/)
: CDialog(CSNWriterDlg::IDD, pParent)
{
    //{{AFX_DATA_INIT(CSNWriterDlg)
    m_strTotal = _T("");
    m_strPass = _T("");
    m_strFail = _T("");
    //}}AFX_DATA_INIT
    // Note that LoadIcon does not require a subsequent DestroyIcon in Win32
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSNWriterDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CSNWriterDlg)

    DDX_Control(pDX, IDC_COMBO_TARGET_TYPE, m_cTargetTypeBox);
    DDX_Control(pDX, IDC_COMBO_COMPORT, m_cComPortBox);
    DDX_Control(pDX, IDC_PROGRESS_SN, m_ProgressSN);
    DDX_Text(pDX, IDC_COUNT_TOTAL, m_strTotal);
    DDX_Text(pDX, IDC_COUNT_PASS, m_strPass);
    DDX_Text(pDX, IDC_COUNT_FAIL, m_strFail);
    DDX_Text(pDX,IDC_MAINUI_TEMP1,m_MainUIT1);
    //}}AFX_DATA_MAP

#ifdef _BITMAP_BTN_
    DDX_Control(pDX, IDC_BTN_INDITE, m_InditeBTN);

#else
    DDX_Control(pDX, IDC_BTN_INDITE, m_InditeBTN);
#endif

    DDX_Control(pDX, IDC_BTN_START, m_StartBTN);
    DDX_Control(pDX, IDC_BTN_QUIT, m_QuitBTN);
    DDX_Control(pDX, IDC_BTN_SYSCONFIG, m_SystemCfgBTN);


}

BEGIN_MESSAGE_MAP(CSNWriterDlg, CDialog)
    //{{AFX_MSG_MAP(CSNWriterDlg)
    ON_WM_SYSCOMMAND()
    ON_WM_PAINT()
    ON_WM_QUERYDRAGICON()
    ON_BN_CLICKED(IDC_BTN_START, OnBtnStart)
    ON_BN_CLICKED(IDC_BTN_QUIT, OnBtnQuit)
    ON_BN_CLICKED(IDC_BTN_SYSCONFIG, OnBtnSysconfig)
    ON_CBN_SELCHANGE(IDC_COMBO_COMPORT, OnSelchangeComboComport)
    ON_CBN_SELCHANGE(IDC_COMBO_TARGET_TYPE, OnSelchangeComboTargetType)
    ON_WM_CTLCOLOR()
    ON_COMMAND(IDR_ABOUT_SN, OnAboutSn)
    ON_COMMAND(IDR_ATCMD_MODE, OnAtcmdMode)
    ON_COMMAND(IDR_CHANGE_PASSWD, OnChangePasswd)
    ON_COMMAND(IDR_ENG_TO_OPERATER, OnEngToOperater)
    ON_COMMAND(IDR_FP_AUTH_FILE, OnFpAuthFile)
    ON_COMMAND(IDR_OPTION_ALREADYINMETA, OnOptionAlreadyInMeta)
    ON_COMMAND(IDR_META_MODE, OnMetaMode)
    ON_COMMAND(IDR_OPERATOR_TO_ENG, OnOperatorToEng)
    ON_COMMAND(IDR_OPTION_DRMKEY, OnOptionDrmkey)
    ON_COMMAND(IDR_OPTION_EXTMODEM, OnOptionExtmodem)
    ON_COMMAND(IDR_OPTION_HDCP, OnOptionHdcp)
    ON_COMMAND(IDR_OPTION_SECURITY_USB, OnOptionSecurityUsb)
    ON_COMMAND(IDR_OPTION_SWITCHTOOL, OnOptionSwitchtool)
    ON_COMMAND(IDR_SP_AUTH_FILE, OnSpAuthFile)
    ON_COMMAND(IDR_OPTION_HDCPDATA, OnOptionHdcpdata)
    ON_COMMAND(IDR_OPTION_USB_WITHOUT_BATTERY, OnOptionUsbWithoutBattery)
    ON_COMMAND(IDR_ENABLE_AUTOGEN, OnEnableAutogen)
    ON_COMMAND(IDR_OPTION_CHECK_CAL_FLAG, OnOptionCheckCalFlag)
    ON_COMMAND(IDR_OPTION_CHECK_FT_FLAG, OnOptionCheckFtFlag)
    ON_COMMAND(IDR_OPTION_SKIP_WRITE_PRODINFO, OnOptionSkipWriteProdinfo)
    ON_COMMAND(IDR_CHECK_BTWIFI, OnCheckBtwifi)
    ON_COMMAND(IDR_OPTION_COMPOSITE_DEVICE, OnOptionCompositeDevice)
    ON_COMMAND(IDR_BACKNV_TOPC, OnBacknvTopc)
    ON_COMMAND(IDR_OEM_LOCK, OnFastbootOemLock)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSNWriterDlg message handlers

BOOL CSNWriterDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // Add "About..." menu item to system menu.

    // IDM_ABOUTBOX must be in the system command range.
    //ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
    // ASSERT(IDM_ABOUTBOX < 0xF000);

    CMenu* pSysMenu = GetSystemMenu(FALSE);
    if (pSysMenu != NULL)
    {
        CString strAboutMenu;
        strAboutMenu.LoadString(IDS_ABOUTBOX);
        if (!strAboutMenu.IsEmpty())
        {
            pSysMenu->AppendMenu(MF_SEPARATOR);
            //pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
        }
    }

    // Set the icon for this dialog.  The framework does this automatically
    //  when the application's main window is not a dialog
    SetIcon(m_hIcon, TRUE);			// Set big icon
    SetIcon(m_hIcon, FALSE);		// Set small icon

    SetWindowText(g_strToolVersion);

    // TODO: Add extra initialization here
    //g_MainDlgHandle = (DWORD)this;

    m_SNMenu.LoadMenu(IDR_SN_MENU);
    m_hSNMenu = m_SNMenu.GetSafeHmenu();

#ifdef _LOAD_SKIN_ 
    skinppSetDrawMenu(m_hSNMenu, TRUE);
#endif

    m_font.CreatePointFont(380, "Arial");

    //m_hSNMenu = LoadMenu(AfxGetInstanceHandle(),MAKEINTRESOURCE(IDR_SN_MENU));
    ::SetMenu(this->GetSafeHwnd(),m_hSNMenu);

    m_hBitmapFail = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_FAIL));
    m_hBitmapPass = ::LoadBitmap(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDB_BITMAP_PASS));
    ((CWnd*)GetDlgItem(IDC_BTN_INDITE))->ShowWindow(SW_HIDE);

#ifdef _BITMAP_BTN_
    m_InditeBTN.SetBitmap(m_hBitmapPass);
#else
    m_InditeBTN.SetShade(CShadeButtonST::SHS_METAL);
#endif

    m_StartBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_QuitBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_SystemCfgBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);

    // Get main dialog handle
    g_pMainDlg = (CSNWriterDlg*)this;
    ParameterInit();

    return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSNWriterDlg::MenuItemInit()
{
    CMenu * pSubMenu = NULL;

    //sub menu - option
    pSubMenu = m_SNMenu.GetSubMenu(1);

    if (g_sMetaComm.bAlreadyInMeata)
    {
        pSubMenu->CheckMenuItem(IDR_OPTION_ALREADYINMETA, MF_CHECKED | MF_BYCOMMAND);
    }

    if (g_sMetaComm.eOperatorMode == META_MODE)
    {
        pSubMenu->GetSubMenu(1)->CheckMenuItem(IDR_META_MODE, MF_CHECKED | MF_BYCOMMAND);
        pSubMenu->GetSubMenu(1)->CheckMenuItem(IDR_ATCMD_MODE, MF_UNCHECKED | MF_BYCOMMAND);
    }
    else if (g_sMetaComm.eOperatorMode == AT_MODE)
    {
        pSubMenu->GetSubMenu(1)->CheckMenuItem(IDR_ATCMD_MODE, MF_CHECKED | MF_BYCOMMAND);
        pSubMenu->GetSubMenu(1)->CheckMenuItem(IDR_META_MODE, MF_UNCHECKED | MF_BYCOMMAND);
    }

    if (g_sMetaComm.bSwithTool)
    {
        g_sMetaComm.bDualTalk = false;
        pSubMenu->CheckMenuItem(IDR_OPTION_SWITCHTOOL, MF_CHECKED | MF_BYCOMMAND);
        pSubMenu->CheckMenuItem(IDR_OPTION_EXTMODEM, MF_UNCHECKED | MF_BYCOMMAND);
    }
    else if (g_sMetaComm.bDualTalk)
    {
        g_sMetaComm.bSwithTool = false;
        pSubMenu->CheckMenuItem(IDR_OPTION_EXTMODEM, MF_CHECKED | MF_BYCOMMAND);
        pSubMenu->CheckMenuItem(IDR_OPTION_SWITCHTOOL, MF_UNCHECKED | MF_BYCOMMAND);
    }

    if (g_sMetaComm.bWithoutBattery)
    {
        pSubMenu->CheckMenuItem(IDR_OPTION_USB_WITHOUT_BATTERY, MF_CHECKED | MF_BYCOMMAND);
    }

    if (g_sMetaComm.bSecurityUSB)
    {
        pSubMenu->CheckMenuItem(IDR_OPTION_SECURITY_USB, MF_CHECKED | MF_BYCOMMAND);
    }

    if (g_sMetaComm.bCheckCalFlag)
    {
        pSubMenu->GetSubMenu(6)->CheckMenuItem(IDR_OPTION_CHECK_CAL_FLAG, MF_CHECKED | MF_BYCOMMAND);
    }

    if (g_sMetaComm.bCheckFtFlag)
    {
        pSubMenu->GetSubMenu(6)->CheckMenuItem(IDR_OPTION_CHECK_FT_FLAG, MF_CHECKED | MF_BYCOMMAND);
    }

    if (g_sMetaComm.bSkipWriteProdInfo)
    {
        pSubMenu->CheckMenuItem(IDR_OPTION_SKIP_WRITE_PRODINFO , MF_CHECKED | MF_BYCOMMAND);
    }

    if (g_sMetaComm.bCompositeDeviceEnable)
    {
        pSubMenu->CheckMenuItem(IDR_OPTION_COMPOSITE_DEVICE, MF_CHECKED | MF_BYCOMMAND);
    } 
    if (g_sMetaComm.bCheckBackNVtoPC)
    {
        pSubMenu->CheckMenuItem(IDR_BACKNV_TOPC, MF_CHECKED | MF_BYCOMMAND);
    }
    if (g_sMetaComm.bCheckFastbootLock)
    {
        pSubMenu->CheckMenuItem(IDR_OEM_LOCK, MF_CHECKED | MF_BYCOMMAND);
    }

    // sub menu - Hdcp_DrmKey
    pSubMenu = m_SNMenu.GetSubMenu(2);
    if (g_sMetaComm.eTargetType == TABLET_WIFI_ONLY)
    {
        pSubMenu->EnableMenuItem(IDR_OPTION_HDCP, MF_GRAYED | MF_DISABLED | MF_BYCOMMAND);
        if (g_sMetaComm.sWriteOption.bWriteDrm)
        {
            pSubMenu->CheckMenuItem(IDR_OPTION_DRMKEY, MF_CHECKED | MF_BYCOMMAND);
        }
        pSubMenu->EnableMenuItem(IDR_OPTION_HDCPDATA, MF_GRAYED | MF_DISABLED | MF_BYCOMMAND);
    }
    else
    {
        if (g_sMetaComm.sWriteOption.bWriteHdcp)
        {
            pSubMenu->CheckMenuItem(IDR_OPTION_HDCP, MF_CHECKED | MF_BYCOMMAND);
        }
        if (g_sMetaComm.sWriteOption.bWriteDrm)
        {
            pSubMenu->CheckMenuItem(IDR_OPTION_DRMKEY, MF_CHECKED | MF_BYCOMMAND);
        }
        if (g_sMetaComm.sWriteOption.bInstallHdcpData)
        {
            pSubMenu->CheckMenuItem(IDR_OPTION_HDCPDATA, MF_CHECKED | MF_BYCOMMAND);
        }
    }

    //sub menu - identify
    pSubMenu = m_SNMenu.GetSubMenu(3);
    if (g_LoginIdentify == ENGINEER)
    {
        pSubMenu->CheckMenuItem(0, MF_CHECKED | MF_BYPOSITION);  
        pSubMenu->CheckMenuItem(1, MF_UNCHECKED | MF_BYPOSITION); 
        if (g_AutoGenData.bEnableAutoGen)
        {
            pSubMenu->GetSubMenu(0)->CheckMenuItem(IDR_ENABLE_AUTOGEN, MF_CHECKED | MF_BYCOMMAND);
        } 
        else
        {
            pSubMenu->GetSubMenu(0)->CheckMenuItem(IDR_ENABLE_AUTOGEN, MF_UNCHECKED | MF_BYCOMMAND);
        }

        if (g_sMetaComm.bCheckBTWifi)
        {
            pSubMenu->GetSubMenu(0)->CheckMenuItem(IDR_CHECK_BTWIFI, MF_CHECKED | MF_BYCOMMAND);
        } 
        else
        {
            pSubMenu->GetSubMenu(0)->CheckMenuItem(IDR_CHECK_BTWIFI, MF_UNCHECKED | MF_BYCOMMAND);
        }
    }
    else if (g_LoginIdentify == OPERATOR)
    {
        pSubMenu->CheckMenuItem(1, MF_CHECKED | MF_BYPOSITION);  
        pSubMenu->CheckMenuItem(0, MF_UNCHECKED | MF_BYPOSITION); 
    }
}

void CSNWriterDlg::ParameterInit()
{
    InitSNIni();

    MenuItemInit();

    EnableUIItem();

    SetUIItem();

}
void CSNWriterDlg::EnableStartBTN(bool bEnable)
{
    (CWnd*)GetDlgItem(IDC_BTN_START)->EnableWindow(bEnable);
}

void CSNWriterDlg::EnableUIItem()
{
    GetDlgItem(IDC_COMBO_COMPORT)->EnableWindow(TRUE);

    if (g_LoginIdentify == ENGINEER)
    {
        GetDlgItem(IDC_BTN_SYSCONFIG)->EnableWindow(TRUE);
        GetDlgItem(IDC_COMBO_TARGET_TYPE)->EnableWindow(TRUE);

        m_SNMenu.EnableMenuItem(0, MF_ENABLED | MF_BYPOSITION);
        m_SNMenu.EnableMenuItem(1, MF_ENABLED | MF_BYPOSITION);
        m_SNMenu.EnableMenuItem(2, MF_ENABLED | MF_BYPOSITION);
        m_SNMenu.EnableMenuItem(3, MF_ENABLED | MF_BYPOSITION);
        m_SNMenu.GetSubMenu(3)->EnableMenuItem(0, MF_ENABLED | MF_BYPOSITION);
        m_SNMenu.GetSubMenu(3)->EnableMenuItem(1, MF_GRAYED | MF_DISABLED | MF_BYPOSITION);
    }
    else
    {
        GetDlgItem(IDC_BTN_SYSCONFIG)->EnableWindow(FALSE);
        GetDlgItem(IDC_COMBO_TARGET_TYPE)->EnableWindow(FALSE);
        m_SNMenu.EnableMenuItem(0, MF_GRAYED | MF_DISABLED | MF_BYPOSITION);
        m_SNMenu.EnableMenuItem(1, MF_GRAYED | MF_DISABLED | MF_BYPOSITION);
        m_SNMenu.EnableMenuItem(2, MF_GRAYED | MF_DISABLED | MF_BYPOSITION);
        m_SNMenu.EnableMenuItem(3, MF_ENABLED | MF_BYPOSITION);
        m_SNMenu.GetSubMenu(3)->EnableMenuItem(0, MF_GRAYED | MF_DISABLED | MF_BYPOSITION);
        m_SNMenu.GetSubMenu(3)->EnableMenuItem(1, MF_ENABLED | MF_BYPOSITION);
    }
    GetDlgItem(IDC_MAINUI_TEMP1)->ShowWindow(FALSE);
    GetDlgItem(IDC_MAINUI_TEMP2)->ShowWindow(FALSE);

    SetDlgItemText(IDC_BTN_START, "Start");
}

void CSNWriterDlg::DisableUIItem()
{
    GetDlgItem(IDC_BTN_SYSCONFIG)->EnableWindow(FALSE);
    GetDlgItem(IDC_COMBO_TARGET_TYPE)->EnableWindow(FALSE);
    GetDlgItem(IDC_COMBO_COMPORT)->EnableWindow(FALSE);
    m_SNMenu.EnableMenuItem( 0, MF_GRAYED | MF_DISABLED | MF_BYPOSITION ); 
    m_SNMenu.EnableMenuItem( 1, MF_GRAYED | MF_DISABLED | MF_BYPOSITION ); 
    m_SNMenu.EnableMenuItem( 2, MF_GRAYED | MF_DISABLED | MF_BYPOSITION );
    m_SNMenu.EnableMenuItem(3, MF_GRAYED | MF_DISABLED | MF_BYPOSITION);
    m_SNMenu.GetSubMenu(3)->EnableMenuItem(0, MF_GRAYED | MF_DISABLED | MF_BYPOSITION);
    m_SNMenu.GetSubMenu(3)->EnableMenuItem(1, MF_GRAYED | MF_DISABLED | MF_BYPOSITION);

    SetDlgItemText(IDC_BTN_START, "Stop");
}

void CSNWriterDlg::PopupMsgBox(const char* strTilte, UINT uType, const char* strMsg, ...)
{
    char szBuf[256] = "";

    va_list varg;
    va_start(varg, strMsg);
    vsprintf(szBuf, strMsg, varg);
    va_end(varg);
    MessageBox(strMsg, strTilte, uType);
}

void CSNWriterDlg::GetIndicatorPos(CRect &rect)
{
    ((CWnd*)GetDlgItem(IDC_BTN_INDITE))->GetWindowRect(&rect);
}

void CSNWriterDlg::UpdateOperateResult(WriteNvram_Status_e eWriteStatus)
{
#ifdef _BITMAP_BTN_
    switch (eWriteStatus)
    {
    case FAIL:
        ((CWnd*)GetDlgItem(IDC_BTN_INDITE))->ShowWindow(SW_SHOW);
        m_InditeBTN.SetBitmap(m_hBitmapFail);
        break;

    case PASS:
        ((CWnd*)GetDlgItem(IDC_BTN_INDITE))->ShowWindow(SW_SHOW);
        m_InditeBTN.SetBitmap(m_hBitmapPass);
        break;

    case NORMAL:
        ((CWnd*)GetDlgItem(IDC_BTN_INDITE))->ShowWindow(SW_HIDE);
        break;

    case CANCEL:       
    default:
        //Do nothing
        break;
    }
#endif
}

void CSNWriterDlg::GetUIItem()
{
    OnSelchangeComboComport();
    OnSelchangeComboTargetType();
}

void CSNWriterDlg::SwitchToEngineer()
{
    g_LoginIdentify = ENGINEER;   
    SaveLoginIdentify(ENGINEER);
    EnableUIItem();
}

void CSNWriterDlg::SwitchToOperator()
{
    g_LoginIdentify = OPERATOR;
    SaveLoginIdentify(OPERATOR);
    EnableUIItem();
}

void CSNWriterDlg::GetComPortDynamiclly()
{
    char DestString[10]; 
    int i = 0, result = 0;

    result = ComPortEnumerate(g_iComportArray, &g_iTotalComPort);
    if(result != COM_ENUM_OK)
    {
        if( result == COM_ENUM_NO_COM_PORT_FOUND)                            // find no COM port, some NB will have no COM.
        {
            g_iTotalComPort = 0;
        }
        /*
        else
        {
        MessageBox("FAIL","Get Com Port Fail");
        m_cComPortBox.InsertString(0, "USB VCOM");
        m_cComPortBox.SetCurSel(0);
        return;
        }
        */
    }

    if(g_iTotalComPort < 1 || g_iTotalComPort >= MAX_COMPORT_COUNT)
    {
        m_cComPortBox.InsertString(0, "USB VCOM");
    }
    else
    {       
        for(i = 0; i < g_iTotalComPort; i++)	// show all com port got dynamiclly
        {	           
            sprintf(DestString,"COM%d",g_iComportArray[g_iTotalComPort - i - 1]);
            m_cComPortBox.InsertString(0, DestString);
        }

        m_cComPortBox.InsertString(0, "USB VCOM");
    }

    m_cComPortBox.SetCurSel(0);

}

void CSNWriterDlg::SetUIItem()
{
    GetComPortDynamiclly();

    m_cTargetTypeBox.InsertString(FEATURE_PHONE, "Feature Phone");
    m_cTargetTypeBox.InsertString(SMART_PHONE, "Smart Phone");
    m_cTargetTypeBox.InsertString(SMART_PHONE_DUALMODEM, "SP DualModem");
    m_cTargetTypeBox.InsertString(TABLET_WIFI_ONLY, "Tablet Wifi Only");
    m_cTargetTypeBox.InsertString(RNDIG_DONGLE, "Rndis Dongle");
    m_cTargetTypeBox.SetCurSel(g_sMetaComm.eTargetType);
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSNWriterDlg::OnPaint() 
{
    if (IsIconic())
    {
        CPaintDC dc(this); // device context for painting

        SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

        // Center icon in client rectangle
        int cxIcon = GetSystemMetrics(SM_CXICON);
        int cyIcon = GetSystemMetrics(SM_CYICON);
        CRect rect;
        GetClientRect(&rect);
        int x = (rect.Width() - cxIcon + 1) / 2;
        int y = (rect.Height() - cyIcon + 1) / 2;

        // Draw the icon
        dc.DrawIcon(x, y, m_hIcon);
    }
    else
    {
        CDialog::OnPaint();
    }
}

void CSNWriterDlg::ShowTemperatureOnUI()
{
    GetDlgItem(IDC_MAINUI_TEMP1)->ShowWindow(true);
    GetDlgItem(IDC_MAINUI_TEMP2)->ShowWindow(true);

    m_MainUIT1.Format("%s", g_sMetaComm.sIMEIOption.Temp_Option.strTemperatureData);
    GetDlgItem(IDC_MAINUI_TEMP1)->SetWindowText(m_MainUIT1);

    GetDlgItem(IDC_MAINUI_TEMP1)->SetFont(&m_font);
    GetDlgItem(IDC_MAINUI_TEMP2)->SetFont(&m_font);
    //m_font.DeleteObject(); 
}


// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSNWriterDlg::OnQueryDragIcon()
{
    return (HCURSOR) m_hIcon;
}

void CSNWriterDlg::OnBtnStart() 
{
    // TODO: Add your control notification handler code here
    OnSelchangeComboTargetType();
    OnSelchangeComboComport();
    E_TARGET_TYPE eTargetType = GetTargetType();

    CString strText;
    ((CWnd*)GetDlgItem(IDC_BTN_START))->GetWindowText(strText);

    if (strText == "Start")
    {                     
        if (eTargetType == FEATURE_PHONE)
        {
            m_fpSN.SNThread_Start();
        } 
        else
        {
            m_spSN.SNThread_Start();
        }
    }  
    else if(strText == "Stop")
    {
        if (eTargetType == FEATURE_PHONE)
        {
            m_fpSN.SNThread_Stop();
        } 
        else
        {
            m_spSN.SNThread_Stop();
        }  

        EnableUIItem();
    }    
}

void CSNWriterDlg::OnBtnQuit() 
{
    // TODO: Add your control notification handler code here
    CDialog::OnCancel();
}

BOOL CSNWriterDlg::PreTranslateMessage(MSG* pMsg) 
{
    // TODO: Add your specialized code here and/or call the base class
    if ( pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE )
    {
        return TRUE;
    }
    return CDialog::PreTranslateMessage(pMsg);
}

BOOL CSNWriterDlg::DestroyWindow() 
{
    // TODO: Add your specialized code here and/or call the base class

    SaveParaToSetupFile();
    AuthHandle_DeInit();

    return CDialog::DestroyWindow();
}

void CSNWriterDlg::OnBtnSysconfig() 
{
    // TODO: Add your control notification handler code here
    CSystemConfig dlg;
    dlg.DoModal();
}

void CSNWriterDlg::OnSelchangeComboComport() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);

    CString strComport;  
    m_cComPortBox.GetWindowText(strComport);
    if(strComport.Find("USB", 0) != -1)
    {
        g_sMetaComm.bUsbEnable = true;
        g_sMetaComm.iCOMPort = 0;
    }
    else
    {
        char *pStr = (LPSTR)(LPCTSTR)strComport;
        g_sMetaComm.bUsbEnable = false;
        pStr += 3; 
        g_sMetaComm.iCOMPort = atoi(pStr);
    }   
}

void CSNWriterDlg::OnSelchangeComboTargetType() 
{
    // TODO: Add your control notification handler code here
    UpdateData(TRUE);
    g_sMetaComm.eTargetType =(E_TARGET_TYPE)m_cTargetTypeBox.GetCurSel();

    if (g_sMetaComm.eTargetType == RNDIG_DONGLE)
    {
        g_sMetaComm.bSwithTool = true;
        g_sMetaComm.bDualTalk = false;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_SWITCHTOOL, MF_CHECKED | MF_BYCOMMAND);   //USB SwithTool option
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_EXTMODEM, MF_UNCHECKED | MF_BYCOMMAND);   //Extern modem option
    }

    if (g_sMetaComm.eTargetType != FEATURE_PHONE && g_sMetaComm.eTargetType != RNDIG_DONGLE)
    {
        g_sMetaComm.bSwithTool = false;
        g_sMetaComm.bWithoutBattery = false;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_USB_WITHOUT_BATTERY, MF_UNCHECKED | MF_BYCOMMAND); //USB without battery
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_SWITCHTOOL, MF_UNCHECKED | MF_BYCOMMAND);          //USB SwithTool
    }

    if(g_sMetaComm.eTargetType == TABLET_WIFI_ONLY)
    {
        g_sMetaComm.sWriteOption.bWriteHdcp = false;
        g_sMetaComm.sWriteOption.bInstallHdcpData = false;
        m_SNMenu.GetSubMenu(2)->EnableMenuItem(IDR_OPTION_HDCP, MF_GRAYED | MF_DISABLED | MF_BYCOMMAND);
        m_SNMenu.GetSubMenu(2)->EnableMenuItem(IDR_OPTION_HDCPDATA, MF_GRAYED | MF_DISABLED | MF_BYCOMMAND);
        m_SNMenu.GetSubMenu(2)->CheckMenuItem(IDR_OPTION_HDCP, MF_UNCHECKED);
        m_SNMenu.GetSubMenu(2)->CheckMenuItem(IDR_OPTION_HDCPDATA, MF_UNCHECKED);
    }
    else
    {
        m_SNMenu.GetSubMenu(2)->EnableMenuItem(IDR_OPTION_HDCP, MF_ENABLED | MF_BYCOMMAND);
        m_SNMenu.GetSubMenu(2)->EnableMenuItem(IDR_OPTION_HDCPDATA, MF_ENABLED | MF_BYCOMMAND);
    }
}

HBRUSH CSNWriterDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
    HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);

    // TODO: Change any attributes of the DC here   
    if((IDC_MAINUI_TEMP1 == pWnd->GetDlgCtrlID())||(IDC_MAINUI_TEMP2 == pWnd->GetDlgCtrlID()))
    {
        pDC->SetTextColor(RGB(255,0,0));           
    }

    // TODO: Return a different brush if the default is not desired
    return hbr;
}

void CSNWriterDlg::OnAboutSn() 
{
    // TODO: Add your command handler code here
    CAboutSNDlg dlg;
    dlg.DoModal();
}

void CSNWriterDlg::OnChangePasswd() 
{
    // TODO: Add your command handler code here
    CChgPasswdDlg dlg;
    dlg.DoModal();
}

void CSNWriterDlg::OnEngToOperater() 
{
    // TODO: Add your command handler code here
    SwitchToOperator();   
}

void CSNWriterDlg::OnOperatorToEng() 
{
    // TODO: Add your command handler code here
    CVerifyPasswdDlg dlg;
    if(IDOK == dlg.DoModal())
    {
        SwitchToEngineer();
    }
}

void CSNWriterDlg::OnOptionAlreadyInMeta() 
{
    if (g_sMetaComm.bAlreadyInMeata)
    {
        g_sMetaComm.bAlreadyInMeata = false;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_ALREADYINMETA, MF_UNCHECKED | MF_BYCOMMAND);
    } 
    else
    {
        g_sMetaComm.bAlreadyInMeata = true;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_ALREADYINMETA, MF_CHECKED | MF_BYCOMMAND);
    }
}

void CSNWriterDlg::OnMetaMode() 
{
    // TODO: Add your command handler code here
    g_sMetaComm.eOperatorMode = META_MODE;
    m_SNMenu.GetSubMenu(1)->GetSubMenu(1)->CheckMenuItem(IDR_META_MODE, MF_CHECKED | MF_BYCOMMAND);
    m_SNMenu.GetSubMenu(1)->GetSubMenu(1)->CheckMenuItem(IDR_ATCMD_MODE, MF_UNCHECKED | MF_BYCOMMAND);
}

void CSNWriterDlg::OnAtcmdMode() 
{
    // TODO: Add your command handler code here

    //Current only support meta mode
    g_sMetaComm.eOperatorMode = META_MODE;
    m_SNMenu.GetSubMenu(1)->GetSubMenu(1)->CheckMenuItem(IDR_META_MODE, MF_CHECKED | MF_BYCOMMAND);
    m_SNMenu.GetSubMenu(1)->GetSubMenu(1)->CheckMenuItem(IDR_ATCMD_MODE, MF_UNCHECKED | MF_BYCOMMAND);

    MessageBox("Current only support meta mode!", "Warning", MB_ICONWARNING);

    /*
    g_sMetaComm.eOperatorMode = AT_MODE;
    m_SNMenu.GetSubMenu(1)->GetSubMenu(1)->CheckMenuItem(0, MF_UNCHECKED | MF_BYPOSITION);
    m_SNMenu.GetSubMenu(1)->GetSubMenu(1)->CheckMenuItem(1, MF_CHECKED | MF_BYPOSITION);
    */
}

void CSNWriterDlg::OnOptionExtmodem() 
{
    // TODO: Add your command handler code here
    if (g_sMetaComm.bDualTalk)
    {
        g_sMetaComm.bDualTalk = false;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_EXTMODEM, MF_UNCHECKED | MF_BYCOMMAND);
    }
    else
    {
        g_sMetaComm.bSwithTool = false;
        g_sMetaComm.bDualTalk = true;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_EXTMODEM, MF_CHECKED | MF_BYCOMMAND);
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_SWITCHTOOL, MF_UNCHECKED | MF_BYCOMMAND);
    }   
}

void CSNWriterDlg::OnOptionSwitchtool() 
{
    // TODO: Add your command handler code here
    if (g_sMetaComm.bSwithTool)
    {
        g_sMetaComm.bSwithTool = false;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_SWITCHTOOL, MF_UNCHECKED | MF_BYCOMMAND);
    }
    else
    {
        g_sMetaComm.bSwithTool = true;
        g_sMetaComm.bDualTalk = false;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_SWITCHTOOL, MF_CHECKED | MF_BYCOMMAND);
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_EXTMODEM, MF_UNCHECKED | MF_BYCOMMAND);
    }
}

void CSNWriterDlg::OnOptionSecurityUsb() 
{
    // TODO: Add your command handler code here
    if (g_sMetaComm.bSecurityUSB)
    {
        g_sMetaComm.bSecurityUSB = false;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_SECURITY_USB, MF_UNCHECKED | MF_BYCOMMAND);
    }
    else
    {
        g_sMetaComm.bSecurityUSB = true;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_SECURITY_USB, MF_CHECKED | MF_BYCOMMAND);
    }
}


void CSNWriterDlg::OnOptionUsbWithoutBattery() 
{
    // TODO: Add your command handler code here
    if (g_sMetaComm.bWithoutBattery)
    {
        g_sMetaComm.bWithoutBattery = false;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_USB_WITHOUT_BATTERY, MF_UNCHECKED | MF_BYCOMMAND);
    }
    else
    {
        g_sMetaComm.bWithoutBattery = true;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_USB_WITHOUT_BATTERY, MF_CHECKED | MF_BYCOMMAND);
    }
}

void CSNWriterDlg::OnOptionCheckCalFlag() 
{
    // TODO: Add your command handler code here
    if(g_sMetaComm.bCheckCalFlag)
    {
        g_sMetaComm.bCheckCalFlag = false;
        m_SNMenu.GetSubMenu(1)->GetSubMenu(6)->CheckMenuItem(IDR_OPTION_CHECK_CAL_FLAG, MF_UNCHECKED | MF_BYCOMMAND);
    }
    else
    {
        g_sMetaComm.bCheckCalFlag = true;
        m_SNMenu.GetSubMenu(1)->GetSubMenu(6)->CheckMenuItem(IDR_OPTION_CHECK_CAL_FLAG, MF_CHECKED | MF_BYCOMMAND);
    }

}

void CSNWriterDlg::OnOptionCheckFtFlag() 
{
    // TODO: Add your command handler code here
    if(g_sMetaComm.bCheckFtFlag)
    {
        g_sMetaComm.bCheckFtFlag = false;
        m_SNMenu.GetSubMenu(1)->GetSubMenu(6)->CheckMenuItem(IDR_OPTION_CHECK_FT_FLAG, MF_UNCHECKED | MF_BYCOMMAND);
    }
    else
    {
        g_sMetaComm.bCheckFtFlag = true;
        m_SNMenu.GetSubMenu(1)->GetSubMenu(6)->CheckMenuItem(IDR_OPTION_CHECK_FT_FLAG, MF_CHECKED | MF_BYCOMMAND);
    }
}

void CSNWriterDlg::OnOptionSkipWriteProdinfo() 
{
    // TODO: Add your command handler code here
    if (g_sMetaComm.bSkipWriteProdInfo)
    {
        g_sMetaComm.bSkipWriteProdInfo = false;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_SKIP_WRITE_PRODINFO, MF_UNCHECKED | MF_BYCOMMAND);
    } 
    else
    {
        g_sMetaComm.bSkipWriteProdInfo = true;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_SKIP_WRITE_PRODINFO, MF_CHECKED | MF_BYCOMMAND);
    }
}


void CSNWriterDlg::OnSpAuthFile() 
{
    // TODO: Add your command handler code here
    CFileSelDlg dlg;
    dlg.SetLoadFileType(LOAD_SP_AUTH_FILE);
    if (IDOK == dlg.DoModal())
    {
        g_sMetaComm.bSecurityUSB = true;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_SECURITY_USB, MF_CHECKED | MF_BYCOMMAND);  
    }
}

void CSNWriterDlg::OnFpAuthFile() 
{
    // TODO: Add your command handler code here
    CFileSelDlg dlg;
    dlg.SetLoadFileType(LOAD_FP_AUTH_FILE);
    if (IDOK == dlg.DoModal())
    {              
        g_sMetaComm.bSecurityUSB = true;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_SECURITY_USB, MF_CHECKED | MF_BYCOMMAND);              
    }
}

void CSNWriterDlg::OnOptionHdcp() 
{
    // TODO: Add your command handler code here
    if (g_sMetaComm.sWriteOption.bWriteHdcp)
    {
        g_sMetaComm.sWriteOption.bWriteHdcp = false;
        m_SNMenu.GetSubMenu(2)->CheckMenuItem(IDR_OPTION_HDCP, MF_UNCHECKED | MF_BYCOMMAND);
    }
    else
    {
        CFileSelDlg dlg;
        dlg.SetLoadFileType(LOAD_HDCP_BIN_FILE);
        if (IDOK == dlg.DoModal())
        {
            g_sMetaComm.sWriteOption.bWriteHdcp = true;
            m_SNMenu.GetSubMenu(2)->CheckMenuItem(IDR_OPTION_HDCP, MF_CHECKED | MF_BYCOMMAND);
        }        
    }
}

void CSNWriterDlg::OnOptionDrmkey() 
{
    // TODO: Add your command handler code here
    if (g_sMetaComm.sWriteOption.bWriteDrm)
    {
        g_sMetaComm.sWriteOption.bWriteDrm = false;
        m_SNMenu.GetSubMenu(2)->CheckMenuItem(IDR_OPTION_DRMKEY, MF_UNCHECKED | MF_BYCOMMAND);
    }
    else
    {
        CFileSelDlg dlg;
        dlg.SetLoadFileType(LOAD_DRMKEY_FILE);
        if (IDOK == dlg.DoModal())
        {
            g_sMetaComm.sWriteOption.bWriteDrm = true;
            m_SNMenu.GetSubMenu(2)->CheckMenuItem(IDR_OPTION_DRMKEY, MF_CHECKED | MF_BYCOMMAND);
        }        
    }   
}

void CSNWriterDlg::OnOptionHdcpdata() 
{
    // TODO: Add your command handler code here
    if (g_sMetaComm.sWriteOption.bInstallHdcpData)
    {
        g_sMetaComm.sWriteOption.bInstallHdcpData = false;
        m_SNMenu.GetSubMenu(2)->CheckMenuItem(IDR_OPTION_HDCPDATA, MF_UNCHECKED | MF_BYCOMMAND);
    }
    else
    {
        CFileSelDlg dlg;
        dlg.SetLoadFileType(LOAD_HDCP_DATA_FILE);
        if (IDOK == dlg.DoModal())
        {
            g_sMetaComm.sWriteOption.bInstallHdcpData = true;
            m_SNMenu.GetSubMenu(2)->CheckMenuItem(IDR_OPTION_HDCPDATA, MF_CHECKED | MF_BYCOMMAND);
        }        
    }  
}

void CSNWriterDlg::OnEnableAutogen() 
{
    // TODO: Add your command handler code here
    CAutoGenDlg dlg;
    dlg.DoModal();
    if (g_AutoGenData.bEnableAutoGen)
    {
        m_SNMenu.GetSubMenu(3)->GetSubMenu(0)->CheckMenuItem(IDR_ENABLE_AUTOGEN, MF_CHECKED | MF_BYCOMMAND);
    } 
    else
    {
        m_SNMenu.GetSubMenu(3)->GetSubMenu(0)->CheckMenuItem(IDR_ENABLE_AUTOGEN, MF_UNCHECKED | MF_BYCOMMAND);
    }
}

void CSNWriterDlg::OnCheckBtwifi() 
{
    // TODO: Add your command handler code here
    if (g_sMetaComm.bCheckBTWifi)
    {
        g_sMetaComm.bCheckBTWifi = false;
        m_SNMenu.GetSubMenu(3)->GetSubMenu(0)->CheckMenuItem(IDR_CHECK_BTWIFI, MF_UNCHECKED | MF_BYCOMMAND);
    } 
    else
    {
        g_sMetaComm.bCheckBTWifi = true;
        m_SNMenu.GetSubMenu(3)->GetSubMenu(0)->CheckMenuItem(IDR_CHECK_BTWIFI, MF_CHECKED | MF_BYCOMMAND);
    }

}

void CSNWriterDlg::OnOptionCompositeDevice() 
{
    // TODO: Add your command handler code here
    if (g_sMetaComm.bCompositeDeviceEnable)
    {
        g_sMetaComm.bCompositeDeviceEnable = false;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_COMPOSITE_DEVICE, MF_UNCHECKED | MF_BYCOMMAND);
    } 
    else
    {
        g_sMetaComm.bCompositeDeviceEnable = true;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OPTION_COMPOSITE_DEVICE, MF_CHECKED | MF_BYCOMMAND);
    }
}

void CSNWriterDlg::OnBacknvTopc() 
{
    // TODO: Add your command handler code here
    if (g_sMetaComm.bCheckBackNVtoPC)
    {
        g_sMetaComm.bCheckBackNVtoPC = false;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_BACKNV_TOPC, MF_UNCHECKED | MF_BYCOMMAND);
    } 
    else
    {
        g_sMetaComm.bCheckBackNVtoPC = true;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_BACKNV_TOPC, MF_CHECKED | MF_BYCOMMAND);
    }

}

void CSNWriterDlg::OnFastbootOemLock() 
{
    // TODO: Add your command handler code here
    if (g_sMetaComm.bCheckFastbootLock)
    {
        g_sMetaComm.bCheckFastbootLock = false;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OEM_LOCK, MF_UNCHECKED | MF_BYCOMMAND);
    } 
    else
    {
        g_sMetaComm.bCheckFastbootLock = true;
        m_SNMenu.GetSubMenu(1)->CheckMenuItem(IDR_OEM_LOCK, MF_CHECKED | MF_BYCOMMAND);
    }

}
