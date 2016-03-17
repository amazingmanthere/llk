// llkDoc.h : interface of the CLlkDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LLKDOC_H__5E5FEE1B_408C_490E_9B50_030780D4A7CD__INCLUDED_)
#define AFX_LLKDOC_H__5E5FEE1B_408C_490E_9B50_030780D4A7CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLlkDoc : public CDocument
{
protected: // create from serialization only
	CLlkDoc();
	DECLARE_DYNCREATE(CLlkDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLlkDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CLlkDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLlkDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LLKDOC_H__5E5FEE1B_408C_490E_9B50_030780D4A7CD__INCLUDED_)
