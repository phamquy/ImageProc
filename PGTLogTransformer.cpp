// PGTLogTransformer.cpp: implementation of the CPGTLogTransformer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "PGTLogTransformer.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include <math.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPGTLogTransformer::CPGTLogTransformer()
{
	m_eType = eLogarithm;
}

CPGTLogTransformer::CPGTLogTransformer(BYTE in_nC)
{
	m_eType = eLogarithm;
	InitLogTransform(in_nC);
}

CPGTLogTransformer::~CPGTLogTransformer()
{

}

VOID CPGTLogTransformer::InitLogTransform( BYTE C )
{
	for (INT i=0;i<IMP_GRAY_LEVELS;i++)
	{
		DOUBLE dTemp = (C * logf(1 + i) * 255) / logf(256);
		m_nLookUpTable[i] =  dTemp;
	}
}
