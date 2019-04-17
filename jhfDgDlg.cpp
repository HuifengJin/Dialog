
// jhfDgDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "jhfDg.h"
#include "jhfDgDlg.h"
#include "afxdialogex.h"

#include "OtherDLG.h"
#include "SecondDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CjhfDgDlg �Ի���




CjhfDgDlg::CjhfDgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CjhfDgDlg::IDD, pParent)
	, m_time(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_old = 0;
}

void CjhfDgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Text(pDX, IDC_EDIT1, m_old);
	DDV_MinMaxInt(pDX, m_old, 0, 130);
	DDX_Control(pDX, IDC_LIST1, m_list1);
	DDX_Control(pDX, IDC_COMBO1, m_combo1);
	DDX_Control(pDX, IDC_SPIN, m_spin);
	DDX_Text(pDX, IDC_EDIT2, m_time);
}

BEGIN_MESSAGE_MAP(CjhfDgDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_JHF_BN, &CjhfDgDlg::OnSleep)
	ON_BN_CLICKED(IDC_JXM_BN, &CjhfDgDlg::OnDblEvent)
	ON_EN_KILLFOCUS(IDC_EDIT1, &CjhfDgDlg::OnEnKillfocusEdit1)
	ON_LBN_SELCHANGE(IDC_LIST1, &CjhfDgDlg::OnLbnSelchangeList1)
	ON_COMMAND(ID_ABOUT, &CjhfDgDlg::OnAbout)
	ON_COMMAND(ID_OPEN, &CjhfDgDlg::OnOpen)
	ON_COMMAND(ID_SHOWMSG, &CjhfDgDlg::OnShowMSG)
	ON_WM_SIZE()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
//	ON_WM_CHAR()
END_MESSAGE_MAP()


// CjhfDgDlg ��Ϣ�������

BOOL CjhfDgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	if( !m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS ) ||  
    !m_ToolBar.LoadToolBar(IDR_TOOLBAR))  
	{  
		TRACE0("δ�ܴ���������\n");  
		AfxMessageBox(_T("δ�ܴ���������\n"));  
		return FALSE;      // δ�ܴ���  
	}  
	m_ToolBar.ShowWindow(SW_SHOW);  

	m_bitmap.LoadBitmapW(IDB_BITMAP);  

	m_ImageList.Create(32,32, ILC_COLOR32 | ILC_MASK,0,0);  
	m_ImageList.Add(&m_bitmap, RGB(0, 0, 0));  
	m_ToolBar.GetToolBarCtrl().SetImageList(&m_ImageList); 

	//�ؼ�����λ  
    RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0); 

	m_check1.SetCheck(true);
	((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(true);

	((CButton *)GetDlgItem(IDC_SEX_GIRL))->SetCheck(true);

	m_list1.AddString(_T("jhf"));
	m_list1.AddString(_T("myf"));
	m_list1.AddString(_T("wyl"));
	m_list1.AddString(_T("fk"));


	m_combo1.AddString(_T("��ѧ"));
	m_combo1.AddString(_T("Ӣ��"));
	m_combo1.AddString(_T("����"));
	m_combo1.AddString(_T("����"));
	m_combo1.SetCurSel(0);

	RECT rect;
	
	rect.left = 10;
	rect.top = 250;
	rect.right = 90;
	rect.bottom = 300;

	//�����Լ��ֶ���ӻ��߶�̬��ӿؼ�
	m_ownBtn.Create(_T("�Խ���ť"),BS_CHECKBOX,rect,this,ID_OWNBTN);
	m_ownBtn.EnableWindow(false);
	m_ownBtn.ShowWindow(SW_SHOW);

	//ע�⣺spin�ؼ���auto buttyҪ���true
	CEdit *prow=(CEdit *)GetDlgItem(IDC_NUM_EDIT); 
	m_spin.SetBuddy(prow);
	m_spin.SetRange(1,100); 
	m_spin.SetBase(1); 
	m_spin.SetPos(2);

	//���ö�ʱ��
	SetTimer(10,1000,NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CjhfDgDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CjhfDgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CjhfDgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CjhfDgDlg::OnSleep()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//MessageBox(L"JHF is sleeping!");
	
	//ģʽ�Ի�����ʾ��ʽ
	//COtherDLG m_otherDG;
	//m_otherDG.DoModal();

	//��ģʽ�Ի�����ʾ��ʽ
	COtherDLG* m_otherDG;
	m_otherDG = new COtherDLG;
	m_otherDG->Create(IDD_OTHERDLG,this);
	m_otherDG->ShowWindow(SW_SHOW);

}


void CjhfDgDlg::OnDblEvent()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CSecondDlg m_secondDLG;
	m_secondDLG.DoModal();
}


void CjhfDgDlg::OnEnKillfocusEdit1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(true);
}


void CjhfDgDlg::OnLbnSelchangeList1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if( m_list1.GetCurSel() == 2)
		MessageBox(L"wyl is choosing!");
}


void CjhfDgDlg::OnAbout()
{
	// TODO: �ڴ���������������
	CAboutDlg m_adg;
	m_adg.DoModal();
}


void CjhfDgDlg::OnOpen()
{
	// TODO: �ڴ���������������
	MessageBox(_T("click open!"));
}

void CjhfDgDlg::OnShowMSG()
{
	MessageBox(_T("Show Message!"));
}


void CjhfDgDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: �ڴ˴������Ϣ����������
	//MessageBox(_T("Size changed!"));
}


void CjhfDgDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(nIDEvent == 10)
	{
		m_time += 1;
		UpdateData(false);
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CjhfDgDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	MessageBox(_T("Mouse clicked!"));

	CDialogEx::OnLButtonDown(nFlags, point);
}


//void CjhfDgDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
//	MessageBox(_T("Keyboard clicked!"));
//
//	CDialogEx::OnChar(nChar, nRepCnt, nFlags);
//}


BOOL CjhfDgDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if( pMsg->message == WM_KEYDOWN )
	{		
		switch( pMsg->wParam )
        { 
          case VK_LEFT://�������
			  MessageBox(_T("LEFT clicked!!!!"));
			  break;
		  case VK_NUMPAD0:
			  MessageBox(_T("0 clicked!!!!"));
			  break;
		  case 0x61:
		  case 0x62:
		  case 0x63:
			  MessageBox(_T("a clicked!!!!"));
			  break;
		  case 'A':
			  MessageBox(_T("A clicked!!!!"));
			  break;
		  case 0x38:
			  MessageBox(_T("8 clicked!!!!"));
			  break;
		  case VK_OEM_PLUS:
			   if(GetAsyncKeyState(VK_SHIFT) & 0x8000)
				   MessageBox(_T("+ clicked!!!!"));
			   else
				   MessageBox(_T("= clicked!!!!"));
			   break;
		  default:
			  break;
		}

	}

	return CDialogEx::PreTranslateMessage(pMsg);
}
