
// calculator1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Ccalculator1App: 
// �йش����ʵ�֣������ calculator1.cpp
//

class Ccalculator1App : public CWinApp
{
public:
	Ccalculator1App();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Ccalculator1App theApp;