// Loader.h: interface for the CLoader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOADER_H__954740A3_402A_4DE3_BE91_088B04DE304C__INCLUDED_)
#define AFX_LOADER_H__954740A3_402A_4DE3_BE91_088B04DE304C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImgSource.h"

class CLoader
{
public:
	CLoader();
	virtual ~CLoader();

/*
protected:
	CString m_sFileFilter;
*/
public:
	t_RawSize m_tSize;
	CString GetFilePath()
	{
		return m_sFileName;
	}

	VOID SetFilePath(CString in_sFilePath)
	{
		m_sFileName = in_sFilePath;
	}


	virtual procStatus Load(ImgSrcList* out_srcSet);

	CString m_sFileName;
};

#endif // !defined(AFX_LOADER_H__954740A3_402A_4DE3_BE91_088B04DE304C__INCLUDED_)
