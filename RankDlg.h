#if !defined(AFX_RANKDLG_H__7FF8EC9C_9028_4E23_924F_9FB91E3D324A__INCLUDED_)
#define AFX_RANKDLG_H__7FF8EC9C_9028_4E23_924F_9FB91E3D324A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RankDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRankDlg dialog

class CRankDlg : public CDialog
{
// Construction
public:
	CRankDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRankDlg)
	enum { IDD = IDD_DLG_RANK };
	CString	m_rank1;
	CString	m_rank2;
	CString	m_rank3;
	CString	m_rank4;
	CString	m_rank5;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRankDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
//	CString score[5];
	// Generated message map functions
	//{{AFX_MSG(CRankDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RANKDLG_H__7FF8EC9C_9028_4E23_924F_9FB91E3D324A__INCLUDED_)
