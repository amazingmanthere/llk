// SettingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "llk.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg dialog


CMusicDlg::CMusicDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMusicDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSettingDlg)
	m_FileName = _T("");
	//}}AFX_DATA_INIT
}


void CMusicDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSettingDlg)
	DDX_CBString(pDX, IDC_FILE, m_FileName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMusicDlg, CDialog)
	//{{AFX_MSG_MAP(CSettingDlg)
	ON_BN_CLICKED(IDC_BTN_OPEN, OnBtnOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg message handlers

void CMusicDlg::OnBtnOpen() 
{
	// TODO: Add your control notification handler code here
	CFileDialog dlg(TRUE);
	if (IDOK==dlg.DoModal())
	{
		m_FileName=dlg.GetPathName();
	}
	UpdateData(false);
}

BOOL CMusicDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	
	GetPrivateProfileString("music","path","",m_FileName.GetBuffer(MAX_PATH),			
		MAX_PATH,"llk.ini");
	m_FileName.ReleaseBuffer();
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
