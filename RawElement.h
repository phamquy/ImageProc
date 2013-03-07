// RawElement.h: interface for the CRawElement class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAWELEMENT_H__2F9BBC09_39EE_479F_9A84_44E2E0DD4136__INCLUDED_)
#define AFX_RAWELEMENT_H__2F9BBC09_39EE_479F_9A84_44E2E0DD4136__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define UNIMPELMENTED_CRawElement

class CRawElement
{
public:
	CRawElement();
	virtual ~CRawElement();
	BYTE	m_nValue;

public:
	
	//unary operator
	CRawElement& operator=(const CRawElement& rightOperand);
	const CRawElement& operator+() const;
	const CRawElement& operator-() const;
	const CRawElement& operator+=(const INT nRight);
	const CRawElement& operator-=(const INT nRight);
	const CRawElement& operator*=(const INT nRight);
	const CRawElement& operator/=(const INT nRight);
	
	//binary operator
	friend const CRawElement operator+(	const CRawElement& opleft,const CRawElement& opright);
	friend const CRawElement operator-(	const CRawElement& opleft,const CRawElement& opright);
	friend const CRawElement operator*(	const CRawElement& opleft,const CRawElement& opright);
	friend const CRawElement operator*(	const CRawElement& opleft,const CRawElement& opright);


};

#endif // !defined(AFX_RAWELEMENT_H__2F9BBC09_39EE_479F_9A84_44E2E0DD4136__INCLUDED_)
