// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "ImageProcessing.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
/*
// MAINTAIN [3/3/2009 QUYPS]
	ON_COMMAND(ID_TREE_VIEW, OnTreeView)
	ON_UPDATE_COMMAND_UI(ID_TREE_VIEW, OnUpdateTreeView)
*/
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	

	//==================== Create instant bar and tree [12/27/2007 QUYPS]=========================
// MAINTAIN [3/3/2009 QUYPS]
// 	if (!m_wndInstantBar.Create(_T("Instant Bar"), this, 127))
// 	{
// 		TRACE0("Failed to create instant bar\n");
// 		return -1;		// fail to create
// 	}
// 	if (!m_wndIBTree.Create(WS_CHILD|WS_VISIBLE|
// 		TVS_HASLINES|TVS_HASBUTTONS|TVS_LINESATROOT,
// 		CRect(0, 0, 0, 0), &m_wndInstantBar, 100))
// 	{
// 		TRACE0("Failed to create instant bar child\n");
// 		return -1;		// fail to create
// 	}
// 	m_wndIBTree.ModifyStyleEx(0, WS_EX_CLIENTEDGE);
// 	//m_treeCtrl.SetBkColor( RGB (125, 255, 225 ) ) ;
// 	m_wndIBTree.SetItemHeight( 20 ) ;
// 	
// 	// TESTING TEMPORARY [12/28/2007 QUYPS] add items..
// 	MyNewTreeCtrl::NewTreeCtrlItem *tItem = NULL ;
// 	MyNewTreeCtrl::NewTreeCtrlItem *ttItem = NULL ;
// 	CString lbl ;
// 	for ( int i = 0; i < 10 ; i++  ) {
// 		lbl.Format ( "Image_%i", i ) ;
// 		tItem = new MyNewTreeCtrl::NewTreeCtrlItem ( lbl ) ;
// 		m_wndIBTree.InsertItem( tItem ) ;
// 		
// 		tItem->setBkColor( RGB ( i * 25 + 5, 255 , (10-i ) * 25 + 5 ) ) ;
// 		
// 		for ( int j = 0; j < 10 ; j++  ) {
// 			lbl.Format ( "ProcessResult%i_%i", i, j ) ;
// 			ttItem = new MyNewTreeCtrl::NewTreeCtrlItem ( lbl ) ;
// 			m_wndIBTree.InsertItem( ttItem, tItem ) ;
// 			
// 			ttItem->setBkColor( RGB ( 255 , j * 25 + 5, (10-j ) * 25 + 5 ) ) ;
// 		}
// 	}

	//==================== Setting style [12/27/2007 QUYPS]=========================
// MAINTAIN [3/3/2009 QUYPS]
// 	m_wndInstantBar.SetSCBStyle(m_wndInstantBar.GetSCBStyle() |	SCBS_SIZECHILD);
// 	m_wndInstantBar.SetBarStyle(m_wndInstantBar.GetBarStyle() |	CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC);
// 	m_wndInstantBar.EnableDocking(CBRS_ALIGN_LEFT|CBRS_ALIGN_RIGHT);

// #ifdef _SCB_REPLACE_MINIFRAME
//  	m_pFloatingFrameClass = RUNTIME_CLASS(CSCBMiniDockFrameWnd);
// #endif //_SCB_REPLACE_MINIFRAME
// 
// 	DockControlBar(&m_wndInstantBar, AFX_IDW_DOCKBAR_LEFT);
// 	//ShowControlBar(&m_wndInstantBar, TRUE, FALSE);
// 	m_wndInstantBar.ShowWindow(SW_SHOWNORMAL);



	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers


void CMainFrame::OnTreeView() 
{
	// TODO: Add your command handler code here
// MAINTAIN [3/3/2009 QUYPS]
//	ShowControlBar(&m_wndInstantBar, !m_wndInstantBar.IsVisible(), FALSE);
}


void CMainFrame::OnUpdateTreeView(CCmdUI* pCmdUI) 
{
// MAINTAIN [3/3/2009 QUYPS]
// 	// TODO: Add your command update UI handler code here
// 	pCmdUI->Enable();
// 	pCmdUI->SetCheck(m_wndInstantBar.IsVisible());
}
