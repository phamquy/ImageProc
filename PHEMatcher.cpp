// PHEMatcher.cpp: implementation of the CPHEMatcher class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "PHEMatcher.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPHEMatcher::CPHEMatcher()
{

}

CPHEMatcher::~CPHEMatcher()
{

}

CPHEMatcher::CPHEMatcher(CHistogram* in_oMatching)
{	
	
	INT nSize = in_oMatching->GetSize();
	m_oMatchingHis.InitData(nSize, NULL);
	for (INT i=0; i<nSize; i++)
	{
		m_oMatchingHis.SetAt(i,in_oMatching->GetAt(i));
	}
}

//************************************
// Method:    ApplyProcessor
// FullName:  CPHEMatcher::ApplyProcessor
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * in_pImgSrc
// Parameter: CImgSource * out_ImgResult
//************************************
procStatus CPHEMatcher::ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult)
{
	ASSERT(in_pImgSrc);
	ASSERT(in_pImgSrc->GetSourceRef());
	ASSERT(out_ImgResult);
	
	procStatus eRetCode = eNormal;	

	CHistogram oSrcHis;
	eRetCode = in_pImgSrc->GetHistoram(oSrcHis);
	INT nSize = 0;

	if(eRetCode == eNormal) 
	{
		nSize = oSrcHis.GetSize();
		if(nSize != m_oMatchingHis.GetSize()) 
		{
			eRetCode = eInvalideArg;
		}
	}
	
	CDWordArray arrSrcProb;
	CDWordArray arrDesProb;
	CByteArray arrMatchTbl;
	arrMatchTbl.SetSize(nSize);
	arrSrcProb.SetSize(nSize);
	arrDesProb.SetSize(nSize);
	
	if(eRetCode == eNormal)
	{
		//precompute the probablitity table
		for (INT i=0; i<nSize; i++)
		{
			arrSrcProb.SetAt(i, oSrcHis.Accumulate(i));
			arrDesProb.SetAt(i, m_oMatchingHis.Accumulate(i));
		}
		
		//matching
		for (INT r=0; r< nSize; r++)
		{
			BYTE nMatched = 0;
			INT z=0;
			while (z<nSize)
			{
				if (arrDesProb.GetAt(z) >= arrSrcProb.GetAt(r))
				{
					nMatched = z;
					break;
				}
				z++;					
			}

			arrMatchTbl.SetAt(r, nMatched);			
		}

#ifdef _DEBUG
// 	for(INT j=0; j<nSize; j++)
// 	{
// 		TRACE("\nr:%d \tz:%d", j, arrMatchTbl.GetAt(j));
// 	}
#endif
		//Apply to source
		CProcGrayTransformer oTransformer;
		oTransformer.m_eType = eCustomTrans;
		oTransformer.InitCustomTransform(&arrMatchTbl);
		eRetCode = oTransformer.ApplyProcessor(in_pImgSrc, out_ImgResult); 
	}
		
	return eRetCode;
}
