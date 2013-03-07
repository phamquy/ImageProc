// ImgView.h : interface of the CImgView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMGVIEW_H__2283A0EE_DBC0_48AA_93E9_915EF3CE5D3C__INCLUDED_)
#define AFX_IMGVIEW_H__2283A0EE_DBC0_48AA_93E9_915EF3CE5D3C__INCLUDED_

#include "Include.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImgProcessor.h"

class CImgView : public CView
{
protected: // create from serialization only
	CImgView();
	DECLARE_DYNCREATE(CImgView)

// Attributes
public:
	CImgDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImgView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CImgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	procStatus process(CImgProcessor* pProc);
	//{{AFX_MSG(CImgView)
	afx_msg void OnOpLaplacian();
	afx_msg void OnOpSobel();
	afx_msg void OnOpPrewitt();
	afx_msg void OnOpRobert();
	afx_msg void OnOpThresold();
	afx_msg void OnOpPower();
	afx_msg void OnOpLog();
	afx_msg void OnOpReverse();
	afx_msg void OnHisQualize();
	afx_msg void OnHisStretch();
	afx_msg void OnHisMatching();
	afx_msg void OnOpFftview();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ImgView.cpp
inline CImgDoc* CImgView::GetDocument()
   { return (CImgDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMGVIEW_H__2283A0EE_DBC0_48AA_93E9_915EF3CE5D3C__INCLUDED_)
