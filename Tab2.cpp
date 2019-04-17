// Tab2.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "jhfDg.h"
#include "Tab2.h"
#include "afxdialogex.h"


// CTab2 �Ի���

IMPLEMENT_DYNAMIC(CTab2, CDialog)

CTab2::CTab2(CWnd* pParent /*=NULL*/)
	: CDialog(CTab2::IDD, pParent)
{

}

CTab2::~CTab2()
{
}

void CTab2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE1, m_webTree);
	DDX_Control(pDX, IDC_TREEEDIT, m_treeNode);
}


BEGIN_MESSAGE_MAP(CTab2, CDialog)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CTab2::OnTvnSelchangedTree1)
END_MESSAGE_MAP()


// CTab2 ��Ϣ�������


BOOL CTab2::OnInitDialog()
{
	CDialog::OnInitDialog();

	//****   ��tree��ͼ���й�  ��ʼ  *****
	// ��������ͼ�꣬�������ǵľ�����浽����   
    hIcon[0] = theApp.LoadIcon(IDI_WEB_ICON);   
    hIcon[1] = theApp.LoadIcon(IDI_CATALOG_ICON);   
    hIcon[2] = theApp.LoadIcon(IDI_ARTICLE_ICON); 
	// ����ͼ������CImageList����   
    m_imageList.Create(32, 32, ILC_COLOR32, 3, 3);   
    // ������ͼ����ӵ�ͼ������   
    for (int i=0; i<3; i++)   
    {   
        m_imageList.Add(hIcon[i]);   
    }   
    // Ϊ���οؼ�����ͼ������   
    m_webTree.SetImageList(&m_imageList, TVSIL_NORMAL); 
	//****   ��tree��ͼ���й�  ����  *****
	
	//����Ӧ�ã�tree control���ã�����Has Buttons��Has Lines��Lines At Root����ΪTrue

	    // ������ڵ�   
    hRoot = m_webTree.InsertItem(_T("������"), 0, 0);   
    // �ڸ��ڵ��²����ӽڵ�   
    hCataItem = m_webTree.InsertItem(_T("IT������"), 1, 1, hRoot, TVI_LAST);   
    // Ϊ��IT���������ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
    m_webTree.SetItemData(hCataItem, 1);   
    // �ڡ�IT���������ڵ��²����ӽڵ�   
    hArtItem = m_webTree.InsertItem(_T("�ٶ�����1"), 2, 2, hCataItem, TVI_LAST);   
    // Ϊ���ٶ�����1���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
    m_webTree.SetItemData(hArtItem, 2);   
    // �ڡ�IT���������ڵ��²�����һ�ӽڵ�   
    hArtItem = m_webTree.InsertItem(_T("�ȸ�����2"), 2, 2, hCataItem, TVI_LAST);   
    // Ϊ���ȸ�����2���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
    m_webTree.SetItemData(hArtItem, 3);   
    // �ڸ��ڵ��²���ڶ����ӽڵ�   
    hCataItem = m_webTree.InsertItem(_T("��������"), 1, 1, hRoot, TVI_LAST);   
    // Ϊ����������ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
    m_webTree.SetItemData(hCataItem, 4);   
    // �ڡ���������ڵ��²����ӽڵ�   
    hArtItem = m_webTree.InsertItem(_T("�����ֻ�����1"), 2, 2, hCataItem, TVI_LAST);   
    // Ϊ�������ֻ�����1���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
    m_webTree.SetItemData(hArtItem, 5);   
    // �ڡ���������ڵ��²�����һ�ӽڵ�   
    hArtItem = m_webTree.InsertItem(_T("ƽ���������2"), 2, 2, hCataItem, TVI_LAST);   
    // Ϊ��ƽ���������2���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
    m_webTree.SetItemData(hArtItem, 6);   
    // �ڸ��ڵ��²���������ӽڵ�   
    hCataItem = m_webTree.InsertItem(_T("�������"), 1, 1, hRoot, TVI_LAST);   
    // Ϊ������������ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
    m_webTree.SetItemData(hCataItem, 7);   
    // �ڡ�����������ڵ��²����ӽڵ�   
    hArtItem = m_webTree.InsertItem(_T("C++�������ϵ��1"), 2, 2, hCataItem, TVI_LAST);   
    // Ϊ��C++�������ϵ��1���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
    m_webTree.SetItemData(hArtItem, 8);   
    // �ڡ�����������ڵ��²�����һ�ӽڵ�   
    hArtItem = m_webTree.InsertItem(_T("VS2010/MFC�������2"), 2, 2, hCataItem, TVI_LAST);   
    // Ϊ��VS2010/MFC�������2���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
    m_webTree.SetItemData(hArtItem, 9);   
    // �ڸ��ڵ��²�����ĸ��ӽڵ�   
    hCataItem = m_webTree.InsertItem(_T("��������"), 1, 1, hRoot, TVI_LAST);   
    // Ϊ���������С��ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
    m_webTree.SetItemData(hCataItem, 10);   
    // �ڡ��������С��ڵ��²����ӽڵ�   
    hArtItem = m_webTree.InsertItem(_T("������������1"), 2, 2, hCataItem, TVI_LAST);   
    // Ϊ��������������1���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
    m_webTree.SetItemData(hArtItem, 11);   
    // �ڡ��������С��ڵ��²�����һ�ӽڵ�   
    hArtItem = m_webTree.InsertItem(_T("ITЦ��2"), 2, 2, hCataItem, TVI_LAST);   
    // Ϊ��ITЦ��2���ڵ���Ӹ��ӵı�����ݣ�����껮���ýڵ�ʱ��ʾ   
    m_webTree.SetItemData(hArtItem, 12);   

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}

void CTab2::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	 HTREEITEM hItem = m_webTree.GetSelectedItem();  //��ǰ��ѡ�ڵ� 
    if(hItem != NULL)  
    {  
        CString strText= m_webTree.GetItemText(hItem);//��ȡ�ڵ��ı�  
        SetDlgItemText(IDC_TREEEDIT , strText); //��ʾ���ı�����  
    }  

//	m_treeNode =;
	*pResult = 0;
}
