// ImgProcessor.cpp: implementation of the CImgProcessor class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "ImgProcessor.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CImgProcessor::CImgProcessor()
{
	m_eOpType = eOpNone;
}

CImgProcessor::~CImgProcessor()
{

}

procStatus CImgProcessor::ApplyProcessor(CImgSource* in_pImgSrc, CImgSource* out_ImgResult)
{
	ASSERT(FALSE);
	return eNormal;
}