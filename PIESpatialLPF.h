// PIESpatialLPF.h: interface for the CPIESpatialLPF class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIESPATIALLPF_H__9789A89C_4727_45C0_8185_B558B385B6C6__INCLUDED_)
#define AFX_PIESPATIALLPF_H__9789A89C_4727_45C0_8185_B558B385B6C6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ProcImgEnhancer.h"
#include "Include.h"	// Added by ClassView

class CPIESpatialLPF : public CProcImgEnhancer  
{
public:
	virtual procStatus ApplyProcessor(CImgSource *in_pImgSrc, CImgSource *out_ImgResult);
	CPIESpatialLPF();
	virtual ~CPIESpatialLPF();

};

#endif // !defined(AFX_PIESPATIALLPF_H__9789A89C_4727_45C0_8185_B558B385B6C6__INCLUDED_)
