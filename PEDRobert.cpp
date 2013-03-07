// PEDRobert.cpp: implementation of the CPEDRobert class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "PEDRobert.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "Mask.h"
#include "Utility.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPEDRobert::CPEDRobert()
{
	m_eType = eRobert;
}

CPEDRobert::~CPEDRobert()
{

}

//************************************
// Method:    ApplyProcessor
// FullName:  CPEDRobert::ApplyProcessor
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * in_pImgSrc
// Parameter: CImgSource * out_ImgResult
//************************************
procStatus CPEDRobert::ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult)
{
	procStatus eRetCode = eNormal;
	
	CMask oRobertX(eRobertGx);
	CMask oRobertY(eRobertGx);
	
	CImgSource oGxRes;
	CImgSource oGyRes;
	
	eRetCode = oRobertX.ApplyMask(in_pImgSrc, &oGxRes);
	
	if(eRetCode == eNormal) 
		eRetCode = oRobertY.ApplyMask(in_pImgSrc, &oGyRes);
	
	if(eRetCode == eNormal)
		eRetCode = CUtility::Add2Source(&oGxRes, &oGyRes, out_ImgResult);
	
	out_ImgResult->SetName(in_pImgSrc->GetName() + IMP_SUF_ROBERT);
	return eRetCode;
}
