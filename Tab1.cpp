// Tab1.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "jhfDg.h"
#include "Tab1.h"
#include "afxdialogex.h"


// CTab1 �Ի���

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


// CTab1 ��Ϣ�������


BOOL CTab1::OnInitDialog()
{
	CDialog::OnInitDialog();

	//****����Ӧ�ñ����list control��type���ó�report****

	m_listCtrl.DeleteAllItems();//���
	m_listCtrl.InsertColumn(0,_T("���"));//�����
	m_listCtrl.InsertColumn(1,_T("����"));
	m_listCtrl.InsertColumn(2,_T("����"));
	m_listCtrl.SetColumnWidth(0, 50);//�����п�
	m_listCtrl.SetColumnWidth(1, 120);
	m_listCtrl.SetColumnWidth(2, 70);
	m_listCtrl.SetRedraw(false);//��ֹ�ػ�

	int nIndex;
	nIndex=m_listCtrl.InsertItem( 0,_T("1") );
	m_listCtrl.SetItemText( nIndex, 1, _T("��ޥ��") );
	m_listCtrl.SetItemText( nIndex, 2, _T("18") );
	nIndex=m_listCtrl.InsertItem( 0,_T("2") );
	m_listCtrl.SetItemText( nIndex, 1, _T("������") );
	m_listCtrl.SetItemText( nIndex, 2, _T("45") );
	nIndex=m_listCtrl.InsertItem( 0,_T("3") );
	m_listCtrl.SetItemText( nIndex, 1, _T("�����") );
	m_listCtrl.SetItemText( nIndex, 2, _T("46") );
	

	m_listCtrl.SetRedraw(true);


	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}



