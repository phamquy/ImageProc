// PGTReveser.cpp: implementation of the CPGTReveser class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "PGTReveser.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPGTReveser::CPGTReveser()
{
	m_eType = eInvert;
	for (INT i=0;i<IMP_GRAY_LEVELS; i++)
	{
		m_nLookUpTable[i] = IMP_GRAY_LEVELS - i -1;
	}
}

CPGTReveser::~CPGTReveser()
{

}
