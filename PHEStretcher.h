// PHEStretcher.h: interface for the CPHEStretcher class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PHESTRETCHER_H__33D21739_AB76_4FCE_8ECD_7205B2E2BD69__INCLUDED_)
#define AFX_PHESTRETCHER_H__33D21739_AB76_4FCE_8ECD_7205B2E2BD69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcHisEnhancer.h"
#include "Include.h"	// Added by ClassView

class CPHEStretcher : public CProcHisEnhancer  
{
public:
	virtual procStatus ApplyProcessor(CImgSource* in_pImgSrc, CImgSource* out_ImgResult);
	CPHEStretcher();
	virtual ~CPHEStretcher();

};

#endif // !defined(AFX_PHESTRETCHER_H__33D21739_AB76_4FCE_8ECD_7205B2E2BD69__INCLUDED_)
