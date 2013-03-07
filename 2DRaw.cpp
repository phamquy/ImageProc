// 2DRaw.cpp: implementation of the C2DRaw class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "2DRaw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

C2DRaw::C2DRaw()
{
	m_nColums = m_nRows = 0;
	m_pDataElements = NULL;
}

C2DRaw::C2DRaw(INT in_rows, INT in_cols)
{	
	m_nColums = m_nRows = 0;
	m_pDataElements = NULL;
	InitSource(in_rows,in_cols);
}

C2DRaw::C2DRaw(INT in_nSize)
{
	m_nColums = m_nRows = 0;
	m_pDataElements = NULL;
	InitSource(in_nSize,in_nSize);
}

C2DRaw::~C2DRaw()
{
	clearSource();
}

//************************************
// Method:    
// FullName:  
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
INT C2DRaw::GetNumberOfRow() const
{
	return m_nRows;
}

//************************************
// Method:    
// FullName:  
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
INT C2DRaw::GetNumberOfCol() const
{
	return m_nColums;
}

//************************************
// Method:    
// FullName:  
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
element C2DRaw::GetElementAt(INT in_rowPos, INT in_colPos) const
{
// 	INT nSizeOfElement = sizeof(element);
	ASSERT((in_rowPos < m_nRows) && (in_colPos < m_nColums));
	element* temp = (element*)(m_pDataElements + in_rowPos * m_nColums + in_colPos);
	return *temp;
}

//************************************
// Method:    
// FullName:  
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
element* C2DRaw::GetElementRefAt(INT in_rowPos, INT in_colPos) const
{
// 	INT nSizeOfElement = sizeof(element);
	ASSERT((in_rowPos < m_nRows)&&(in_colPos < m_nColums));
	element* temp = (m_pDataElements + in_rowPos * m_nColums + in_colPos);
	return temp;
}


//************************************
// Method:    SetElementAt
// FullName:  
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
INT C2DRaw::SetElementAt(INT in_rowPos, INT in_colPos,const element in_Element)
{
	ASSERT((in_rowPos < m_nRows)&&(in_colPos < m_nColums));
	element* temp = (m_pDataElements + in_rowPos * m_nColums + in_colPos);
	*temp = in_Element;
	return eNormal;
}

//************************************
// Method:    clearSource
// FullName:  clear source 
// Access:    private
// Returns:   error code
// Qualifier: 
// Parameter: 
//************************************
INT C2DRaw::clearSource()
{
	ASSERT(IsValid());
	if(m_pDataElements != NULL)
	{
		//release memory
// 		for(int i=0; i< m_nRows * m_nColums; i++)
// 		{
// 			delete (m_pDataElements+i);
// 		}

		delete[] m_pDataElements;
	}
	m_pDataElements = NULL;
 	m_nColums = m_nRows = 0;
	return eNormal;	
}


INT C2DRaw::InitSource(INT in_nSize)
{
	return InitSource(in_nSize, in_nSize);
}

//************************************
// Method:    initSource
// FullName:  init for the object with number of row and colume
// Access:    protected
// Returns:   error code
// Qualifier: 
// Parameter: 
//************************************
INT C2DRaw::InitSource(INT in_rows, INT in_cols)
{
	INT retCode = eNormal;
	ASSERT(IsValid());
	if (m_pDataElements != NULL)
	{
		clearSource();
	} 
	else
	{
	}
	if(retCode == eNormal) 
	{
		m_nRows = in_rows;
		m_nColums = in_cols;
		m_pDataElements = new element[m_nRows * m_nColums];
		if(m_pDataElements == NULL)
		{
			retCode = eMemAllocErr;
		}
		else
		{
			FillMemory(m_pDataElements, sizeof(element)*m_nRows*m_nColums,0);
			/*
			for (int i=0; i < m_nRows; i++)
			{
				for(int j=0; j < m_nColums; j++)
				{
					//INT it = i;
					SetElementAt(i,j, ELEMENT_MIN);					
				}
			}*/
			
		}		
	}
		
	return retCode;
}

//************************************
// Method:    IsValid
// FullName:  Check if the inconsist between source and size
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
BOOL C2DRaw::IsValid() const
{
	if(((m_nColums * m_nRows) == 0) && (m_pDataElements != NULL))
	{		
		return FALSE;
	}
	
	if(((m_nColums * m_nRows) != 0) && (m_pDataElements == NULL))
	{
		return FALSE;
	}
	return TRUE;
}


/************************************************************************/
/*                     OPERATOR DEFINITION                              */
/************************************************************************/

/*
//--------------------unary operator--------------------------------------
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
*/

//************************************
// Method:    operator=
// FullName:  assign source
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
C2DRaw& C2DRaw::operator=(const C2DRaw& rightOperand)
{
	ASSERT(rightOperand.IsValid());

	if(&rightOperand != this) //avoid self assignment
	{
		int nRows = rightOperand.GetNumberOfRow();
		int nCols = rightOperand.GetNumberOfCol();
		//re-construct object
		InitSource(nRows, nCols);

		//copy source to this
		for(int i=0; i< nRows; i++)
		{
			for (int j=0; j< nCols; j++)
			{
				SetElementAt(i,j, rightOperand.GetElementAt(i,j));
			}			
		}
	}

	return *this; //enable x = y = z
}



//************************************
// Method:    operator+
// FullName:  unary operator +
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
const C2DRaw& C2DRaw::operator+() const
{
	ASSERT(IsValid());
	return *this;
}


//************************************
// Method:    operator-
// FullName:  unary invert operator: element = 255 - element
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
const C2DRaw& C2DRaw::operator-() const
{
	ASSERT(IsValid());
	C2DRaw temp(m_nRows, m_nColums);
	element eMax(ELEMENT_MAX);

	for(int i=0; i<temp.GetNumberOfRow(); i++)
	{
		for(int j=0; j< temp.GetNumberOfCol(); j++)
		{
			temp.SetElementAt(i, j, eMax - GetElementAt(i,j));
		}
	}
	return temp;
}


//************************************
// Method:    operator+=
// FullName:  Add all element of image with a constant value
// Access:    public
// Returns:   reference to this
// Qualifier: 
// Parameter: 
//************************************
const C2DRaw& C2DRaw::operator+=(const INT nRight)
{
	ASSERT(IsValid());
	element eRight(nRight);
	for(int i=0; i<GetNumberOfRow(); i++)
	{
		for(int j=0; j< GetNumberOfCol(); j++)
		{
			// TEMPORARY CODE [12/19/2007 QUYPS]
			if ((GetElementAt(i,j) + eRight) > ELEMENT_MAX)
			{
				SetElementAt(i, j, ELEMENT_MAX);
			} 
			else
			{
				SetElementAt(i, j, GetElementAt(i,j) + eRight);
			}			
		}
	}

	return *this;
}


//************************************
// Method:    operator+=
// FullName:  Add all element of image with corresponding element in right operand
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
const C2DRaw& C2DRaw::operator+=(const C2DRaw& opright)
{
	ASSERT(opright.IsValid() && IsValid());
	for(int i=0; i<GetNumberOfRow(); i++)
	{
		for(int j=0; j< GetNumberOfCol(); j++)
		{
			if ((GetElementAt(i,j) + opright.GetElementAt(i,j)) > ELEMENT_MAX)
			{
				SetElementAt(i, j, ELEMENT_MAX);
			} 
			else
			{
				SetElementAt(i, j, GetElementAt(i,j) + opright.GetElementAt(i,j));
			}			
		}
	}
	
	return *this;
	
}
//************************************
// Method:    operator-=
// FullName:  subtract by a constant value
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
const C2DRaw& C2DRaw::operator-=(const INT nRight)
{
	ASSERT(IsValid());
	element eRight(nRight);
	for(int i=0; i<GetNumberOfRow(); i++)
	{
		for(int j=0; j< GetNumberOfCol(); j++)
		{
			if ((GetElementAt(i,j) - eRight) < ELEMENT_MIN)
			{
				SetElementAt(i, j, ELEMENT_MIN);
			} 
			else
			{
				SetElementAt(i, j, GetElementAt(i,j) - eRight);
			}			
		}
	}

	return *this;
}

//************************************
// Method:    operator-=
// FullName:  subtract all element of image by corresponding element in right operand
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
const C2DRaw& C2DRaw::operator-=(const C2DRaw& opright)
{
	ASSERT(opright.IsValid() && IsValid());
	for(int i=0; i<GetNumberOfRow(); i++)
	{
		for(int j=0; j< GetNumberOfCol(); j++)
		{
			if ((GetElementAt(i,j) - opright.GetElementAt(i,j)) < ELEMENT_MIN)
			{
				SetElementAt(i, j, ELEMENT_MIN);
			} 
			else
			{
				SetElementAt(i, j, GetElementAt(i,j) - opright.GetElementAt(i,j));
			}			
		}
	}	
	return *this;
}


//************************************
// Method:    operator*=
// FullName:  multiple with a constant value
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
const C2DRaw& C2DRaw::operator*=(const INT nRight)
{
	ASSERT(IsValid());
	element eRight(nRight);
	for(int i=0; i<GetNumberOfRow(); i++)
	{
		for(int j=0; j< GetNumberOfCol(); j++)
		{
			// TEMPORARY [12/19/2007 QUYPS]
			if ((GetElementAt(i,j) * eRight) > ELEMENT_MAX)
			{
				SetElementAt(i, j, ELEMENT_MAX);
			} 
			else
			{
				SetElementAt(i, j, GetElementAt(i,j) * eRight);
			}			
		}
	}
	
	return *this;
}


//************************************
// Method:    operator*=
// FullName:  multiple all element of image with corresponding element in right operand
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
const C2DRaw& C2DRaw::operator*=(const C2DRaw& opright)
{
	ASSERT(opright.IsValid() && IsValid());
	for(int i=0; i<GetNumberOfRow(); i++)
	{
		// TEMPORARY [12/19/2007 QUYPS]
		for(int j=0; j< GetNumberOfCol(); j++)
		{
			if ((GetElementAt(i,j) * opright.GetElementAt(i,j)) > ELEMENT_MAX)
			{
				SetElementAt(i, j, ELEMENT_MAX);
			} 
			else
			{
				SetElementAt(i, j, GetElementAt(i,j) * opright.GetElementAt(i,j));
			}
			
		}
	}	
	return *this;
}

//************************************
// Method:    operator/=
// FullName:  divide by a constant value
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
const C2DRaw& C2DRaw::operator/=(const INT nRight)
{	
	ASSERT(IsValid());

	element eRight(nRight);
	for(int i=0; i<GetNumberOfRow(); i++)
	{
		for(int j=0; j< GetNumberOfCol(); j++)
		{
			if (nRight == 0)
			{
				SetElementAt(i, j, ELEMENT_MAX);
			} 
			else
			{
				SetElementAt(i, j, GetElementAt(i,j) / eRight);
			}			
		}
	}
	
	return *this;
}


//************************************
// Method:    operator/=
// FullName:  multiple all element of image with corresponding element in right operand
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
const C2DRaw& C2DRaw::operator/=(const C2DRaw& opright)
{
	ASSERT(opright.IsValid() && IsValid());
	for(int i=0; i<GetNumberOfRow(); i++)
	{
		// TEMPORARY [12/19/2007 QUYPS]
		for(int j=0; j< GetNumberOfCol(); j++)
		{
			if (opright.GetElementAt(i,j) == 0)
			{
				SetElementAt(i, j, ELEMENT_MAX);
			} 
			else
			{
				SetElementAt(i, j, GetElementAt(i,j) / opright.GetElementAt(i,j));
			}
			
		}
	}	
	return *this;
}



/*
//---------------------------binary operator-------------------------------
friend const C2DRaw operator+(	const C2DRaw& opleft,const C2DRaw& opright);
friend const C2DRaw operator-(	const C2DRaw& opleft,const C2DRaw& opright);
friend const C2DRaw operator*(	const C2DRaw& opleft,const C2DRaw& opright);
friend const C2DRaw operator*(	const C2DRaw& opleft,const C2DRaw& opright);
*/

//************************************
// Method:    operator+
// FullName:  binary operator+
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
const C2DRaw operator+(	const C2DRaw& opleft,const C2DRaw& opright)
{
	//check the validation
	ASSERT(opleft.IsValid() && opright.IsValid());
	
	//Check the validation of size
	ASSERT((opleft.GetNumberOfRow() == opright.GetNumberOfRow()) && (opleft.GetNumberOfCol() == opright.GetNumberOfCol()));
	
	C2DRaw temp(opleft.GetNumberOfRow(), opleft.GetNumberOfCol());
	
	for(int i=0; i<temp.GetNumberOfRow(); i++)
	{
		for(int j=0; j< temp.GetNumberOfCol(); j++)
		{
			temp.SetElementAt(i, j, opleft.GetElementAt(i,j) + opright.GetElementAt(i,j));
		}
	}
	return C2DRaw(temp);
}

//************************************
// Method:    operator-
// FullName:  binary operator-
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
const C2DRaw operator-(	const C2DRaw& opleft,const C2DRaw& opright)
{
	//check the validation
	ASSERT(opleft.IsValid() && opright.IsValid());
	
	//Check the validation of size
	ASSERT((opleft.GetNumberOfRow() == opright.GetNumberOfRow()) && (opleft.GetNumberOfCol() == opright.GetNumberOfCol()));
	
	C2DRaw temp(opleft.GetNumberOfRow(), opleft.GetNumberOfCol());
	
	for(int i=0; i<temp.GetNumberOfRow(); i++)
	{
		for(int j=0; j< temp.GetNumberOfCol(); j++)
		{
			temp.SetElementAt(i, j, opleft.GetElementAt(i,j) - opright.GetElementAt(i,j));
		}
	}
	return temp;
}

//************************************
// Method:    operator*
// FullName:  binary operator*
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
const C2DRaw operator*(	const C2DRaw& opleft,const C2DRaw& opright)
{
	//check the validation
	ASSERT(opleft.IsValid() && opright.IsValid());
	
	//Check the validation of size
	ASSERT((opleft.GetNumberOfRow() == opright.GetNumberOfRow()) && (opleft.GetNumberOfCol() == opright.GetNumberOfCol()));
	
	C2DRaw temp(opleft.GetNumberOfRow(), opleft.GetNumberOfCol());
	
	for(int i=0; i<temp.GetNumberOfRow(); i++)
	{
		for(int j=0; j< temp.GetNumberOfCol(); j++)
		{
			temp.SetElementAt(i, j, opleft.GetElementAt(i,j) * opright.GetElementAt(i,j));
		}
	}
		
	return temp;
}


//************************************
// Method:    operator*
// FullName:  binary operator*
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
const C2DRaw operator/(	const C2DRaw& opleft,const C2DRaw& opright)
{
	//check the validation
	ASSERT(opleft.IsValid() && opright.IsValid());
	
	//Check the validation of size
	ASSERT((opleft.GetNumberOfRow() == opright.GetNumberOfRow()) && (opleft.GetNumberOfCol() == opright.GetNumberOfCol()));
	
	C2DRaw temp(opleft.GetNumberOfRow(), opleft.GetNumberOfCol());
	
	for(int i=0; i<temp.GetNumberOfRow(); i++)
	{
		for(int j=0; j< temp.GetNumberOfCol(); j++)
		{
			// TEMPORARY [12/19/2007 QUYPS]
			//when the divisor is zero
			if (opright.GetElementAt(i,j) == 0)
			{
				temp.SetElementAt(i,j, ELEMENT_MAX);
			} 
			else
			{
				temp.SetElementAt(i, j, opleft.GetElementAt(i,j) * opright.GetElementAt(i,j));	
			}
			//temp.SetElementAt(i, j, opleft.GetElementAt(i,j) * opright.GetElementAt(i,j));			
		}
	}
		
	return temp;
}