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
	bool InitPath(); //��ʼ��·����ȡ�ò����б����ļ���ȫ·��
	bool OpenFiles();   //��CFileDialog,��ȡ�����б�
	bool OpenList();  //��ȡ�ļ��еĸ����б�
	bool Play();      //����
*/
};

#endif // !defined(AFX_MEDIA_H__6E908128_659F_4DFC_B49B_449C8906B7BC__INCLUDED_)
