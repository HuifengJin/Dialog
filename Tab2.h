#pragma once


// CTab2 对话框

class CTab2 : public CDialog
{
	DECLARE_DYNAMIC(CTab2)

public:
	CTab2(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTab2();

// 对话框数据
	enum { IDD = IDD_TAB2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_webTree;

	HTREEITEM hRoot;     // 树的根节点的句柄   
    HTREEITEM hCataItem; // 可表示任一分类节点的句柄   
    HTREEITEM hArtItem;  // 可表示任一文章节点的句柄

	//与tree的图标有关
	HICON hIcon[3];      // 图标句柄数组
	CImageList m_imageList;

	virtual BOOL OnInitDialog();

	CEdit m_treeNode;
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
};
