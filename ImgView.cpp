// ImgView.cpp : implementation of the CImgView class
//

#include "stdafx.h"
#include "ImageProcessing.h"

#include "ImgDoc.h"
#include "ImgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// TEMPORARY [12/19/2007 QUYPS]
#include "2DRaw.h"
#include "Mask.h"
#include "RawImgLoader.h"
#include "ImgSource.h"
#include "FormatedImgLoader.h"
#include "RawImgSaver.h"
#include "Utility.h"
#include "Histogram.h"
#include "FormatedImgSaver.h"
#include "FFTMachine.h"
#include "ProcGrayTransformer.h"
#include "PGTLogTransformer.h"
#include "PGTPowerTransformer.h"
#include "PGTReveser.h"
#include "PGTThresolder.h"
#include "PHEEqualizer.h"
#include "PHEMatcher.h"
#include "PHEStretcher.h"
#include "PEDLaplacian.h"
#include "PEDPrewitt.h"
#include "PEDRobert.h"
#include "PEDSobel.h"
#include "LaplacianSelectDlg.h"
#include "ThresoldDlg.h"
#include "PowerDlg.h"
#include "LogarihDlg.h"
#include "MatchingDlg.h"


/////////////////////////////////////////////////////////////////////////////
// CImgView

IMPLEMENT_DYNCREATE(CImgView, CView)

BEGIN_MESSAGE_MAP(CImgView, CView)
	//{{AFX_MSG_MAP(CImgView)
	ON_COMMAND(ID_OP_LAPLACIAN, OnOpLaplacian)
	ON_COMMAND(ID_OP_SOBEL, OnOpSobel)
	ON_COMMAND(ID_OP_PREWITT, OnOpPrewitt)
	ON_COMMAND(ID_OP_ROBERT, OnOpRobert)
	ON_COMMAND(ID_OP_THRESOLD, OnOpThresold)
	ON_COMMAND(ID_OP_POWER, OnOpPower)
	ON_COMMAND(ID_OP_LOG, OnOpLog)
	ON_COMMAND(ID_OP_REVERSE, OnOpReverse)
	ON_COMMAND(ID_HIS_QUALIZE, OnHisQualize)
	ON_COMMAND(ID_HIS_STRETCH, OnHisStretch)
	ON_COMMAND(ID_HIS_MATCHING, OnHisMatching)
	ON_COMMAND(ID_OP_FFTVIEW, OnOpFftview)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImgView construction/destruction

CImgView::CImgView()
{
	// TODO: add construction code here

}

CImgView::~CImgView()
{
}

BOOL CImgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CImgView drawing

void CImgView::OnDraw(CDC* pDC)
{
	CImgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	// TEST [12/28/2007 QUYPS]
	CRect rect;
	GetClientRect(&rect);
	Graphics graphics(pDC->m_hDC);
	pDoc->Draw(&graphics,rect);
}

/////////////////////////////////////////////////////////////////////////////
// CImgView printing

BOOL CImgView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CImgView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CImgView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CImgView diagnostics

#ifdef _DEBUG
void CImgView::AssertValid() const
{
	CView::AssertValid();
}

void CImgView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CImgDoc* CImgView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CImgDoc)));
	return (CImgDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CImgView message handlers


//************************************
// Method:    OnOpLaplacian
// FullName:  CImgView::OnOpLaplacian
// Access:    protected 
// Returns:   void
// Qualifier:
//************************************
void CImgView::OnOpLaplacian() 
{
	// TODO: Add your command handler code here
	procStatus eRetCode = eNormal;
	CLaplacianSelectDlg oDlgSelect;
	INT nRes = oDlgSelect.DoModal();
	if(nRes == IDOK)
	{
		MaskType eType;
		if(oDlgSelect.m_nLaptype == 0) eType = eLaplacian1_4;
		else if(oDlgSelect.m_nLaptype == 1)eType = eLaplacian1_8;
		else eType = eLaplacian1_2_4;
		CPEDLaplacian oLap(eType);
		
		eRetCode = process(&oLap);
		if(eRetCode != eNormal)
		{
			AfxMessageBox(CUtility::MessageTranslate(eRetCode));
		}
	}
}

//************************************
// Method:    OnOpSobel
// FullName:  CImgView::OnOpSobel
// Access:    protected 
// Returns:   void
// Qualifier:
//************************************
void CImgView::OnOpSobel() 
{
	// TODO: Add your command handler code here
	procStatus eRetCode = eNormal;
	CPEDSobel oSobel;
	
	eRetCode = process(&oSobel);
	if(eRetCode != eNormal)
	{
		AfxMessageBox(CUtility::MessageTranslate(eRetCode));
	}
}

//************************************
// Method:    OnOpPrewitt
// FullName:  CImgView::OnOpPrewitt
// Access:    protected 
// Returns:   void
// Qualifier:
//************************************
void CImgView::OnOpPrewitt() 
{
	// TODO: Add your command handler code here
	procStatus eRetCode = eNormal;
	CPEDPrewitt oPrewitt;
	eRetCode = process(&oPrewitt);
	if(eRetCode != eNormal)
	{
		AfxMessageBox(CUtility::MessageTranslate(eRetCode));
	}
}

//************************************
// Method:    OnOpRobert
// FullName:  CImgView::OnOpRobert
// Access:    protected 
// Returns:   void
// Qualifier:
//************************************
void CImgView::OnOpRobert() 
{
	// TODO: Add your command handler code here
	procStatus eRetCode = eNormal;
	CPEDRobert oRobert;
	
	eRetCode = process(&oRobert);
	if(eRetCode != eNormal)
	{
		AfxMessageBox(CUtility::MessageTranslate(eRetCode));
	}
}

//************************************
// Method:    OnOpThresold
// FullName:  CImgView::OnOpThresold
// Access:    protected 
// Returns:   void
// Qualifier:
//************************************
void CImgView::OnOpThresold() 
{
	// TODO: Add your command handler code here
	procStatus eRetCode = eNormal;
	CThresoldDlg oDlg;
	INT nRes = oDlg.DoModal();
	if(nRes == IDOK)
	{
		CPGTThresolder oThresold(oDlg.m_nThresold);
		
		eRetCode = process(&oThresold);
		if(eRetCode != eNormal) 
		{
			AfxMessageBox(CUtility::MessageTranslate(eRetCode));
		}
	}	
}

//************************************
// Method:    OnOpPower
// FullName:  CImgView::OnOpPower
// Access:    protected 
// Returns:   void
// Qualifier:
//************************************
void CImgView::OnOpPower() 
{
	// TODO: Add your command handler code here
	procStatus eRetCode = eNormal;
	CPowerDlg oDlg;
	INT nRes = oDlg.DoModal();
	
	if(nRes == IDOK)
	{
		CPGTPowerTransformer oPower(oDlg.m_nConst, oDlg.m_dExp);
		eRetCode = process(&oPower);
		if(eRetCode != eNormal)
		{
			AfxMessageBox(CUtility::MessageTranslate(eRetCode));
		}
	}
}

//************************************
// Method:    OnOpLog
// FullName:  CImgView::OnOpLog
// Access:    protected 
// Returns:   void
// Qualifier:
//************************************
void CImgView::OnOpLog() 
{
	// TODO: Add your command handler code here
	procStatus eRetCode = eNormal;
	CLogarihDlg oDlg;
	INT nRes = oDlg.DoModal();		
	if(nRes == IDOK)
	{
		CPGTLogTransformer oLog(oDlg.m_nConst);
		
		eRetCode = process(&oLog);
		if(eRetCode != eNormal)
		{
			AfxMessageBox(CUtility::MessageTranslate(eRetCode));
		}
	}	
}

//************************************
// Method:    OnOpReverse
// FullName:  CImgView::OnOpReverse
// Access:    protected 
// Returns:   void
// Qualifier:
//************************************
void CImgView::OnOpReverse() 
{
	// TODO: Add your command handler code here
	procStatus eRetCode = eNormal;
	CPGTReveser oRev;
	eRetCode = process(&oRev);
	if(eRetCode != eNormal)
	{
		AfxMessageBox(CUtility::MessageTranslate(eRetCode));
	}
}

//************************************
// Method:    OnHisQualize
// FullName:  CImgView::OnHisQualize
// Access:    protected 
// Returns:   void
// Qualifier:
//************************************
void CImgView::OnHisQualize() 
{
	procStatus eRetCode = eNormal;
	// TODO: Add your command handler code here
	CPHEEqualizer oEqualize;
	eRetCode = process(&oEqualize);
	if(eRetCode != eNormal)
	{
		AfxMessageBox(CUtility::MessageTranslate(eRetCode));
	}
}

//************************************
// Method:    OnHisStretch
// FullName:  CImgView::OnHisStretch
// Access:    protected 
// Returns:   void
// Qualifier:
//************************************
void CImgView::OnHisStretch() 
{
	// TODO: Add your command handler code here
	procStatus eRetCode = eNormal;
	CPHEStretcher oStretcher;
	eRetCode = process(&oStretcher);
	if(eRetCode != eNormal)
	{
		AfxMessageBox(CUtility::MessageTranslate(eRetCode));
	}
}

//************************************
// Method:    OnHisMatching
// FullName:  CImgView::OnHisMatching
// Access:    protected 
// Returns:   void
// Qualifier:
//************************************
void CImgView::OnHisMatching() 
{
	// TODO: Add your command handler code here	
	procStatus eRetCode = eNormal;
	CMultiDocTemplate* pDocTemplate = ((CImgApp*)AfxGetApp())->m_pDocTemplate;
	ImgSrcList imgList;
	
	POSITION curDocPos = pDocTemplate->GetFirstDocPosition();
	
	while(curDocPos != NULL)
	{
		CImgDoc* curDoc  =	(CImgDoc*)pDocTemplate->GetNextDoc(curDocPos);
		CImgSource* imgSrc = curDoc->GetSource();
		if (imgSrc->GetType() >= eSrcMonoBitmap)
		{
			imgList.Add(imgSrc);
		}		
	}

	CMatchingDlg oDlg;
	oDlg.m_pImgList = &imgList;
	INT nRes = oDlg.DoModal();

	if(nRes == IDOK)
	{
		CImgSource* pImgSelected = imgList.GetAt(oDlg.m_nSelected);
		
		CHistogram oHis;
		eRetCode = pImgSelected->GetHistoram(oHis);
		
		if(eRetCode == eNormal)
		{
			CPHEMatcher oMatcher(&oHis);
			eRetCode = process(&oMatcher);
			if(eRetCode != eNormal)
			{
				AfxMessageBox(CUtility::MessageTranslate(eRetCode));
			}
		}	
	}	
}

//************************************
// Method:    OnOpFftview
// FullName:  CImgView::OnOpFftview
// Access:    protected 
// Returns:   void
// Qualifier:
//************************************
void CImgView::OnOpFftview() 
{
	// TODO: Add your command handler code here
	CImgDoc* pDoc = GetDocument();
	CFFTMachine oFFmachine;
	CImgFourierSource* imgRed = new CImgFourierSource();
	
	oFFmachine.Run(pDoc->GetSource(), imgRed, eForward);
	
	CImgApp* pApp = (CImgApp*)AfxGetApp();
	CMultiDocTemplate* pTemplate = pApp->m_pDocTemplate;
	CImgDoc* newDoc = (CImgDoc*)pTemplate->OpenDocumentFile(NULL);
	newDoc->SetTitle(pDoc->GetTitle() + IMP_SUF_FOURIER);
	newDoc->SetModifiedFlag();
	newDoc->SetSource(imgRed);
	newDoc->SetParentSrc(pDoc);
	pDoc->AddChild(newDoc);
}

//************************************
// Method:    process
// FullName:  CImgView::process
// Access:    protected 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgProcessor * pProc
//************************************
procStatus CImgView::process(CImgProcessor *pProc)
{
	procStatus eRetCode = eNormal;

	CImgDoc* pDoc = NULL;
	CImgSource* imgRes = NULL;

	pDoc = GetDocument();
	if (pDoc == NULL)
		eRetCode = eSystemErr;
	else
		imgRes = new CImgSource();
	
	if (imgRes == NULL)
		eRetCode = eMemAllocErr;
	

	if(eRetCode == eNormal)
	{
		eRetCode = pProc->ApplyProcessor(pDoc->GetSource(), imgRes);
		if(eRetCode == eNormal)
		{
			CImgApp* pApp = (CImgApp*)AfxGetApp();
			CMultiDocTemplate* pTemplate = pApp->m_pDocTemplate;
			CImgDoc* newDoc = (CImgDoc*)pTemplate->OpenDocumentFile(NULL);
			newDoc->SetTitle(imgRes->GetName());
			newDoc->SetModifiedFlag();
			newDoc->SetSource(imgRes);
			newDoc->SetParentSrc(pDoc);
			pDoc->AddChild(newDoc);
		}		
	}
	else
	{
		delete imgRes;
	}

	return eRetCode;
}
