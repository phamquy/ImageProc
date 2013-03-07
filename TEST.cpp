// TEST.cpp : implementation file
//

#include "stdafx.h"
#include "ImageProcessing.h"
#include "TEST.h"


// CTEST dialog

IMPLEMENT_DYNAMIC(CTEST, CDialog)

CTEST::CTEST(CWnd* pParent /*=NULL*/)
	: CDialog(CTEST::IDD, pParent)
{

}

CTEST::~CTEST()
{
}

void CTEST::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTEST, CDialog)
END_MESSAGE_MAP()


// CTEST message handlers
