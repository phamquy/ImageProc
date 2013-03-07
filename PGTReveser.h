// PGTReveser.h: interface for the CPGTReveser class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PGTREVESER_H__CC7FC7AD_A6E7_4DBE_A9C9_A026E009BA43__INCLUDED_)
#define AFX_PGTREVESER_H__CC7FC7AD_A6E7_4DBE_A9C9_A026E009BA43__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcGrayTransformer.h"

class CPGTReveser : public CProcGrayTransformer  
{
public:
	CPGTReveser();
	virtual ~CPGTReveser();
protected:
};

#endif // !defined(AFX_PGTREVESER_H__CC7FC7AD_A6E7_4DBE_A9C9_A026E009BA43__INCLUDED_)
