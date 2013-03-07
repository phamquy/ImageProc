// PEDSobel.cpp: implementation of the CPEDSobel class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "PEDSobel.h"

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

CPEDSobel::CPEDSobel()
{
	m_eType = eSobel;
}

CPEDSobel::~CPEDSobel()
{

}

procStatus CPEDSobel::ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult)
{
	procStatus eRetCode = eNormal;
	
	CMask oSobelX(eSobelGx);
	CMask oSobelY(eSobelGx);
	
	CImgSource oGxRes;
	CImgSource oGyRes;
	
	eRetCode = oSobelX.ApplyMask(in_pImgSrc, &oGxRes);
	
	if(eRetCode == eNormal) 
		eRetCode = oSobelY.ApplyMask(in_pImgSrc, &oGyRes);
	
	if(eRetCode == eNormal)
		eRetCode = CUtility::Add2Source(&oGxRes, &oGyRes, out_ImgResult);
	
	out_ImgResult->SetName(in_pImgSrc->GetName() + IMP_SUF_SOBEL);
	return eRetCode;
}
