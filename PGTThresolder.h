// PGTThresolder.h: interface for the CPGTThresolder class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PGTTHRESOLDER_H__AAD06CB6_0E94_4482_80F0_FED6D88CE2B0__INCLUDED_)
#define AFX_PGTTHRESOLDER_H__AAD06CB6_0E94_4482_80F0_FED6D88CE2B0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcGrayTransformer.h"

class CPGTThresolder : public CProcGrayTransformer  
{
public:
	CPGTThresolder();
	CPGTThresolder(BYTE threshold);
	VOID InitThresholdTransform(BYTE threshold);
	virtual ~CPGTThresolder();
protected:
};

#endif // !defined(AFX_PGTTHRESOLDER_H__AAD06CB6_0E94_4482_80F0_FED6D88CE2B0__INCLUDED_)
