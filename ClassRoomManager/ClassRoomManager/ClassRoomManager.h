
// ClassRoomManager.h : ClassRoomManager Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CClassRoomManagerApp:
// �йش����ʵ�֣������ ClassRoomManager.cpp
//

class CClassRoomManagerApp : public CWinApp
{
public:
	CClassRoomManagerApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CClassRoomManagerApp theApp;
