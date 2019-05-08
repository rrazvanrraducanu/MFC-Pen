#pragma once


// CControlDlg dialog

class CControlDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CControlDlg)

public:
	CControlDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CControlDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

public:
	int m_edit1;
	int m_edit2;
	CString m_edit3;
	COLORREF m_color;
	COLORREF m_colorText;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
