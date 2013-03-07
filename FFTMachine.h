// FFTMachine.h: interface for the CFFTMachine class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FFTMACHINE_H__DDE2DAD6_F5B5_4A72_A13F_4E54442F2A09__INCLUDED_)
#define AFX_FFTMACHINE_H__DDE2DAD6_F5B5_4A72_A13F_4E54442F2A09__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImgSource.h"
#include "Include.h"	// Added by ClassView
#include "ImgFourierSource.h"

class CFFTMachine  
{

public:
	CFFTMachine();
	virtual ~CFFTMachine();
	procStatus Run(CImgSource* in_pSrcImg, CImgFourierSource* out_pDesImg, FourierDirection eDirection);


protected:
	BYTE valueTransform(DOUBLE in_dReal);
	
	procStatus freeAllocateComplex(COMPLEX** ppSource, INT in_nRows, INT in_nCols);
	
	COMPLEX** allocateComplexArray(INT in_nRows, INT in_nCols);
	
	Bitmap* getBitmapFromComplex(LPCOMPLEX* pSource,INT  in_nWidth,INT in_nHeight);
	
	BOOL Powerof2(int nx,int* out_exp, int* out_nearest);
	
	int FFT(int dir,int m,double *x,double *y);
	
	procStatus FFT2D(COMPLEX **c,int nx,int ny,int dir);
	
	procStatus getComplexImage(CImgSource* in_pSrc, LPCOMPLEX* out_ppComplex);
};

#endif // !defined(AFX_FFTMACHINE_H__DDE2DAD6_F5B5_4A72_A13F_4E54442F2A09__INCLUDED_)
