// ThresoldDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "ThresoldDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThresoldDlg dialog


CThresoldDlg::CThresoldDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CThresoldDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CThresoldDlg)
	m_nThresold = 0;
	//}}AFX_DATA_INIT
}


void CThresoldDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CThresoldDlg)
	DDX_Text(pDX, IDC_EDIT_THRESOLD, m_nThresold);
	DDV_MinMaxUInt(pDX, m_nThresold, 0, 255);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CThresoldDlg, CDialog)
	//{{AFX_MSG_MAP(CThresoldDlg)

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThresoldDlg message handlers

BOOL CThresoldDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

