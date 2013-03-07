// ProcGrayTransformer.h: interface for the CProcGrayTransformer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROCGRAYTRANSFORMER_H__96984184_5315_466D_8BDD_245ABD7C00BC__INCLUDED_)
#define AFX_PROCGRAYTRANSFORMER_H__96984184_5315_466D_8BDD_245ABD7C00BC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImgProcessor.h"

class CProcGrayTransformer : public CImgProcessor  
{
public:
	VOID InitCustomTransform(CByteArray* in_pData);
	CProcGrayTransformer();
	virtual ~CProcGrayTransformer();
	
	BYTE LookUp(BYTE x)
	{
		return m_nLookUpTable[x];
	}
	INT RevertLookUp(BYTE Y);
	BOOL IsSingleValued();	
	BOOL IsMonoIncreased();
	TransformFunction m_eType;

	virtual procStatus ApplyProcessor(CImgSource* in_pImgSrc, CImgSource* out_ImgResult);
protected:
	BYTE m_nLookUpTable[IMP_GRAY_LEVELS]; //256 entries
};

#endif // !defined(AFX_PROCGRAYTRANSFORMER_H__96984184_5315_466D_8BDD_245ABD7C00BC__INCLUDED_)
