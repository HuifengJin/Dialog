#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CTab1 �Ի���

class CTab1 : public CDialog
{
	DECLARE_DYNAMIC(CTab1)

public:
	CTab1(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTab1();

// �Ի�������
	enum { IDD = IDD_TAB2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listCtrl;
	virtual BOOL OnInitDialog();
	
};
