// VignearDlg.h : header file
//

#if !defined(AFX_VIGNEARDLG_H__A29CBE55_0A4C_4775_AEC8_AA93B094AEB8__INCLUDED_)
#define AFX_VIGNEARDLG_H__A29CBE55_0A4C_4775_AEC8_AA93B094AEB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVignearDlg dialog

class CVignearDlg : public CDialog
{
// Construction
public:
	CVignearDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVignearDlg)
	enum { IDD = IDD_VIGNEAR_DIALOG };
	CEdit	c_edit8;
	CEdit	c_edit7;
	CEdit	c_edit6;
	CEdit	c_edit5;
	CEdit	c_edit4;
	CEdit	c_edit3;
	CEdit	c_edit2;
	CEdit	c_edit1;
	CString	m_edit1;
	CString	m_edit2;
	CString	m_edit3;
	CString	m_edit4;
	CString	m_edit5;
	CString	m_edit6;
	CString	m_edit7;
	CString	m_edit8;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVignearDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVignearDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIGNEARDLG_H__A29CBE55_0A4C_4775_AEC8_AA93B094AEB8__INCLUDED_)
