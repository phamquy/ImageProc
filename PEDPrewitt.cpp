// PEDPrewitt.cpp: implementation of the CPEDPrewitt class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "PEDPrewitt.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "Utility.h"
#include "Mask.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
CPEDPrewitt::CPEDPrewitt()
{
	m_eType = ePrewitt;
}

CPEDPrewitt::~CPEDPrewitt()
{

}

//************************************
// Method:    ApplyProcessor
// FullName:  CPEDPrewitt::ApplyProcessor
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * in_pImgSrc
// Parameter: CImgSource * out_ImgResult
//************************************
procStatus CPEDPrewitt::ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult)
{
	procStatus eRetCode = eNormal;
	
	CMask oHorizontalMask(ePrewittHoriz);
	CMask oVerticalMask(ePrewittVerti);
	
	CImgSource oHorRes;
	CImgSource oVerRes;
	
	eRetCode = oHorizontalMask.ApplyMask(in_pImgSrc, &oHorRes);
	
	if(eRetCode == eNormal) 
		eRetCode = oVerticalMask.ApplyMask(in_pImgSrc, &oVerRes);

	if(eRetCode == eNormal)
		eRetCode = CUtility::Add2Source(&oVerRes, &oHorRes, out_ImgResult);
	out_ImgResult->SetName(in_pImgSrc->GetName() + IMP_SUF_PREWITT);
	return eRetCode;
}
