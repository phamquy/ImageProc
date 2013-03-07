// Utility.cpp: implementation of the CUtility class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "Utility.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CUtility::CUtility()
{

}

CUtility::~CUtility()
{

}

//************************************
// Method:    GetEncoderClsid
// FullName:  CUtility::GetEncoderClsid
// Access:    public 
// Returns:   int
// Qualifier:
// Parameter: const WCHAR * format
// Parameter: CLSID * pClsid
//************************************
int CUtility::GetEncoderClsid(const WCHAR *format, CLSID *pClsid)
{
	   UINT  num = 0;          // number of image encoders
	   UINT  size = 0;         // size of the image encoder array in bytes
	   
	   ImageCodecInfo* pImageCodecInfo = NULL;
	   
	   GetImageEncodersSize(&num, &size);
	   if(size == 0)
		   return -1;  // Failure
	   
	   pImageCodecInfo = (ImageCodecInfo*)(malloc(size));
	   if(pImageCodecInfo == NULL)
		   return -1;  // Failure
	   
	   GetImageEncoders(num, size, pImageCodecInfo);
	   
	   for(UINT j = 0; j < num; ++j)
	   {
		   if( wcscmp(pImageCodecInfo[j].MimeType, format) == 0 )
		   {
			   *pClsid = pImageCodecInfo[j].Clsid;
			   free(pImageCodecInfo);
			   return j;  // Success
		   }    
	   }
	   
	   free(pImageCodecInfo);

	   return -1;  // Failure
}

//************************************
// Method:    Grayscalize
// FullName:  CUtility::Grayscalize
// Access:    public static 
// Returns:   Color
// Qualifier:
// Parameter: Color in_oColor
//************************************
Color CUtility::Grayscalize(Color in_oColor)
{
	//Y=0.3RED+0.59GREEN+0.11Blue
	DOUBLE red = in_oColor.GetRed();
	DOUBLE green = in_oColor.GetGreen();
	DOUBLE blue = in_oColor.GetBlue();

	DOUBLE gray = 0.3 * red + 0.59 * green + 0.11 * blue;

	return Color::MakeARGB(255,gray,gray,gray);
}
 

//************************************
// Method:    GetRed
// FullName:  CUtility::GetRed
// Access:    public 
// Returns:   Color
// Qualifier:
// Parameter: Color in_color
//************************************
Color CUtility::GetRed(Color in_color)
{
	return Color::MakeARGB(255, in_color.GetR(),0,0);
}

//************************************
// Method:    GetGreen
// FullName:  CUtility::GetGreen
// Access:    public 
// Returns:   Color
// Qualifier:
// Parameter: Color in_color
//************************************
Color CUtility::GetGreen(Color in_color)
{
	return Color::MakeARGB(255,0,in_color.GetG(),0);
}

//************************************
// Method:    GetBlue
// FullName:  CUtility::GetBlue
// Access:    public 
// Returns:   Color
// Qualifier:
// Parameter: Color in_color
//************************************
Color CUtility::GetBlue(Color in_color)
{
	return Color::MakeARGB(255,0,0,in_color.GetB());
}

//************************************
// Method:    Add2Source
// FullName:  CUtility::Add2Source
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * in_pSource1
// Parameter: CImgSource * in_pSource2
// Parameter: CImgSource * out_pSource
//************************************
procStatus CUtility::Add2Source( CImgSource* in_pSource1, CImgSource* in_pSource2, CImgSource* out_pImdRes )
{
	procStatus eRetCode = eNormal;

	Bitmap* pBmp1 = in_pSource1->GetSourceRef();
	Bitmap* pBmp2 = in_pSource2->GetSourceRef();
	// Check the operation valid
	SourceType e1= in_pSource1->GetType();
	SourceType e2= in_pSource2->GetType();

	if ((in_pSource1->GetType()<eSrcMonoBitmap)||
		(in_pSource2->GetType()<eSrcMonoBitmap)||
		(in_pSource1->GetType() != in_pSource2->GetType()))
	{
		AfxMessageBox(IMP_MSG_ADDSRC_INVALIDTYPE);
		eRetCode = eInvalideArg;
	}

	if( (pBmp1 == NULL)||
		(pBmp2 == NULL)||
		(pBmp1->GetWidth() != pBmp2->GetWidth())||
		(pBmp1->GetHeight() != pBmp1->GetHeight()))
	{
		eRetCode = eInvalideArg;	
	}

	//Add two source
	SourceType eType = in_pSource1->GetType();
	INT nWidth = pBmp1->GetWidth();
	INT nHeight = pBmp1->GetHeight();
	Bitmap* pBmp = NULL;

	if(eRetCode == eNormal)
	{
		pBmp = pBmp2->Clone(0,0, nWidth, nHeight,PixelFormatDontCare);
		if(pBmp == NULL) eRetCode = eSystemErr;
		
		if(eRetCode == eNormal)
		{
			Status sts = Ok;
			for(INT x=0; x<nWidth; x++)
			{
				for (INT y=0; y<nHeight; y++)
				{
					Color clr1(0,0,0);
					Color clr2(0,0,0);
					sts = pBmp1->GetPixel(x,y, &clr1);
					if(sts == Ok) 
						sts = pBmp2->GetPixel(x,y, &clr2);
					if(sts != Ok) break;
					
					BYTE val1 = CUtility::GetMonoPixelValue(clr1, eType);
					BYTE val2 = CUtility::GetMonoPixelValue(clr2, eType);
					
					INT sum = CUtility::GetMonoPixelValue(clr1, eType) + CUtility::GetMonoPixelValue(clr2, eType);
					BYTE nRes = CUtility::Normalize(sum, eTrimming);
					Color clr = GetMonoPixel(nRes, eType);
					
					sts = pBmp->SetPixel(x,y, clr);
					if(sts != Ok) break;
				}
				if(sts != Ok) break;
			}
			if (sts != Ok) 
			{
				delete pBmp;
				eRetCode = eSystemErr; 				
			}
		}
	}
	
#ifdef _DEBUG
// 	if(eRetCode == eNormal)
// 	{
// 		CLSID pngClsid;
// 		CUtility::GetEncoderClsid(L"image/bmp", &pngClsid);
// 		pBmp1->Save(L".\\source1.bmp", &pngClsid, NULL);
// 		pBmp2->Save(L".\\source2.bmp", &pngClsid, NULL);
// 		pBmp->Save(L".\\resutlsAfter.bmp", &pngClsid, NULL);
// 	}	
#endif	
	if(eRetCode == eNormal)
	{
		out_pImdRes->SetType(eType);
		out_pImdRes->AttachSource(pBmp);
	}	
	return eRetCode;
}

//************************************
// Method:    Sub2Source
// FullName:  CUtility::Sub2Source
// Access:    public 
// Returns:   CImgSource*
// Qualifier:
// Parameter: CImgSource * in_pSource1
// Parameter: CImgSource * in_pSource2
//************************************
CImgSource* CUtility::Sub2Source(CImgSource* in_pSource1, CImgSource* in_pSource2)
{
	Bitmap* pBmp1 = in_pSource1->GetSourceRef();
	Bitmap* pBmp2 = in_pSource2->GetSourceRef();
	
	// Check the operation valid
	if ((in_pSource1->GetType()<eSrcMonoBitmap)||(in_pSource2->GetType()<eSrcMonoBitmap))
	{
		AfxMessageBox(IMP_MSG_ADDSRC_INVALIDTYPE);
		return NULL;
	}
	
	if(in_pSource1->GetType() != in_pSource2->GetType())
		return NULL;
	
	if((pBmp1 == NULL) || (pBmp2 == NULL))
	{
		return NULL;	
	}
	
	if ((pBmp1->GetWidth() != pBmp2->GetWidth())||(pBmp1->GetHeight() != pBmp1->GetHeight()))
	{
		return NULL;
	} 
	
	//Add two source
	SourceType eType = in_pSource1->GetType();
	INT nWidth = pBmp1->GetWidth();
	INT nHeight = pBmp1->GetHeight();
	Bitmap* pBmp = NULL;
	pBmp = pBmp1->Clone(0,0, nWidth, nHeight,PixelFormatDontCare);
	
	if(pBmp == NULL) return NULL;
	
	Status sts = Ok;
	for(INT x=0; x<nWidth; x++)
	{
		for (INT y=0; y<nHeight; y++)
		{
			Color clr1(0,0,0);
			Color clr2(0,0,0);
			sts = pBmp1->GetPixel(x,y, &clr1);
			if(sts == Ok) sts = pBmp2->GetPixel(x,y, &clr2);
			if(sts != Ok) break;
			

			INT resultval = CUtility::GetMonoPixelValue(clr1, eType) - CUtility::GetMonoPixelValue(clr2, eType);
			BYTE nRes = CUtility::Normalize(resultval, eTrimming);
			Color clr = GetMonoPixel(nRes, eType);
			
			sts = pBmp->SetPixel(x,y, clr);
			if(sts != Ok) break;
		}
		if(sts != Ok) break;
	}
	if (sts != Ok) 
	{
		delete pBmp;
		return NULL;
	}
	
	CImgSource* reImg = new CImgSource();
	reImg->SetType(eType);
	reImg->AttachSource(pBmp);
	return reImg;
}


//************************************
// Method:    Multi2Source
// FullName:  CUtility::Multi2Source
// Access:    public 
// Returns:   CImgSource*
// Qualifier:
// Parameter: CImgSource * in_pSource1
// Parameter: CImgSource * in_pSource2
//************************************
CImgSource* CUtility::Multi2Source(CImgSource* in_pSource1, CImgSource* in_pSource2)
{
	Bitmap* pBmp1 = in_pSource1->GetSourceRef();
	Bitmap* pBmp2 = in_pSource2->GetSourceRef();
	
	// Check the operation valid
	if ((in_pSource1->GetType()<eSrcMonoBitmap)||(in_pSource2->GetType()<eSrcMonoBitmap))
	{
		AfxMessageBox(IMP_MSG_ADDSRC_INVALIDTYPE);
		return NULL;
	}
	
	if(in_pSource1->GetType() != in_pSource2->GetType())
		return NULL;
	
	if((pBmp1 == NULL) || (pBmp2 == NULL))
	{
		return NULL;	
	}
	
	if ((pBmp1->GetWidth() != pBmp2->GetWidth())||(pBmp1->GetHeight() != pBmp1->GetHeight()))
	{
		return NULL;
	} 
	
	//Add two source
	SourceType eType = in_pSource1->GetType();
	INT nWidth = pBmp1->GetWidth();
	INT nHeight = pBmp1->GetHeight();
	Bitmap* pBmp = NULL;
	pBmp = pBmp1->Clone(0,0, nWidth, nHeight,PixelFormatDontCare);
	
	if(pBmp == NULL) return NULL;
	
	Status sts = Ok;
	for(INT x=0; x<nWidth; x++)
	{
		for (INT y=0; y<nHeight; y++)
		{
			Color clr1(0,0,0);
			Color clr2(0,0,0);
			sts = pBmp1->GetPixel(x,y, &clr1);
			if(sts == Ok) sts = pBmp2->GetPixel(x,y, &clr2);
			if(sts != Ok) break;
			
			INT resultval;
			if(CUtility::GetMonoPixelValue(clr2, eType) == 0) resultval = 255;
			resultval = CUtility::GetMonoPixelValue(clr1, eType) / CUtility::GetMonoPixelValue(clr2, eType);
			BYTE nRes = CUtility::Normalize(resultval, eTrimming);
			Color clr = GetMonoPixel(nRes, eType);
			
			sts = pBmp->SetPixel(x,y, clr);
			if(sts != Ok) break;
		}
		if(sts != Ok) break;
	}
	if (sts != Ok) 
	{
		delete pBmp;
		return NULL;
	}
	
	CImgSource* reImg = new CImgSource();
	reImg->SetType(eType);
	reImg->AttachSource(pBmp);
	return reImg;
}


//************************************
// Method:    Normalize
// FullName:  CUtility::Normalize
// Access:    public 
// Returns:   BYTE
// Qualifier:
// Parameter: INT in_nVal
//************************************
BYTE CUtility::Normalize(INT in_nVal,NormalizeMode in_eMode)
{
	switch(in_eMode)
	{
	case eAbsolute:
		if(in_nVal < 0)   in_nVal = -in_nVal;
		if(in_nVal > 255) in_nVal = 255;		
		break;

	default:
		if(in_nVal < 0)   in_nVal = 0;
		if(in_nVal > 255) in_nVal = 255;		
	    break;
	}
	

	return in_nVal;
}

//************************************
// Method:    GetMonoPixelValue
// FullName:  CUtility::GetMonoPixelValue
// Access:    public 
// Returns:   BYTE
// Qualifier:
// Parameter: Color in_px
// Parameter: SourceType in_eType
//************************************
BYTE CUtility::GetMonoPixelValue(Color in_px, SourceType in_eType)
{
	BYTE retVal = 0;
	switch(in_eType)
	{
	case eSrcMonoBitmap:
	case eSrcMonoRed:
		retVal = in_px.GetRed();
		break;
	case eSrcMonoGreen:
		retVal = in_px.GetGreen();
	    break;
	case eSrcMonoBlue:
		retVal = in_px.GetBlue();
	    break;
	default:
	    break;
	}
	return retVal;
}

//************************************
// Method:    SetMonoPixelValue
// FullName:  CUtility::SetMonoPixelValue
// Access:    public 
// Returns:   VOID
// Qualifier:
// Parameter: Color & out_clr
// Parameter: SourceType in_eType
//************************************
Color CUtility::GetMonoPixel( BYTE in_val, SourceType in_eType )
{
	switch(in_eType)
	{
	case eSrcMonoBitmap:
		return Color(255, in_val,in_val,in_val);
		break;
	case eSrcMonoRed:
		return Color(255, in_val,0,0);
		break;
	case eSrcMonoGreen:
		return Color(255, 0,in_val,0);
		break;
	case eSrcMonoBlue:
		return Color(255, 0,0,in_val);
	    break;
	default:
	    break;
	}
}


//************************************
// Method:    GetFileType
// FullName:  CUtility::GetFileType
// Access:    public 
// Returns:   FileType
// Qualifier:
// Parameter: LPCTSTR lpszPathName
//************************************
FileType CUtility::GetFileType( LPCTSTR lpszPathName )
{
	FileType eType = eFormated;
	CString sPath(lpszPathName);

	CString sExt = sPath.Right(3);

	if (!sExt.CompareNoCase(IMP_FILEEXT_RAW))
	{
		eType = eUnformated;
	}
	else if(
		!sExt.CompareNoCase(IMP_FILEEXT_BMP)||
		!sExt.CompareNoCase(IMP_FILEEXT_JPG)||
		!sExt.CompareNoCase(IMP_FILEEXT_TIF)||
		!sExt.CompareNoCase(IMP_FILEEXT_PNG)||
		!sExt.CompareNoCase(IMP_FILEEXT_GIF))
	{
		eType = eFormated;
	}
	else
	{
		eType = eUnknown;
	}
	return eType;

}

//************************************
// Method:    GetTransSuffixName
// FullName:  CUtility::GetTransSuffixName
// Access:    public 
// Returns:   CString
// Qualifier:
// Parameter: TransformFunction eType
//************************************
CString CUtility::GetTransSuffixName(TransformFunction eType)
{	
	switch(eType)
	{
	case eNoTrans:
		return "";	
		break;
	case eThreshold:
		return IMP_SUF_THRESOLD;
		break;
	case ePower:
		return IMP_SUF_POWER;
	    break;
	case eLogarithm:
		return IMP_SUF_LOGARITHED;
	    break;
	case eInvert:
		return IMP_SUF_REVESED;
	    break;
	default:
		return "";
	    break;
	}
}

//************************************
// Method:    GetFileName
// FullName:  CUtility::GetFileName
// Access:    public 
// Returns:   CString
// Qualifier:
// Parameter: CString sPath
//************************************
CString CUtility::GetFileName(CString sPath)
{
	INT sLastSlash = sPath.ReverseFind('\\');
	CString sName = sPath.Right(sPath.GetLength() - sLastSlash -1);
	return sName;
}

//************************************
// Method:    MessageTranslate
// FullName:  CUtility::MessageTranslate
// Access:    public 
// Returns:   CString
// Qualifier:
// Parameter: eRetCode
//************************************
CString CUtility::MessageTranslate(procStatus eRetCode)
{
	CString s;
	s.Format("Error code:%d", eRetCode);
	return s;
}
