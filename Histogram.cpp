// Histogram.cpp: implementation of the CHistogram class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "Histogram.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CHistogram::CHistogram()
{
	InitData(IMP_HIS_DEFAULT_SIZE, NULL);
}


CHistogram::CHistogram(UINT in_nNumberOfEntries, UINT* in_pData)
{
	InitData(in_nNumberOfEntries, in_pData);
}


CHistogram::~CHistogram()
{

}


//************************************
// Method:    InitData
// FullName:  initialize data from input channel
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
VOID CHistogram::InitData(UINT in_nNumOfEntries, UINT* in_pData)
{
	m_arrGrayData.SetSize(in_nNumOfEntries);
	m_nSize = in_nNumOfEntries;
	
	if (in_pData != NULL)
	{
		if(in_nNumOfEntries > 0)
		{
			for (int i=0; i< m_nSize; i ++)
			{
				m_arrGrayData.SetAt(i, *(in_pData + i));
			}
		}
	}	
}


//************************************
// Method:    GetAt
// FullName:  Get value from channels at specified position
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
UINT CHistogram::GetAt(UINT in_nPos)
{
	ASSERT(in_nPos < m_nSize);
	return m_arrGrayData.GetAt(in_nPos);
}
				  
//************************************
// Method:    SetAt
// FullName:  Set value at specified position for each channel
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
VOID CHistogram::SetAt(UINT in_nPos, UINT in_nVal)
{
	ASSERT(in_nPos < m_nSize);
	m_arrGrayData.SetAt(in_nPos,in_nVal);
}

//************************************
// Method:    Accumulate
// FullName:  calculate the accumulation of value from 0 to specified position in histogram table
// Access:    
// Returns:   
// Qualifier: 
// Parameter: in_nPos: specified position
//************************************
DWORD CHistogram::Accumulate(INT in_nPos)
{
	DWORD nTemp = 0;
	ASSERT(in_nPos < m_arrGrayData.GetSize());
	for (int i=0; i<=in_nPos; i++)
	{
		nTemp += m_arrGrayData.GetAt(i);
	}
	return nTemp;
}


//************************************
// Method:    IncreaseAt
// FullName:  CHistogram::IncreaseAt
// Access:    public 
// Returns:   VOID
// Qualifier:
// Parameter: UINT in_pos
//************************************
VOID CHistogram::IncreaseAt(UINT in_pos)
{
	ASSERT(in_pos < m_arrGrayData.GetSize());
	m_arrGrayData.SetAt(in_pos, m_arrGrayData.GetAt(in_pos) + 1);
}

//************************************
// Method:    Normalize
// FullName:  CHistogram::Normalize, normalizing this histogram
// Access:    public 
// Returns:   VOID
// Qualifier:
//************************************
VOID CHistogram::Normalize()
{
	
}
