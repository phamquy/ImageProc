// RawImgLoader.cpp: implementation of the CRawImgLoader class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "RawImgLoader.h"
#include "Utility.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRawImgLoader::CRawImgLoader()
{
	m_nBitPerPixel = 8;
}

CRawImgLoader::~CRawImgLoader()
{

}


//************************************
// Method:    Load
// FullName:  CRawImgLoader::Load
// Access:    virtual public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * out_srcSet
// Parameter: CString in_strFilePath
//************************************
procStatus CRawImgLoader::Load(ImgSrcList* out_srcSet)
{
	//ASSERT(FALSE);
	if (!m_sFileName.CompareNoCase(""))
	{
		return eFileIOError;
	}
	
	CFile oFile;
	CFileException oFileException;

	procStatus eRetCode = eNormal;
	//if file open is not successful
	if(!oFile.Open(m_sFileName, CFile::modeRead, &oFileException))
	{
		TRACE( "Can't open file %s, error = %u\n",   m_sFileName, oFileException.m_cause );
		CString msg;
		msg.Format(IMP_MSG_FILEOPEN_ERR, oFileException.m_strFileName);
		AfxMessageBox(msg);
		eRetCode = eFileIOError;
	}

	ULONG nFileSize  = oFile.GetLength();
	if(nFileSize > (IMP_SRC_MAXHEIGHT*IMP_SRC_MAXWIDTH))
	{
		AfxMessageBox(IMP_MSG_BIGIMAGE);
		eRetCode = eFileIOError;
	}

	t_RawSize usedSize;
	
	//obtain the size of image
	if(eRetCode == eNormal)	obtainRawSize(nFileSize);
	if ((m_tSize.nWidth * m_tSize.nHeight) == 0)
	{
		eRetCode = eFileIOError;
	}

	//load file
	if(eRetCode == eNormal)
	{	
		BYTE* pImgBuffer;
		BYTE* pBuffer = new BYTE[nFileSize];
		
		if(pBuffer == NULL)
			eRetCode = eNullPointer;
		
		if(eRetCode == eNormal)	
			pImgBuffer = new BYTE[nFileSize * 3];
		
		if(pImgBuffer == NULL)
		{
			delete[] pBuffer;
			eRetCode = eNullPointer;
		}
		else
		{
			oFile.Seek(0, CFile::begin);
			oFile.Read(pBuffer, nFileSize);

			//LPBYTE pBbuf = (LPBYTE)pBuffer;
			//adjust image
			for (INT j=0;j<(m_tSize.nHeight/2);j++)
			{
				for(INT k=0;k<m_tSize.nWidth;k++)
				{	
					BYTE temp = *(pBuffer+j*m_tSize.nWidth+k);
					*(pBuffer+j*m_tSize.nWidth+k) = *(pBuffer + (m_tSize.nHeight- j -1)*m_tSize.nWidth+k);
					*(pBuffer + (m_tSize.nHeight- j -1)*m_tSize.nWidth+k) = temp;
				}
			}

			for(INT m=0, n=0; (m< nFileSize)&&(n< nFileSize*3); m++, n+=3)
			{
				*(pImgBuffer + n + 0) = *(pBuffer+m);
				*(pImgBuffer + n + 1) = *(pBuffer+m);
				*(pImgBuffer + n + 2) = *(pBuffer+m);
			}
			//convert from raw array to source
			eRetCode = rawToSource(pImgBuffer, out_srcSet);
		}
		delete[] pBuffer;
	}
	
	oFile.Close();
	return eRetCode;
}

//************************************
// Method:    optimizeSize
// FullName:  CRawImgLoader::optimizeSize
// Access:    public 
// Returns:   t_RawSize
// Qualifier:
// Parameter: ULONG in_nFileSize
//************************************
t_RawSize CRawImgLoader::optimizeSize(ULONG in_nFileSize)
{
	return t_RawSize();
}

//************************************
// Method:    obtainRawSize
// FullName:  CRawImgLoader::obtainRawSize
// Access:    public 
// Returns:   procStatus
// Qualifier:
// Parameter: ULONG in_filesize
//************************************
void CRawImgLoader::obtainRawSize(ULONG in_filesize)
{
	if ((m_tSize.nHeight * m_tSize.nWidth) == 0)
	{
		AfxMessageBox(IMP_MSG_AUTOADJUST);
		m_tSize = optimizeSize(in_filesize); //<-- for the future
	}
	else
	{
		//if user define size -->  check it
		if((m_tSize.nHeight * m_tSize.nWidth) != in_filesize)
		{
			if(AfxMessageBox(IMP_MSG_ADJUSTSIZE, MB_YESNO) == IDOK)
			{
				m_tSize = optimizeSize(in_filesize); //<-- for the future
			}
			else
			{
				m_tSize.nHeight = m_tSize.nWidth = 0;
			}
		}
	}
}

//************************************
// Method:    rawToSource
// FullName:  CRawImgLoader::rawToSource
// Access:    protected 
// Returns:   procStatus
// Qualifier:
// Parameter: LPVOID pBuffer
// Parameter: ImgSrcList out_ImgSrcList
//************************************
procStatus CRawImgLoader::rawToSource( LPVOID pBuffer, ImgSrcList* out_ImgSrcList )
{

	procStatus eRetCoce = eNormal;
	
	BITMAPINFO t_BMPinfo;
	BITMAPINFOHEADER* pBMPInfoHeader = &(t_BMPinfo.bmiHeader); 
	memset(pBMPInfoHeader, 0, sizeof(BITMAPINFOHEADER));
	//Create bitmap header	
	pBMPInfoHeader->biSize			= sizeof(BITMAPINFOHEADER);
	pBMPInfoHeader->biWidth			= m_tSize.nWidth;
	pBMPInfoHeader->biHeight		= m_tSize.nHeight;
	pBMPInfoHeader->biPlanes		= 1;
	pBMPInfoHeader->biCompression	= BI_RGB;
	pBMPInfoHeader->biBitCount		= IMP_MONOBMP_BITS * 3;
	pBMPInfoHeader->biSizeImage		= m_tSize.nWidth * m_tSize.nHeight * 3;

	Bitmap* pBmp = Bitmap::FromBITMAPINFO(&t_BMPinfo,pBuffer);
	CImgSource* pImgSrc = new CImgSource();

	pImgSrc->AttachSource(pBmp);
	pImgSrc->SetName(m_sFileName);
	pImgSrc->SetType(eSrcMonoBitmap);
	
	t_OpCap OperationCap;
	OperationCap.flagFourier = TRUE;
	OperationCap.flagBitoperation = TRUE;
	OperationCap.flagHistogram = TRUE;
	pImgSrc->SetOpCap(OperationCap);
	out_ImgSrcList->Add(pImgSrc);

#ifdef _DEBUG
	CLSID pngClsid;
	CUtility::GetEncoderClsid(L"image/bmp", &pngClsid);
	Status res = pBmp->Save(L".\\temp.bmp", &pngClsid, NULL);	
#endif
	return eRetCoce;
}


