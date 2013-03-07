// PHEEqualizer.h: interface for the CPHEEqualizer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHEEQUALIZER_H__176B2FBA_A5D6_432D_ABDC_81AB40492BFD__INCLUDED_)
#define AFX_PHEEQUALIZER_H__176B2FBA_A5D6_432D_ABDC_81AB40492BFD__INCLUDED_

#include "Include.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcHisEnhancer.h"

class CPHEEqualizer : public CProcHisEnhancer  
{
public:
	virtual procStatus ApplyProcessor(CImgSource* in_pImgSrc, CImgSource* out_ImgResult);
	CPHEEqualizer();
	virtual ~CPHEEqualizer();

};

#endif // !defined(AFX_PHEEQUALIZER_H__176B2FBA_A5D6_432D_ABDC_81AB40492BFD__INCLUDED_)
