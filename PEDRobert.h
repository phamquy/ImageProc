// PEDRobert.h: interface for the CPEDRobert class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PEDROBERT_H__BC92B7FA_7984_4720_A574_9D6D4FFA59C2__INCLUDED_)
#define AFX_PEDROBERT_H__BC92B7FA_7984_4720_A574_9D6D4FFA59C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcEdgeDetector.h"
#include "Include.h"	// Added by ClassView

class CPEDRobert : public CProcEdgeDetector  
{
public:
	virtual procStatus ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult);
	CPEDRobert();
	virtual ~CPEDRobert();

};

#endif // !defined(AFX_PEDROBERT_H__BC92B7FA_7984_4720_A574_9D6D4FFA59C2__INCLUDED_)
