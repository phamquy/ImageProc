// ImgSource.h: interface for the CImgSource class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMGSOURCE_H__6CF0FE5D_DB1E_4FB2_B9C5_63654D25819C__INCLUDED_)
#define AFX_IMGSOURCE_H__6CF0FE5D_DB1E_4FB2_B9C5_63654D25819C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Histogram.h"
#include "Include.h"	// Added by ClassView


// Class declaration [12/17/2007 QUYPS]
class CImgSource  : public CObject
{

public:
	CImgSource();
	CImgSource(SourceType m_nSourceType, CString m_strName, t_OpCap	m_tCapacity, Bitmap* pBmp = NULL);
	virtual ~CImgSource();


protected:
	t_OpCap	m_tCapacity;	//the capacity of operation that can apply for this source
	SourceType 	m_nSourceType;	//Type of source SourceType
	CString	m_strName;		//Name of this source
	Bitmap*	m_pGdipBitmap;	//gdi plus bitmap to display

public:	
	virtual procStatus Draw(Graphics* in_pGraph, const CRect& in_rcArea);
	procStatus GetHistoram(CHistogram& out_his) const;

	INT DettachSource();
	// check if type of operation is available for this source
	BOOL IsCapable(INT in_nOpType);

	//return capacity structure of this source
	t_OpCap GetOpCap();

	//return name of this source
	CString GetName();

	//Return type of this source
	SourceType GetType();

	//Set capacity
	VOID SetOpCap(t_OpCap in_tOpCap);

	//Set name of source
	VOID SetName(CString in_sName);

	VOID SetType(SourceType in_srcType);
	
	//Get source reference
	Bitmap* GetSourceRef();

	//Attach bitmap to this source
	INT		AttachSource(Bitmap* in_pBitmap); 

};

//  [12/21/2007 QUYPS]
typedef CTypedPtrArray<CObArray, CImgSource*> ImgSrcList;


#endif // !defined(AFX_IMGSOURCE_H__6CF0FE5D_DB1E_4FB2_B9C5_63654D25819C__INCLUDED_)
