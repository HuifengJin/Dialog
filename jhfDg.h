
// jhfDg.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CjhfDgApp:
// �йش����ʵ�֣������ jhfDg.cpp
//

class CjhfDgApp : public CWinApp
{
public:
	CjhfDgApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CjhfDgApp theApp;