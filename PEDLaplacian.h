// PEDLaplacian.h: interface for the CPEDLaplacian class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PEDLAPLACIAN_H__AC9810AD_6C83_4257_95A2_2F334BE10F04__INCLUDED_)
#define AFX_PEDLAPLACIAN_H__AC9810AD_6C83_4257_95A2_2F334BE10F04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcEdgeDetector.h"
#include "Include.h"	// Added by ClassView
#include "Mask.h"	// Added by ClassView

class CPEDLaplacian : public CProcEdgeDetector  
{
public:
	MaskType m_eMaskType;
	CPEDLaplacian(MaskType in_eMaskType);
	virtual procStatus ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult);
	CPEDLaplacian();
	virtual ~CPEDLaplacian();
};

#endif // !defined(AFX_PEDLAPLACIAN_H__AC9810AD_6C83_4257_95A2_2F334BE10F04__INCLUDED_)
