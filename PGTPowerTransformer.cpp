// PGTPowerTransformer.cpp: implementation of the CPGTPowerTransformer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "PGTPowerTransformer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include <math.h>
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPGTPowerTransformer::CPGTPowerTransformer()
{
	m_eType = ePower;
}

CPGTPowerTransformer::CPGTPowerTransformer(BYTE C, DOUBLE Gamma)
{
	m_eType = ePower;
	InitPowerTransform(C, Gamma);
}

CPGTPowerTransformer::~CPGTPowerTransformer()
{

}

VOID CPGTPowerTransformer::InitPowerTransform( BYTE C, DOUBLE gamma )
{
	for (INT i=0;i<IMP_GRAY_LEVELS;i++)
	{		
		LONG temp = (C * pow(i,gamma))/(pow(255,gamma-1));
		m_nLookUpTable[i] = min(temp, 255);		 
	}
}
