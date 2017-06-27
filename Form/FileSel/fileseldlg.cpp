// FileSelDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SN Writer.h"
#include "FileSelDlg.h"
#include "Common.h"
#include "xboot_debug.h"
#include "SLA.h"
#include "AUTH.h"
#include "SCERT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileSelDlg dialog


CFileSelDlg::CFileSelDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileSelDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFileSelDlg)
	m_strDRMKeyPath = _T("");
	m_strFPAuthPath = _T("");
	m_strHdcpBinPath = _T("");
	m_strHdcpCekPath = _T("");
	m_strHdcpDataPath = _T("");
	m_strSPAuthPath = _T("");
	//}}AFX_DATA_INIT

    m_eFileType = UNKOWN_FILETYPE;
}


void CFileSelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFileSelDlg)
	DDX_Text(pDX, IDC_DRMKEY_FIEL_PATH, m_strDRMKeyPath);
	DDV_MaxChars(pDX, m_strDRMKeyPath, 260);
	DDX_Text(pDX, IDC_FP_AUTH_FIEL_PATH, m_strFPAuthPath);
	DDV_MaxChars(pDX, m_strFPAuthPath, 260);
	DDX_Text(pDX, IDC_HDCP_BIN_FIEL_PATH, m_strHdcpBinPath);
	DDV_MaxChars(pDX, m_strHdcpBinPath, 260);
	DDX_Text(pDX, IDC_HDCP_CEK_FIEL_PATH, m_strHdcpCekPath);
	DDV_MaxChars(pDX, m_strHdcpCekPath, 260);
	DDX_Text(pDX, IDC_HDCP_DATA_FIEL_PATH, m_strHdcpDataPath);
	DDV_MaxChars(pDX, m_strHdcpDataPath, 260);
	DDX_Text(pDX, IDC_SP_AUTH_FIEL_PATH, m_strSPAuthPath);
	DDV_MaxChars(pDX, m_strSPAuthPath, 260);
	//}}AFX_DATA_MAP

    DDX_Control(pDX, IDC_BTN_SEL_FP_AUTH_FILE, m_LoadFPAuthBTN);
    DDX_Control(pDX, IDC_BTN_SEL_SP_AUTH_FILE, m_LoadSPAuthBTN);
    DDX_Control(pDX, IDC_BTN_SEL_HDCP_BIN_FILE, m_LoadHdcpBinBTN);
    DDX_Control(pDX, IDC_BTN_SEL_DRMKEY_FILE, m_LoadDRMKeyBTN);
    DDX_Control(pDX, IDC_BTN_SEL_HDCP_DATAFILE, m_LoadHdcpDataBTN);
    DDX_Control(pDX, IDC_BTN_SEL_HDCP_CEK_FILE, m_LoadHdcpCekBTN);
    DDX_Control(pDX, IDC_BTN_FILE_SEL_OK, m_LoadOKBTN);
    DDX_Control(pDX, IDC_BTN_FILE_SEL_CANCEL, m_LoadCancelBTN);

}


BEGIN_MESSAGE_MAP(CFileSelDlg, CDialog)
	//{{AFX_MSG_MAP(CFileSelDlg)
	ON_BN_CLICKED(IDC_BTN_FILE_SEL_CANCEL, OnBtnFileSelCancel)
	ON_BN_CLICKED(IDC_BTN_FILE_SEL_OK, OnBtnFileSelOk)
	ON_BN_CLICKED(IDC_BTN_SEL_DRMKEY_FILE, OnBtnSelDrmkeyFile)
	ON_BN_CLICKED(IDC_BTN_SEL_FP_AUTH_FILE, OnBtnSelFpAuthFile)
	ON_BN_CLICKED(IDC_BTN_SEL_HDCP_BIN_FILE, OnBtnSelHdcpBinFile)
	ON_BN_CLICKED(IDC_BTN_SEL_HDCP_CEK_FILE, OnBtnSelHdcpCekFile)
	ON_BN_CLICKED(IDC_BTN_SEL_HDCP_DATAFILE, OnBtnSelHdcpDatafile)
	ON_BN_CLICKED(IDC_BTN_SEL_SP_AUTH_FILE, OnBtnSelSpAuthFile)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileSelDlg message handlers

BOOL CFileSelDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    // TODO: Add extra initialization here
    m_LoadFPAuthBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_LoadSPAuthBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_LoadHdcpBinBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_LoadDRMKeyBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_LoadHdcpDataBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_LoadHdcpCekBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_LoadOKBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);
    m_LoadCancelBTN.SetShade(CShadeButtonST::SHS_SOFTBUMP);

    EnableUIItemByFileType(m_eFileType);

    return TRUE;  // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
}

void CFileSelDlg::EnableUIItemByFileType(const LoadFile_Type_e eFileType)
{
    m_strFPAuthPath   = g_sMetaComm.sLoadFile.strFPAuthPath;
    m_strSPAuthPath   = g_sMetaComm.sLoadFile.strSPAuthPath;
    m_strHdcpBinPath  = g_sMetaComm.sLoadFile.strHdcpBinPath;
    m_strDRMKeyPath   = g_sMetaComm.sLoadFile.strDrmKeyPath;
    m_strHdcpDataPath = g_sMetaComm.sLoadFile.strHdcpDataPath;
    m_strHdcpCekPath  = g_sMetaComm.sLoadFile.strHdcpCekPath;

    GetDlgItem(IDC_BTN_SEL_FP_AUTH_FILE)->EnableWindow(FALSE);
    GetDlgItem(IDC_FP_AUTH_FIEL_PATH)->EnableWindow(FALSE);

    GetDlgItem(IDC_BTN_SEL_SP_AUTH_FILE)->EnableWindow(FALSE);
    GetDlgItem(IDC_SP_AUTH_FIEL_PATH)->EnableWindow(FALSE);

    GetDlgItem(IDC_BTN_SEL_HDCP_BIN_FILE)->EnableWindow(FALSE);
    GetDlgItem(IDC_HDCP_BIN_FIEL_PATH)->EnableWindow(FALSE);

    GetDlgItem(IDC_BTN_SEL_DRMKEY_FILE)->EnableWindow(FALSE);
    GetDlgItem(IDC_DRMKEY_FIEL_PATH)->EnableWindow(FALSE);

    GetDlgItem(IDC_BTN_SEL_HDCP_DATAFILE)->EnableWindow(FALSE);
    GetDlgItem(IDC_HDCP_DATA_FIEL_PATH)->EnableWindow(FALSE);

    GetDlgItem(IDC_BTN_SEL_HDCP_CEK_FILE)->EnableWindow(FALSE);
    GetDlgItem(IDC_HDCP_CEK_FIEL_PATH)->EnableWindow(FALSE);

    switch(eFileType)
    {
    case LOAD_FP_AUTH_FILE:
        GetDlgItem(IDC_BTN_SEL_FP_AUTH_FILE)->EnableWindow(TRUE);
        GetDlgItem(IDC_FP_AUTH_FIEL_PATH)->EnableWindow(TRUE);
        break;

    case LOAD_SP_AUTH_FILE:
        GetDlgItem(IDC_BTN_SEL_SP_AUTH_FILE)->EnableWindow(TRUE);
        GetDlgItem(IDC_SP_AUTH_FIEL_PATH)->EnableWindow(TRUE);
        break;

    case LOAD_HDCP_BIN_FILE:
        GetDlgItem(IDC_BTN_SEL_HDCP_BIN_FILE)->EnableWindow(TRUE);
        GetDlgItem(IDC_HDCP_BIN_FIEL_PATH)->EnableWindow(TRUE);
        break;

    case LOAD_DRMKEY_FILE:
        GetDlgItem(IDC_BTN_SEL_DRMKEY_FILE)->EnableWindow(TRUE);
        GetDlgItem(IDC_DRMKEY_FIEL_PATH)->EnableWindow(TRUE);
        break;

    case LOAD_HDCP_DATA_FILE:
    case LOAD_HDCP_CEK_FILE:
        GetDlgItem(IDC_BTN_SEL_HDCP_DATAFILE)->EnableWindow(TRUE);
        GetDlgItem(IDC_HDCP_DATA_FIEL_PATH)->EnableWindow(TRUE);
        GetDlgItem(IDC_BTN_SEL_HDCP_CEK_FILE)->EnableWindow(TRUE);
        GetDlgItem(IDC_HDCP_CEK_FIEL_PATH)->EnableWindow(TRUE);
        break;

    default:
        break;
    }

    UpdateData(FALSE);
}

void CFileSelDlg::SetLoadFileType(const LoadFile_Type_e eFileType)
{
    m_eFileType = eFileType;
}

void CFileSelDlg::OnBtnFileSelCancel()
{
	// TODO: Add your control notification handler code here
    CDialog::OnCancel();
}

void CFileSelDlg::OnBtnFileSelOk()
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);

    strncpy(g_sMetaComm.sLoadFile.strFPAuthPath, (LPCTSTR)m_strFPAuthPath, strlen(m_strFPAuthPath)+1);
    strncpy(g_sMetaComm.sLoadFile.strSPAuthPath, (LPCTSTR)m_strSPAuthPath, strlen(m_strSPAuthPath)+1);
    strncpy(g_sMetaComm.sLoadFile.strHdcpBinPath, (LPCTSTR)m_strHdcpBinPath, strlen(m_strHdcpBinPath)+1);
    strncpy(g_sMetaComm.sLoadFile.strDrmKeyPath, (LPCTSTR)m_strDRMKeyPath, strlen(m_strDRMKeyPath)+1);
    strncpy(g_sMetaComm.sLoadFile.strHdcpDataPath, (LPCTSTR)m_strHdcpDataPath, strlen(m_strHdcpDataPath)+1);
    strncpy(g_sMetaComm.sLoadFile.strHdcpCekPath, (LPCTSTR)m_strHdcpCekPath, strlen(m_strHdcpCekPath)+1);

    if (m_eFileType == LOAD_FP_AUTH_FILE)
    {
        if(AuthInit(m_strFPAuthPath))
        {
            MTRACE(g_hEBOOT_DEBUG, "Init auth file success, auth path = %s", m_strFPAuthPath);
        }
        else
        {
            MTRACE_ERR(g_hEBOOT_DEBUG, "Init auth file fail, auth path = %s", m_strFPAuthPath);
        }
    }
    else if (m_eFileType == LOAD_SP_AUTH_FILE)
    {
        if (SPAuthInit(m_strSPAuthPath))
        {
            MTRACE(g_hEBOOT_DEBUG, "Init SP auth file success, auth path = %s", m_strSPAuthPath);
        }
        else
        {
            MTRACE_ERR(g_hEBOOT_DEBUG, "Init SP auth file fail, auth path = %s", m_strSPAuthPath);
        }
    }

	CDialog::OnOK();
}

void CFileSelDlg::OnBtnSelFpAuthFile()
{
	// TODO: Add your control notification handler code here
    char szFilter[]="Auth files(*.auth)|*.auth|All File(*.*)|*.*||";

    CFileDialog dlg(TRUE, NULL, NULL,
		OFN_FILEMUSTEXIST|OFN_EXPLORER|OFN_ENABLESIZING|0x10000000/*OFN_FORCESHOWHIDDEN*/,
		szFilter, this);
    dlg.m_ofn.lpstrTitle = _T("Select FP Auth file...");
    if (IDOK == dlg.DoModal())
    {
        m_strFPAuthPath = dlg.GetPathName();
        UpdateData(FALSE);
    }
}

void CFileSelDlg::OnBtnSelSpAuthFile()
{
    // TODO: Add your control notification handler code here
    char szFilter[]="Auth files(*.auth)|*.auth|All File(*.*)|*.*||";

    CFileDialog dlg(TRUE, NULL, NULL,
		OFN_FILEMUSTEXIST|OFN_EXPLORER|OFN_ENABLESIZING|0x10000000/*OFN_FORCESHOWHIDDEN*/,
		szFilter, this);
    dlg.m_ofn.lpstrTitle = _T("Select SP Auth file...");
    if (IDOK == dlg.DoModal())
    {
        m_strSPAuthPath = dlg.GetPathName();
        UpdateData(FALSE);
    }
}

void CFileSelDlg::OnBtnSelHdcpBinFile()
{
	// TODO: Add your control notification handler code here

    CHAR szFolderPath[MAX_PATH] = {0};
    CString strFolderPath = "";

    BROWSEINFO sInfo;
    ::ZeroMemory(&sInfo, sizeof(BROWSEINFO));
    sInfo.pidlRoot   = 0;
    sInfo.lpszTitle  = "Please select Hdcp Bin folder...";
    sInfo.ulFlags    = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_EDITBOX | 0x41/*BIF_NEWDIALOGSTYLE*/;
    sInfo.lpfn       = NULL;

    LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo);
    if (lpidlBrowse != NULL)
    {
        if (::SHGetPathFromIDList(lpidlBrowse, szFolderPath) == TRUE)
        {
            strFolderPath = szFolderPath;
        }
        ::CoTaskMemFree(lpidlBrowse);
    }

    m_strHdcpBinPath = strFolderPath;
    UpdateData(FALSE);

    /*
    char szFilter[]="Hdcp Bin files(*.*)|*.*";
    CFileDialog dlg(TRUE, NULL, NULL, NULL,szFilter);
    dlg.m_ofn.lpstrTitle = _T("Select Hdcp bin file...");
    if (IDOK == dlg.DoModal())
    {
        m_strHdcpBinPath = dlg.GetPathName();
        UpdateData(FALSE);
    }
    */
}

void CFileSelDlg::OnBtnSelDrmkeyFile()
{
    // TODO: Add your control notification handler code here

    CHAR          szFolderPath[MAX_PATH] = {0};
    CString       strFolderPath = "";

    BROWSEINFO      sInfo;
    ::ZeroMemory(&sInfo, sizeof(BROWSEINFO));
    sInfo.pidlRoot   = 0;
    sInfo.lpszTitle  = "Please select DRM key folder...";
    sInfo.ulFlags    = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_EDITBOX | 0x41/*BIF_NEWDIALOGSTYLE*/;
    sInfo.lpfn       = NULL;

    LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo);
    if (lpidlBrowse != NULL)
    {
        if (::SHGetPathFromIDList(lpidlBrowse, szFolderPath) == TRUE)
        {
            strFolderPath = szFolderPath;
        }
        ::CoTaskMemFree(lpidlBrowse);
    }

    m_strDRMKeyPath = strFolderPath;
    UpdateData(FALSE);

    /*
    char szFilter[]="DRMkey files(*.*)|*.*";

    CFileDialog dlg(TRUE, NULL, NULL, NULL,szFilter);
    dlg.m_ofn.lpstrTitle = _T("Select DRMKey file...");
    if (IDOK == dlg.DoModal())
    {
        m_strDRMKeyPath = dlg.GetPathName();
        UpdateData(FALSE);
    }
    */
}

void CFileSelDlg::OnBtnSelHdcpCekFile()
{
	// TODO: Add your control notification handler code here
    char szFilter[]="Hdcp cek files(*.*)|*.*||";

    CFileDialog dlg(TRUE, NULL, NULL,
		OFN_FILEMUSTEXIST|OFN_EXPLORER|OFN_ENABLESIZING|0x10000000/*OFN_FORCESHOWHIDDEN*/,
		szFilter, this);
    dlg.m_ofn.lpstrTitle = _T("Select Hdcp cek file...");
    if (IDOK == dlg.DoModal())
    {
        m_strHdcpCekPath = dlg.GetPathName();
        UpdateData(FALSE);
    }
}

void CFileSelDlg::OnBtnSelHdcpDatafile()
{
	// TODO: Add your control notification handler code here
    char szFilter[]="Hdcp Data files(*.*)|*.*||";

    CFileDialog dlg(TRUE, NULL, NULL,
		OFN_FILEMUSTEXIST|OFN_EXPLORER|OFN_ENABLESIZING|0x10000000/*OFN_FORCESHOWHIDDEN*/,
		szFilter, this);
    dlg.m_ofn.lpstrTitle = _T("Select Hdcp install data file...");
    if (IDOK == dlg.DoModal())
    {
        m_strHdcpDataPath = dlg.GetPathName();
        UpdateData(FALSE);
    }
}

BOOL CFileSelDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
    if ( pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE )
    {
        return TRUE;
    }

	return CDialog::PreTranslateMessage(pMsg);
}
