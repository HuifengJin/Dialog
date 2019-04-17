// OtherDLG.cpp : 实现文件
//

#include "stdafx.h"
#include "jhfDg.h"
#include "OtherDLG.h"
#include "afxdialogex.h"


// COtherDLG 对话框

IMPLEMENT_DYNAMIC(COtherDLG, CDialogEx)

COtherDLG::COtherDLG(CWnd* pParent /*=NULL*/)
	: CDialogEx(COtherDLG::IDD, pParent)
	, m_hsValue(0)
	, m_hsValue2(0)
{

}

COtherDLG::~COtherDLG()
{
}

void COtherDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER1, m_slide);
	DDX_Control(pDX, IDC_IMAGE, m_pic);
	DDX_Control(pDX, IDC_SCROLLBAR1, m_hScroll);
	DDX_Control(pDX, IDC_SCROLLBAR3, m_hscroll2);
	DDX_Text(pDX, IDC_EDIT1, m_hsValue);
	DDX_Text(pDX, IDC_EDIT2, m_hsValue2);
	DDX_Control(pDX, IDC_PROGRESS1, m_progress);
	DDX_Control(pDX, IDC_SCROLLBAR2, m_vscroll);
	DDX_Control(pDX, IDC_TAB1, m_tab);
}


BEGIN_MESSAGE_MAP(COtherDLG, CDialogEx)
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_SLIDER1, &COtherDLG::OnNMReleasedcaptureSlider1)
	ON_NOTIFY(NM_THEMECHANGED, IDC_SCROLLBAR1, &COtherDLG::OnNMThemeChangedScrollbar1)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_UPDATE, &COtherDLG::OnBnClickedUpdate)
	ON_WM_TIMER()
	ON_WM_VSCROLL()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB, &COtherDLG::OnTcnSelchangeTab)
END_MESSAGE_MAP()


// COtherDLG 消息处理程序


BOOL COtherDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_slide.SetRange(0,100);
	m_slide.SetPos(50);

	m_hScroll.SetScrollRange(0,100);
	m_hScroll.SetScrollPos(50);

	m_hscroll2.SetScrollRange(0,100);
	m_hscroll2.SetScrollPos(0);

	m_vscroll.SetScrollRange(0,100);
	m_vscroll.SetScrollPos(0);

	m_progress.SetRange(0,1000);
	m_progress.SetPos(0);
	m_progress.SetStep(10);
	SetTimer(1,100,NULL);

	//tab
	m_tab.InsertItem(0,_T("系统登录"));  
    m_tab.InsertItem(1,_T("服务器设置"));  
    m_login_tab1.Create(IDD_TAB1,GetDlgItem(IDC_TAB));  
    m_login_tab2.Create(IDD_TAB2,GetDlgItem(IDC_TAB));  
    //获得IDC_TABTEST客户区大小  
	CRect rs;  
	m_tab.GetClientRect(&rs);  
	//调整子对话框在父窗口中的位置，根据实际修改  
	rs.top+=25;  
	rs.bottom-=60;  
	rs.left+=1;  
	rs.right-=10;  
      
	//设置子对话框尺寸并移动到指定位置  
	m_login_tab1.MoveWindow(&rs);  
	m_login_tab2.MoveWindow(&rs);  
	//分别设置隐藏和显示  
	m_login_tab1.ShowWindow(true);  
	m_login_tab2.ShowWindow(false);  
      
	//设置默认的选项卡  
	m_tab.SetCurSel(0); 

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void COtherDLG::OnNMReleasedcaptureSlider1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	int curPos = m_slide.GetPos();

	*pResult = 0;
}


void COtherDLG::OnNMThemeChangedScrollbar1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// 该功能要求使用 Windows XP 或更高版本。
	// 符号 _WIN32_WINNT 必须 >= 0x0501。
	// TODO: 在此添加控件通知处理程序代码

	//这个消息映射目前没发现有什么用

	*pResult = 0;
}


void COtherDLG::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	int ntemp1, ntemp2;
	ntemp1 = pScrollBar->GetScrollPos();
	switch(nSBCode) 
	{ 
		case SB_THUMBTRACK:
			pScrollBar->SetScrollPos(nPos);
			m_hsValue = m_hScroll.GetScrollPos();
			UpdateData(false);
			break;
		case SB_LINELEFT: // 左按钮：100和0与设置的范围有关
			ntemp2 = (100 - 0) / 10; //划为10等份(nmax － nmin)
			if ((ntemp1 - ntemp2) > 0)  //nmin 
			{
				ntemp1 -= ntemp2; 
			}
			else 
			{ 
				ntemp1 = 0;  //nmin
			}
			pScrollBar->SetScrollPos(ntemp1);
			break;
		case SB_LINERIGHT: // 右箭头按钮
			ntemp2 = (100 - 0) / 10;  //(nmax － nmin)
			if ((ntemp1 + ntemp2) < 100) //nmax
			{
				ntemp1 += ntemp2; 
			}
			else 
			{
				ntemp1 = 100; //nmax
			}
			pScrollBar->SetScrollPos(ntemp1);
			break; 
		}

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void COtherDLG::OnBnClickedUpdate()
{
	// TODO: 在此添加控件通知处理程序代码
//	m_hsValue = m_hScroll.GetScrollPos();
//	m_hsValue2 = m_hscroll2.GetScrollPos();
	UpdateData(false);
}


void COtherDLG::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if(m_progress.GetPos()< 1000)
	{
		m_progress.StepIt();
	}
	else
		KillTimer(1);

	CDialogEx::OnTimer(nIDEvent);
}


void COtherDLG::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
		int ntemp1, ntemp2;
	ntemp1 = pScrollBar->GetScrollPos();
	switch(nSBCode) 
	{ 
		case SB_THUMBTRACK:
			pScrollBar->SetScrollPos(nPos);
			m_hsValue2 = pScrollBar->GetScrollPos();
			UpdateData(false);
			break;
		case SB_LINEUP: // 左按钮：100和0与设置的范围有关
			ntemp2 = (100 - 0) / 10; //划为10等份(nmax － nmin)
			if ((ntemp1 - ntemp2) > 0)  //nmin 
			{
				ntemp1 -= ntemp2; 
			}
			else 
			{ 
				ntemp1 = 0;  //nmin
			}
			pScrollBar->SetScrollPos(ntemp1);
			break;
		case SB_LINEDOWN: // 右箭头按钮
			ntemp2 = (100 - 0) / 10;  //(nmax － nmin)
			if ((ntemp1 + ntemp2) < 100) //nmax
			{
				ntemp1 += ntemp2; 
			}
			else 
			{
				ntemp1 = 100; //nmax
			}
			pScrollBar->SetScrollPos(ntemp1);
			break; 
		}

	CDialogEx::OnVScroll(nSBCode, nPos, pScrollBar);
}


void COtherDLG::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
    int CurSel = m_tab.GetCurSel();  
    switch(CurSel)  
    {  
    case 0:  
        m_login_tab1.ShowWindow(true);  
        m_login_tab2.ShowWindow(false);  
        break;  
    case 1:  
        m_login_tab1.ShowWindow(false);  
        m_login_tab2.ShowWindow(true);  
        break;  
    default: ;  
    }  
	*pResult = 0;
}
