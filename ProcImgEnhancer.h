// ProcImgEnhancer.h: interface for the CProcImgEnhancer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROCIMGENHANCER_H__33F1D668_56EE_4391_B9B6_A7341DED4E83__INCLUDED_)
#define AFX_PROCIMGENHANCER_H__33F1D668_56EE_4391_B9B6_A7341DED4E83__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImgProcessor.h"
#include "Include.h"	// Added by ClassView

class CProcImgEnhancer : public CImgProcessor  
{
public:
	virtual procStatus ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult);
	CProcImgEnhancer();
	virtual ~CProcImgEnhancer();

};

#endif // !defined(AFX_PROCIMGENHANCER_H__33F1D668_56EE_4391_B9B6_A7341DED4E83__INCLUDED_)
