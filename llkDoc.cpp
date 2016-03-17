// llkDoc.cpp : implementation of the CLlkDoc class
//

#include "stdafx.h"
#include "llk.h"

#include "llkDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLlkDoc

IMPLEMENT_DYNCREATE(CLlkDoc, CDocument)

BEGIN_MESSAGE_MAP(CLlkDoc, CDocument)
	//{{AFX_MSG_MAP(CLlkDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLlkDoc construction/destruction

CLlkDoc::CLlkDoc()
{
	// TODO: add one-time construction code here

}

CLlkDoc::~CLlkDoc()
{
}

BOOL CLlkDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CLlkDoc serialization

void CLlkDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CLlkDoc diagnostics

#ifdef _DEBUG
void CLlkDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CLlkDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLlkDoc commands
