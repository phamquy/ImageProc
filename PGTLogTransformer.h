// PGTLogTransformer.h: interface for the CPGTLogTransformer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PGTLOGTRANSFORMER_H__F0C4121F_18CF_42CB_8461_788896880960__INCLUDED_)
#define AFX_PGTLOGTRANSFORMER_H__F0C4121F_18CF_42CB_8461_788896880960__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcGrayTransformer.h"

class CPGTLogTransformer : public CProcGrayTransformer  
{
public:
	VOID InitLogTransform(BYTE C);
	CPGTLogTransformer();
	CPGTLogTransformer(BYTE in_nC);	
	virtual ~CPGTLogTransformer();	
protected:
	
};

#endif // !defined(AFX_PGTLOGTRANSFORMER_H__F0C4121F_18CF_42CB_8461_788896880960__INCLUDED_)
