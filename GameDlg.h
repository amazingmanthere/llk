#if !defined(AFX_GAMEDLG_H__5DCF5CAD_5E0C_4E1F_8A53_7C3A1CAF1115__INCLUDED_)
#define AFX_GAMEDLG_H__5DCF5CAD_5E0C_4E1F_8A53_7C3A1CAF1115__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGameDlg dialog

class CGameDlg : public CDialog
{
// Construction
public:
	CGameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGameDlg)
	enum { IDD = IDD_DLG_SETTING_GAME };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGameDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMEDLG_H__5DCF5CAD_5E0C_4E1F_8A53_7C3A1CAF1115__INCLUDED_)
