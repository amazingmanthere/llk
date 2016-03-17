// RankDlg.cpp : implementation file
//

#include "stdafx.h"
#include "llk.h"
#include "RankDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRankDlg dialog


CRankDlg::CRankDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRankDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRankDlg)
	m_rank1 = _T("");
	m_rank2 = _T("");
	m_rank3 = _T("");
	m_rank4 = _T("");
	m_rank5 = _T("");
	//}}AFX_DATA_INIT
}


void CRankDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRankDlg)
	DDX_Text(pDX, IDC_RANK1, m_rank1);
	DDX_Text(pDX, IDC_RANK2, m_rank2);
	DDX_Text(pDX, IDC_RANK3, m_rank3);
	DDX_Text(pDX, IDC_RANK4, m_rank4);
	DDX_Text(pDX, IDC_RANK5, m_rank5);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRankDlg, CDialog)
	//{{AFX_MSG_MAP(CRankDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRankDlg message handlers

BOOL CRankDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	GetPrivateProfileString("rank","1",      
		"0",m_rank1.GetBuffer(MAX_PATH),			
		MAX_PATH,"llk.ini");
	GetPrivateProfileString("rank","2",      
		"0",m_rank2.GetBuffer(MAX_PATH),			
		MAX_PATH,"llk.ini");
	GetPrivateProfileString("rank","3",      
		"0",m_rank3.GetBuffer(MAX_PATH),			
		MAX_PATH,"llk.ini");
	GetPrivateProfileString("rank","4",      
		"0",m_rank4.GetBuffer(MAX_PATH),			
		MAX_PATH,"llk.ini");
	GetPrivateProfileString("rank","5",      
		"0",m_rank5.GetBuffer(MAX_PATH),			
		MAX_PATH,"llk.ini");
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
