// CControlDlg.cpp : implementation file
//

#include "pch.h"
#include "Pen.h"
#include "CControlDlg.h"
#include "afxdialogex.h"


// CControlDlg dialog

IMPLEMENT_DYNAMIC(CControlDlg, CDialogEx)

CControlDlg::CControlDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, m_edit1(0)
	, m_edit2(0)
	, m_edit3(_T(""))
{
	m_color = RGB(255, 0, 0);
	m_colorText = RGB(0, 0, 255);
}

CControlDlg::~CControlDlg()
{
}

void CControlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_edit1);
	DDX_Text(pDX, IDC_EDIT2, m_edit2);
	DDX_Text(pDX, IDC_EDIT3, m_edit3);
}


BEGIN_MESSAGE_MAP(CControlDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CControlDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CControlDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CControlDlg message handlers


void CControlDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.DoModal();
	m_color = dlg.GetColor();
}


void CControlDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.DoModal();
	m_colorText = dlg.GetColor();
}
