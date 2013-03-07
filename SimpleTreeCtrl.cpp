// SimpleTreeCtrl.cpp : implementation file
//

#include "stdafx.h"
#include "SimpleTreeCtrl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSimpleTreeCtrl::TreeCtrlItem


CSimpleTreeCtrl::TreeCtrlItem::TreeCtrlItem ( CString name ) 
{
	m_name = name ;
	m_parent = NULL ;
	m_hItem = NULL ;
	m_treeCtrl = NULL ;

	m_bkColor = RGB ( 255, 255, 255 ) ;
	m_color = RGB ( 0, 0, 0 ) ;
} ;

CSimpleTreeCtrl::TreeCtrlItem::~TreeCtrlItem () 
{
	m_hItem = NULL ;
	for ( int i = 0 ; i < m_children.size(); i++ ) {
		//
		//@tricky: all pointers are deleted at remove item step
		//
		m_children[i] = NULL ;
	}
	m_children.clear() ;

	if ( m_treeCtrl->m_selectedItem == this )
		m_treeCtrl->m_selectedItem = NULL ;
	m_treeCtrl = NULL ;
} ;

CString CSimpleTreeCtrl::TreeCtrlItem::getName () 
{ 
	return m_name ; 
}

void CSimpleTreeCtrl::TreeCtrlItem::setName ( CString name ) 
{
	m_name = name ;
	if ( m_treeCtrl && m_hItem )
		m_treeCtrl->SetItemText ( m_hItem, m_name ) ;

}

int CSimpleTreeCtrl::TreeCtrlItem::getNumChildren () 
{ 
	return m_children.size() ; 
}

void CSimpleTreeCtrl::TreeCtrlItem::addChild ( CSimpleTreeCtrl::TreeCtrlItem* item ) 
{ 
	m_children.push_back( item ) ; 
	item->m_parent = this ;
}

void CSimpleTreeCtrl::TreeCtrlItem::removeChild ( CSimpleTreeCtrl::TreeCtrlItem* item ) 
{
	std::vector<TreeCtrlItem*>::iterator iVec = m_children.begin() ;
	while ( iVec != m_children.end() ) {
		if ( *iVec == item ) {
			item->m_parent = NULL ;
			m_children.erase( iVec ) ;
			break ;
		}
		iVec++ ;
	}

}

CSimpleTreeCtrl::TreeCtrlItem* CSimpleTreeCtrl::TreeCtrlItem::getChild ( int i ) 
{ 
	return m_children[i] ; 
} 

CSimpleTreeCtrl::TreeCtrlItem* CSimpleTreeCtrl::TreeCtrlItem::getParent ( ) 
{ 
	return m_parent ; 
}

void CSimpleTreeCtrl::TreeCtrlItem::setTextColor ( COLORREF color ) 
{ 
	m_color = color ; 
} 

void CSimpleTreeCtrl::TreeCtrlItem::setBkColor ( COLORREF color ) 
{ 
	m_bkColor = color ; 
} 

HTREEITEM	CSimpleTreeCtrl::TreeCtrlItem::getHandle ( void ) 
{
	return m_hItem ;
}

/////////////////////////////////////////////////////////////////////////////
// CSimpleTreeCtrl

CSimpleTreeCtrl::CSimpleTreeCtrl()
{
	m_selectedItem = NULL ;
}

CSimpleTreeCtrl::~CSimpleTreeCtrl()
{
	DeleteAllItems() ;
}


BEGIN_MESSAGE_MAP(CSimpleTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CSimpleTreeCtrl)
	ON_WM_CREATE()
	ON_NOTIFY_REFLECT(NM_DBLCLK, OnDblclk)
	ON_NOTIFY_REFLECT(NM_RCLICK, OnRclick)
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, OnSelchanged)
	ON_NOTIFY_REFLECT(TVN_DELETEITEM, OnDeleteItem)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnCustomdraw )
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSimpleTreeCtrl message handlers

int CSimpleTreeCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CTreeCtrl::OnCreate(lpCreateStruct) == -1)
		return -1;

	postCreate () ;

	return 0;
}

void CSimpleTreeCtrl::OnDblclk(NMHDR* pNMHDR, LRESULT* pResult) 
{
	TreeCtrlItem *item = NULL ;
	HTREEITEM hItem = GetSelectedItem ( ) ;

	if ( hItem ) 
		item = ( TreeCtrlItem *) GetItemData ( hItem ) ;

	selChanged ( item ) ;

	if ( item ) 
		item->onLDblClick () ;

	*pResult = 0;
}

void CSimpleTreeCtrl::OnRclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	//
	//@todo: Get the mouse position here then perform a hit test
	// and notify class with TreeCtrlItem
	// this class makes that right click shall select the item...
	// and send selChanged message if necessary 
	//
	//
	// If mouse is not on any item, that means this is right click
	// for tree it self...
	//
	DWORD Result = GetMessagePos();
	CPoint pos (GET_X_LPARAM(Result), GET_Y_LPARAM(Result));
	CPoint posScr = pos ;
	
	// Retreive the coordinates of the treecrtl viwndow
	CRect cRect ;
	GetWindowRect(&cRect);
	pos.Offset(-cRect.left, -cRect.top);
	HTREEITEM hItem = CTreeCtrl::HitTest( pos ) ;
	if ( hItem ) {
		CTreeCtrl::SelectItem( hItem ) ;

		TreeCtrlItem *item = ( TreeCtrlItem*) GetItemData( hItem ) ;
		rClick ( item ) ;
		if ( item )
			item->onRClick( posScr ) ;
	}
	else
		rClick ( NULL ) ;

	*pResult = 0;
}

void CSimpleTreeCtrl::OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	
	// 
	TreeCtrlItem *item = NULL ;
	item = (TreeCtrlItem *) GetItemData ( pNMTreeView->itemNew.hItem ) ;

	// Call first three ctrl virtual function
	selChanged ( item ) ;

	// First onUnSelected () function for old item
	if ( m_selectedItem )
		m_selectedItem->onUnSelected () ;

	m_selectedItem = item ;

	// Then call item virtual function
	if ( item )
		item->onSelected() ;
	
	*pResult = 0;
}

void CSimpleTreeCtrl::InsertItem( CSimpleTreeCtrl::TreeCtrlItem *item, CSimpleTreeCtrl::TreeCtrlItem *parent )
{

	HTREEITEM hParent = NULL ;
	if ( parent ) {
		hParent = parent->m_hItem ;
		parent->addChild( item ) ;
	}
	else
		m_itemList.push_back( item ) ;

	item->m_hItem = CTreeCtrl::InsertItem ( item->m_name, hParent ) ;
	SetItemData ( item->m_hItem, (DWORD) item ) ;

	item->m_treeCtrl = this ;

	//
	// Let user do something after insert if necessary
	//
	item->postInsert() ;
	
}

BOOL CSimpleTreeCtrl::SelectItem( CSimpleTreeCtrl::TreeCtrlItem *item )
{
	if ( item == NULL )
		return NULL ;
	return CTreeCtrl::SelectItem ( item->m_hItem ) ;
}

BOOL CSimpleTreeCtrl::DeleteItem( CSimpleTreeCtrl::TreeCtrlItem *item )
{
	return  CTreeCtrl::DeleteItem ( item->m_hItem ) ;
}

BOOL CSimpleTreeCtrl::DeleteAllItems ( void )
{
	/*
	First traverse the tree and delete ol Item pointers
	then delete all...
	*/
	for ( int i = 0 ; i < m_itemList.size() ; i++ ){
		m_itemList[i] = NULL ;
	}
	m_itemList.clear() ;
	

	if ( m_hWnd )
		return CTreeCtrl::DeleteAllItems ( ) ;
	
	return TRUE ;
}

void CSimpleTreeCtrl::OnDeleteItem(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;
	// TODO: Add your control notification handler code here
	HTREEITEM hItem = pNMTreeView->itemOld.hItem ;
	TreeCtrlItem *item = (TreeCtrlItem *) GetItemData ( hItem ) ;
	if ( item ) {
		if ( item->getParent () ) {
			item->getParent()->removeChild (item ) ;
		}
		delete item ;
	}
	
	*pResult = 0;
}


void CSimpleTreeCtrl::setSelectedItem( CSimpleTreeCtrl::TreeCtrlItem *item, bool select )
{
	if ( select == true ) {
		HTREEITEM hItem = item->m_hItem ;
		CTreeCtrl::SelectItem ( hItem ) ;
	}
	else
		m_selectedItem = item ;
}

void CSimpleTreeCtrl::OnCustomdraw ( NMHDR* pNMHDR, LRESULT* pResult )
{
	NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>( pNMHDR );
	// Take the default processing unless we set this to something else below.
	*pResult = CDRF_DODEFAULT;
	TreeCtrlItem *bItem = (TreeCtrlItem *) pLVCD->nmcd.lItemlParam ;
	switch (pLVCD->nmcd.dwDrawStage) {
		case CDDS_ITEM:
		case CDDS_POSTPAINT:
		case CDDS_PREERASE:
		case CDDS_POSTERASE:
		case CDDS_ITEMPOSTPAINT :
		case CDDS_ITEMPREERASE :
		case CDDS_ITEMPOSTERASE :
			break ;

		case CDDS_PREPAINT :
			*pResult = CDRF_NOTIFYITEMDRAW  ;
			break ;
		case CDDS_ITEMPREPAINT :
			if ( bItem ) {
				if ( GetSelectedItem() != bItem->getHandle() ) {
					pLVCD->clrTextBk = bItem->m_bkColor ;
					pLVCD->clrText   = bItem->m_color ;
				}
				
			}
			break ;
	}
}