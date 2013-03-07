// RawImgLoader.h: interface for the CRawImgLoader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAWIMGLOADER_H__B9318216_67C1_45A8_B83F_CFCEB6A03640__INCLUDED_)
#define AFX_RAWIMGLOADER_H__B9318216_67C1_45A8_B83F_CFCEB6A03640__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// [12/21/2007 QUYPS]
#include "Include.h"

#include "Loader.h"

class CRawImgLoader : public CLoader  
{
public:
	void obtainRawSize(ULONG in_filesize);
	t_RawSize optimizeSize(ULONG in_nFileSize);
	CRawImgLoader();
	virtual ~CRawImgLoader();
	virtual procStatus Load(ImgSrcList* out_srcSet);


	BYTE m_nBitPerPixel;

protected:	
	procStatus rawToSource(LPVOID pBuffer, ImgSrcList* out_ImgSrcList);
};

#endif // !defined(AFX_RAWIMGLOADER_H__B9318216_67C1_45A8_B83F_CFCEB6A03640__INCLUDED_)
