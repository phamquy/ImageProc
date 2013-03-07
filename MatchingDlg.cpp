// MatchingDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "MatchingDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "ImgSource.h"

/////////////////////////////////////////////////////////////////////////////
// CMatchingDlg dialog


CMatchingDlg::CMatchingDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMatchingDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMatchingDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_pImgList = NULL;
}

void CMatchingDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMatchingDlg)
	DDX_Control(pDX, IDC_IMG_LIST, m_lstImglist);
	//DDX_Control(pDX, IDC_ST_PREVIEW, m_stPreview);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMatchingDlg, CDialog)
	//{{AFX_MSG_MAP(CMatchingDlg)
	ON_LBN_SELCHANGE(IDC_IMG_LIST, OnSelchangeImgList)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMatchingDlg message handlers

BOOL CMatchingDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(m_pImgList != NULL)
	{
		for (INT i=0; i<m_pImgList->GetSize(); i++)
		{
			CImgSource* pImg = m_pImgList->GetAt(i);
			m_lstImglist.AddString(pImg->GetName());				
		}
	}
	m_nSelected = 0;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMatchingDlg::OnSelchangeImgList() 
{
	// TODO: Add your control notification handler code here
	m_nSelected = m_lstImglist.GetCurSel();
	Invalidate();
	//INT nCurPos = m_lstImglist.GetCurSel();
	
}

void CMatchingDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting	
	// TODO: Add your message handler code here
	if(m_nSelected >= 0)
	{
		Graphics graph(dc);
		CRect prevRect;
		CRect dlgRect;
		
		GetClientRect(dlgRect);
		prevRect.top = dlgRect.top +15;
		prevRect.bottom = dlgRect.bottom - 52;
		prevRect.left = dlgRect.left + 259;
		prevRect.right = dlgRect.right - 15;
		
					
		CImgSource* pCurSrc = m_pImgList->GetAt(m_nSelected);
		Bitmap* pCurBmp = pCurSrc->GetSourceRef();

		graph.DrawImage(pCurBmp, prevRect.left, prevRect.top, prevRect.Width(), prevRect.Height());

	}		
}
