// PHEStretcher.cpp: implementation of the CPHEStretcher class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "PHEStretcher.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPHEStretcher::CPHEStretcher()
{

}

CPHEStretcher::~CPHEStretcher()
{

}

//************************************
// Method:    ApplyProcessor
// FullName:  CPHEStretcher::ApplyProcessor
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * in_pImgSrc
// Parameter: CImgSource * out_ImgResult
//************************************
procStatus CPHEStretcher::ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult)
{
	ASSERT(in_pImgSrc);
	ASSERT(in_pImgSrc->GetSourceRef());
	ASSERT(out_ImgResult);
	
	procStatus eRetCode = eNormal;	
	
	CHistogram oSrcHis;
	eRetCode = in_pImgSrc->GetHistoram(oSrcHis);
	INT nSize = 0; 

	if(eRetCode == eNormal)
		nSize = oSrcHis.GetSize();

	BYTE nLowest = 0;
	BYTE nHighest = nSize-1;

	//calculate the lowest and highest boundary
	if(eRetCode == eNormal)
	{
		for (INT i=0;i<nSize; i++)
		{
			if(oSrcHis.GetAt(i)>0) 
			{	
				nLowest = i;
				break;
			}
		}

		for (INT j= nSize-1; j>=0; j--)
		{
			if(oSrcHis.GetAt(j)>0) 
			{
				nHighest = j;
				break;
			}
		}

		CByteArray arrStretcher;
		arrStretcher.SetSize(nSize);

		for (INT k=0; k<nSize; k++)
		{
			if (k<nLowest) //less than low boundary
			{
				arrStretcher.SetAt(k, 0);
			}
			else if ( (k >= nLowest) && (k <= nHighest) )
			{
				BYTE newVal = k;
				newVal = ((k-nLowest) * (nSize -1))/(nHighest - nLowest);
				arrStretcher.SetAt(k, newVal);
			}
			else //greater than high boundary
			{
				arrStretcher.SetAt(k, nSize-1);
			}
		}

#ifdef _DEBUG
// for(INT m=0; m<nSize; m++)
// {
// 	TRACE("\nr:%d \ts:%d", m, arrStretcher.GetAt(m));
// }
#endif
		//Apply to source
		CProcGrayTransformer oTransformer;
		oTransformer.m_eType = eCustomTrans;
		oTransformer.InitCustomTransform(&arrStretcher);
		eRetCode = oTransformer.ApplyProcessor(in_pImgSrc, out_ImgResult); 
	}

	return eRetCode;
}
