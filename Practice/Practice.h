
// Practice.h : PROJECT_NAME ���ε{�����D�n���Y��
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�� PCH �]�t���ɮ׫e���]�t 'stdafx.h'"
#endif

#include "resource.h"		// �D�n�Ÿ�


// CPracticeApp: 
// �аѾ\��@�����O�� Practice.cpp
//

class CPracticeApp : public CWinApp
{
public:
	CPracticeApp();

// �мg
public:
	virtual BOOL InitInstance();

// �{���X��@

	DECLARE_MESSAGE_MAP()
};

extern CPracticeApp theApp;