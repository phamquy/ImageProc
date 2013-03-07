// LaplacianSelectDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "LaplacianSelectDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLaplacianSelectDlg dialog


CLaplacianSelectDlg::CLaplacianSelectDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLaplacianSelectDlg::IDD, pParent)
	, m_nLaptype(0)
{
	//{{AFX_DATA_INIT(CLaplacianSelectDlg)
	//m_nLapType = 0;
	//}}AFX_DATA_INIT
}


void CLaplacianSelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLaplacianSelectDlg)
	DDX_CBIndex(pDX, IDC_CB_LAPTYPE, m_nLaptype);
	//}}AFX_DATA_MAP
	
}


BEGIN_MESSAGE_MAP(CLaplacianSelectDlg, CDialog)
	//{{AFX_MSG_MAP(CLaplacianSelectDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLaplacianSelectDlg message handlers
