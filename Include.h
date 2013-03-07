// ***************************************************************
//  Include   version:  1.0   ¡¤  date: 12/17/2007
//  -------------------------------------------------------------
//  File for general definition 
//  -------------------------------------------------------------
//  Copyright (C) 2007 - All Rights Reserved
// ***************************************************************
// 
// ***************************************************************

#if !defined(IMP_GENERAL_INCLUDE__H_)
#define IMP_GENERAL_INCLUDE__H_


#include <GdiPlus.h>
using namespace Gdiplus;

//Definition of mask type  [12/17/2007 QUYPS]
enum MaskType
{
	eUserDefined,	//user define
	eSobelGx,		
	eSobelGy,		
	eRobertGx,		
	eRobertGy,
	ePrewittVerti,
	ePrewittHoriz,
	eLaplacian1_4,
	eLaplacian1_8,
	eLaplacian1_2_4,
	eGaussian1_115
};

// Definition of mask name [12/20/2007 QUYPS]
#define IMP_MASK_USER_DEFINED _T("User defined mask")
#define IMP_MASK_SOBEL_GX		_T("Sobel GX mask")
#define IMP_MASK_SOBEL_GY		_T("Sobel GY mask")
#define IMP_MASK_ROBERT_GX		_T("Robert GX mask")
#define IMP_MASK_ROBERT_GY		_T("Robert GY mask")
#define IMP_MASK_PREWITT_VER	_T("Prewitt vertical mask")
#define IMP_MASK_PREWITT_HOR	_T("Prewitt horizontal mask")
#define IMP_MASK_LAP_1_4		_T("Laplacian type1 mask")
#define IMP_MASK_LAP_1_8		_T("Laplacian type2 mask")
#define IMP_MASK_LAP_1_2_4		_T("Laplacian type3 mask")
#define IMP_MASK_GAUSS_1_115	_T("Gaussian mask 1/115")

// Definition of mask size [12/20/2007 QUYPS]
#define IMP_MASK_SIZE_SOBEL		3
#define IMP_MASK_SIZE_ROBERT	2		
#define IMP_MASK_SIZE_PREWITT	3	
#define IMP_MASK_SIZE_LAP_1		3
#define IMP_MASK_SIZE_GAUSS		5


// Definition of image source type [12/17/2007 QUYPS]
enum SourceType
{
	eSrcNone,
	eSrcFourierBitmap,	//Fourier transformed bitmap it only can be used for Fourier domain transform
	eSrcColorBitmap,	//Color (RGB) bitmap, it cann't be used for any image process
	eSrcMonoBitmap,		//Monochrome bitmap, it can be use for any image process
	eSrcMonoRed,
	eSrcMonoGreen,
	eSrcMonoBlue		
};


// Definition of operation type [12/17/2007 QUYPS]
enum OperationType
{
	eOpNone,
	ePixelOperation,
	eFourier,
	eHistogram,
	eGrayTransform,
	eFiltering
};

// Definition of operation capacity structure [12/17/2007 QUYPS]
typedef struct tagOPERATION_CAP
{
	BOOL flagFourier;
	BOOL flagHistogram;
	BOOL flagBitoperation;
	tagOPERATION_CAP()
	{
		flagFourier = TRUE;
		flagHistogram = TRUE;
		flagBitoperation = TRUE;
	}

	tagOPERATION_CAP(BOOL bFourier,BOOL bHis,BOOL bBitOp)
	{
		flagFourier = bFourier;
		flagHistogram = bHis;
		flagBitoperation = bBitOp;
	}

	tagOPERATION_CAP(BOOL flag)
	{	
		flagFourier = flagBitoperation = flagHistogram = flag;
	}

} t_OpCap;


// Definition of raw size struct [12/21/2007 QUYPS]
typedef struct tagRAWSIZE
{
	UINT nWidth;
	UINT nHeight;
	tagRAWSIZE()
	{
		nWidth = 0;
		nHeight = 0;
	}
} t_RawSize;

// Definition of raw pixel format [12/22/2007 QUYPS]
enum BitOrder
{
	eHigh,
	eLow,
};


// Definition of file type [12/23/2007 QUYPS]

enum FileFormat
{
	eRaw,
	eBitmap,
	eJpeg,
	eTiff,
	ePng,
	eGif
};

enum FileType
{
	eUnknown,
	eUnformated,
	eFormated
};
// Definition of supported extesion [12/23/2007 QUYPS]
#define IMP_MIME_BITMAP _T("image/bmp")
#define IMP_MIME_JPEG	_T("image/jpeg")
#define IMP_MIME_GIF	_T("image/gif")
#define IMP_MIME_TIFF	_T("image/tif")
#define IMP_MIME_PNG	_T("image/png")

#define IMP_FILEEXT_RAW _T("raw")
#define IMP_FILEEXT_BMP _T("bmp")
#define IMP_FILEEXT_JPG _T("jpg")
#define IMP_FILEEXT_PNG _T("png")
#define IMP_FILEEXT_TIF _T("tif")
#define IMP_FILEEXT_GIF _T("gif")


typedef struct tagRAWPIXELFORMAT
{
	BYTE nBitPerPixel;
	BitOrder nBitOrder;
	BYTE nUsedBits;
	tagRAWPIXELFORMAT()
	{
		nBitPerPixel = 8;
		nBitOrder = eHigh;
		nUsedBits  = 8;
	}
}RAWPIXELFORMAT;

// Definition of process status [12/17/2007 QUYPS]
enum procStatus
{
	eNormal,
	eSystemErr,
	eNullPointer,
	eFileIOError,
	eMemErr,
	eMemAllocErr,
	eInvalidOp,
	eInvalideArg
};


// Definition of color channel [12/20/2007 QUYPS]
enum ColorChannel
{
	eGray,
	eRed,
	eGreen,
	eBlue
};

// Definition of grayscale transform function [12/26/2007 QUYPS]
enum TransformFunction
{
	eNoTrans,
	eCustomTrans,
	eInvert,
	ePower,
	eLogarithm,
	ePieceWise,
	eThreshold,
	eSlicing
};

enum HistogramFunction
{
	eNoChange,
	eEqualization,
	eMatching,
	eStretch
};

enum ThresholedType
{
	eHighPass,
	eLowPass
};

enum EdgeDetectorType
{
	eCustom,
	eCanny,
	eLaplacian,
	ePrewitt,
	eRobert,
	eSobel
};

// Definition of normalize value mode[12/27/2007 QUYPS]

enum NormalizeMode
{
	eTrimming,
	eAbsolute
};

// FourierDirection [12/26/2007 QUYPS]
enum FourierDirection
{
	eForward = 1,
	ereverse = -1
};

// COMPLEX [12/26/2007 QUYPS]
typedef struct tagCOMPLEX{
	DOUBLE real;
	DOUBLE imag;
} COMPLEX,FAR *LPCOMPLEX; 

typedef struct tagFFRESULT 
{
	LPCOMPLEX* ppComplex;
	INT nWidth;
	INT nHeight;
	tagFFRESULT()
	{
		ppComplex = NULL;
		nWidth = 0;
		nHeight = 0;
	}
}FFRESULT;

// definition of default number of entries in histogram table [12/20/2007 QUYPS]
#define IMP_HIS_DEFAULT_SIZE	256
#define IMP_FUNC_DEFAULT_SIZE	256
#define IMP_GRAY_LEVELS			256

// Supported maximum size of image [12/21/2007 QUYPS]
#define IMP_SRC_MAXWIDTH			1024
#define IMP_SRC_MAXHEIGHT			1024


#define IMP_IMAGESPACING			10

// Definition of messages [12/21/2007 QUYPS]
#define IMP_MSG_FILEOPEN_ERR _T("Can't open file:\n%s")
#define IMP_MSG_FILESAVE_ERR _T("Can't save file:\n%s")
#define IMP_MSG_FILESAVE_INVALIDTYPE _T("This type of source is not valid for saving")
#define IMP_MSG_ADDSRC_INVALIDTYPE _T("This type of source is not valid for this operation!")
#define IMP_MSG_ADJUSTSIZE	_T("Your raw size is not correct for this file.\nDo you want to size it automically?")
#define IMP_MSG_AUTOADJUST	_T("Raw size if not defined\nSizing it automically")
#define IMP_MSG_BIGIMAGE	_T("Image size is large than ability!")

#define IMP_MONOBMP_BITS			8	
#define IMP_MONOBMP_TABLE_ENTRIES	256


// Definition of name suffix [12/26/2007 QUYPS]
#define IMP_SUF_CUSTOM		_T("-Userdefined")
#define IMP_SUF_FOURIER		_T("-Frourier")
#define IMP_SUF_LAPLACED	_T("-Laplacian")
#define IMP_SUF_PREWITT		_T("-Prewitt")
#define IMP_SUF_SOBEL		_T("-Sobel")
#define IMP_SUF_ROBERT		_T("-Robert")
#define IMP_SUF_THRESOLD	_T("-Thresholed")
#define IMP_SUF_POWER		_T("-Powered")
#define IMP_SUF_LOGARITHED	_T("-Logarithed")
#define IMP_SUF_REVESED		_T("-Reversed")
#define IMP_SUF_EQUALIZE	_T("-Histogram Equalized")
#define IMP_SUF_MATCHED		_T("-Histogram Matched")
#define IMP_SUF_STRETCH		_T("-Histogram stretched")


#define IMP_SUF_COLOR	_T("-color")
#define IMP_SUF_GRAY	_T("-gray")
#define IMP_SUF_RED		_T("-red")
#define IMP_SUF_GREEN	_T("-green")
#define IMP_SUF_BLUE	_T("-blue")
// Definition file filter  string [12/28/2007 QUYPS]
#define IMP_FILEFILTER _T("Raw files (*.raw)|*.raw|Bitmap file (*.bmp)|*.bmp|JPEG file (*.jpg)|*.jpg|Giff files(*.gif)|*.gif|TIFF files(*.tif)|*.tif|PNG files (*.png)|*.png||")

struct MONOCHROME_BMP
{
    BITMAPINFOHEADER    bmiHeader;
    RGBQUAD             bmiColors[256];
};

#endif // !defined(IMP_GENERAL_INCLUDE__H_)