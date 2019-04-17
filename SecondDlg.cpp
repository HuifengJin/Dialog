// SecondDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "jhfDg.h"
#include "SecondDlg.h"
#include "afxdialogex.h"


// CSecondDlg 对话框

IMPLEMENT_DYNAMIC(CSecondDlg, CDialogEx)

CSecondDlg::CSecondDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSecondDlg::IDD, pParent)
{

}

CSecondDlg::~CSecondDlg()
{
}

void CSecondDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSecondDlg, CDialogEx)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CSecondDlg 消息处理程序


BOOL CSecondDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	if( m_bmp.m_hObject != NULL )//判断
         m_bmp.DeleteObject();
     //载入图片
     HBITMAP hbmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
         _T("res//usertile35.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION|LR_LOADFROMFILE);
     if( hbmp == NULL )
         return FALSE;
     //该断程序用来取得加载的BMP的信息//
     m_bmp.Attach( hbmp );
     DIBSECTION ds;
     BITMAPINFOHEADER &bminfo = ds.dsBmih;
     m_bmp.GetObject( sizeof(ds), &ds );
     int cx=bminfo.biWidth;   //得到图像宽度
     int cy=bminfo.biHeight; //得到图像高度
     /////////////////// ////////////////////////////////
     //得到了图像的宽度和高度后,我们就可以对图像大小进行适应,
     //即调整控件的大小,让它正好显示一张图片
     ////////////////////////////////////////////////////
     CRect rect;
     GetDlgItem(IDC_PICDRAW)->GetWindowRect(&rect);
     ScreenToClient(&rect);
     GetDlgItem(IDC_PICDRAW)->MoveWindow(rect.left,rect.top,cx,cy,true);//调整大小

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void CSecondDlg::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: 在此处添加消息处理程序代码
	// 不为绘图消息调用 CDialogEx::OnPaint()

	//CPaintDC dc(this);       //若用此句,得到的是对话框的DC,图片将被绘制在对话框上.
     CPaintDC dc(GetDlgItem(IDC_PICDRAW)); //用此句,得到picture控件的DC,图像将被绘制在控件上
     //CDC dc;
     //dc.m_hDC=::GetDC(NULL);   //若用此两句,得到的是屏幕的DC,图片将被绘制在屏幕上

	 CRect rcclient;
     GetDlgItem(IDC_PICDRAW)->GetClientRect(&rcclient);

     CDC memdc;
     memdc.CreateCompatibleDC(&dc);

     CBitmap bitmap;
     bitmap.CreateCompatibleBitmap(&dc, rcclient.Width(), rcclient.Height());
     memdc.SelectObject( &bitmap );

     CWnd::DefWindowProc(WM_PAINT, (WPARAM)memdc.m_hDC , 0);

     CDC maskdc;
     maskdc.CreateCompatibleDC(&dc);

     CBitmap maskbitmap;
     maskbitmap.CreateBitmap(rcclient.Width(), rcclient.Height(), 1, 1, NULL);
     maskdc.SelectObject( &maskbitmap );
     maskdc.BitBlt( 0, 0, rcclient.Width(), rcclient.Height(), &memdc,
         rcclient.left, rcclient.top, SRCCOPY);

     CBrush brush;
     brush.CreatePatternBrush(&m_bmp);
     dc.FillRect(rcclient, &brush);
     dc.BitBlt(rcclient.left, rcclient.top, rcclient.Width(), rcclient.Height(),
              &memdc, rcclient.left, rcclient.top,SRCPAINT);
     brush.DeleteObject();

	//第二个picture控件中绘制图形
	CWnd *pWnd=GetDlgItem(IDC_OWNDRAW); 
	CDC *pControlDC=pWnd->GetDC(); 
	pWnd->Invalidate(); 
	pWnd->UpdateWindow(); 
	pControlDC->SelectStockObject(BLACK_BRUSH); 
	pControlDC->Rectangle(30,30,100,100); 
	POINT pnt;
	pnt.x = 130;
	pnt.y = 130;
	pControlDC->MoveTo(pnt);
	pnt.x = 200;
	pnt.y = 200;
	pControlDC->LineTo(pnt);
	pWnd->ReleaseDC(pControlDC); 
}
