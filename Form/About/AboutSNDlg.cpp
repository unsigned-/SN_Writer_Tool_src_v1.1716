// AboutSNDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SN Writer.h"
#include "AboutSNDlg.h"
#include "SNBase.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutSNDlg dialog

CAboutSNDlg::CAboutSNDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAboutSNDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAboutSNDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CAboutSNDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutSNDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAboutSNDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutSNDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAboutSNDlg message handlers

BOOL CAboutSNDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
    // SN Writer Version
    const char *p_version;
    CString strVersion;
    CString toolVersion = g_strToolVersion;
    ((CWnd*)GetDlgItem(IDC_SN_VERSION))->SetWindowText(toolVersion);

    // SPBootMode.dll Version
    // Can't Get Directly

    // META_DLL.dll Version
	META_GetDLLInfo(&p_version, NULL, NULL, NULL);
    strVersion = p_version;
    ((CWnd*)GetDlgItem(IDC_METADLL_VERSION))->SetWindowText(strVersion);

    // SP_META_DLL.dll Version
    SPMETA_DLL::SP_META_GetDLLInfo(&p_version, NULL, NULL, NULL);
    strVersion = p_version;
    ((CWnd*)GetDlgItem(IDC_SPMETADLL_VERSION))->SetWindowText(strVersion);

    // return TRUE unless you set the focus to a control
    // EXCEPTION: OCX Property Pages should return FALSE
	return TRUE;
}
