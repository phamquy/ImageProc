// FormatedImgLoader.h: interface for the CFormatedImgLoader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FORMATEDIMGLOADER_H__88F44CC6_A14D_4232_B636_4929F9D14977__INCLUDED_)
#define AFX_FORMATEDIMGLOADER_H__88F44CC6_A14D_4232_B636_4929F9D14977__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Loader.h"
#include "Include.h"	// Added by ClassView

class CFormatedImgLoader : public CLoader  
{
public:
	CFormatedImgLoader();
	virtual ~CFormatedImgLoader();
	virtual procStatus Load(ImgSrcList* out_srcSet);
protected:
};

#endif // !defined(AFX_FORMATEDIMGLOADER_H__88F44CC6_A14D_4232_B636_4929F9D14977__INCLUDED_)
