// Mask.cpp: implementation of the CMask class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "Mask.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// temporary [12/24/2007 QUYPS]
#include "Utility.h"


CMask::CMask()
{
	InitMask();
}

CMask::~CMask()
{
	
}



//************************************
// Method:    CMask
// FullName:  Constructor, create a predefined mask
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
CMask::CMask(INT in_eType)
{
	InitMask(in_eType);
}

//************************************
// Method:    InitMask
// FullName:  init for mask
// Access:    
// Returns:   
// Qualifier: 
// Parameter: 
//************************************
/*
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
*/

VOID CMask::InitMask(INT in_eType)
{	
	SetType(in_eType);
	switch(in_eType)
	{
	case eUserDefined:
		SetMaskName(CString(IMP_MASK_USER_DEFINED));
		//m_oMaskSource = NULL;
		m_nMaskRatio = 1;
		m_ptAppliedPos = CPoint(0,0);
		break;

	case eSobelGx:
		SetMaskName(CString(IMP_MASK_SOBEL_GX));
		m_oMaskSource.InitSource(IMP_MASK_SIZE_SOBEL);
		//first row
		m_oMaskSource.SetElementAt(0,0, -1);
		m_oMaskSource.SetElementAt(0,1,  0);
		m_oMaskSource.SetElementAt(0,2, +1);
		//second row
		m_oMaskSource.SetElementAt(1,0, -2);
		m_oMaskSource.SetElementAt(1,1,  0);
		m_oMaskSource.SetElementAt(1,2, +2);
		//Third row
		m_oMaskSource.SetElementAt(2,0, -1);
		m_oMaskSource.SetElementAt(2,1,  0);
		m_oMaskSource.SetElementAt(2,2, +1);
		m_nMaskRatio = 1;
		m_ptAppliedPos.x = m_ptAppliedPos.y = 1;
	    break;

	case eSobelGy:
		SetMaskName(CString(IMP_MASK_SOBEL_GY));
		m_oMaskSource.InitSource(IMP_MASK_SIZE_SOBEL);
		//first row
		m_oMaskSource.SetElementAt(0,0, +1);
		m_oMaskSource.SetElementAt(0,1, +2);
		m_oMaskSource.SetElementAt(0,2, +1);
		//second row
		m_oMaskSource.SetElementAt(1,0,	 0);
		m_oMaskSource.SetElementAt(1,1,  0);
		m_oMaskSource.SetElementAt(1,2,  0);
		//Third row
		m_oMaskSource.SetElementAt(2,0, -1);
		m_oMaskSource.SetElementAt(2,1, -2);
		m_oMaskSource.SetElementAt(2,2, -1);
		m_nMaskRatio = 1;
		m_ptAppliedPos.x = m_ptAppliedPos.y = 1;
	    break;

	case eRobertGx:
		SetMaskName(CString(IMP_MASK_ROBERT_GX));
		m_oMaskSource.InitSource(IMP_MASK_SIZE_ROBERT);
		//first row
		m_oMaskSource.SetElementAt(0,0, +1);
		m_oMaskSource.SetElementAt(0,1,  0);
		//second row
		m_oMaskSource.SetElementAt(1,0,  0);
		m_oMaskSource.SetElementAt(1,1, -1);
		m_nMaskRatio = 1;
		m_ptAppliedPos.x = m_ptAppliedPos.y = 0;
		break;

	case eRobertGy:
		SetMaskName(CString(IMP_MASK_ROBERT_GY));
		m_oMaskSource.InitSource(IMP_MASK_SIZE_ROBERT);
		//first row
		m_oMaskSource.SetElementAt(0,0,  0);
		m_oMaskSource.SetElementAt(0,1, +1);
		//second row
		m_oMaskSource.SetElementAt(1,0, -1);
		m_oMaskSource.SetElementAt(1,1,  0);
		m_nMaskRatio = 1;
		m_ptAppliedPos.x = 0; m_ptAppliedPos.y = 0;
		break;

	case ePrewittVerti:
		SetMaskName(CString(IMP_MASK_PREWITT_VER));
		m_oMaskSource.InitSource(IMP_MASK_SIZE_PREWITT);
		//first row
		m_oMaskSource.SetElementAt(0,0, +1);
		m_oMaskSource.SetElementAt(0,1, +1);
		m_oMaskSource.SetElementAt(0,2, +1);
		//second row
		m_oMaskSource.SetElementAt(1,0,	 0);
		m_oMaskSource.SetElementAt(1,1,  0);
		m_oMaskSource.SetElementAt(1,2,  0);
		//Third row
		m_oMaskSource.SetElementAt(2,0, -1);
		m_oMaskSource.SetElementAt(2,1, -1 );
		m_oMaskSource.SetElementAt(2,2, -1);
		m_nMaskRatio = 1;
		m_ptAppliedPos.x = m_ptAppliedPos.y = 1;
	    break;

	case ePrewittHoriz:
		SetMaskName(CString(IMP_MASK_PREWITT_HOR));
		m_oMaskSource.InitSource(IMP_MASK_SIZE_PREWITT);
		//first row
		m_oMaskSource.SetElementAt(0,0, -1);
		m_oMaskSource.SetElementAt(0,1,  0);
		m_oMaskSource.SetElementAt(0,2, +1);
		//second row
		m_oMaskSource.SetElementAt(1,0,	-1);
		m_oMaskSource.SetElementAt(1,1,  0);
		m_oMaskSource.SetElementAt(1,2, +1);
		//Third row
		m_oMaskSource.SetElementAt(2,0, -1);
		m_oMaskSource.SetElementAt(2,1,  0);
		m_oMaskSource.SetElementAt(2,2, +1);
		m_nMaskRatio = 1;
		m_ptAppliedPos.x = m_ptAppliedPos.y = 1;
	    break;

	case eLaplacian1_4:
		SetMaskName(CString(IMP_MASK_LAP_1_4));
		m_oMaskSource.InitSource(IMP_MASK_SIZE_LAP_1);
		//first row
		m_oMaskSource.SetElementAt(0,0,  0);
		m_oMaskSource.SetElementAt(0,1, +1);
		m_oMaskSource.SetElementAt(0,2,  0);
		//second row
		m_oMaskSource.SetElementAt(1,0,	+1);
		m_oMaskSource.SetElementAt(1,1, -4);
		m_oMaskSource.SetElementAt(1,2, +1);
		//Third row
		m_oMaskSource.SetElementAt(2,0,  0);
		m_oMaskSource.SetElementAt(2,1, +1);
		m_oMaskSource.SetElementAt(2,2,  0);
		m_nMaskRatio = 1;
		m_ptAppliedPos.x = m_ptAppliedPos.y = 1;
		break;

	case eLaplacian1_8:
		SetMaskName(CString(IMP_MASK_LAP_1_8));
		m_oMaskSource.InitSource(IMP_MASK_SIZE_LAP_1);
		//first row
		m_oMaskSource.SetElementAt(0,0, +1);
		m_oMaskSource.SetElementAt(0,1, +1);
		m_oMaskSource.SetElementAt(0,2, +1);
		//second row
		m_oMaskSource.SetElementAt(1,0,	+1);
		m_oMaskSource.SetElementAt(1,1, -8);
		m_oMaskSource.SetElementAt(1,2, +1);
		//Third row
		m_oMaskSource.SetElementAt(2,0, +1);
		m_oMaskSource.SetElementAt(2,1, +1);
		m_oMaskSource.SetElementAt(2,2, +1);
		m_nMaskRatio = 1;
		m_ptAppliedPos.x = m_ptAppliedPos.y = 1;
		break;

	case eLaplacian1_2_4:
		SetMaskName(CString(IMP_MASK_LAP_1_2_4));
		m_oMaskSource.InitSource(IMP_MASK_SIZE_LAP_1);
		//first row
		m_oMaskSource.SetElementAt(0,0, -1);
		m_oMaskSource.SetElementAt(0,1, +2);
		m_oMaskSource.SetElementAt(0,2, -1);
		//second row
		m_oMaskSource.SetElementAt(1,0,	+2);
		m_oMaskSource.SetElementAt(1,1, -4);
		m_oMaskSource.SetElementAt(1,2, +2);
		//Third row
		m_oMaskSource.SetElementAt(2,0, -1);
		m_oMaskSource.SetElementAt(2,1, +2);
		m_oMaskSource.SetElementAt(2,2, -1);
		m_nMaskRatio = 1;
		m_ptAppliedPos.x = m_ptAppliedPos.y = 1;
		break;

	case eGaussian1_115:
		SetMaskName(CString(IMP_MASK_GAUSS_1_115));
		m_oMaskSource.InitSource(IMP_MASK_SIZE_GAUSS);
		//first row
		m_oMaskSource.SetElementAt(0,0, +2);
		m_oMaskSource.SetElementAt(0,1, +4);
		m_oMaskSource.SetElementAt(0,2, +5);
		m_oMaskSource.SetElementAt(0,3, +4);
		m_oMaskSource.SetElementAt(0,4, +2);
		//second row
		m_oMaskSource.SetElementAt(1,0, +4);
		m_oMaskSource.SetElementAt(1,1, +9);
		m_oMaskSource.SetElementAt(1,2,+12);
		m_oMaskSource.SetElementAt(1,3, +9);
		m_oMaskSource.SetElementAt(1,4, +4);
		//Third row
		m_oMaskSource.SetElementAt(2,0, +5);
		m_oMaskSource.SetElementAt(2,1,+12);
		m_oMaskSource.SetElementAt(2,2,+15);
		m_oMaskSource.SetElementAt(2,3,+12);
		m_oMaskSource.SetElementAt(2,4, +5);
		//Fourth row
		m_oMaskSource.SetElementAt(3,0, +4);
		m_oMaskSource.SetElementAt(3,1, +9);
		m_oMaskSource.SetElementAt(3,2,+12);
		m_oMaskSource.SetElementAt(3,3, +9);
		m_oMaskSource.SetElementAt(3,4, +4);
		//Fifth row
		m_oMaskSource.SetElementAt(4,0, +2);
		m_oMaskSource.SetElementAt(4,1, +4);
		m_oMaskSource.SetElementAt(4,2, +5);
		m_oMaskSource.SetElementAt(4,3, +4);
		m_oMaskSource.SetElementAt(4,4, +2);
		m_nMaskRatio = 115;
		m_ptAppliedPos.x = m_ptAppliedPos.y = 2;
		break;


	default:
	    break;
	}
		
}


//************************************
// Method:    ApplyMask
// FullName:  CMask::ApplyMask
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource inout_oSource
//************************************
procStatus CMask::ApplyMask( CImgSource* in_pSource, CImgSource *out_pSource )
{
	procStatus eRetCode = eNormal;
	Bitmap* pBitmap = in_pSource->GetSourceRef();
	Bitmap* pResult = NULL;
	SourceType eType = in_pSource->GetType() ;
	if ((eType == eSrcNone)||(eType == eSrcFourierBitmap)||(eType == eSrcColorBitmap))
	{
		eRetCode = eInvalideArg;
	}

	if(eRetCode == eNormal)
	{
		INT nImgWidth = pBitmap->GetWidth();
		INT nImgHeight = pBitmap->GetHeight();
		INT nMaskWidth = GetColCount(); //m_oMaskSource.GetNumberOfCol();
		INT nMaskHeight = GetRowCount();//m_oMaskSource.GetNumberOfRow();
		pResult = pBitmap->Clone(0,0,nImgWidth,nImgHeight, PixelFormatDontCare);


		//================ CONVOLUTION ======================
		//---------for all point in image-----------------
		for (INT y=0; y<nImgHeight; y++)
		{
			for (INT x=0; x<nImgWidth; x++)
			{
				//image point = (x,y)
				LONG nSumOfMask = 0;
				BOOL flagValidPos = TRUE;

				Status stRet;
				//--------for all point in mask--------
				for (INT ym=0; ym<nMaskHeight; ym++)
				{					
					for (INT xm=0;xm<nMaskWidth; xm++)
					{
						stRet = Ok;
						Color pixelColor(0,0,0);						
						//mask position (xm,ym)
						INT dx = (INT)xm - (INT)m_ptAppliedPos.x;
						INT dy = (INT)ym - (INT)m_ptAppliedPos.y;
						
						INT xx = (INT)x + dx;
						INT yy = (INT)y + dy;
						//check out of image range
						if((xx >= 0)&&(xx < nImgWidth)&&(yy >= 0)&&(yy < nImgHeight))
						{
							stRet = pBitmap->GetPixel(xx,yy,&pixelColor);
						}
						else
						{
							flagValidPos = FALSE;	
							break;
						}
						if(stRet != Ok) 
						{
							eRetCode = eSystemErr;
							break;
						}
						nSumOfMask += GetValueAt(ym, xm) * CUtility::GetMonoPixelValue(pixelColor, eType);

					}
					if((stRet != Ok)||(!flagValidPos)) 
						break;
				}//-----------------------------------				
				
				if(eRetCode != eNormal) 
					break;
				else
				{
					if(flagValidPos)
					{
						//Adjust by mask ratio
						DOUBLE temp = (DOUBLE)nSumOfMask / (DOUBLE)m_nMaskRatio;
						nSumOfMask = temp;
						
						if(m_nMaskType < eLaplacian1_4)	nSumOfMask = CUtility::Normalize(nSumOfMask, eAbsolute);
						else nSumOfMask = CUtility::Normalize(nSumOfMask, eTrimming);
						
						Color retClr = CUtility::GetMonoPixel(nSumOfMask, eType);
						//retClr.SetFromCOLORREF(RGB(nSumOfMask,nSumOfMask,nSumOfMask));						
						Status stss = pResult->SetPixel(x,y, retClr);
					}					
				}
			}
			if(eRetCode != eNormal) break;
		}//------------------------------------------------

	}


#ifdef _DEBUG
	if(eRetCode == eNormal)
	{
		CLSID pngClsid;
		CUtility::GetEncoderClsid(L"image/bmp", &pngClsid);
		Status res = pResult->Save(L".\\Laplacian.bmp", &pngClsid, NULL);
	}	
#endif
	
	out_pSource->AttachSource(pResult);
	out_pSource->SetType(eType);

	return eRetCode;
}