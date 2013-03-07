// ProcGrayTransformer.cpp: implementation of the CProcGrayTransformer class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "ProcGrayTransformer.h"
#include "Utility.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CProcGrayTransformer::CProcGrayTransformer()
{
	m_eType = eNoTrans;
	for (INT i=0; i<IMP_GRAY_LEVELS; i++)
	{
		m_nLookUpTable[i] = i;
	}
}

CProcGrayTransformer::~CProcGrayTransformer()
{

}

//************************************
// Method:    IsSingleValued
// FullName:  CProcGrayTransformer::IsSingleValued
// Access:    public 
// Returns:   BOOL
// Qualifier:
//************************************
BOOL CProcGrayTransformer::IsSingleValued()
{
	BOOL isSingle = TRUE;

	for(INT i=0; i<IMP_GRAY_LEVELS-1; i++)
	{
		for (INT j=i+1; j<IMP_GRAY_LEVELS;j++)
		{
			if(m_nLookUpTable[i] = m_nLookUpTable[j]) isSingle=FALSE;
			break;
		}
		if(!isSingle) break;
	}

	return isSingle;
}

//************************************
// Method:    IsMonoIncreased
// FullName:  CProcGrayTransformer::IsMonoIncreased
// Access:    public 
// Returns:   BOOL
// Qualifier:
//************************************
BOOL CProcGrayTransformer::IsMonoIncreased()
{
	BOOL isMono = TRUE;
	
	for(INT i=0; i<IMP_GRAY_LEVELS-1; i++)
	{
		for (INT j=i+1; j<IMP_GRAY_LEVELS;j++)
		{
			if(m_nLookUpTable[i] >= m_nLookUpTable[j]) isMono=FALSE;
			break;
		}
		if(!isMono) break;
	}
	
	return isMono;
}

//************************************
// Method:    RevertLookUp
// FullName:  CProcGrayTransformer::RevertLookUp
// Access:    public 
// Returns:   INT
// Qualifier:
// Parameter: BYTE Y
//************************************
INT CProcGrayTransformer::RevertLookUp(BYTE Y)
{
	INT retVal = -1;
	for(INT i=0; i<IMP_GRAY_LEVELS; i++)
	{
		if (m_nLookUpTable[i] == Y)
			retVal = Y;
		break;
	}

	return retVal;
}

//************************************
// Method:    ApplyProcessor
// FullName:  CProcGrayTransformer::ApplyProcessor
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * in_pImgSrc
// Parameter: CImgSource & out_ImgResult
//************************************
procStatus CProcGrayTransformer::ApplyProcessor( CImgSource* in_pImgSrc, CImgSource* out_ImgResult )
{
	ASSERT(in_pImgSrc);
	ASSERT(out_ImgResult);

	Bitmap* pBmpRes = NULL;
	Bitmap* pBmpSrc = NULL;

	procStatus eRetCode = eNormal;
	SourceType eSrcType = in_pImgSrc->GetType();

	if(eSrcType < eSrcMonoBitmap) eRetCode = eInvalideArg;
	
	if(eRetCode == eNormal)
	{
		pBmpSrc = in_pImgSrc->GetSourceRef();
		if (pBmpSrc == NULL) eRetCode = eSystemErr;
	}
	
	INT nWidth = pBmpSrc->GetWidth();
	INT nHeight = pBmpSrc->GetHeight();
	
	if(eRetCode == eNormal)	pBmpRes = pBmpSrc->Clone(0,0,nWidth,nHeight,PixelFormatDontCare);
	if(pBmpRes == NULL) eRetCode = eSystemErr;
	
	if(eRetCode == eNormal)
	{
		for (INT y=0; y<nHeight; y++)
		{
			for (INT x=0; x<nWidth; x++)
			{
				Color clr(0,0,0);
				Status sts = Ok;
				BYTE clrVal;
				sts = pBmpSrc->GetPixel(x,y, &clr);
				
				if(sts == Ok)
				{
					clrVal = CUtility::GetMonoPixelValue(clr, eSrcType);
					clrVal = this->LookUp(clrVal);
					sts = pBmpRes->SetPixel(x,y, CUtility::GetMonoPixel(clrVal, eSrcType));
				}

				if (sts != Ok)
				{
					eRetCode = eSystemErr;
					break;
				}
			}
			if(eRetCode != eNormal) break;
		}
	}

	if(eRetCode == eNormal)
	{
		out_ImgResult->SetType(eSrcType);
		out_ImgResult->SetName(in_pImgSrc->GetName() + CUtility::GetTransSuffixName(m_eType));
		out_ImgResult->AttachSource(pBmpRes);
	}
	else
	{
		delete pBmpRes;
	}

	return eRetCode;
}


//************************************
// Method:    InitCustomTransform
// FullName:  CProcGrayTransformer::InitCustomTransform
// Access:    public 
// Returns:   VOID
// Qualifier:
// Parameter: CByteArray * in_pData
//************************************
VOID CProcGrayTransformer::InitCustomTransform( CByteArray* in_pData )
{
	ASSERT(in_pData);
	if(in_pData ==NULL) return;

	INT nSize = min(in_pData->GetSize(), IMP_GRAY_LEVELS);

	for (INT i=0; i<nSize; i++)
	{
		m_nLookUpTable[i] = in_pData->GetAt(i);
	}
}
