#pragma once


// CTab2 �Ի���

class CTab2 : public CDialog
{
	DECLARE_DYNAMIC(CTab2)

public:
	CTab2(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTab2();

// �Ի�������
	enum { IDD = IDD_TAB2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CTreeCtrl m_webTree;

	HTREEITEM hRoot;     // ���ĸ��ڵ�ľ��   
    HTREEITEM hCataItem; // �ɱ�ʾ��һ����ڵ�ľ��   
    HTREEITEM hArtItem;  // �ɱ�ʾ��һ���½ڵ�ľ��

	//��tree��ͼ���й�
	HICON hIcon[3];      // ͼ��������
	CImageList m_imageList;

	virtual BOOL OnInitDialog();

	CEdit m_treeNode;
	afx_msg void OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult);
};
