// Utility.h: interface for the CUtility class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UTILITY_H__321A6BD6_D07E_44B1_A606_F72B966785F6__INCLUDED_)
#define AFX_UTILITY_H__321A6BD6_D07E_44B1_A606_F72B966785F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ImgSource.h"
#include "Include.h"	// Added by ClassView

class CUtility  
{
public:
	static CString MessageTranslate(procStatus eRetCode);
	static CString GetFileName(CString sPath);
	static CString GetTransSuffixName(TransformFunction eType);
	static FileType GetFileType(LPCTSTR lpszPathName);
	static Color GetMonoPixel(BYTE in_val, SourceType in_eType );
	static BYTE GetMonoPixelValue(Color in_px, SourceType in_eType);
	static BYTE Normalize(INT in_nVal,NormalizeMode in_eMode);
	static Color GetBlue(Color in_color);
	static Color GetGreen(Color in_color);
	static Color GetRed(Color in_color);
	static Color Grayscalize(Color in_oColor);
	static int GetEncoderClsid(const WCHAR* format, CLSID* pClsid);
	static procStatus Add2Source(CImgSource* in_pSource1, CImgSource* in_pSource2, CImgSource* out_pImdRes);
	static CImgSource* Sub2Source(CImgSource* in_pSource1, CImgSource* in_pSource2);
	static CImgSource* Multi2Source(CImgSource* in_pSource1, CImgSource* in_pSource2);
	CUtility();
	virtual ~CUtility();

};

#endif // !defined(AFX_UTILITY_H__321A6BD6_D07E_44B1_A606_F72B966785F6__INCLUDED_)
