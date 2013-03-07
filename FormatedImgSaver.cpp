// FormatedImgSaver.cpp: implementation of the CFormatedImgSaver class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "FormatedImgSaver.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


#include "Utility.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFormatedImgSaver::CFormatedImgSaver()
{

}

CFormatedImgSaver::~CFormatedImgSaver()
{

}


//************************************
// Method:    Save
// FullName:  CFormatedImgSaver::Save
// Access:    virtual public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * in_pSource
//************************************
procStatus CFormatedImgSaver::Save(CImgSource* in_pSource)
{
	ASSERT(in_pSource);
	ASSERT(in_pSource->GetSourceRef());

	procStatus eRetCode = eNormal;
	//create new file
	Bitmap* pBitmap = NULL;
	pBitmap = in_pSource->GetSourceRef();
	if(pBitmap == NULL) eRetCode = eSystemErr;
	
	
	CLSID pngClsid;	
	CString sMime = IMP_MIME_BITMAP;

	if (eRetCode == eNormal)
	{
		switch(m_eOutputFormat)
		{
		case eBitmap:
			sMime = IMP_MIME_BITMAP;
			break;
			
		case eJpeg:
			sMime = IMP_MIME_JPEG;
			break;
			
		case eGif:
			sMime = IMP_MIME_GIF;
			break;
			
		case eTiff:
			sMime = IMP_MIME_TIFF;
			break;
			
		case ePng:
			sMime = IMP_MIME_PNG;
			break;
			
		default:
			eRetCode = eFileIOError;
			break;
		}
	}
	
	
	if(eRetCode == eNormal)
	{
		CUtility::GetEncoderClsid(sMime.AllocSysString(), &pngClsid);
	}

	if(!m_sFilePath.Compare(""))
			eRetCode = eFileIOError;
	
	if(eRetCode == eNormal)
	{
		Status reSt = pBitmap->Save(m_sFilePath.AllocSysString(), &pngClsid, NULL);
		if(reSt != Ok) eRetCode = eFileIOError;
	}

	return eRetCode;
}