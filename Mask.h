// Mask.h: interface for the CMask class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MASK_H__C06A6C7F_F04F_4D53_925D_AF2474F5CF65__INCLUDED_)
#define AFX_MASK_H__C06A6C7F_F04F_4D53_925D_AF2474F5CF65__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "2DRaw.h"
#include "ImgSource.h"

class CMask  
{
public:
	CMask();
	CMask(INT in_eType);
	virtual ~CMask();

protected:
	CPoint	m_ptAppliedPos;
	UINT	m_nMaskRatio;
	INT		m_nMaskType;
	CString	m_sMaskName;
	C2DRaw	m_oMaskSource;

public:

	procStatus ApplyMask(CImgSource* in_pSource, CImgSource *out_pSource);

	INT GetType() const
	{ 
		return m_nMaskType;
	}
	
	VOID SetType(INT in_nType)
	{
		m_nMaskType = in_nType;
	}

	CString GetMaskName() const
	{
		return m_sMaskName;
	}

	VOID SetMaskName(CString in_sName)
	{
		m_sMaskName = in_sName;
	}

	VOID InitMask(INT in_eType = eUserDefined);
	
	INT GetRowCount()
	{
		return m_oMaskSource.GetNumberOfRow();
	}	

	INT GetColCount()
	{
		return m_oMaskSource.GetNumberOfCol();
	}

	INT GetValueAt(UINT in_RowPos, UINT in_nColPos)
	{
		return m_oMaskSource.GetElementAt(in_RowPos, in_nColPos);
	}
};

typedef CTypedPtrArray<CObArray, CMask*> MaskList;

#endif // !defined(AFX_MASK_H__C06A6C7F_F04F_4D53_925D_AF2474F5CF65__INCLUDED_)
