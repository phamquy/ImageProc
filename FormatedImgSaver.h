// FormatedImgSaver.h: interface for the CFormatedImgSaver class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FORMATEDIMGSAVER_H__FC33281A_7A87_4C5A_9EFF_70E0650946AA__INCLUDED_)
#define AFX_FORMATEDIMGSAVER_H__FC33281A_7A87_4C5A_9EFF_70E0650946AA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Saver.h"

class CFormatedImgSaver : public CSaver  
{
public:
	CFormatedImgSaver();
	virtual ~CFormatedImgSaver();
	virtual  procStatus Save(CImgSource* in_pSource);

};

#endif // !defined(AFX_FORMATEDIMGSAVER_H__FC33281A_7A87_4C5A_9EFF_70E0650946AA__INCLUDED_)
