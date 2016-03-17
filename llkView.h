// llkView.h : interface of the CLlkView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LLKVIEW_H__4D2B8951_E232_4A17_B2C9_F8245469C4C1__INCLUDED_)
#define AFX_LLKVIEW_H__4D2B8951_E232_4A17_B2C9_F8245469C4C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <afxtempl.h>

#define BMP_WIDTH 44    //图片宽度
#define BMP_HEIGHT 54	//图片长度
#define BMP_ROWS 10     //游戏地图图片行数  
#define BMP_COLS 12     //游戏地图图片列数
struct BMP
{
	int index;          
	int row;     //行数
 	int col;     //列数
	bool IsSelect;
	bool exit;
};
struct SelBmp
{
	int SelRow;  //被选中图片的行数
	int SelCol;  //被选中图片的列数
	bool flag;    //标志是否有选中的图片
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
	BOOL IsGameStrart;    //标识游戏是否开始
	CBitmap BmpSel;   //被选中的图片
	CBitmap BmpNor;    //正常显示的图片
	CBitmap BmpBK;     //
	CDC* mdc;           //双缓冲，用于内存画图
//	CDC* ndc;       //双缓冲，用于内存存图
	CRect GameRect;   //游戏范围
	CRect InfoRect;  //非游戏范围
	int BmpNum;    //游戏图片的总数，只能是偶数，这样每一对都能匹配到
//	CArray<BMP,BMP> m_abmp;  //存储图片的信息
	BMP **bmp;      //存储图片的信息
	SelBmp SBmp;     //存储选中图片的信息
	CRect ProgressRect;   //进度条
	int Upper;//进度条已走的长度
//	CArray<POINT,POINT> m_way;//用于保存可以想消的点的信息，方便画线
	COleDateTime m_GameTime;
	int SecAll;       //倒计时总秒数
	int second;        //倒计时剩余秒数
	int speed;        //进度条速度
	HANDLE hThread;
	DWORD ThreadID;
	int score;        //分数
//	DWORD tNow;       
//	DWORD tPre;
	bool sound;       //标志音效 
	bool music;       //标志声音
	int TipCount;       //提示次数
	int RearrangeCount;   //重列次数
	
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
