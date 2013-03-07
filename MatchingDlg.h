#if !defined(AFX_MATCHINGDLG_H__C0510BD4_A9C5_4B76_B1FF_392F7E5B96F4__INCLUDED_)
#define AFX_MATCHINGDLG_H__C0510BD4_A9C5_4B76_B1FF_392F7E5B96F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MatchingDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMatchingDlg dialog

class CMatchingDlg : public CDialog
{
// Construction
public:
	INT m_nSelected;
	ImgSrcList* m_pImgList;
	CMatchingDlg(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CMatchingDlg)
	enum { IDD = IDD_DLG_MATCHIMG };
	CListBox	m_lstImglist;
	//CStatic		m_stPreview;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMatchingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMatchingDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeImgList();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MATCHINGDLG_H__C0510BD4_A9C5_4B76_B1FF_392F7E5B96F4__INCLUDED_)
