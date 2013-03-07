// ImageProcessing.cpp : Defines the class behaviors for the application.
//


#include "stdafx.h"
#include "ImageProcessing.h"

#include "MainFrm.h"
#include "ChildFrm.h"
#include "ImgDoc.h"
#include "ImgView.h"
#include "Utility.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif




// TEMPORARY [12/19/2007 QUYPS]
#include "2DRaw.h"
#include "Mask.h"
#include "RawImgLoader.h"
#include "ImgSource.h"
#include "FormatedImgLoader.h"
#include "RawImgSaver.h"
#include "Utility.h"
#include "Histogram.h"
#include "FormatedImgSaver.h"
#include "FFTMachine.h"
#include "ProcGrayTransformer.h"
#include "PGTLogTransformer.h"
#include "PGTPowerTransformer.h"
#include "PGTReveser.h"
#include "PGTThresolder.h"
#include "PHEEqualizer.h"
#include "PHEMatcher.h"
#include "PHEStretcher.h"
#include "PEDLaplacian.h"
#include "PEDPrewitt.h"
#include "PEDRobert.h"
#include "PEDSobel.h"


// using gdi+ [12/20/2007 QUYPS]
#include <GdiPlus.h>
using namespace Gdiplus;

/////////////////////////////////////////////////////////////////////////////
// CImgApp

BEGIN_MESSAGE_MAP(CImgApp, CWinApp)
	//{{AFX_MSG_MAP(CImgApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_BTN_TEST, OnBtnTest)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImgApp construction

CImgApp::CImgApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CImgApp object

CImgApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CImgApp initialization

BOOL CImgApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	//CMultiDocTemplate* pDocTemplate;
	m_pDocTemplate = new CMultiDocTemplate(
		IDR_IMAGEPTYPE,
		RUNTIME_CLASS(CImgDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CImgView));
	AddDocTemplate(m_pDocTemplate);

	// create main MDI Frame window
	m_pMainframe = new CMainFrame;
	if (!m_pMainframe->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = m_pMainframe;

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	cmdInfo.m_nShellCommand = CCommandLineInfo::FileNothing;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// The main window has been initialized, so show and update it.
	m_pMainframe->ShowWindow(m_nCmdShow);
	m_pMainframe->UpdateWindow();

	//start GDI+
 	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
 	Status iniGDI = Gdiplus::GdiplusStartup(&m_gdiplusToken, &gdiplusStartupInput, NULL);


	return TRUE;
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CImgApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CImgApp message handlers

void CImgApp::OnBtnTest() 
{

	//COMPLEX


		CFormatedImgLoader oLoader;
		//CRawImgLoader oLoader;
		oLoader.SetFilePath("D:\\Temp\\lenna.jpg");
		ImgSrcList imgList;
		oLoader.Load(&imgList);

		CImgSource* imgSrc = imgList.GetAt(1);
		CImgSource* imgRes = new CImgSource();


		CPEDSobel oPrewitt;
		oPrewitt.ApplyProcessor(imgSrc, imgRes);
	
/*
		CFFTMachine oFFmachine;
		oFFmachine.Run(imgSrc,imgffResults, eForward);
*/		
		CFormatedImgSaver oFsaver;
		oFsaver.m_eOutputFormat = eJpeg;
		oFsaver.m_sFilePath = "D:\\Temp\\lenna_sobel.bmp";
		procStatus sts = oFsaver.Save(imgRes);

// 		CRawImgSaver oSaver;
// 		oSaver.m_sFilePath = "D:\\Temp\\Cycle.raw";
// 		oSaver.Save(imgSrc);



//  	CMask oMask(eLaplacian1_4);
// 		//CImgSource *pResultX = new CImgSource();
// 		//CImgSource *pResultY = new CImgSource();
// 		CImgSource *pResult1 = new CImgSource();
// 		CImgSource *pResult = new CImgSource();
// 	  	oMask.ApplyMask(imgSrc, pResult);		
// 		pResult1 = CUtility::Sub2Source(imgSrc, pResult);
// 
// 		CFormatedImgSaver oFsaver;
// 		oFsaver.m_eOutputFormat = eJpeg;
// 		oFsaver.m_sFilePath = "D:\\Temp\\EarthSrc.jpg";
// 		procStatus sts = oFsaver.Save(imgSrc);
// 
// 		oFsaver.m_sFilePath = "D:\\Temp\\EarthRet.jpg";
// 		sts = oFsaver.Save(pResult);
// 
// 		oFsaver.m_sFilePath = "D:\\Temp\\EarthRet1.jpg";
// 		sts = oFsaver.Save(pResult1);



		//CFormatedImgSaver oSaver;
// 		CRawImgSaver oSaver;
// 		oSaver.m_sFilePath = "D:\\Temp\\Airplane.raw";
// 		procStatus sts1 = oSaver.Save(pResult);
}


int CImgApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	Gdiplus::GdiplusShutdown(m_gdiplusToken);
	return CWinApp::ExitInstance();
}
