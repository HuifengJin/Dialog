// SecondDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "jhfDg.h"
#include "SecondDlg.h"
#include "afxdialogex.h"


// CSecondDlg �Ի���

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


// CSecondDlg ��Ϣ�������


BOOL CSecondDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��

	if( m_bmp.m_hObject != NULL )//�ж�
         m_bmp.DeleteObject();
     //����ͼƬ
     HBITMAP hbmp = (HBITMAP)::LoadImage(AfxGetInstanceHandle(),
         _T("res//usertile35.bmp"), IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION|LR_LOADFROMFILE);
     if( hbmp == NULL )
         return FALSE;
     //�öϳ�������ȡ�ü��ص�BMP����Ϣ//
     m_bmp.Attach( hbmp );
     DIBSECTION ds;
     BITMAPINFOHEADER &bminfo = ds.dsBmih;
     m_bmp.GetObject( sizeof(ds), &ds );
     int cx=bminfo.biWidth;   //�õ�ͼ����
     int cy=bminfo.biHeight; //�õ�ͼ��߶�
     /////////////////// ////////////////////////////////
     //�õ���ͼ��Ŀ�Ⱥ͸߶Ⱥ�,���ǾͿ��Զ�ͼ���С������Ӧ,
     //�������ؼ��Ĵ�С,����������ʾһ��ͼƬ
     ////////////////////////////////////////////////////
     CRect rect;
     GetDlgItem(IDC_PICDRAW)->GetWindowRect(&rect);
     ScreenToClient(&rect);
     GetDlgItem(IDC_PICDRAW)->MoveWindow(rect.left,rect.top,cx,cy,true);//������С

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}


void CSecondDlg::OnPaint()
{
	//CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CDialogEx::OnPaint()

	//CPaintDC dc(this);       //���ô˾�,�õ����ǶԻ����DC,ͼƬ���������ڶԻ�����.
     CPaintDC dc(GetDlgItem(IDC_PICDRAW)); //�ô˾�,�õ�picture�ؼ���DC,ͼ�񽫱������ڿؼ���
     //CDC dc;
     //dc.m_hDC=::GetDC(NULL);   //���ô�����,�õ�������Ļ��DC,ͼƬ������������Ļ��

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

	//�ڶ���picture�ؼ��л���ͼ��
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
