// RawImgSaver.h: interface for the CRawImgSaver class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAWIMGSAVER_H__F7D8BDAF_B448_4FCA_BE17_51563443F23C__INCLUDED_)
#define AFX_RAWIMGSAVER_H__F7D8BDAF_B448_4FCA_BE17_51563443F23C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Saver.h"

class CRawImgSaver : public CSaver  
{
public:
	CRawImgSaver();
	virtual ~CRawImgSaver();
	virtual  procStatus Save(CImgSource* in_pSource);
};

#endif // !defined(AFX_RAWIMGSAVER_H__F7D8BDAF_B448_4FCA_BE17_51563443F23C__INCLUDED_)
