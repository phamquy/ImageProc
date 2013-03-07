#if !defined(AFX_RAWINFODLG_H__027950AE_0EB7_4055_A732_A6F80B25302F__INCLUDED_)
#define AFX_RAWINFODLG_H__027950AE_0EB7_4055_A732_A6F80B25302F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RawInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRawInfoDlg dialog

class CRawInfoDlg : public CDialog
{
// Construction
public:
	CRawInfoDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CRawInfoDlg)
	enum { IDD = IDD_RAW_INFOR };
	UINT	m_nCols;
	UINT	m_nRows;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRawInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CRawInfoDlg)
	afx_msg void OnCmdCancel();
	afx_msg void OnCmdOk();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RAWINFODLG_H__027950AE_0EB7_4055_A732_A6F80B25302F__INCLUDED_)
