#if !defined(AFX_SETTINGDLG_H__D66715DA_AFF0_4D88_A1B3_C5A421BDCB38__INCLUDED_)
#define AFX_SETTINGDLG_H__D66715DA_AFF0_4D88_A1B3_C5A421BDCB38__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// SettingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CSettingDlg dialog

class CMusicDlg : public CDialog
{
// Construction
public:
	CMusicDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSettingDlg)
	enum { IDD = IDD_DLG_SETTING_MUSIC };
	CString	m_FileName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSettingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSettingDlg)
	afx_msg void OnBtnOpen();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETTINGDLG_H__D66715DA_AFF0_4D88_A1B3_C5A421BDCB38__INCLUDED_)
