
// jhfDgDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"

#define ID_OWNBTN 2009


// CjhfDgDlg �Ի���
class CjhfDgDlg : public CDialogEx
{
// ����
public:
	CjhfDgDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_JHFDG_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	CToolBar m_ToolBar; 
	CBitmap m_bitmap;  
    CImageList m_ImageList; 

	CButton m_ownBtn;


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSleep();
	afx_msg void OnDblEvent();
	CButton m_check1;
	int m_old;
	afx_msg void OnEnKillfocusEdit1();
	CListBox m_list1;
	afx_msg void OnLbnSelchangeList1();
	CComboBox m_combo1;
	afx_msg void OnAbout();
	afx_msg void OnShowMSG();
	afx_msg void OnOpen();

	CSpinButtonCtrl m_spin;
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	long m_time;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
//	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
