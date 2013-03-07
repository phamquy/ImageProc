// ImgFourierSource.h: interface for the CImgFourierSource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMGFOURIERSOURCE_H__91C949D0_0D33_437A_97F7_036E67C7A31B__INCLUDED_)
#define AFX_IMGFOURIERSOURCE_H__91C949D0_0D33_437A_97F7_036E67C7A31B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImgSource.h"

class CImgFourierSource : public CImgSource  
{
public:
	CImgFourierSource();
	virtual ~CImgFourierSource();

public:
	FFRESULT m_oFFresult;
};

#endif // !defined(AFX_IMGFOURIERSOURCE_H__91C949D0_0D33_437A_97F7_036E67C7A31B__INCLUDED_)
