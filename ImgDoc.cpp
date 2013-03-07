// ImgDoc.cpp : implementation of the CImgDoc class
//

#include "stdafx.h"
#include "ImageProcessing.h"

#include "ImgDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#include "FormatedImgLoader.h"
#include "RawImgLoader.h"
#include "Utility.h"
#include "RawInfoDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CImgDoc

IMPLEMENT_DYNCREATE(CImgDoc, CDocument)

BEGIN_MESSAGE_MAP(CImgDoc, CDocument)
	//{{AFX_MSG_MAP(CImgDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImgDoc construction/destruction

CImgDoc::CImgDoc()
{
	// TODO: add one-time construction code here
	m_pParent = NULL;
	m_lstChildList.SetSize(0);
	m_pSource = NULL;
}

CImgDoc::~CImgDoc()
{
	delete m_pSource;
}

BOOL CImgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CImgDoc serialization

void CImgDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CImgDoc diagnostics

#ifdef _DEBUG
void CImgDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CImgDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImgDoc commands

// return number of child this document has
INT CImgDoc::GetNumberOfChild()
{
	return m_lstChildList.GetSize();
}

// return reference to parant source
CImgDoc* CImgDoc::GetParentRef()
{
	return m_pParent;
}

//return reger
CImgDoc* CImgDoc::GetChildRefAt(INT in_nPos)
{	
	CImgDoc* pTemp = m_lstChildList[in_nPos];
	return pTemp;
}

//Add new child document, return index of added element
INT CImgDoc::AddChild(CImgDoc *in_pChildSrc)
{
	return m_lstChildList.Add(in_pChildSrc);
	
}

//Set parent reference, parent pointer will be null if it is a toplevel
INT CImgDoc::SetParentSrc(CImgDoc *in_pParentSrc)
{
	m_pParent = in_pParentSrc;
	return eNormal;
}

//remove child source at specified position
INT CImgDoc::RemoveChildAt(INT in_nPos)
{
	//Unset parent source
	m_lstChildList[in_nPos]->SetParentSrc(NULL);

	//remove from this list
	m_lstChildList.RemoveAt(in_nPos);

	return eNormal;
}


//Remove all children source
INT CImgDoc::RemoveAllChilds()
{
	//Clear parent for all child
	for(int i=0; i< m_lstChildList.GetSize(); i++ )
	{
		m_lstChildList[i]->SetParentSrc(NULL);
	}

	m_lstChildList.RemoveAll();

	return eNormal;
}

BOOL CImgDoc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	// TEST [12/28/2007 QUYPS]
	BOOL retVal = TRUE;
	FileType eType = CUtility::GetFileType(lpszPathName);
	ImgSrcList imgList;
	procStatus sts = eNormal;
	if (eType == eUnformated)
	{
		CRawInfoDlg infoDlg;
		INT nRes = infoDlg.DoModal();
		if(nRes == IDOK)	
		{			
			t_RawSize tSize;
			tSize.nWidth = infoDlg.m_nCols;
			tSize.nHeight = infoDlg.m_nRows;
			CRawImgLoader oRLoader;
			oRLoader.SetFilePath(lpszPathName);
			oRLoader.m_tSize = tSize;
			sts = oRLoader.Load(&imgList);
			if(sts == eNormal)	
			{
				m_pSource = imgList.GetAt(0);				
				retVal = TRUE;
			}
			else 
			{
				retVal = FALSE;
			}
		}
		else retVal = FALSE;		
	}
	else if(eType == eFormated)
	{
		CFormatedImgLoader oLoader;
		oLoader.SetFilePath(lpszPathName);
		oLoader.Load(&imgList);
		
		//color image
		m_pSource = imgList.GetAt(0);
		
		for (int j=1; j< imgList.GetSize(); j++)
		{
			
			CImgApp* pApp = (CImgApp*)AfxGetApp();
			CMultiDocTemplate* pTemplate = pApp->m_pDocTemplate;
			CImgDoc* newDoc = (CImgDoc*)pTemplate->OpenDocumentFile(NULL);
			CImgSource* imgSrc = imgList.GetAt(j);
			newDoc->SetTitle(imgSrc->GetName());
			newDoc->SetModifiedFlag();
			newDoc->SetSource(imgSrc);
			newDoc->SetParentSrc(this);
			AddChild(newDoc);
		}
	}
	else
	{
		retVal = FALSE;
	}
	
	return TRUE;
}

//************************************
// Method:    Draw
// FullName:  CImgDoc::Draw
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: Graphics * in_pGraph
// Parameter: const Rect & in_rcArea
//************************************
procStatus CImgDoc::Draw( Graphics* in_pGraph, const CRect& in_rcArea )
{
	return m_pSource->Draw(in_pGraph, in_rcArea);
}

BOOL CImgDoc::OnSaveDocument(LPCTSTR lpszPathName) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CDocument::OnSaveDocument(lpszPathName);
}
