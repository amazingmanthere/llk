// GameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "llk.h"
#include "GameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CGameDlg dialog


CGameDlg::CGameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGameDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CGameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGameDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CGameDlg, CDialog)
	//{{AFX_MSG_MAP(CGameDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGameDlg message handlers
