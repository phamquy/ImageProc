// RawImgSaver.cpp: implementation of the CRawImgSaver class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "RawImgSaver.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRawImgSaver::CRawImgSaver()
{

}

CRawImgSaver::~CRawImgSaver()
{

}

//************************************
// Method:    Save
// FullName:  CRawImgSaver::Save
// Access:    virtual public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * in_pSource
//************************************
procStatus CRawImgSaver::Save(CImgSource* in_pSource)
{
	procStatus eRetCode = eNormal;
	CFile oFile;
	CFileException oFileException;

	SourceType eType = in_pSource->GetType();
	if(eType < 3) 
	{
		AfxMessageBox(IMP_MSG_FILESAVE_INVALIDTYPE);
		eRetCode = eFileIOError;
	}

	//create new file
	if(eRetCode == eNormal)
	{
		if(!oFile.Open(m_sFilePath, CFile::modeCreate|CFile::modeWrite, &oFileException))
		{
			TRACE("\nCan not create file %s, error= %u\n", m_sFilePath, oFileException.m_cause);
			CString msg;
			msg.Format(IMP_MSG_FILESAVE_ERR, oFileException.m_strFileName);
			AfxMessageBox(msg);
			eRetCode = eFileIOError;
		}
	}
	
	Bitmap* pBitmap = in_pSource->GetSourceRef();

	// For the future extension [12/22/2007 QUYPS]
	//calculate the byte per pixel and 
	//Save source as a userdefined format
	//save it as raw file
	if(eRetCode == eNormal)
	{
		UINT nWidth = pBitmap->GetWidth();
		UINT nHeight = pBitmap->GetHeight();

		Color oClr;
		Status sts;
		for (UINT i=0; i<nHeight; i++)
		{
			for (UINT j=0; j<nWidth; j++)
			{
				BYTE nByte;
				sts = pBitmap->GetPixel(j,i,&oClr);
				if (sts != Ok) 
				{
					eRetCode = eFileIOError;
					break;
				}
				nByte = oClr.GetR();
				oFile.Write(&nByte, 1);		
			}		
		}
	}
	oFile.Close();
	return eRetCode;
}