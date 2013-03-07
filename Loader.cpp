// Loader.cpp: implementation of the CLoader class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "Loader.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLoader::CLoader()
{
	
}

CLoader::~CLoader()
{

}


//************************************
// Method:    Load
// FullName:  CLoader::Load
// Access:    virtual public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource & out_srcSet
// Parameter: CString in_strFilePath
//************************************
procStatus CLoader::Load( ImgSrcList* out_srcSet )
{
	TRACE("virtual call\n");
	ASSERT(FALSE);
	return eNormal;
}