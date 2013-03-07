// ProcEdgeDetector.cpp: implementation of the CProcEdgeDetector class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "ProcEdgeDetector.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProcEdgeDetector::CProcEdgeDetector()
{

}

CProcEdgeDetector::~CProcEdgeDetector()
{

}

//************************************
// Method:    ApplyProcessor
// FullName:  CProcEdgeDetector::ApplyProcessor
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * in_pImgSrc
// Parameter: CImgSource * out_ImgResult
//************************************
procStatus CProcEdgeDetector::ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult)
{
	ASSERT(FALSE);
	return eNormal;
}
