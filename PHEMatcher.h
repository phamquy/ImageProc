// PHEMatcher.h: interface for the CPHEMatcher class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHEMATCHER_H__6A4853C5_6AFD_4001_AD0C_36A37A31BAC0__INCLUDED_)
#define AFX_PHEMATCHER_H__6A4853C5_6AFD_4001_AD0C_36A37A31BAC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcHisEnhancer.h"
#include "Histogram.h"	// Added by ClassView
#include "Include.h"	// Added by ClassView

class CPHEMatcher : public CProcHisEnhancer  
{
public:	
	virtual procStatus ApplyProcessor(CImgSource* in_pImgSrc, CImgSource* out_ImgResult);
	CPHEMatcher(CHistogram* in_oMatching);
	CPHEMatcher();
	virtual ~CPHEMatcher();

protected:
	CHistogram m_oMatchingHis;
};

#endif // !defined(AFX_PHEMATCHER_H__6A4853C5_6AFD_4001_AD0C_36A37A31BAC0__INCLUDED_)
