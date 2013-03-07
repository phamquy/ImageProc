// FFTMachine.cpp: implementation of the CFFTMachine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "FFTMachine.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

#include <math.h>
#include "Utility.h"

CFFTMachine::CFFTMachine()
{

}

CFFTMachine::~CFFTMachine()
{

}

//************************************
// Method:    FF2D
// FullName:  CFFTMachine::FF2D
// Access:    public 
// Returns:   CImgSource*
// Qualifier:
// Parameter: CImgSource * in_pSrcImg
//************************************
procStatus CFFTMachine::Run( CImgSource* in_pSrcImg, CImgFourierSource* out_pDesImg, FourierDirection eDirection )
{
	procStatus eRetCode = eNormal;

	ASSERT (out_pDesImg);
	ASSERT (in_pSrcImg);
	SourceType eType = in_pSrcImg->GetType();
	if( eType < eSrcMonoBitmap) 
	{
		AfxMessageBox(IMP_MSG_ADDSRC_INVALIDTYPE);
		eRetCode = eInvalidOp;
	}
	if(eRetCode != eNormal) return eRetCode;
	
	COMPLEX** ppSource = NULL;
	Bitmap* pResBmp = NULL;
	INT nWidth = 0;
	INT nHeight = 0;
	nWidth = in_pSrcImg->GetSourceRef()->GetWidth();
	nHeight = in_pSrcImg->GetSourceRef()->GetHeight();
	
	//Convert bitmap to complex in memory
	ppSource = allocateComplexArray(nHeight, nWidth);
	if(ppSource == NULL)
	{
		eRetCode = eMemAllocErr;
	}

	if (eRetCode == eNormal)eRetCode = getComplexImage(in_pSrcImg, ppSource);

	//Run 2D Fourier transform
	if(eRetCode == eNormal)
	{	
		BOOL ffRetults = TRUE;
	
		//run Fourier transform
		eRetCode = FFT2D(ppSource, nWidth, nHeight, eDirection);
	}

	//Convert from complex to bitmap			
	if(eRetCode == eNormal)
	{
	
		
#ifdef _DEBUG
// 		for (INT row=0; row<nHeight; row++)
// 		for(INT col=0; col<nWidth; col++)
// 			TRACE("\nrow:%d \tcol:%d real:%f imag:%f",row, col, ppSource[row][col].real,  ppSource[row][col].imag);		
#endif	
		
		pResBmp = getBitmapFromComplex(ppSource, nWidth, nHeight);
		if(pResBmp == NULL)
		{
			eRetCode = eSystemErr;
		}
	}

	//Create ImgSource object
	if(eRetCode == eNormal)
	{
		out_pDesImg->SetType(eSrcFourierBitmap);
		out_pDesImg->AttachSource(pResBmp);
		out_pDesImg->SetName(in_pSrcImg->GetName() + IMP_SUF_FOURIER);
		out_pDesImg->m_oFFresult.nWidth= nWidth;
		out_pDesImg->m_oFFresult.nHeight = nHeight;
		out_pDesImg->m_oFFresult.ppComplex= ppSource;
	}
	else
	{
		freeAllocateComplex(ppSource, nHeight, nWidth);
	}
		
	return eRetCode;		
}



//************************************
// Method:    allocateComplexArray
// FullName:  CFFTMachine::allocateComplexArray
// Access:    protected 
// Returns:   COMPLEX**
// Qualifier:
// Parameter: INT in_nRows
// Parameter: INT in_nCols
//************************************
COMPLEX** CFFTMachine::allocateComplexArray(INT in_nRows, INT in_nCols)
{
	//ASSERT(FALSE);
	BOOL flagOk = TRUE;
	COMPLEX** ppSource = NULL;

	ppSource = new LPCOMPLEX[in_nRows];

	if(ppSource != NULL)
	{
		for(INT row=0; row<in_nRows; row++)
		{
			ppSource[row] = NULL;
			ppSource[row] = new COMPLEX[in_nCols];
			if(ppSource[row] == NULL) 
			{
				flagOk = FALSE;
				break;		
			}
		}
	}

	//if error during allocating, release allocated memory
	if(!flagOk)
	{
		for(INT row1=0; row1<in_nRows; row1++)
		{
			if(ppSource[row1] != NULL)
			{
				delete[] ppSource[row1];
				ppSource[row1] = NULL;				
			}				
		}
		delete[] ppSource;
		ppSource = NULL;
	}
	
	//if allocate  success, clear memory
	if(flagOk)
	{
		for (INT row2=0; row2<in_nRows; row2++)
		{
			for(INT col=0; col<in_nCols; col++)
			{
				ppSource[row2][col].real = 0;
				ppSource[row2][col].imag = 0;
			}
		}
	}
	return ppSource;
}


//************************************
// Method:    freeAllocateComplex
// FullName:  CFFTMachine::freeAllocateComplex
// Access:    protected 
// Returns:   procStatus
// Qualifier:
// Parameter: COMPLEX * * ppSource
// Parameter: INT rows
// Parameter: INT cols
//************************************
procStatus CFFTMachine::freeAllocateComplex(COMPLEX **ppSource, INT in_nRows, INT in_nCols)
{
	
	for(INT row=0; row<in_nRows; row++)
	{
		if(ppSource[row] != NULL)
		{
			delete[] ppSource[row];
			ppSource[row] = NULL;				
		}				
	}
	delete[] ppSource;
	ppSource = NULL;
	return eNormal;
}



//************************************
// Method:    valueTransform
// FullName:  CFFTMachine::valueTransform
// Access:    protected 
// Returns:   BYTE
// Qualifier:
// Parameter: DOUBLE in_dReal
//************************************
BYTE CFFTMachine::valueTransform(DOUBLE in_dReal)
{
	
	DOUBLE retVal = 0;
	retVal = (256 * log(1 + fabs(in_dReal)));
	if(retVal > 255) retVal = 255;
	
//	TRACE("\nBefore:%f \t\tAfter:%d",in_dReal, retVal);
	return retVal;
}


//************************************
// Method:    getBitmapFromComplex
// FullName:  CFFTMachine::getBitmapFromComplex
// Access:    protected 
// Returns:   Bitmap*
// Qualifier:
// Parameter: LPCOMPLEX pSource
// Parameter: INT nWidth
// Parameter: INT nHeight
//************************************
Bitmap* CFFTMachine::getBitmapFromComplex(LPCOMPLEX* ppSource,INT  in_nWidth,INT in_nHeight)
{
	ASSERT(ppSource);
	BYTE* pBuffer = NULL;
	pBuffer = new BYTE[in_nWidth * in_nHeight * 3];
	
	//change the coordinate and calculate the value to display
	/*
			0	   --->		cols (x)
		  0	+-------+-------+	
	  		|	1	|   2   |
		  |	|		|		|
		  |	+-------+-------+
		  Y	|	3  	|	4	|
			|		|		|
	   rows	+-------+-------+
	    (y)

		Coordinate transform
		1<->4; 2<->3 
	*/

	if(pBuffer != NULL)
	{
		FillMemory(pBuffer, in_nWidth * in_nHeight * 3, 0);
		INT nWidth_2  = in_nWidth/2;
		INT nHeight_2 = in_nHeight/2;
		
		for(INT y=0; y<in_nHeight; y++)
		{
			for (INT x=0; x<in_nWidth; x++)	
			{
				BYTE nPixelVal = 0;
				//in the part1 --> move to part 4
				if((x<nWidth_2)&&(y<nHeight_2))
					nPixelVal = valueTransform(ppSource[y + nHeight_2][x + nWidth_2].real);
				//in the part2 --> move to part 3
				else if ((x>=nWidth_2)&&(y<nHeight_2))
					nPixelVal = valueTransform(ppSource[y + nHeight_2][x - nWidth_2].real);
				//in the part3 --> move to part 2
				else if((x<nWidth_2)&&(y>=nHeight_2))
					nPixelVal = valueTransform(ppSource[y - nHeight_2][x + nWidth_2].real);
				//in the part4 --> move to part 1
				else
					nPixelVal = valueTransform(ppSource[y - nHeight_2][x - nWidth_2].real);					
					
				*(pBuffer + 3*(y*in_nWidth + x) + 0) = nPixelVal;	//R
				*(pBuffer + 3*(y*in_nWidth + x) + 1) = nPixelVal;	//G
				*(pBuffer + 3*(y*in_nWidth + x) + 2) = nPixelVal;	//B
			}
		}
		//adjust image
		for (INT j=0;j<nHeight_2;j++)
		{
			for(INT k=0;k<in_nWidth;k++)
			{
				BYTE temp = *(pBuffer + 3*(j*in_nWidth + k) + 0);
				*(pBuffer + 3*(j*in_nWidth + k) + 0) = *(pBuffer + 3*((in_nHeight- j -1)*in_nWidth+k));	//R
				*(pBuffer + 3*(j*in_nWidth + k) + 1) = *(pBuffer + 3*((in_nHeight- j -1)*in_nWidth+k));
				*(pBuffer + 3*(j*in_nWidth + k) + 2) = *(pBuffer + 3*((in_nHeight- j -1)*in_nWidth+k));
				*(pBuffer + 3*((in_nHeight- j -1)*in_nWidth+k) + 0) =  temp;
				*(pBuffer + 3*((in_nHeight- j -1)*in_nWidth+k) + 1) =  temp;
				*(pBuffer + 3*((in_nHeight- j -1)*in_nWidth+k) + 2) =  temp;
			}
		}
	}

	Bitmap* pRetBmp = NULL; 
	BITMAPINFO t_BMPinfo;
	BITMAPINFOHEADER* pBMPInfoHeader = &(t_BMPinfo.bmiHeader); 
	memset(pBMPInfoHeader, 0, sizeof(BITMAPINFOHEADER));
	//Create bitmap header	
	pBMPInfoHeader->biSize			= sizeof(BITMAPINFOHEADER);
	pBMPInfoHeader->biWidth			= in_nWidth;
	pBMPInfoHeader->biHeight		= in_nHeight;
	pBMPInfoHeader->biPlanes		= 1;
	pBMPInfoHeader->biCompression	= BI_RGB;
	pBMPInfoHeader->biBitCount		= IMP_MONOBMP_BITS * 3;
	pBMPInfoHeader->biSizeImage		= in_nWidth * in_nHeight * 3;

	if(pBuffer != NULL)	pRetBmp = Bitmap::FromBITMAPINFO(&t_BMPinfo,pBuffer);		
	
	if(pRetBmp == NULL)
	{
		delete[] pBuffer;
		pBuffer = NULL;
	}

	
#ifdef _DEBUG
	if(pRetBmp != NULL)
	{
		CLSID pngClsid;
		CUtility::GetEncoderClsid(L"image/bmp", &pngClsid);
		Status res = pRetBmp->Save(L".\\Fourier.bmp", &pngClsid, NULL);	
	}	
#endif
	
	return pRetBmp;
}

//************************************
// Method:    getComplexImage
// FullName:  CFFTMachine::getComplexImage
// Access:    protected 
// Returns:   LPCOMPLEX
// Qualifier:
// Parameter: CImgSource * in_pSrcImg
//************************************
procStatus CFFTMachine::getComplexImage( CImgSource* in_pSrc, LPCOMPLEX* out_ppComplex )
{
	procStatus eRetCode = eNormal;

	Bitmap* pBmp = in_pSrc->GetSourceRef();
	ASSERT(pBmp != NULL);
	ASSERT(out_ppComplex);
	

	INT nWidth = pBmp->GetWidth();
	INT nHeight= pBmp->GetHeight();
	
	SourceType eType = in_pSrc->GetType();
	Status sts = Ok;
	BYTE nVal = 0;

	for (INT y=0;y<nHeight;y++)	//for all rows
	{
		for (INT x=0;x<nWidth; x++) //for all col
		{
			nVal = 0;
			Color clr(0,0,0);
			sts = pBmp->GetPixel(x,y, &clr);
			if(sts == Ok)
			{
				nVal = CUtility::GetMonoPixelValue(clr, eType);
				out_ppComplex[y][x].real = nVal; 
			}
			else
			{
				break;
			}
		}
		if(sts != Ok) break;
	}
	
	if (sts != Ok)
	{
		eRetCode = eSystemErr;
	}
	return eRetCode;
}



// ----------------------------- [12/26/2007 QUYPS]-------------------------
BOOL CFFTMachine::Powerof2( int nx,int* out_exp, int* out_nearest )
{
	BOOL retVal = TRUE;
	INT nTemp;
	INT nExp;
	
	nExp = 0;
	nTemp = 1;
	
	//check if size is power of two
	while (nTemp < nx)
	{
		nTemp = nTemp*2;
		nExp++;
	}
	
	if(nTemp != nx)
	{
		retVal =  FALSE;
	}
	
	*out_exp = nExp;
	*out_nearest = nTemp;
	return retVal;
}

/*-------------------------------------------------------------------------
   Perform a 2D FFT inplace given a complex 2D array
   The direction dir, 1 for forward, -1 for reverse
   The size of the array (nx,ny)
   Return false if there are memory problems or
      the dimensions are not powers of 2
*/
procStatus CFFTMachine::FFT2D( COMPLEX **c,int nx,int ny,int dir )
{
   int i,j;
   int m,twopm;
   double *real,*imag;

   /* Transform the rows */
   real = (double *)malloc(nx * sizeof(double));
   imag = (double *)malloc(nx * sizeof(double));
   if (real == NULL || imag == NULL)
      return(eMemAllocErr);
   if (!Powerof2(nx,&m,&twopm) || twopm != nx)
      return(eInvalideArg);
   for (j=0;j<ny;j++) {
      for (i=0;i<nx;i++) {
         real[i] = c[i][j].real;
         imag[i] = c[i][j].imag;
      }
      FFT(dir,m,real,imag);
      for (i=0;i<nx;i++) {
         c[i][j].real = real[i];
         c[i][j].imag = imag[i];
      }
   }
   free(real);
   free(imag);

   /* Transform the columns */
   real = (double *)malloc(ny * sizeof(double));
   imag = (double *)malloc(ny * sizeof(double));
   if (real == NULL || imag == NULL)
      return(eMemAllocErr);
   if (!Powerof2(ny,&m,&twopm) || twopm != ny)
      return(eInvalideArg);
   for (i=0;i<nx;i++) {
      for (j=0;j<ny;j++) {
         real[j] = c[i][j].real;
         imag[j] = c[i][j].imag;
      }
      FFT(dir,m,real,imag);
      for (j=0;j<ny;j++) {
         c[i][j].real = real[j];
         c[i][j].imag = imag[j];
      }
   }
   free(real);
   free(imag);

   return(eNormal);
}

/*-------------------------------------------------------------------------
   This computes an in-place complex-to-complex FFT
   x and y are the real and imaginary arrays of 2^m points.
   dir =  1 gives forward transform
   dir = -1 gives reverse transform

     Formula: forward
                  N-1
                  ---
              1   \          - j k 2 pi n / N
      X(n) = ---   >   x(k) e                    = forward transform
              N   /                                n=0..N-1
                  ---
                  k=0

      Formula: reverse
                  N-1
                  ---
                  \          j k 2 pi n / N
      X(n) =       >   x(k) e                    = forward transform
                  /                                n=0..N-1
                  ---
                  k=0
*/
int CFFTMachine::FFT(int dir,int m,double *x,double *y)
{
   long nn,i,i1,j,k,i2,l,l1,l2;
   double c1,c2,tx,ty,t1,t2,u1,u2,z;

   /* Calculate the number of points */
   nn = 1;
   for (i=0;i<m;i++)
      nn *= 2;

   /* Do the bit reversal */
   i2 = nn >> 1;
   j = 0;
   for (i=0;i<nn-1;i++) {
      if (i < j) {
         tx = x[i];
         ty = y[i];
         x[i] = x[j];
         y[i] = y[j];
         x[j] = tx;
         y[j] = ty;
      }
      k = i2;
      while (k <= j) {
         j -= k;
         k >>= 1;
      }
      j += k;
   }

   /* Compute the FFT */
   c1 = -1.0;
   c2 = 0.0;
   l2 = 1;
   for (l=0;l<m;l++) {
      l1 = l2;
      l2 <<= 1;
      u1 = 1.0;
      u2 = 0.0;
      for (j=0;j<l1;j++) {
         for (i=j;i<nn;i+=l2) {
            i1 = i + l1;
            t1 = u1 * x[i1] - u2 * y[i1];
            t2 = u1 * y[i1] + u2 * x[i1];
            x[i1] = x[i] - t1;
            y[i1] = y[i] - t2;
            x[i] += t1;
            y[i] += t2;
         }
         z =  u1 * c1 - u2 * c2;
         u2 = u1 * c2 + u2 * c1;
         u1 = z;
      }
      c2 = sqrt((1.0 - c1) / 2.0);
      if (dir == 1)
         c2 = -c2;
      c1 = sqrt((1.0 + c1) / 2.0);
   }

   /* Scaling for forward transform */
   if (dir == 1) {
      for (i=0;i<nn;i++) {
         x[i] /= (double)nn;
         y[i] /= (double)nn;
      }
   }

   return(TRUE);
}

