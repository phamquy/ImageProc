// ImgSource.cpp: implementation of the CImgSource class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "ImgSource.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

#include "Utility.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CImgSource::CImgSource()
{
	m_nSourceType = eSrcNone;
	m_strName = "";
	m_pGdipBitmap = NULL;
}

CImgSource::CImgSource(SourceType nSourceType, CString strName, t_OpCap	tCapacity, Bitmap* pBmp)
{
	m_nSourceType = nSourceType;
	m_strName = strName;
	m_tCapacity = tCapacity;
	m_pGdipBitmap = pBmp;
}

CImgSource::~CImgSource()
{

	//release image memory
	DettachSource();
}

// check if type of operation is available for this source
BOOL CImgSource::IsCapable(INT in_nOpType)
{
	//is still not implemented
	return TRUE;
}

//return capacity structure of this source
t_OpCap CImgSource::GetOpCap()
{
	return m_tCapacity;
}

//return name of this source
CString CImgSource::GetName()
{
	return m_strName;
}

//Return type of this source
SourceType CImgSource::GetType()
{
	return m_nSourceType;
}


VOID CImgSource::SetType(SourceType in_srcType)
{
	m_nSourceType = in_srcType;
}

//Set capacity
VOID CImgSource::SetOpCap(t_OpCap in_tOpCap)
{
	m_tCapacity = in_tOpCap;
}

//Set name of source
VOID CImgSource::SetName(CString in_sName)
{
	m_strName = in_sName;
}

//Get source reference
Bitmap* CImgSource::GetSourceRef()
{
	return m_pGdipBitmap;
}

//Attach bitmap to this source
//************************************
// Method:    
// FullName:  
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
INT	CImgSource::AttachSource(Bitmap* in_pBitmap)
{
	DettachSource();	
	m_pGdipBitmap = in_pBitmap;
	return eNormal;
}


//Dettach source from this 
//************************************
// Method:    
// FullName:  
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
INT CImgSource::DettachSource()
{
	if(m_pGdipBitmap != NULL)
		delete m_pGdipBitmap;
	m_pGdipBitmap = NULL;

	return eNormal;
}

//************************************
// Method:    GetHistoram
// FullName:  CImgSource::GetHistoram
// Access:    public 
// Returns:   proStatus
// Qualifier: const
// Parameter: CHistogram & out_his
//************************************
procStatus CImgSource::GetHistoram(CHistogram &out_his) const
{
	procStatus eRetValue = eNormal;
	
	if((m_nSourceType == eSrcNone)||(m_nSourceType == eSrcColorBitmap)||(m_nSourceType == eSrcFourierBitmap))
	{
		eRetValue = eInvalidOp;
	}
	Bitmap* pBmp = m_pGdipBitmap;

	if (eRetValue == eNormal)
	{
		UINT nWidth = pBmp->GetWidth();
		UINT nHeight = pBmp->GetHeight();
	
		Color oClr;
		Status sts;
		for (UINT i=0; i<nHeight; i++)
		{
			for (UINT j=0; j<nWidth; j++)
			{
				sts = pBmp->GetPixel(i,j,&oClr);
				if (sts != Ok) 
				{
					eRetValue = eSystemErr;
					break;
				}
				out_his.IncreaseAt(oClr.GetRed());
			}
			if(eRetValue != eNormal)
				 break;
		}
	}

	return eRetValue;
}

//************************************
// Method:    Draw
// FullName:  CImgSource::Draw
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: Graphics * in_pGraph
// Parameter: Rect in_rcArea
//************************************
procStatus CImgSource::Draw( Graphics* in_pGraph, const CRect& in_rcArea )
{

//	ASSERT(m_pGdipBitmap);
	ASSERT(in_pGraph);

	Status sts = Ok;
	procStatus eRetCode = eNormal;
	
	if(m_pGdipBitmap != NULL)
	{
 		INT xTPos = in_rcArea.Width() - m_pGdipBitmap->GetWidth();	
 		INT yTPos = in_rcArea.Height() - m_pGdipBitmap->GetHeight();
		INT xPos = 0;
 		INT yPos = 0;

		if(xTPos > IMP_IMAGESPACING) xPos = xTPos/2;
 		if(yTPos > IMP_IMAGESPACING) yPos = yTPos/2;
 		
			
		sts = in_pGraph->DrawImage(m_pGdipBitmap, (INT)xPos,(INT)yPos);
		if (sts != Ok)
		{
			eRetCode = eSystemErr;
		}
	}
	
	return eRetCode;
}
