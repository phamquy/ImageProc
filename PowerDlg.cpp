// PowerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "PowerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPowerDlg dialog


CPowerDlg::CPowerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPowerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPowerDlg)
	m_nConst = 0;
	m_dExp = 0.0;
	//}}AFX_DATA_INIT
}


void CPowerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPowerDlg)
	DDX_Text(pDX, IDC_ED_C, m_nConst);
	DDV_MinMaxInt(pDX, m_nConst, 1, 255);
	DDX_Text(pDX, IDC_ED_EXP, m_dExp);
	DDV_MinMaxDouble(pDX, m_dExp, 1.e-002, 25.);
	//}}AFX_DATA_MAP
}
 

BEGIN_MESSAGE_MAP(CPowerDlg, CDialog)
	//{{AFX_MSG_MAP(CPowerDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPowerDlg message handlers

BOOL CPowerDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dExp = 1;
	m_nConst = 1;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
