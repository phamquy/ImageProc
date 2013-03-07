// ImgDoc.h : interface of the CImgDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMGDOC_H__72379A01_E7DF_4538_AB47_BD1A8374E3E9__INCLUDED_)
#define AFX_IMGDOC_H__72379A01_E7DF_4538_AB47_BD1A8374E3E9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// Include file [12/17/2007 QUYPS]
#include "ImgSource.h"
#include "Include.h"	// Added by ClassView

class CImgDoc;
// ImgDoc list type definition [12/17/2007 QUYPS]
typedef CTypedPtrArray<CObArray, CImgDoc*> DocList;

class CImgDoc : public CDocument
{

protected: // create from serialization only
	CImgDoc();
	DECLARE_DYNCREATE(CImgDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImgDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	void	SetSource(CImgSource* pNewSrc)
	{
		if (m_pSource != NULL)
		{
			delete m_pSource;
		}
		m_pSource = pNewSrc;
	}
	CImgSource* GetSource(){return m_pSource;}
	procStatus Draw(Graphics* in_pGraph, const CRect& in_rcArea);
	INT RemoveAllChilds();
	INT RemoveChildAt(INT in_nPos);
	INT SetParentSrc(CImgDoc* in_pParentSrc);
	INT AddChild(CImgDoc* in_pChildSrc);
	CImgDoc* GetChildRefAt(INT in_nPos);
	CImgDoc* GetParentRef();
	INT GetNumberOfChild();
	virtual ~CImgDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	// List of child document [12/17/2007 QUYPS]
	DocList m_lstChildList;
	
	// Parent Doc [12/17/2007 QUYPS]
	CImgDoc* m_pParent;

	//Image source
	CImgSource* m_pSource;
	
// Generated message map functions
protected:
	//{{AFX_MSG(CImgDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMGDOC_H__72379A01_E7DF_4538_AB47_BD1A8374E3E9__INCLUDED_)
