#pragma once


// CSecondDlg �Ի���

class CSecondDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CSecondDlg)

public:
	CSecondDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSecondDlg();

// �Ի�������
	enum { IDD = IDD_SECDLG };

	CBitmap   m_bmp;

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
};
