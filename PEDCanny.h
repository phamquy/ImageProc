// PEDCanny.h: interface for the CPEDCanny class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PEDCANNY_H__880E1E47_0F4E_4DA5_BF21_8A730BB66B30__INCLUDED_)
#define AFX_PEDCANNY_H__880E1E47_0F4E_4DA5_BF21_8A730BB66B30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcEdgeDetector.h"
#include "Include.h"	// Added by ClassView

class CPEDCanny : public CProcEdgeDetector  
{
public:
	virtual procStatus ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult);
	CPEDCanny();
	virtual ~CPEDCanny();

};

#endif // !defined(AFX_PEDCANNY_H__880E1E47_0F4E_4DA5_BF21_8A730BB66B30__INCLUDED_)
