// PIEFrequencyHPF.h: interface for the CPIEFrequencyHPF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIEFREQUENCYHPF_H__380F31C1_A171_4FEE_B3D5_28A263613B8F__INCLUDED_)
#define AFX_PIEFREQUENCYHPF_H__380F31C1_A171_4FEE_B3D5_28A263613B8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcImgEnhancer.h"
#include "Include.h"	// Added by ClassView

class CPIEFrequencyHPF : public CProcImgEnhancer  
{
public:
	virtual procStatus ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult);
	CPIEFrequencyHPF();
	virtual ~CPIEFrequencyHPF();

};

#endif // !defined(AFX_PIEFREQUENCYHPF_H__380F31C1_A171_4FEE_B3D5_28A263613B8F__INCLUDED_)
