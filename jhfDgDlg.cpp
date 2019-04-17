
// jhfDgDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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


// CjhfDgDlg 对话框




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


// CjhfDgDlg 消息处理程序

BOOL CjhfDgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	if( !m_ToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_ALIGN_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS ) ||  
    !m_ToolBar.LoadToolBar(IDR_TOOLBAR))  
	{  
		TRACE0("未能创建工具栏\n");  
		AfxMessageBox(_T("未能创建工具栏\n"));  
		return FALSE;      // 未能创建  
	}  
	m_ToolBar.ShowWindow(SW_SHOW);  

	m_bitmap.LoadBitmapW(IDB_BITMAP);  

	m_ImageList.Create(32,32, ILC_COLOR32 | ILC_MASK,0,0);  
	m_ImageList.Add(&m_bitmap, RGB(0, 0, 0));  
	m_ToolBar.GetToolBarCtrl().SetImageList(&m_ImageList); 

	//控件条定位  
    RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0); 

	m_check1.SetCheck(true);
	((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(true);

	((CButton *)GetDlgItem(IDC_SEX_GIRL))->SetCheck(true);

	m_list1.AddString(_T("jhf"));
	m_list1.AddString(_T("myf"));
	m_list1.AddString(_T("wyl"));
	m_list1.AddString(_T("fk"));


	m_combo1.AddString(_T("数学"));
	m_combo1.AddString(_T("英语"));
	m_combo1.AddString(_T("语文"));
	m_combo1.AddString(_T("体育"));
	m_combo1.SetCurSel(0);

	RECT rect;
	
	rect.left = 10;
	rect.top = 250;
	rect.right = 90;
	rect.bottom = 300;

	//可以自己手动添加或者动态添加控件
	m_ownBtn.Create(_T("自建按钮"),BS_CHECKBOX,rect,this,ID_OWNBTN);
	m_ownBtn.EnableWindow(false);
	m_ownBtn.ShowWindow(SW_SHOW);

	//注意：spin控件的auto butty要设成true
	CEdit *prow=(CEdit *)GetDlgItem(IDC_NUM_EDIT); 
	m_spin.SetBuddy(prow);
	m_spin.SetRange(1,100); 
	m_spin.SetBase(1); 
	m_spin.SetPos(2);

	//设置定时器
	SetTimer(10,1000,NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CjhfDgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CjhfDgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CjhfDgDlg::OnSleep()
{
	// TODO: 在此添加控件通知处理程序代码
	//MessageBox(L"JHF is sleeping!");
	
	//模式对话框显示方式
	//COtherDLG m_otherDG;
	//m_otherDG.DoModal();

	//非模式对话框显示方式
	COtherDLG* m_otherDG;
	m_otherDG = new COtherDLG;
	m_otherDG->Create(IDD_OTHERDLG,this);
	m_otherDG->ShowWindow(SW_SHOW);

}


void CjhfDgDlg::OnDblEvent()
{
	// TODO: 在此添加控件通知处理程序代码
	CSecondDlg m_secondDLG;
	m_secondDLG.DoModal();
}


void CjhfDgDlg::OnEnKillfocusEdit1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(true);
}


void CjhfDgDlg::OnLbnSelchangeList1()
{
	// TODO: 在此添加控件通知处理程序代码
	if( m_list1.GetCurSel() == 2)
		MessageBox(L"wyl is choosing!");
}


void CjhfDgDlg::OnAbout()
{
	// TODO: 在此添加命令处理程序代码
	CAboutDlg m_adg;
	m_adg.DoModal();
}


void CjhfDgDlg::OnOpen()
{
	// TODO: 在此添加命令处理程序代码
	MessageBox(_T("click open!"));
}

void CjhfDgDlg::OnShowMSG()
{
	MessageBox(_T("Show Message!"));
}


void CjhfDgDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	// TODO: 在此处添加消息处理程序代码
	//MessageBox(_T("Size changed!"));
}


void CjhfDgDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(nIDEvent == 10)
	{
		m_time += 1;
		UpdateData(false);
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CjhfDgDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MessageBox(_T("Mouse clicked!"));

	CDialogEx::OnLButtonDown(nFlags, point);
}


//void CjhfDgDlg::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
//{
//	// TODO: 在此添加消息处理程序代码和/或调用默认值
//	MessageBox(_T("Keyboard clicked!"));
//
//	CDialogEx::OnChar(nChar, nRepCnt, nFlags);
//}


BOOL CjhfDgDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if( pMsg->message == WM_KEYDOWN )
	{		
		switch( pMsg->wParam )
        { 
          case VK_LEFT://按下左键
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
