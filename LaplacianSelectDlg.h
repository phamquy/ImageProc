#if !defined(AFX_LAPLACIANSELECTDLG_H__94CFED89_78EF_4EEF_8E3E_A4BE30DDAB36__INCLUDED_)
#define AFX_LAPLACIANSELECTDLG_H__94CFED89_78EF_4EEF_8E3E_A4BE30DDAB36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LaplacianSelectDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLaplacianSelectDlg dialog

class CLaplacianSelectDlg : public CDialog
{
// Construction
public:
	CLaplacianSelectDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLaplacianSelectDlg)
	enum { IDD = IDD_DLG_LAPLACIAN };
	//int		m_nLapType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLaplacianSelectDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLaplacianSelectDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	int m_nLaptype;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LAPLACIANSELECTDLG_H__94CFED89_78EF_4EEF_8E3E_A4BE30DDAB36__INCLUDED_)
