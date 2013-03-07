// Saver.h: interface for the CSaver class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SAVER_H__ADE38360_5A2D_4F90_A27B_5C4CB8D94C4E__INCLUDED_)
#define AFX_SAVER_H__ADE38360_5A2D_4F90_A27B_5C4CB8D94C4E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImgSource.h"
#include "Include.h"	// Added by ClassView

class CSaver  
{
public:	
	CSaver();
	virtual ~CSaver();
	virtual  procStatus Save(CImgSource* in_pSource);
	CString m_sFilePath;
	RAWPIXELFORMAT m_tPXFormat;
	FileFormat m_eOutputFormat;
};

#endif // !defined(AFX_SAVER_H__ADE38360_5A2D_4F90_A27B_5C4CB8D94C4E__INCLUDED_)
