// FormatedImgLoader.cpp: implementation of the CFormatedImgLoader class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "FormatedImgLoader.h"
#include "Utility.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFormatedImgLoader::CFormatedImgLoader()
{

}

CFormatedImgLoader::~CFormatedImgLoader()
{

}

//************************************
// Method:    Load
// FullName:  CFormatedImgLoader::Load
// Access:    virtual public 
// Returns:   procStatus
// Qualifier:
// Parameter: ImgSrcList out_srcSet
// Parameter: CString in_strFilePath
//************************************
procStatus CFormatedImgLoader::Load( ImgSrcList* out_srcSet)
{

	procStatus eRetCode = eNormal;


	//ASSERT(FALSE);
	if (!m_sFileName.CompareNoCase(""))
	{
		return eFileIOError;
	}
	
	Bitmap* pOrgBitmap = NULL;
	Bitmap* pGrayBmp = NULL;
	Bitmap* pRedBmp = NULL;
	Bitmap* pGreenBmp = NULL;
	Bitmap* pBlueBmp = NULL;

	CImgSource* pOrgSource = NULL;
	CImgSource* pGraySource = NULL;
	CImgSource* pRedSource = NULL;
	CImgSource* pGreenSource = NULL;
	CImgSource* pBlueSource = NULL;

	pOrgBitmap = Bitmap::FromFile(m_sFileName.AllocSysString());	
	if(pOrgBitmap == NULL)
	{
		eRetCode = eFileIOError;
		return eRetCode;
	}


	UINT nWidth = pOrgBitmap->GetWidth();
	UINT nHeight = pOrgBitmap->GetHeight();
	if(eRetCode == eNormal)
	{
		pGrayBmp = pOrgBitmap->Clone(0,0,nWidth,nHeight,PixelFormatDontCare);
		pRedBmp = pOrgBitmap->Clone(0,0,nWidth,nHeight,PixelFormatDontCare);
		pGreenBmp = pOrgBitmap->Clone(0,0,nWidth,nHeight,PixelFormatDontCare);
		pBlueBmp = pOrgBitmap->Clone(0,0,nWidth,nHeight,PixelFormatDontCare);

		if(!((pGrayBmp != NULL)&&(pRedBmp != NULL)&&(pGreenBmp != NULL)&&(pBlueBmp != NULL)))
		{
			eRetCode = eFileIOError;
		}
	}
	
	//split this bitmap into four color channel: gray, red, green,blue
	Color oPixColor;
	Status stErr = Ok;
	if(eRetCode == eNormal)
	{
		for (INT i=0; i<nWidth; i++)
		{
			for (INT j=0; j< nHeight; j++)
			{
				stErr = Ok;
				stErr = pOrgBitmap->GetPixel(i,j,&oPixColor);
				if (stErr == Ok)
				{
					pGrayBmp->SetPixel(i,j, CUtility::Grayscalize(oPixColor));
					pRedBmp->SetPixel(i,j, CUtility::GetRed(oPixColor));
					pGreenBmp->SetPixel(i,j, CUtility::GetGreen(oPixColor));
					pBlueBmp->SetPixel(i,j, CUtility::GetBlue(oPixColor));
				} 
				else
				{
					eRetCode = eFileIOError;
					break;
				}				
			}
			if (stErr != Ok) break;
		}				
	}

	
	if(eRetCode == eNormal)
	{
		CString sNameOnly = CUtility::GetFileName(m_sFileName);
		pOrgSource = new CImgSource(eSrcColorBitmap, sNameOnly + IMP_SUF_COLOR, t_OpCap(FALSE), pOrgBitmap);
		pGraySource = new CImgSource(eSrcMonoBitmap, sNameOnly + IMP_SUF_GRAY, t_OpCap(), pGrayBmp);
		pRedSource = new CImgSource(eSrcMonoRed, sNameOnly + IMP_SUF_RED, t_OpCap(), pRedBmp);
		pGreenSource = new CImgSource(eSrcMonoGreen, sNameOnly + IMP_SUF_GREEN, t_OpCap(), pGreenBmp);
		pBlueSource = new CImgSource(eSrcMonoBlue, sNameOnly + IMP_SUF_BLUE, t_OpCap(), pBlueBmp);

		if (!(
			  (pOrgSource != NULL)
			&&(pGraySource != NULL)
			&&(pRedSource != NULL)
			&&(pGreenSource != NULL)
			&&(pBlueSource != NULL)))
		{
			eRetCode = eFileIOError;			
		}
		else
		{
			out_srcSet->Add(pOrgSource);
			out_srcSet->Add(pGraySource);
			out_srcSet->Add(pRedSource);
			out_srcSet->Add(pGreenSource);
			out_srcSet->Add(pBlueSource);
		}		
	}



#ifdef _DEBUG
	CLSID pngClsid;
	CUtility::GetEncoderClsid(L"image/bmp", &pngClsid);
	pOrgBitmap->Save(L".\\orgigin.bmp", &pngClsid, NULL);
	pGrayBmp->Save(L".\\gray.bmp", &pngClsid, NULL);
	pRedBmp->Save(L".\\red.bmp", &pngClsid, NULL);
	pGreenBmp->Save(L".\\green.bmp", &pngClsid, NULL);
	pBlueBmp->Save(L".\\blue.bmp", &pngClsid, NULL);	
#endif

	//release memory if error occur
	if(eRetCode != eNormal)
	{
		delete pOrgBitmap;	delete pOrgSource;
		delete pGrayBmp;	delete pGraySource; 
		delete pRedBmp;		delete pRedSource; 
		delete pGreenBmp;	delete pGreenSource;	
		delete pBlueBmp;	delete pBlueSource;
	}

	return eRetCode;	
}

//************************************
// Method:    splitBitmap
// FullName:  CFormatedImgLoader::splitBitmap
// Access:    protected 
// Returns:   procStatus
// Qualifier:
// Parameter: Bitmap * pBitmap
// Parameter: CImgSource * pRed
// Parameter: CImgSource * pGreen
// Parameter: CImgSource * pBlue
//************************************

//DEL procStatus CFormatedImgLoader::splitBitmap(Bitmap *pBitmap, CImgSource *pRed, CImgSource *pGreen, CImgSource *pBlue)
//DEL {
//DEL 	procStatus eRetCode = eNormal;
//DEL 
//DEL 	UINT nWidth = pBitmap->GetWidth();
//DEL 	UINT nHeight = pBitmap->GetHeight();
//DEL 
//DEL 	return eRetCode;	
//DEL }

