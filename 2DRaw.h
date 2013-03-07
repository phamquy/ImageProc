// 2DRaw.h: interface for the C2DRaw class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_2DRAW_H__1B7E35B6_6134_4A66_A19E_D62868AACF45__INCLUDED_)
#define AFX_2DRAW_H__1B7E35B6_6134_4A66_A19E_D62868AACF45__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "RawElement.h"

// #ifndef UNIMPELMENTED_CRawElement
// typedef CRawElement element;
// #endif

//#ifdef UNIMPELMENTED_CRawElement
typedef INT element;
#define ELEMENT_MAX UCHAR_MAX 
#define ELEMENT_MIN 0
// #endif


class C2DRaw  
{
public:
	C2DRaw();
	C2DRaw(INT in_rows, INT in_cols);
	C2DRaw(INT in_nSize);
	virtual ~C2DRaw();
	
protected:	
	INT clearSource();
	INT m_nRows;
	INT m_nColums;
	//CRawElement* m_pDataElement;
	element* m_pDataElements;

public:
	INT InitSource(INT in_nSize=0);
	INT InitSource(INT in_rows, INT in_cols);
	//unary operator
	C2DRaw& operator=(const C2DRaw& rightOperand);
	const C2DRaw& operator+() const;
	const C2DRaw& operator-() const;
	const C2DRaw& operator+=(const INT nRight);
	const C2DRaw& operator+=(const C2DRaw& opright);
	const C2DRaw& operator-=(const INT nRight);
	const C2DRaw& operator-=(const C2DRaw& opright);
	const C2DRaw& operator*=(const INT nRight);
	const C2DRaw& operator*=(const C2DRaw& opright);
	const C2DRaw& operator/=(const INT nRight);
	const C2DRaw& operator/=(const C2DRaw& opright);

	//binary operator
	friend const C2DRaw operator+(	const C2DRaw& opleft,const C2DRaw& opright);
	friend const C2DRaw operator-(	const C2DRaw& opleft,const C2DRaw& opright);
	friend const C2DRaw operator*(	const C2DRaw& opleft,const C2DRaw& opright);
	friend const C2DRaw operator/(	const C2DRaw& opleft,const C2DRaw& opright);

public:
	BOOL IsValid() const;
	INT GetNumberOfRow() const;
	INT GetNumberOfCol() const;
	element GetElementAt(INT in_rowPos, INT in_colPos) const;
	element* GetElementRefAt(INT in_rowPos, INT in_colPos) const; 
	INT SetElementAt(INT in_rowPos, INT in_colPos,const element in_Element);
};

#endif // !defined(AFX_2DRAW_H__1B7E35B6_6134_4A66_A19E_D62868AACF45__INCLUDED_)
