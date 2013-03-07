// ImgFourierSource.cpp: implementation of the CImgFourierSource class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "ImgFourierSource.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CImgFourierSource::CImgFourierSource()
{

}

CImgFourierSource::~CImgFourierSource()
{
	if(m_oFFresult.ppComplex != NULL)
	{
		for (INT i=0; i<m_oFFresult.nHeight; i++)
		{
			delete[] m_oFFresult.ppComplex[i];
		}
		m_oFFresult.ppComplex = NULL;
	}
}
