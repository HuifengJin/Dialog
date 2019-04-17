#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CTab1 对话框

class CTab1 : public CDialog
{
	DECLARE_DYNAMIC(CTab1)

public:
	CTab1(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTab1();

// 对话框数据
	enum { IDD = IDD_TAB2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listCtrl;
	virtual BOOL OnInitDialog();
	
};
