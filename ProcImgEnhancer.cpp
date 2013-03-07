// ProcImgEnhancer.cpp: implementation of the CProcImgEnhancer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "ProcImgEnhancer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProcImgEnhancer::CProcImgEnhancer()
{

}

CProcImgEnhancer::~CProcImgEnhancer()
{

}

//************************************
// Method:    ApplyProcessor
// FullName:  CProcImgEnhancer::ApplyProcessor
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * in_pImgSrc
// Parameter: CImgSource * out_ImgResult
//************************************
procStatus CProcImgEnhancer::ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult)
{
	ASSERT(FALSE);
	return eNormal;
}
