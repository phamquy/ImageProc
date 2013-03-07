// PEDPrewitt.h: interface for the CPEDPrewitt class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PEDPREWITT_H__07FE89B2_6350_459F_84AE_DA9E468574F8__INCLUDED_)
#define AFX_PEDPREWITT_H__07FE89B2_6350_459F_84AE_DA9E468574F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcEdgeDetector.h"
#include "Include.h"	// Added by ClassView

class CPEDPrewitt : public CProcEdgeDetector  
{
public:
	virtual procStatus ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult);
	CPEDPrewitt();
	virtual ~CPEDPrewitt();

};

#endif // !defined(AFX_PEDPREWITT_H__07FE89B2_6350_459F_84AE_DA9E468574F8__INCLUDED_)
