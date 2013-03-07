// PHEEqualizer.cpp: implementation of the CPHEEqualizer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "PHEEqualizer.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPHEEqualizer::CPHEEqualizer()
{

}

CPHEEqualizer::~CPHEEqualizer()
{

}

//************************************
// Method:    ApplyProcessor
// FullName:  CPHEEqualizer::ApplyProcessor
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * in_pImgSrc
// Parameter: CImgSource * out_ImgResult
//************************************
procStatus CPHEEqualizer::ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult)
{
	ASSERT(in_pImgSrc);
	ASSERT(in_pImgSrc->GetSourceRef());
	ASSERT(out_ImgResult);

	procStatus eRetCode = eNormal;
	//CDWordArray arrProbalility;
	CByteArray arrNewTable;

	CHistogram oSrcHis;
	eRetCode = in_pImgSrc->GetHistoram(oSrcHis);

#ifdef _DEBUG
// 	for (INT i=0; i<IMP_GRAY_LEVELS; i++)
// 	{
// 		TRACE("\nPos:%d \tVal:%d", i, oSrcHis.GetAt(i));
// 	}
// 	TRACE("\nTOTAL:%d", oSrcHis.Accumulate(IMP_GRAY_LEVELS-1));
#endif

	INT nHisSize = oSrcHis.GetSize();
	//arrProbalility.SetSize(nHisSize);
	arrNewTable.SetSize(nHisSize);

	DOUBLE nTotal = oSrcHis.Accumulate(nHisSize-1);
	
	if(eRetCode == eNormal)
	{
		for(INT k=0; k<nHisSize; k++)
		{
			DOUBLE ta = oSrcHis.Accumulate(k);
			DOUBLE dTemp = ((DOUBLE)oSrcHis.Accumulate(k)/nTotal) * (IMP_GRAY_LEVELS -1);
			arrNewTable.SetAt(k, (BYTE) dTemp);
		}
		
		CProcGrayTransformer oTransformer;
		oTransformer.m_eType = eCustomTrans;
		oTransformer.InitCustomTransform(&arrNewTable);
		
		eRetCode = oTransformer.ApplyProcessor(in_pImgSrc, out_ImgResult);
	}
	
	return eRetCode;
}
