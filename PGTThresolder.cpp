// PGTThresolder.cpp: implementation of the CPGTThresolder class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "PGTThresolder.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPGTThresolder::CPGTThresolder()
{
	m_eType = eThreshold;
}

CPGTThresolder::CPGTThresolder(BYTE threshold)						
{
	m_eType = eThreshold;
	InitThresholdTransform(threshold);
}

CPGTThresolder::~CPGTThresolder()
{

}

//************************************
// Method:    InitThresholdTransform
// FullName:  CPGTThresolder::InitThresholdTransform
// Access:    public 
// Returns:   VOID
// Qualifier:
// Parameter: BYTE threshold
//************************************
VOID CPGTThresolder::InitThresholdTransform(BYTE threshold)
{
	for (INT i=0; i<IMP_GRAY_LEVELS; i++)
	{
		if(i < threshold) m_nLookUpTable[i] = 0;
		if(i > threshold) m_nLookUpTable[i] = 255;		
	}
}