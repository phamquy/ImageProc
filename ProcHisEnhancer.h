// ProcHisEnhancer.h: interface for the CProcHisEnhancer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROCHISENHANCER_H__5ACFA779_40B1_40DD_9BCD_E8C2F2BC5220__INCLUDED_)
#define AFX_PROCHISENHANCER_H__5ACFA779_40B1_40DD_9BCD_E8C2F2BC5220__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImgProcessor.h"
#include "Include.h"	// Added by ClassView
#include "ProcGrayTransformer.h"	// Added by ClassView

class CProcHisEnhancer : public CImgProcessor  
{
public:
	HistogramFunction m_eType;
	CProcHisEnhancer();
	virtual ~CProcHisEnhancer();
	virtual procStatus ApplyProcessor(CImgSource* in_pImgSrc, CImgSource* out_ImgResult);
};

#endif // !defined(AFX_PROCHISENHANCER_H__5ACFA779_40B1_40DD_9BCD_E8C2F2BC5220__INCLUDED_)
