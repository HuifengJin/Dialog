#pragma once
#include "afxcmn.h"
#include "afxwin.h"

#include "Tab1.h"
#include "Tab2.h"

// COtherDLG 对话框

class COtherDLG : public CDialogEx
{
	DECLARE_DYNAMIC(COtherDLG)

public:
	COtherDLG(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~COtherDLG();

// 对话框数据
	enum { IDD = IDD_OTHERDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl m_slide;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	CStatic m_pic;
	CScrollBar m_hScroll;
	afx_msg void OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CScrollBar m_hscroll2;
	int m_hsValue;
	afx_msg void OnBnClickedUpdate();
	int m_hsValue2;
	CProgressCtrl m_progress;
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	CScrollBar m_vscroll;
	CTabCtrl m_tab;
	CTab1 m_login_tab1;  
    CTab2 m_login_tab2;  
	afx_msg void OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult);
};
