// PEDCanny.cpp: implementation of the CPEDCanny class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "PEDCanny.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CPEDCanny::CPEDCanny()
{

}

CPEDCanny::~CPEDCanny()
{

}

procStatus CPEDCanny::ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult)
{
	return eNormal;
}
