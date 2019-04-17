#pragma once


// CSecondDlg 对话框

class CSecondDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSecondDlg)

public:
	CSecondDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSecondDlg();

// 对话框数据
	enum { IDD = IDD_SECDLG };

	CBitmap   m_bmp;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
