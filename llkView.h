// llkView.h : interface of the CLlkView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LLKVIEW_H__4D2B8951_E232_4A17_B2C9_F8245469C4C1__INCLUDED_)
#define AFX_LLKVIEW_H__4D2B8951_E232_4A17_B2C9_F8245469C4C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>

#define BMP_WIDTH 44    //ͼƬ���
#define BMP_HEIGHT 54	//ͼƬ����
#define BMP_ROWS 10     //��Ϸ��ͼͼƬ����  
#define BMP_COLS 12     //��Ϸ��ͼͼƬ����
struct BMP
{
	int index;          
	int row;     //����
 	int col;     //����
	bool IsSelect;
	bool exit;
};
struct SelBmp
{
	int SelRow;  //��ѡ��ͼƬ������
	int SelCol;  //��ѡ��ͼƬ������
	bool flag;    //��־�Ƿ���ѡ�е�ͼƬ
};



void ThreadFunc(LPARAM lParam);

class CLlkView : public CView
{
protected: // create from serialization only
	CLlkView();
	DECLARE_DYNCREATE(CLlkView)

// Attributes
public:
	CLlkDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLlkView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void StopMusic();
//	void MusicOperation();
	void PlayMusic();
	    
	bool IsSolution();
	void OnTip();
	void Rearrange();
	void IsSuccess();
	void ClearCDC();
	void DrawProgressCtrl();
	void InitGame();
	void SortPlace();
	void BmpBiblt( );
	bool IsConnection(int NowX, int NowY, int OldX, int OldY);
	bool VerticalConnection(int NowX, int NowY, int OldX, int OldY);
	bool HorizontalConnection(int NowX, int NowY, int OldX, int OldY);
	bool OneWinding(int NowX, int NowY, int OldX, int OldY);
	bool TwoWinding(int NowX, int NowY, int OldX, int OldY);
	virtual ~CLlkView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DWORD m_count;
	BOOL IsGameStrart;    //��ʶ��Ϸ�Ƿ�ʼ
	CBitmap BmpSel;   //��ѡ�е�ͼƬ
	CBitmap BmpNor;    //������ʾ��ͼƬ
	CBitmap BmpBK;     //
	CDC* mdc;           //˫���壬�����ڴ滭ͼ
//	CDC* ndc;       //˫���壬�����ڴ��ͼ
	CRect GameRect;   //��Ϸ��Χ
	CRect InfoRect;  //����Ϸ��Χ
	int BmpNum;    //��ϷͼƬ��������ֻ����ż��������ÿһ�Զ���ƥ�䵽
//	CArray<BMP,BMP> m_abmp;  //�洢ͼƬ����Ϣ
	BMP **bmp;      //�洢ͼƬ����Ϣ
	SelBmp SBmp;     //�洢ѡ��ͼƬ����Ϣ
	CRect ProgressRect;   //������
	int Upper;//���������ߵĳ���
//	CArray<POINT,POINT> m_way;//���ڱ�����������ĵ����Ϣ�����㻭��
	COleDateTime m_GameTime;
	int SecAll;       //����ʱ������
	int second;        //����ʱʣ������
	int speed;        //�������ٶ�
	HANDLE hThread;
	DWORD ThreadID;
	int score;        //����
//	DWORD tNow;       
//	DWORD tPre;
	bool sound;       //��־��Ч 
	bool music;       //��־����
	int TipCount;       //��ʾ����
	int RearrangeCount;   //���д���
	
//{{AFX_MSG(CLlkView)
	afx_msg void OnGameStart();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnVoice();
	afx_msg void OnRank();
	afx_msg void OnUpdateVoice(CCmdUI* pCmdUI);
	afx_msg void OnMusic();
	afx_msg void OnUpdateMusic(CCmdUI* pCmdUI);
	afx_msg void OnSetting();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

#ifndef _DEBUG  // debug version in llkView.cpp
inline CLlkDoc* CLlkView::GetDocument()
   { return (CLlkDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LLKVIEW_H__4D2B8951_E232_4A17_B2C9_F8245469C4C1__INCLUDED_)
