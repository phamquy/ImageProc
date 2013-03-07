// MyNewTreeCtrl.cpp: implementation of the MyNewTreeCtrl class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MyNewTreeCtrl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif



//==============================TREE ITEM DEFINITION===================================
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MyNewTreeCtrl::NewTreeCtrlItem::NewTreeCtrlItem ( CString name )
: MyNewTreeCtrl::TreeCtrlItem ( name ) 
{
}

void MyNewTreeCtrl::NewTreeCtrlItem::onSelected ( void )
{
	CString msg ;
	msg.Format( "NewTreeCtrlItem::onSelected () for %s" , m_name ) ;
	//AfxMessageBox( msg ) ;
}

void MyNewTreeCtrl::NewTreeCtrlItem::onRClick ( CPoint pos )
{
	CString msg ;
	msg.Format( "NewTreeCtrlItem::onRClick () for %s" , m_name ) ;
	AfxMessageBox( msg ) ;
}

void MyNewTreeCtrl::NewTreeCtrlItem::onLDblClick ( void )
{
	CString msg ;
	msg.Format( "NewTreeCtrlItem::onLDblClick () for %s" , m_name ) ;
	AfxMessageBox( msg ) ;
}

void MyNewTreeCtrl::NewTreeCtrlItem::postInsert ( void )
{
}

//=====================================================================================






//==============================MY TREE DEFINITION=====================================
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MyNewTreeCtrl::MyNewTreeCtrl()
{
}

MyNewTreeCtrl::~MyNewTreeCtrl()
{
}

void MyNewTreeCtrl::rClick ( TreeCtrlItem *item ) 
{
}
