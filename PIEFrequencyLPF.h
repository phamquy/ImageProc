// PIEFrequencyLPF.h: interface for the CPIEFrequencyLPF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIEFREQUENCYLPF_H__C3A09F46_E2EC_4912_ABCD_C9074CCCC0DA__INCLUDED_)
#define AFX_PIEFREQUENCYLPF_H__C3A09F46_E2EC_4912_ABCD_C9074CCCC0DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcImgEnhancer.h"
#include "Include.h"	// Added by ClassView

class CPIEFrequencyLPF : public CProcImgEnhancer  
{
public:
	virtual procStatus ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult);
	CPIEFrequencyLPF();
	virtual ~CPIEFrequencyLPF();

};

#endif // !defined(AFX_PIEFREQUENCYLPF_H__C3A09F46_E2EC_4912_ABCD_C9074CCCC0DA__INCLUDED_)
