// ImgProcessor.h: interface for the CImgProcessor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMGPROCESSOR_H__9927DAF4_2A1D_4391_B2CF_59B90E8AF521__INCLUDED_)
#define AFX_IMGPROCESSOR_H__9927DAF4_2A1D_4391_B2CF_59B90E8AF521__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImgSource.h"


class CImgProcessor  
{
public:
	CImgProcessor();
	virtual ~CImgProcessor();
	
	OperationType m_eOpType;
	virtual procStatus ApplyProcessor(CImgSource* in_pImgSrc, CImgSource* out_ImgResult);
};

#endif // !defined(AFX_IMGPROCESSOR_H__9927DAF4_2A1D_4391_B2CF_59B90E8AF521__INCLUDED_)
