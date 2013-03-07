// PIESpatialHPF.cpp: implementation of the CPIESpatialHPF class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "PIESpatialHPF.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPIESpatialHPF::CPIESpatialHPF()
{

}

CPIESpatialHPF::~CPIESpatialHPF()
{

}

//************************************
// Method:    ApplyProcessor
// FullName:  CPIESpatialHPF::ApplyProcessor
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * in_pImgSrc
// Parameter: CImgSource * out_ImgResult
//************************************
procStatus CPIESpatialHPF::ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult)
{
	ASSERT(FALSE);
	return eNormal;
}
