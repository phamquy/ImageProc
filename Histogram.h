//////////////////////////////////////////////////////////////////////

#if !defined(AFX_HISTOGRAM_H__FABE8662_3E30_461B_ABD7_B7676326C397__INCLUDED_)
#define AFX_HISTOGRAM_H__FABE8662_3E30_461B_ABD7_B7676326C397__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CHistogram  
{
public:
	CHistogram();
	CHistogram(UINT,UINT*);
	virtual ~CHistogram();

protected:
	INT m_nSize;
	CUIntArray m_arrGrayData;

	
public:
	VOID Normalize();
	VOID IncreaseAt(UINT in_pos);
	VOID InitData(UINT in_nNumOfEntries, UINT* in_pData);
	
	INT GetSize()
	{
		return m_nSize;
	}
	
	VOID SetSize(INT in_nSize)
	{
		m_nSize = in_nSize;
		m_arrGrayData.SetSize(in_nSize);
	}
	
	
	UINT GetAt(UINT in_nPos);
	VOID SetAt(UINT in_nPos, UINT in_nVal);
	DWORD Accumulate( INT in_nPos);
	
};

#endif // !defined(AFX_HISTOGRAM_H__FABE8662_3E30_461B_ABD7_B7676326C397__INCLUDED_)