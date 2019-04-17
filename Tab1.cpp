// Tab1.cpp : 实现文件
//

#include "stdafx.h"
#include "jhfDg.h"
#include "Tab1.h"
#include "afxdialogex.h"


// CTab1 对话框

IMPLEMENT_DYNAMIC(CTab1, CDialog)

CTab1::CTab1(CWnd* pParent /*=NULL*/)
	: CDialog(CTab1::IDD, pParent)
{

}

CTab1::~CTab1()
{
}

void CTab1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LISTCTRL, m_listCtrl);
	
}


BEGIN_MESSAGE_MAP(CTab1, CDialog)
	
END_MESSAGE_MAP()


// CTab1 消息处理程序


BOOL CTab1::OnInitDialog()
{
	CDialog::OnInitDialog();

	//****这种应用必须把list control的type设置成report****

	m_listCtrl.DeleteAllItems();//清空
	m_listCtrl.InsertColumn(0,_T("序号"));//添加列
	m_listCtrl.InsertColumn(1,_T("人名"));
	m_listCtrl.InsertColumn(2,_T("年龄"));
	m_listCtrl.SetColumnWidth(0, 50);//设置列宽
	m_listCtrl.SetColumnWidth(1, 120);
	m_listCtrl.SetColumnWidth(2, 70);
	m_listCtrl.SetRedraw(false);//防止重绘

	int nIndex;
	nIndex=m_listCtrl.InsertItem( 0,_T("1") );
	m_listCtrl.SetItemText( nIndex, 1, _T("金蕙风") );
	m_listCtrl.SetItemText( nIndex, 2, _T("18") );
	nIndex=m_listCtrl.InsertItem( 0,_T("2") );
	m_listCtrl.SetItemText( nIndex, 1, _T("金晓明") );
	m_listCtrl.SetItemText( nIndex, 2, _T("45") );
	nIndex=m_listCtrl.InsertItem( 0,_T("3") );
	m_listCtrl.SetItemText( nIndex, 1, _T("吕向红") );
	m_listCtrl.SetItemText( nIndex, 2, _T("46") );
	

	m_listCtrl.SetRedraw(true);


	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}



