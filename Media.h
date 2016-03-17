// Media.h: interface for the CMedia class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MEDIA_H__6E908128_659F_4DFC_B49B_449C8906B7BC__INCLUDED_)
#define AFX_MEDIA_H__6E908128_659F_4DFC_B49B_449C8906B7BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <MMSYSTEM.H>
class CMedia  
{
public:
	CMedia();
	virtual ~CMedia();
/*
public:
	bool InitPath(); //初始化路径，取得播放列表中文件的全路径
	bool OpenFiles();   //打开CFileDialog,获取歌曲列表
	bool OpenList();  //读取文件中的歌曲列表
	bool Play();      //播放
*/
};

#endif // !defined(AFX_MEDIA_H__6E908128_659F_4DFC_B49B_449C8906B7BC__INCLUDED_)
