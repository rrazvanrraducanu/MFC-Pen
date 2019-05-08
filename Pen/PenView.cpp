
// PenView.cpp : implementation of the CPenView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Pen.h"
#endif

#include "PenDoc.h"
#include "PenView.h"
#include "CControlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPenView

IMPLEMENT_DYNCREATE(CPenView, CView)

BEGIN_MESSAGE_MAP(CPenView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPenView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CPenView construction/destruction

CPenView::CPenView() noexcept
{
	// TODO: add construction code here
	m_penita = 1;
	m_grosime = 1;
	m_text = "";
	m_culoare = RGB(0, 0, 255);
	m_culoareText = RGB(255, 0, 0);
}

CPenView::~CPenView()
{
}

BOOL CPenView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CPenView drawing

void CPenView::OnDraw(CDC* /*pDC*/)
{
	CPenDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CPenView printing


void CPenView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPenView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CPenView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CPenView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CPenView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPenView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPenView diagnostics

#ifdef _DEBUG
void CPenView::AssertValid() const
{
	CView::AssertValid();
}

void CPenView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPenDoc* CPenView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPenDoc)));
	return (CPenDoc*)m_pDocument;
}
#endif //_DEBUG


// CPenView message handlers


void CPenView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	CControlDlg dlg;
	int res = dlg.DoModal();
	if (res == IDOK) {
		m_penita = dlg.m_edit1;
		m_grosime = dlg.m_edit2;
		m_text = dlg.m_edit3;
		m_culoare = dlg.m_color;
		m_culoareText = dlg.m_colorText;
	}
	CClientDC dc(this);
	CPen pen(m_penita, m_grosime, m_culoare);
	dc.SelectObject(&pen);
	dc.Rectangle(10, 10, 300, 300);
	dc.SetTextColor(m_culoareText);
	dc.TextOut(400, 400, m_text);
	CView::OnLButtonDown(nFlags, point);
}
