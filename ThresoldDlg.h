#if !defined(AFX_THRESOLDDLG_H__457FA67E_7867_4063_B085_50D55E959ABE__INCLUDED_)
#define AFX_THRESOLDDLG_H__457FA67E_7867_4063_B085_50D55E959ABE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ThresoldDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CThresoldDlg dialog

class CThresoldDlg : public CDialog
{
// Construction
public:
	CThresoldDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CThresoldDlg)
	enum { IDD = IDD_DLG_THRE };
	UINT	m_nThresold;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThresoldDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CThresoldDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THRESOLDDLG_H__457FA67E_7867_4063_B085_50D55E959ABE__INCLUDED_)
