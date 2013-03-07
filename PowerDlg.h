#if !defined(AFX_POWERDLG_H__DED541BE_94EC_4658_B92C_3220D53EC8D8__INCLUDED_)
#define AFX_POWERDLG_H__DED541BE_94EC_4658_B92C_3220D53EC8D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PowerDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPowerDlg dialog

class CPowerDlg : public CDialog
{
// Construction 
public:
	CPowerDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CPowerDlg)
	enum { IDD = IDD_DLG_POWER };
	int		m_nConst;
	double	m_dExp;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPowerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPowerDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POWERDLG_H__DED541BE_94EC_4658_B92C_3220D53EC8D8__INCLUDED_)
