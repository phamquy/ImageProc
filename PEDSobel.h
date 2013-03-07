// PEDSobel.h: interface for the CPEDSobel class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PEDSOBEL_H__8516601C_F7FF_4973_B271_A0FEEC17012E__INCLUDED_)
#define AFX_PEDSOBEL_H__8516601C_F7FF_4973_B271_A0FEEC17012E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcEdgeDetector.h"
#include "Include.h"	// Added by ClassView

class CPEDSobel : public CProcEdgeDetector  
{
public:
	virtual procStatus ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult);
	CPEDSobel();
	virtual ~CPEDSobel();

};

#endif // !defined(AFX_PEDSOBEL_H__8516601C_F7FF_4973_B271_A0FEEC17012E__INCLUDED_)
