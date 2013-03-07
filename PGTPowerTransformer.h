// PGTPowerTransformer.h: interface for the CPGTPowerTransformer class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PGTPOWERTRANSFORMER_H__CA0CB27E_E161_47AA_B4D5_4E6020E0D216__INCLUDED_)
#define AFX_PGTPOWERTRANSFORMER_H__CA0CB27E_E161_47AA_B4D5_4E6020E0D216__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcGrayTransformer.h"

class CPGTPowerTransformer : public CProcGrayTransformer  
{
public:
	VOID InitPowerTransform(BYTE C, DOUBLE gamma);
	CPGTPowerTransformer();
	CPGTPowerTransformer(BYTE C, DOUBLE Gamma);
	virtual ~CPGTPowerTransformer();
protected:
};

#endif // !defined(AFX_PGTPOWERTRANSFORMER_H__CA0CB27E_E161_47AA_B4D5_4E6020E0D216__INCLUDED_)
