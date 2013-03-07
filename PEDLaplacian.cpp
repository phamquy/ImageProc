// PEDLaplacian.cpp: implementation of the CPEDLaplacian class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "PEDLaplacian.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPEDLaplacian::CPEDLaplacian()
{
	m_eType = eLaplacian;
	m_eMaskType = eLaplacian1_4;
}

CPEDLaplacian::CPEDLaplacian(MaskType in_eMaskType)
{
	m_eType = eLaplacian;
	ASSERT((in_eMaskType >= eLaplacian1_4)&&(in_eMaskType <= eLaplacian1_2_4));
	m_eMaskType = in_eMaskType;
}

CPEDLaplacian::~CPEDLaplacian()
{

}

//************************************
// Method:    ApplyProcessor
// FullName:  CPEDLaplacian::ApplyProcessor
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * in_pImgSrc
// Parameter: CImgSource * out_ImgResult
//************************************
procStatus CPEDLaplacian::ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult)
{
	procStatus eRetCode = eNormal;
	CMask oMask(m_eMaskType);
	eRetCode = oMask.ApplyMask(in_pImgSrc, out_ImgResult);
	if(eRetCode == eNormal) 
	{
		out_ImgResult->SetName(in_pImgSrc->GetName() + IMP_SUF_LAPLACED);
		out_ImgResult->SetType(in_pImgSrc->GetType());
	}
	
	return eRetCode;
}


