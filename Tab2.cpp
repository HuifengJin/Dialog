// Tab2.cpp : 实现文件
//

#include "stdafx.h"
#include "jhfDg.h"
#include "Tab2.h"
#include "afxdialogex.h"


// CTab2 对话框

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


// CTab2 消息处理程序


BOOL CTab2::OnInitDialog()
{
	CDialog::OnInitDialog();

	//****   与tree的图标有关  开始  *****
	// 加载三个图标，并将它们的句柄保存到数组   
    hIcon[0] = theApp.LoadIcon(IDI_WEB_ICON);   
    hIcon[1] = theApp.LoadIcon(IDI_CATALOG_ICON);   
    hIcon[2] = theApp.LoadIcon(IDI_ARTICLE_ICON); 
	// 创建图像序列CImageList对象   
    m_imageList.Create(32, 32, ILC_COLOR32, 3, 3);   
    // 将三个图标添加到图像序列   
    for (int i=0; i<3; i++)   
    {   
        m_imageList.Add(hIcon[i]);   
    }   
    // 为树形控件设置图像序列   
    m_webTree.SetImageList(&m_imageList, TVSIL_NORMAL); 
	//****   与tree的图标有关  结束  *****
	
	//这种应用，tree control设置：属性Has Buttons、Has Lines和Lines At Root都设为True

	    // 插入根节点   
    hRoot = m_webTree.InsertItem(_T("鸡啄米"), 0, 0);   
    // 在根节点下插入子节点   
    hCataItem = m_webTree.InsertItem(_T("IT互联网"), 1, 1, hRoot, TVI_LAST);   
    // 为“IT互联网”节点添加附加的编号数据，在鼠标划过该节点时显示   
    m_webTree.SetItemData(hCataItem, 1);   
    // 在“IT互联网”节点下插入子节点   
    hArtItem = m_webTree.InsertItem(_T("百度文章1"), 2, 2, hCataItem, TVI_LAST);   
    // 为“百度文章1”节点添加附加的编号数据，在鼠标划过该节点时显示   
    m_webTree.SetItemData(hArtItem, 2);   
    // 在“IT互联网”节点下插入另一子节点   
    hArtItem = m_webTree.InsertItem(_T("谷歌文章2"), 2, 2, hCataItem, TVI_LAST);   
    // 为“谷歌文章2”节点添加附加的编号数据，在鼠标划过该节点时显示   
    m_webTree.SetItemData(hArtItem, 3);   
    // 在根节点下插入第二个子节点   
    hCataItem = m_webTree.InsertItem(_T("数码生活"), 1, 1, hRoot, TVI_LAST);   
    // 为“数码生活”节点添加附加的编号数据，在鼠标划过该节点时显示   
    m_webTree.SetItemData(hCataItem, 4);   
    // 在“数码生活”节点下插入子节点   
    hArtItem = m_webTree.InsertItem(_T("智能手机文章1"), 2, 2, hCataItem, TVI_LAST);   
    // 为“智能手机文章1”节点添加附加的编号数据，在鼠标划过该节点时显示   
    m_webTree.SetItemData(hArtItem, 5);   
    // 在“数码生活”节点下插入另一子节点   
    hArtItem = m_webTree.InsertItem(_T("平板电脑文章2"), 2, 2, hCataItem, TVI_LAST);   
    // 为“平板电脑文章2”节点添加附加的编号数据，在鼠标划过该节点时显示   
    m_webTree.SetItemData(hArtItem, 6);   
    // 在根节点下插入第三个子节点   
    hCataItem = m_webTree.InsertItem(_T("软件开发"), 1, 1, hRoot, TVI_LAST);   
    // 为“软件开发”节点添加附加的编号数据，在鼠标划过该节点时显示   
    m_webTree.SetItemData(hCataItem, 7);   
    // 在“软件开发”节点下插入子节点   
    hArtItem = m_webTree.InsertItem(_T("C++编程入门系列1"), 2, 2, hCataItem, TVI_LAST);   
    // 为“C++编程入门系列1”节点添加附加的编号数据，在鼠标划过该节点时显示   
    m_webTree.SetItemData(hArtItem, 8);   
    // 在“软件开发”节点下插入另一子节点   
    hArtItem = m_webTree.InsertItem(_T("VS2010/MFC编程入门2"), 2, 2, hCataItem, TVI_LAST);   
    // 为“VS2010/MFC编程入门2”节点添加附加的编号数据，在鼠标划过该节点时显示   
    m_webTree.SetItemData(hArtItem, 9);   
    // 在根节点下插入第四个子节点   
    hCataItem = m_webTree.InsertItem(_T("娱乐休闲"), 1, 1, hRoot, TVI_LAST);   
    // 为“娱乐休闲”节点添加附加的编号数据，在鼠标划过该节点时显示   
    m_webTree.SetItemData(hCataItem, 10);   
    // 在“娱乐休闲”节点下插入子节点   
    hArtItem = m_webTree.InsertItem(_T("玛雅文明文章1"), 2, 2, hCataItem, TVI_LAST);   
    // 为“玛雅文明文章1”节点添加附加的编号数据，在鼠标划过该节点时显示   
    m_webTree.SetItemData(hArtItem, 11);   
    // 在“娱乐休闲”节点下插入另一子节点   
    hArtItem = m_webTree.InsertItem(_T("IT笑话2"), 2, 2, hCataItem, TVI_LAST);   
    // 为“IT笑话2”节点添加附加的编号数据，在鼠标划过该节点时显示   
    m_webTree.SetItemData(hArtItem, 12);   

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void CTab2::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	 HTREEITEM hItem = m_webTree.GetSelectedItem();  //当前所选节点 
    if(hItem != NULL)  
    {  
        CString strText= m_webTree.GetItemText(hItem);//获取节点文本  
        SetDlgItemText(IDC_TREEEDIT , strText); //显示在文本框中  
    }  

//	m_treeNode =;
	*pResult = 0;
}
