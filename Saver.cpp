// Saver.cpp: implementation of the CSaver class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ImageProcessing.h"
#include "Saver.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSaver::CSaver()
{
	m_sFilePath = "";
}

CSaver::~CSaver()
{

}


//************************************
// Method:    Save
// FullName:  CSaver::Save
// Access:    virtual public 
// Returns:   procStatus
// Qualifier:
// Parameter: CImgSource * in_pSource
//************************************
procStatus CSaver::Save(CImgSource* in_pSource)
{
	ASSERT(FALSE);
	return eNormal;
}
