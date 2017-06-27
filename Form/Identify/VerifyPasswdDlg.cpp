// VerifyPasswdDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SN Writer.h"
#include "VerifyPasswdDlg.h"
#include "des.h"
#include "Common.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVerifyPasswdDlg dialog


CVerifyPasswdDlg::CVerifyPasswdDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVerifyPasswdDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVerifyPasswdDlg)
	m_strOldPasswd = _T("");
	//}}AFX_DATA_INIT
}


void CVerifyPasswdDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVerifyPasswdDlg)
	DDX_Text(pDX, IDC_EDIT_VERIFY_PASSWD, m_strOldPasswd);
	DDV_MaxChars(pDX, m_strOldPasswd, 64);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVerifyPasswdDlg, CDialog)
	//{{AFX_MSG_MAP(CVerifyPasswdDlg)
	ON_BN_CLICKED(ID_BTN_VERIFY_OK, OnBtnVerifyOk)
	ON_BN_CLICKED(ID_BTN_VERIFY_CANCEL, OnBtnVerifyCancel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVerifyPasswdDlg message handlers

bool CVerifyPasswdDlg::IsVerifyPasswdPass()
{
    UpdateData(TRUE);
    
    BYTE key[10]="03055030";    
    BYTE strPassword[LOGIN_PASSWORD_MAX] = {0};
    BYTE *pOldPasswd = strPassword;
    Login_Identify_e Identify = UNKNOW_IDENTIFY;
    
    if(ReadDataFromFile(strPassword, LOGIN_PASSWORD_MAX, key, g_pPasswdFilepath) == S_DES_SUCCESS)
    {
        CString tmpStr;
        pOldPasswd += 2;
        tmpStr.Format(_T("%s"), pOldPasswd);
        if (tmpStr != m_strOldPasswd)
        {
            m_strOldPasswd = "";
            UpdateData(FALSE);
            MessageBox("Incorrect old password, please try again!", "Warning", MB_ICONWARNING);
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}

void CVerifyPasswdDlg::OnBtnVerifyOk() 
{
	// TODO: Add your control notification handler code here
	if(IsVerifyPasswdPass())
    {
        CDialog::OnOK();
    }
    else
    {
        SetDlgItemText(IDC_EDIT_VERIFY_PASSWD, "");
        GotoDlgCtrl(GetDlgItem(IDC_EDIT_VERIFY_PASSWD));
    }
}

void CVerifyPasswdDlg::OnBtnVerifyCancel() 
{
	// TODO: Add your control notification handler code here
    CDialog::OnCancel();
}

BOOL CVerifyPasswdDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
    if (pMsg->message == WM_KEYDOWN && pMsg->wParam ==VK_ESCAPE)
    {
        return true;
    }

	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CVerifyPasswdDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
    GotoDlgCtrl(GetDlgItem(IDC_EDIT_VERIFY_PASSWD));
    return FALSE;
	//return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
