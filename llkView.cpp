// llkView.cpp : implementation of the CLlkView class
//

#include "stdafx.h"
#include "llk.h"

#include "llkDoc.h"
#include "llkView.h"

#include "RankDlg.h"
#include "Mmsystem.h"
#include "SettingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLlkView

IMPLEMENT_DYNCREATE(CLlkView, CView)

BEGIN_MESSAGE_MAP(CLlkView, CView)
	//{{AFX_MSG_MAP(CLlkView)
	ON_COMMAND(IDM_GAME_START, OnGameStart)
	ON_WM_ERASEBKGND()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
	ON_COMMAND(IDM_VOICE, OnVoice)
	ON_COMMAND(IDM_RANK, OnRank)
	ON_UPDATE_COMMAND_UI(IDM_VOICE, OnUpdateVoice)
	ON_COMMAND(IDM_MUSIC, OnMusic)
	ON_UPDATE_COMMAND_UI(IDM_MUSIC, OnUpdateMusic)
	ON_COMMAND(IDM_SETTING, OnSetting)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLlkView construction/destruction
CArray<POINT,POINT> m_way;//用于保存可以想消的点的信息，方便画线
//volatile int HitCount;
//volatile DWORD tPre,tNow;
CLlkView::CLlkView()
{
	// TODO: add construction code here
	IsGameStrart = false;
	BmpNor.LoadBitmap(IDB_BMP_NORMAL);
	BmpSel.LoadBitmap(IDB_BMP_SELECT);
	BmpBK.LoadBitmap(IDB_BMP_BACKGROUND);
	mdc=new CDC();
	mdc->CreateCompatibleDC(NULL);
//	ndc=new CDC();
//	ndc->CreateCompatibleDC(NULL);
	BmpNum = 100;
//	Upper=0;
	bmp=NULL;
	GameRect.SetRect(50,100,523,595);
	InfoRect.SetRect(50,20,523,100);
	ProgressRect.SetRect(100,50,473,70);
	SBmp.flag=false;
	sound=true;
	music=true;

}

CLlkView::~CLlkView()
{
	delete mdc;
}

BOOL CLlkView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CLlkView drawing

void CLlkView::OnDraw(CDC* pDC)
{
	CLlkDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	ClearCDC();  //对内存DC进行清理
//	if (IsGameStrart)
//	{
		DrawProgressCtrl();   //绘制进度条
		BmpBiblt();
//		if (IsGameStrart)
//		{
//			if (IsSuccess())
//			{
		IsSuccess();
//				IsGameStrart=false;
//				KillTimer(1);
//				MessageBox("游戏成功");
				
				
//			}
//		}

//	}
	CRect rect;
	GetClientRect(rect);

	pDC->BitBlt(0,0,rect.Width(),rect.Height(),mdc,0,0,SRCCOPY);
}

/////////////////////////////////////////////////////////////////////////////
// CLlkView printing

BOOL CLlkView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CLlkView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CLlkView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CLlkView diagnostics

#ifdef _DEBUG
void CLlkView::AssertValid() const
{
	CView::AssertValid();
}

void CLlkView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CLlkDoc* CLlkView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CLlkDoc)));
	return (CLlkDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CLlkView message handlers

void CLlkView::OnGameStart() 
{
	// TODO: Add your command handler code here
	IsGameStrart = true;

	if (sound)
	{
		PlaySound(MAKEINTRESOURCE(IDR_WAVE_START),
				  AfxGetInstanceHandle(),SND_ASYNC|SND_RESOURCE);
	}
	if(music)
		PlayMusic();
	InitGame();
	SetTimer(1,1000,NULL);
	CRect rect;
	GetClientRect(rect);
	InvalidateRect(rect);
}

BOOL CLlkView::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	return true;	
//	return CView::OnEraseBkgnd(pDC);
}


void CLlkView::BmpBiblt( )
{
//	CBitmap* OldBmp;
	if (bmp!=NULL)
	{
		CRect rect;
		GetClientRect(rect);
		CDC* pDC=GetDC();
		CDC ndc;
		ndc.CreateCompatibleDC(pDC);
		ndc.SelectObject(&BmpSel);
		for (int i=0;i<BMP_ROWS;i++)
		{
			for (int j=0;j<BMP_COLS;j++)
				if (bmp[i][j].exit)
				{
					if (bmp[i][j].IsSelect)
					{
						ndc.SelectObject(&BmpSel);
						mdc->BitBlt(GameRect.left+bmp[i][j].col*(BMP_WIDTH-5),
							GameRect.top+bmp[i][j].row*(BMP_HEIGHT-5),
							BMP_WIDTH,BMP_HEIGHT,&ndc,
							BMP_WIDTH*bmp[i][j].index,0,SRCCOPY);
					}
					else
					{
						ndc.SelectObject(&BmpNor);
						mdc->BitBlt(GameRect.left+bmp[i][j].col*(BMP_WIDTH-5),
							GameRect.top+bmp[i][j].row*(BMP_HEIGHT-5),
							BMP_WIDTH,BMP_HEIGHT,&ndc,
							BMP_WIDTH*bmp[i][j].index,0,SRCCOPY);
					}
				}
		}
	}
	
}

void CLlkView::SortPlace()
{
	
}

void CLlkView::InitGame()
{
	int i,j;
	bmp=(BMP **)malloc(sizeof(BMP*)*BMP_ROWS); 
	for(i=0;i<BMP_COLS;i++)   
        bmp[i]=(BMP*)malloc(sizeof(BMP)*BMP_COLS);

	for(i=0;i<BMP_ROWS;i++)
	{
		for(j=0;j<BMP_COLS;j++)
		{
			bmp[i][j].exit=false;
			bmp[i][j].IsSelect=false;
			bmp[i][j].row=i;
			bmp[i][j].col=j;
		}
	}
	int index,num;
	num=0; //已匹配的数量
	bool flag;  
	srand(time(0));
	while(BmpNum>num) //当匹配到的数量小于所要的数量时
	{
		i=rand()%BMP_ROWS;
		j=rand()%BMP_COLS;
		flag=true;
		if (!bmp[i][j].exit)
		{
			bmp[i][j].exit=true;
			bmp[i][j].index=rand()%15;
			index=bmp[i][j].index;
			
			while(flag)
			{
				i=rand()%BMP_ROWS;
				j=rand()%BMP_COLS;
				if (!bmp[i][j].exit)
				{
					bmp[i][j].exit=true;
					bmp[i][j].index=index;
					bmp[i][j].row=i;
					bmp[i][j].col=j;
					flag=false;
				}
			}
			num+=2;   //匹配到的数量加上2，表示匹配到一对
		}
	}


	m_GameTime.SetTime(0,2,0);
	second=SecAll=m_GameTime.GetMinute()*60+m_GameTime.GetSecond();
	score=0;
	Upper=0;
	TipCount=3;
	RearrangeCount=3;
	
//	speed=ProgressRect.Width()/second;
}

void CLlkView::DrawProgressCtrl()
{
	if (bmp!=NULL)
	{
		mdc->Rectangle(ProgressRect);   //绘制进度条的矩形
		CRect rect;//已走过的进度条矩形
		rect.SetRect(ProgressRect.left,ProgressRect.top,
			ProgressRect.left+Upper,ProgressRect.bottom);  
		CBrush brush(RGB(255,0,0));
		CBrush* OldBrush=mdc->SelectObject(&brush);
		mdc->Rectangle(rect);
		mdc->SelectObject(OldBrush);
		brush.DeleteObject();
		
//		CFont font;
//		font.CreatePointFont(150,"方正彩云简体");
//		CFont* OldFont=mdc->SelectObject(&font);
		mdc->SetBkMode(TRANSPARENT);
		mdc->SetTextColor(RGB(255,255,0));
		mdc->TextOut(InfoRect.left,50,"倒计时");
//		mdc->SelectObject(OldFont);
//		font.DeleteObject();
		
		CString m_time=m_GameTime.Format("%M:%S");
		mdc->TextOut(ProgressRect.right+10,50,m_time);
		//	int second=m_GameTime.GetMinute()*60+m_GameTime.GetSecond();
		m_GameTime.SetTime(0,second/60,second%60);

		CString temp;
		temp.Format("当前分数：%d",score);
//		mdc->TextOut(InfoRect.left,InfoRect.top,temp);
		mdc->DrawText(temp,InfoRect,DT_LEFT|DT_SINGLELINE|DT_TOP);

		temp.Format("可用提示：%d",TipCount);
		mdc->DrawText(temp,InfoRect,DT_CENTER|DT_SINGLELINE|DT_TOP);

		temp.Format("可用重列：%d",RearrangeCount);
		mdc->DrawText(temp,InfoRect,DT_RIGHT|DT_SINGLELINE|DT_TOP);
	}
	
}

void CLlkView::ClearCDC()
{
	
	CDC* pDC=GetDC();
	CRect rect;
	GetClientRect(rect);
	CBitmap bitmap;   //创建画布
	bitmap.CreateCompatibleBitmap(pDC,rect.Width(),rect.Height());
	mdc->SelectObject(bitmap);
	CBrush brush(RGB(100,100,200));
	mdc->FillRect(rect,&brush);
	brush.DeleteObject();

//	CBrush* bru=CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
//	CBrush* OldBrush=mdc->SelectObject(bru);
//	mdc->Rectangle(GameRect);
//	mdc->SelectObject(OldBrush);
//	bru->DeleteObject();
	if (bmp!=NULL)
	{
		CDC ndc;
		ndc.CreateCompatibleDC(pDC);
		ndc.SelectObject(&BmpBK);
		mdc->BitBlt(GameRect.left,GameRect.top,GameRect.Width(),GameRect.Height(),
		&ndc,0,0,SRCCOPY);
	}
	
}

void CLlkView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (GameRect.PtInRect(point)&&IsGameStrart)
	{
		//获取鼠标在图片信息数组的位置
		int NowX,NowY;
		NowX=(point.y-GameRect.top)/(BMP_HEIGHT-5);
		NowY=(point.x-GameRect.left)/(BMP_WIDTH-5);
		//判断是否该位置有图片存在
		if (bmp[NowX][NowY].exit)
		{
			//判断是否先前有图片被选中
			if (SBmp.flag)
			{
				//如果当前的图片与先前的图片能够连通
				if (IsConnection(NowX,NowY,SBmp.SelRow,SBmp.SelCol))
				{
					if (sound)
					{
						PlaySound(MAKEINTRESOURCE(IDR_WAVE_OK),
								AfxGetInstanceHandle(),SND_ASYNC|SND_RESOURCE);
					}
					
					//两张图片相消
					bmp[NowX][NowY].exit=false;
					bmp[SBmp.SelRow][SBmp.SelCol].exit=false;
					//之前选中的标志置为false
					SBmp.flag=false;
					//启动线程画线
					hThread=CreateThread(NULL,
						0,
						(LPTHREAD_START_ROUTINE)ThreadFunc,
						&score,
						0,
				&ThreadID);
					
//					SetTimer(2,0,NULL);
				}
				//如果不能连通
				else
				{
					if (sound)
					{
						PlaySound(MAKEINTRESOURCE(IDR_WAVE_NO),
							AfxGetInstanceHandle(),SND_ASYNC|SND_RESOURCE);
					}
					
					bmp[NowX][NowY].IsSelect=false;
					bmp[SBmp.SelRow][SBmp.SelCol].IsSelect=false;
					SBmp.flag=false;

				/*	//如果点到的图片就是先前的图片
					if (SBmp.SelRow==NowX&&SBmp.SelCol==NowY)
					{
						//先前和当前图片的选中标志都置为false
						SBmp.flag=false;
						bmp[NowX][NowY].IsSelect=false;
					}
					//如果不是
					else
					{
						//先前选中的图片的选中标志置为false,
						//当前选中的图片的选中标志置为true
						bmp[NowX][NowY].IsSelect=true;
						bmp[SBmp.SelRow][SBmp.SelCol].IsSelect=false;
						SBmp.SelRow=NowX;
						SBmp.SelCol=NowY;
					}*/
				
				}
					
			}
			//如果先前没有图片被选中
			else
			{
				if (sound)
				{
					PlaySound(MAKEINTRESOURCE(IDR_WAVE_PUT),
						AfxGetInstanceHandle(),SND_ASYNC|SND_RESOURCE);
				}
				//置当前的图片为选中状态，
				//同时把当前的图片存进SelBmp结构中,作为下次先前的图片
				bmp[NowX][NowY].IsSelect=true;
				SBmp.flag=true;
				SBmp.SelRow=NowX;
				SBmp.SelCol=NowY;
			}
			
		}
		InvalidateRect(GameRect);
		
		
	}
	CView::OnLButtonDown(nFlags, point);
}


bool CLlkView::IsConnection(int NowX, int NowY, int OldX, int OldY)
{
	//判断两张图片是否一样或者是不是同一点
	if(bmp[NowX][NowY].index!=bmp[OldX][OldY].index||
		(NowX==OldX&&NowY==OldY))
		return false;
	else
	{
		if(VerticalConnection(NowX,NowY,OldX,OldY))
		{
			m_way.Add(CPoint(NowX,NowY));
			m_way.Add(CPoint(OldX,OldY));
			return true;
			
		}
			
		if(HorizontalConnection(NowX,NowY,OldX,OldY))
		{
			m_way.Add(CPoint(NowX,NowY));
			m_way.Add(CPoint(OldX,OldY));
			return true;
		}
		if(OneWinding(NowX,NowY,OldX,OldY))
			return true;
		if(TwoWinding(NowX,NowY,OldX,OldY))
			return true;
	}
	return false;
}

bool CLlkView::VerticalConnection(int NowX, int NowY, int OldX, int OldY)
{
	if(NowY!=OldY) return false;
	int i,j;
	if(OldX-NowX>0)
	{
		i=NowX;
		j=OldX;
	}
	else
	{
		i=OldX;
		j=NowX;
	}
	for(i+=1;i<j;i++)
	{
		if(bmp[i][NowY].exit)
		{
			return false;
		}
	}
	return true;

}

bool CLlkView::HorizontalConnection(int NowX, int NowY, int OldX, int OldY)
{
	if(NowX!=OldX)return false;
	int i,j;
	if(OldY-NowY>0)
	{
		i=NowY;
		j=OldY;
	}
	else
	{
		i=OldY;
		j=NowY;
	}
	for(i+=1;i<j;i++)
	{
		if(bmp[NowX][i].exit)
			return false;
	}
	return true;

}

bool CLlkView::OneWinding(int NowX, int NowY, int OldX, int OldY)
{
	if(!bmp[NowX][OldY].exit)
	{
		if(HorizontalConnection(NowX,NowY,NowX,OldY)&&
			VerticalConnection(NowX,OldY,OldX,OldY))
//			TRACE("%d,%d,%d,%d,%d,%d",NowX,NowY,NowX,OldY,OldX,OldY);
		{
			m_way.Add(CPoint(NowX,NowY));
			m_way.Add(CPoint(NowX,OldY));
			m_way.Add(CPoint(OldX,OldY));
			return true;
		}
//		if(VerticalConnection(NowX,OldY,OldX,OldY))
//			return true;
	}
	if(!bmp[OldX][NowY].exit)
	{
		if(VerticalConnection(NowX,NowY,OldX,NowY)&&
			HorizontalConnection(OldX,NowY,OldX,OldY))
		{
			m_way.Add(CPoint(NowX,NowY));
			m_way.Add(CPoint(OldX,NowY));
			m_way.Add(CPoint(OldX,OldY));
			return true;
		}
//		if(HorizontalConnection(OldX,NowY,OldX,OldY))
//			return true;
	}
	return false;	
}

bool CLlkView::TwoWinding(int NowX, int NowY, int OldX, int OldY)
{
	//从上下左右各个方向判断
	int i;
	//左右方向

	for (i=NowY-1;i>=0;i--)
	{
		if (bmp[NowX][i].exit||bmp[OldX][i].exit)
			continue;
		if (HorizontalConnection(NowX,NowY,NowX,i)&&
			VerticalConnection(OldX,i,NowX,i)&&
			HorizontalConnection(OldX,OldY,OldX,i))
		{
			m_way.Add(CPoint(NowX,NowY));
			m_way.Add(CPoint(NowX,i));
			m_way.Add(CPoint(OldX,i));
			m_way.Add(CPoint(OldX,OldY));
			return true;
		}
	
	}
	for (i=NowY+1;i<BMP_COLS;i++)
	{
		if (bmp[NowX][i].exit||bmp[OldX][i].exit)
			continue;
		if (HorizontalConnection(NowX,NowY,NowX,i)&&
			VerticalConnection(OldX,i,NowX,i)&&
			HorizontalConnection(OldX,OldY,OldX,i))
		{
			m_way.Add(CPoint(NowX,NowY));
			m_way.Add(CPoint(NowX,i));
			m_way.Add(CPoint(OldX,i));
			m_way.Add(CPoint(OldX,OldY));
			return true;
		}
	}
	for (i=NowX-1;i>=0;i--)
	{
		if (bmp[i][NowY].exit||bmp[i][OldY].exit)
			continue;
		if (VerticalConnection(NowX,NowY,i,NowY)&&
			HorizontalConnection(i,OldY,i,NowY)&&
			VerticalConnection(OldX,OldY,i,OldY))
		{
			m_way.Add(CPoint(NowX,NowY));
			m_way.Add(CPoint(i,NowY));
			m_way.Add(CPoint(i,OldY));
			m_way.Add(CPoint(OldX,OldY));
			return true;
		}
	}
	for (i=NowX+1;i<BMP_ROWS;i++)
	{
		if (bmp[i][NowY].exit||bmp[i][OldY].exit)
			continue;
		if (VerticalConnection(NowX,NowY,i,NowY)&&
			HorizontalConnection(i,OldY,i,NowY)&&
			VerticalConnection(OldX,OldY,i,OldY))
		{
			m_way.Add(CPoint(NowX,NowY));
			m_way.Add(CPoint(i,NowY));
			m_way.Add(CPoint(i,OldY));
			m_way.Add(CPoint(OldX,OldY));
			return true;
		}
	}
	return false;
}

void CLlkView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	Upper=ProgressRect.Width()/(float)SecAll*(SecAll-second);
	InvalidateRect(InfoRect);
//	if (nIDEvent==1)
//	{
		if (second<=0)
		{
			KillTimer(1);
			if (music)
			{
				StopMusic();
			}
			
			MessageBox("游戏失败");
			IsGameStrart=false;
			return;
			
		}
		
		second--;
		
// 	}
	

/*	else
	{
		int count=m_way.GetSize();
		CDC* pDC=GetDC();
		CPen pen(PS_SOLID,10,RGB(255,0,0));
		CPen* OldPen=pDC->SelectObject(&pen);
		DWORD tNow,tPre;
		tNow=tPre=GetTickCount();
		while (tNow-tPre<1000)
		{
			for (int i=0;i<count-1;i++)
			{
				pDC->MoveTo(GameRect.left+m_way.GetAt(i).y*(BMP_WIDTH-5)+BMP_WIDTH/2,
					GameRect.top+m_way.GetAt(i).x*(BMP_HEIGHT-5)+BMP_HEIGHT/2);
				pDC->LineTo(GameRect.left+m_way.GetAt(i+1).y*(BMP_WIDTH-5)+BMP_WIDTH/2,
					GameRect.top+m_way.GetAt(i+1).x*(BMP_HEIGHT-5)+BMP_HEIGHT/2);
				
			}
			tNow=GetTickCount();
		}
	
		pDC->SelectObject(OldPen);
		pen.DeleteObject();
		KillTimer(2);
		m_way.RemoveAll();
		ReleaseDC(pDC);
		InvalidateRect(GameRect);
	}*/
	
	
	
	

	
	CView::OnTimer(nIDEvent);
}


void ThreadFunc(LPARAM lParam)
{
	int *score=(int *)lParam;
	CArray<POINT,POINT> m_aTemp;
	m_aTemp.Copy(m_way);
	m_way.RemoveAll();

	CWnd* pWnd= AfxGetApp()->GetMainWnd();
	CDC* pDC=pWnd->GetDC();
	CPen pen(PS_SOLID,10,RGB(255,0,0));
	CPen* OldPen=pDC->SelectObject(&pen);
	pDC->SetBkMode(TRANSPARENT);



	static int HitCount=0;
	static DWORD tNow=0;
	static DWORD tPre=0;

	tNow=GetTickCount();
	if (tNow-tPre<2000)
	{
		HitCount++;
	}
	else
	{
		HitCount=1;
	}
	(*score)+=HitCount*HitCount;

	pWnd->InvalidateRect(CRect(50,20,573,100));

	tPre=GetTickCount();

	CString temp;
	temp.Format("%d连击",HitCount);
	
	

	int i,count;
	count=m_aTemp.GetSize();


	DWORD t1,t2;
	t1=t2=GetTickCount();
	while (t1-t2<500)
	{
		for (i=0;i<count-1;i++)
		{
			pDC->MoveTo(50+m_aTemp.GetAt(i).y*(BMP_WIDTH-5)+BMP_WIDTH/2,
				100+m_aTemp.GetAt(i).x*(BMP_HEIGHT-5)+BMP_HEIGHT/2);
			pDC->LineTo(50+m_aTemp.GetAt(i+1).y*(BMP_WIDTH-5)+BMP_WIDTH/2,
				100+m_aTemp.GetAt(i+1).x*(BMP_HEIGHT-5)+BMP_HEIGHT/2);
			
		}
		pDC->TextOut(50+m_aTemp.GetAt(0).y*(BMP_WIDTH-5),
			100+m_aTemp.GetAt(0).x*(BMP_HEIGHT-5),temp);
		t1=GetTickCount();

	}
	//------------------------------------

//	tNow=GetTickCount();
//	if (tNow-tPre<3000)
	//-------------------------------------
	pDC->SelectObject(OldPen);
	pen.DeleteObject();

//	CRect rect;
//	pWnd->GetClientRect(&rect);
//	pWnd->InvalidateRect(rect);
	pWnd->InvalidateRect(CRect(50,100,523,595));

	pWnd->ReleaseDC(pDC);
	
}

void CLlkView::IsSuccess()
{
	if (IsGameStrart)
	{
		int i,j;
		for(i=0;i<BMP_ROWS;i++)
		{
			for(j=0;j<BMP_COLS;j++)
			{
				if(bmp[i][j].exit)
					return;
			}
		}
		IsGameStrart=false;
		KillTimer(1);
		if (music)
		{
			StopMusic();
		}
		MessageBox("游戏成功");
		CRankDlg dlg;
		//用数组存储前五名的分数
		int rank[5];
		CString temp;
		for (i=0;i<5;i++)
		{
			temp.Format("%d",i+1);
			rank[i]=GetPrivateProfileInt("rank",temp,      
			0,"llk.ini");
		}
		//循环
		for (i=0;i<5;i++)
		{
			//当发现当前的分数大于第i+1名的分数时
			if (score>=rank[i])
			{
				//第i+1名以后的分数重新排列
				for (j=4;j>i;j--)
				{
					rank[j]=rank[j-1];
				}
				rank[i]=score;
				CString temp1,temp2;
				//把排好的数组依次写进ini文件中，让排行榜读取
				for (i=0;i<5;i++)
				{
					temp1.Format("%d",i+1);
					temp2.Format("%d",rank[i]);
					WritePrivateProfileString("rank",temp1,temp2,"llk.ini");
				}
				break;
			}
		}
		OnRank();
	}

}

void CLlkView::OnTip()
{
	if (!IsSolution())
	{
		MessageBox("当前为无解状态，请重列");
		return;
	}
	if (TipCount>0)
	{
		CArray<POINT,POINT> m_abmp;
		int i,j;
		for (i=0;i<BMP_ROWS;i++)
		{
			for (j=0;j<BMP_COLS;j++)
			{
				if (bmp[i][j].exit)
				{
					m_abmp.Add(CPoint(i,j));
				}
			}
		}
		int count=m_abmp.GetSize();
		for (i=0;i<count;i++)
		{
			for (j=i+1;j<count;j++)
			{
				if (IsConnection(m_abmp.GetAt(i).x,m_abmp.GetAt(i).y,
					m_abmp.GetAt(j).x,m_abmp.GetAt(j).y))
				{
					if (sound)
					{
						PlaySound(MAKEINTRESOURCE(IDR_WAVE_OK),
							AfxGetInstanceHandle(),SND_ASYNC|SND_RESOURCE);
					}
					TipCount--;
					bmp[m_abmp.GetAt(i).x][m_abmp.GetAt(i).y].exit=false;
					bmp[m_abmp.GetAt(j).x][m_abmp.GetAt(j).y].exit=false;
					hThread=CreateThread(NULL,
						0,
						(LPTHREAD_START_ROUTINE)ThreadFunc,
						&score,
						0,
						&ThreadID);
					InvalidateRect(GameRect);
					return;
				}
			}
			
		}
	}
	
}

void CLlkView::OnVoice() 
{
	// TODO: Add your command handler code here
	sound=!sound;
//	OnTip();
}

void CLlkView::OnUpdateVoice(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(sound);
}

void CLlkView::OnRank() 
{
	// TODO: Add your command handler code here
	CRankDlg dlg;
	dlg.DoModal();
}

void CLlkView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if (IsGameStrart)
	{
		if (nChar==VK_F1)
		{
			OnTip();
		}
		if (nChar==VK_F2)
		{
			Rearrange();
		}
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CLlkView::Rearrange()
{
	if (RearrangeCount>0)
	{
		CArray<int,int> m_abmp;
		int i,j;
		for (i=0;i<BMP_ROWS;i++)
		{
			for (j=0;j<BMP_COLS;j++)
			{
				if (bmp[i][j].exit)
				{
					bmp[i][j].exit=false;
					m_abmp.Add(bmp[i][j].index);
					
				}
			}
		}
		int count=m_abmp.GetSize();
		//	srand((unsigned) time(NULL)); 
		srand(rand()%10); 
		int row,col;
		for (i=0;i<count;i++)
		{
			row=rand()%BMP_ROWS;
			col=rand()%BMP_COLS;
			while(bmp[row][col].exit)
			{
				row=rand()%BMP_ROWS;
				col=rand()%BMP_COLS;
			}
			bmp[row][col].exit=true;
			bmp[row][col].index=m_abmp.GetAt(i);
			bmp[row][col].row=row;
			bmp[row][col].col=col;
			bmp[row][col].IsSelect=false;
		}
		RearrangeCount--;
		InvalidateRect(InfoRect);
		InvalidateRect(GameRect);
	}
	
}

bool CLlkView::IsSolution()
{
	if (IsGameStrart)
	{
		CArray<POINT,POINT> m_abmp;
		int i,j;
		for (i=0;i<BMP_ROWS;i++)
		{
			for (j=0;j<BMP_COLS;j++)
			{
				if (bmp[i][j].exit)
				{
					m_abmp.Add(CPoint(i,j));
				}
			}
		}
		int count=m_abmp.GetSize();
		for (i=0;i<count;i++)
		{
			for (j=i+1;j<count;j++)
			{
				if (IsConnection(m_abmp.GetAt(i).x,m_abmp.GetAt(i).y,
					m_abmp.GetAt(j).x,m_abmp.GetAt(j).y))
				{
					m_way.RemoveAll();
					return true;
				}
			}
			
		}
		return false;
	}
	
}

void CLlkView::OnMusic() 
{
	// TODO: Add your command handler code here
	music=!music;
	if (music)
		PlayMusic();
	else
		StopMusic();

	
}

void CLlkView::OnUpdateMusic(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(music);
}

void CLlkView::PlayMusic()
{
	MCI_OPEN_PARMS mciopenparms;
	MCI_PLAY_PARMS mciplayparms;
//	mciopenparms.lpstrElementName="C:\\Documents and Settings\\Administrator\\桌面\\王妃.mp3";
	CString path;
	GetPrivateProfileString("music","path",path,
		path.GetBuffer(MAX_PATH),			
		MAX_PATH,"llk.ini");
	path.ReleaseBuffer();
	mciopenparms.lpstrElementName=path;
//	mciopenparms.lpstrElementName="F:\\lizi\\llk\\res\\yesterday once more carpenter .mp3";
	mciopenparms.lpstrDeviceType=NULL;
	mciSendCommand(0,MCI_OPEN,MCI_DEVTYPE_WAVEFORM_AUDIO,(DWORD)(LPVOID)&mciopenparms);
	m_count=mciopenparms.wDeviceID;
	mciplayparms.dwCallback=(DWORD)GetSafeHwnd();
	//-----------------------
	MCI_STATUS_PARMS mcistatusparms;
	mcistatusparms.dwCallback=(DWORD)GetSafeHwnd();
	mcistatusparms.dwItem=MCI_STATUS_LENGTH;
	mcistatusparms.dwReturn=0;
	mciSendCommand(m_count,MCI_STATUS,MCI_STATUS_ITEM,(DWORD)&mcistatusparms);
	//--------------------------
	DWORD cdlen=mcistatusparms.dwReturn;                                                                                                                                                                                                                                              
	DWORD cdfrom=MCI_MAKE_HMS(0,0,0);
	DWORD cdto=MCI_MAKE_HMS(MCI_HMS_HOUR(cdlen),MCI_HMS_MINUTE(cdlen),MCI_HMS_SECOND(cdlen));  
	mciplayparms.dwFrom=cdfrom;
	mciplayparms.dwTo=cdto;
	mciSendCommand(m_count,MCI_PLAY,MCI_TO|MCI_FROM,(DWORD)(LPVOID)& mciplayparms);
}


void CLlkView::StopMusic()
{
	mciSendCommand(m_count,MCI_CLOSE,0,NULL);
}

void CLlkView::OnSetting() 
{
	// TODO: Add your command handler code here
	CMusicDlg dlg;
	if (IDOK==dlg.DoModal())
	{
		WritePrivateProfileString("music","path",dlg.m_FileName,"llk.ini");
	}
}
