
// PenView.h : interface of the CPenView class
//

#pragma once


class CPenView : public CView
{
protected: // create from serialization only
	CPenView() noexcept;
	DECLARE_DYNCREATE(CPenView)

// Attributes
public:
	CPenDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CPenView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	int m_penita;
	int m_grosime;
	CString m_text;
	COLORREF m_culoare;
	COLORREF m_culoareText;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in PenView.cpp
inline CPenDoc* CPenView::GetDocument() const
   { return reinterpret_cast<CPenDoc*>(m_pDocument); }
#endif

