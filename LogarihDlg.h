#if !defined(AFX_LOGARIHDLG_H__43E1E6DC_0498_469E_95A7_AFACA6494662__INCLUDED_)
#define AFX_LOGARIHDLG_H__43E1E6DC_0498_469E_95A7_AFACA6494662__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LogarihDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLogarihDlg dialog

class CLogarihDlg : public CDialog
{
// Construction
public:
	CLogarihDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLogarihDlg)
	enum { IDD = IDD_DLG_LOGA };
	int	m_nConst;	
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLogarihDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLogarihDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGARIHDLG_H__43E1E6DC_0498_469E_95A7_AFACA6494662__INCLUDED_)
