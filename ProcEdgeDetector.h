// ProcEdgeDetector.h: interface for the CProcEdgeDetector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROCEDGEDETECTOR_H__79DC3A7C_1000_4592_AB51_0E094DA9C97D__INCLUDED_)
#define AFX_PROCEDGEDETECTOR_H__79DC3A7C_1000_4592_AB51_0E094DA9C97D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImgProcessor.h"
#include "Include.h"	// Added by ClassView

class CProcEdgeDetector : public CImgProcessor  
{
public:
	EdgeDetectorType m_eType;
	virtual procStatus ApplyProcessor(CImgSource* in_pImgSrc, CImgSource* out_ImgResult);
	CProcEdgeDetector();
	virtual ~CProcEdgeDetector();


};

#endif // !defined(AFX_PROCEDGEDETECTOR_H__79DC3A7C_1000_4592_AB51_0E094DA9C97D__INCLUDED_)
