// DCMImgLoader.h: interface for the CDCMImgLoader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DCMIMGLOADER_H__2EE73B4E_86EC_420A_8308_B1B3147290DD__INCLUDED_)
#define AFX_DCMIMGLOADER_H__2EE73B4E_86EC_420A_8308_B1B3147290DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Loader.h"

class CDCMImgLoader : public CLoader  
{
public:
	CDCMImgLoader();
	virtual ~CDCMImgLoader();
	virtual procStatus Load(ImgSrcList* out_srcSet)
	{
		ASSERT(FALSE);
		return eNormal;
	};

};

#endif // !defined(AFX_DCMIMGLOADER_H__2EE73B4E_86EC_420A_8308_B1B3147290DD__INCLUDED_)
