// PIESpatialHPF.h: interface for the CPIESpatialHPF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIESPATIALHPF_H__86C440AE_6144_423B_9ADD_E994D3C74409__INCLUDED_)
#define AFX_PIESPATIALHPF_H__86C440AE_6144_423B_9ADD_E994D3C74409__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcImgEnhancer.h"
#include "Include.h"	// Added by ClassView

class CPIESpatialHPF : public CProcImgEnhancer  
{
public:
	virtual procStatus ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult);
	CPIESpatialHPF();
	virtual ~CPIESpatialHPF();

};

#endif // !defined(AFX_PIESPATIALHPF_H__86C440AE_6144_423B_9ADD_E994D3C74409__INCLUDED_)
