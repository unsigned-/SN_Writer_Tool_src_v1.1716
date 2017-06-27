// Encryption.cpp : implementation file
//

#include "stdafx.h"
#include "SN Writer.h"
#include "Encryption.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Encryption dialog
char g_cPwd[52] = {0};


Encryption::Encryption(CWnd* pParent /*=NULL*/)
	: CDialog(Encryption::IDD, pParent)
{
	//{{AFX_DATA_INIT(Encryption)
	m_strPwdData = _T("");
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Encryption::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Encryption)
	DDX_Text(pDX, IDC_PWD_DATA, m_strPwdData);
	DDV_MaxChars(pDX, m_strPwdData, 32);
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Encryption, CDialog)
	//{{AFX_MSG_MAP(Encryption)
	ON_EN_KILLFOCUS(IDC_PWD_DATA, OnKillfocusPwdData)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Encryption message handlers
void Encryption::OnCancel() 
{
	// TODO: Add extra cleanup here
	
	CDialog::OnCancel();
}

void Encryption::OnOK() 
{
	// TODO: Add extra validation here
	bool bCheckPass = false;
	// TODO: Add extra validation here
	if(strlen(m_strPwdData) >= 1)
		bCheckPass = true;
	if(! bCheckPass)
	{
		SetDlgItemText(IDC_PWD_MSG, "EMPTY INPUT !");
		SetDlgItemText(IDC_PWD_DATA, "");
		GotoDlgCtrl(GetDlgItem(IDC_PWD_DATA));
	}
	else
	{
		CDialog::OnOK();
	}
	
	//CDialog::OnOK();
}

void Encryption::OnKillfocusPwdData() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	bool bCheckPass = false;
	strncpy(g_cPwd, (LPCTSTR)m_strPwdData, strlen(m_strPwdData)+1);
	if(strlen(m_strPwdData) >= 1)
		bCheckPass = true;
	if(! bCheckPass)
	{
		SetDlgItemText(IDC_PWD_MSG, "EMPTY INPUT !");
		SetDlgItemText(IDC_PWD_DATA, "");
		GotoDlgCtrl(GetDlgItem(IDC_PWD_DATA));
	}
	
}

BOOL Encryption::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class

	if(pMsg->message == WM_KEYDOWN && pMsg->wParam==VK_RETURN)
	{
		//AfxMessageBox("hello just for test");
		//m_strPwdData += "\n";
		UpdateData(true);
		OnOK();
		return true;
	}
	
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL Encryption::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	GotoDlgCtrl(GetDlgItem(IDC_PWD_DATA));
	return FALSE;
	//return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

