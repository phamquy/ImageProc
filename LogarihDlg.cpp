// LogarihDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "LogarihDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLogarihDlg dialog


CLogarihDlg::CLogarihDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLogarihDlg::IDD, pParent)
	, m_nConst(0)
{
	//{{AFX_DATA_INIT(CLogarihDlg)
	
	//}}AFX_DATA_INIT
}


void CLogarihDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLogarihDlg)
	//}}AFX_DATA_MAP
	DDX_Text(pDX, IDC_EDIT_CCONS, m_nConst);
	DDV_MinMaxInt(pDX, m_nConst, 0, 10);
}


BEGIN_MESSAGE_MAP(CLogarihDlg, CDialog)
	//{{AFX_MSG_MAP(CLogarihDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLogarihDlg message handlers

BOOL CLogarihDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_nConst = 1;
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
