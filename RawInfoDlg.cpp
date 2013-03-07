// RawInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "RawInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRawInfoDlg dialog


CRawInfoDlg::CRawInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRawInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CRawInfoDlg)
	m_nCols = 256;
	m_nRows = 256;
	//}}AFX_DATA_INIT
}


void CRawInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRawInfoDlg)
	DDX_Text(pDX, IDC_EDIT_COLS, m_nCols);
	DDV_MinMaxUInt(pDX, m_nCols, 0, 1024);
	DDX_Text(pDX, IDC_EDIT_ROWS, m_nRows);
	DDV_MinMaxUInt(pDX, m_nRows, 0, 1024);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRawInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CRawInfoDlg)
	ON_BN_CLICKED(IDC_CMD_CANCEL, OnCmdCancel)
	ON_BN_CLICKED(IDC_CMD_OK, OnCmdOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRawInfoDlg message handlers

void CRawInfoDlg::OnCmdCancel() 
{
	// TODO: Add your control notification handler code here
	OnCancel();	
}

void CRawInfoDlg::OnCmdOk() 
{
	// TODO: Add your control notification handler code here
	OnOK();
}
