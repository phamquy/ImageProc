// ImageProcessing.h : main header file for the IMAGEPROCESSING application
//

#if !defined(AFX_IMAGEPROCESSING_H__816E867F_4F38_4948_A407_B7BBB2AEE84F__INCLUDED_)
#define AFX_IMAGEPROCESSING_H__816E867F_4F38_4948_A407_B7BBB2AEE84F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CImgApp:
// See ImageProcessing.cpp for the implementation of this class
//

#include "MainFrm.h"

class CImgApp : public CWinApp
{
public:
	CImgApp();
	ULONG_PTR m_gdiplusToken;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImgApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CImgApp)
	afx_msg void OnAppAbout();
	afx_msg void OnBtnTest();
	afx_msg void OnFileClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CMainFrame* m_pMainframe;
	CMultiDocTemplate* m_pDocTemplate;
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEPROCESSING_H__816E867F_4F38_4948_A407_B7BBB2AEE84F__INCLUDED_)
