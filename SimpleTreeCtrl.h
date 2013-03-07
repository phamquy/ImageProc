//
// SimpleTreeCtrl.h : header file
// by Ozgur Aydin Yuksel ozgur@machsim.com
//

#ifndef SIMPLE_TREE_CTRL_H
#define SIMPLE_TREE_CTRL_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <vector>

#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lp)   ((int)(short)LOWORD(lp))
#endif

#ifndef GET_Y_LPARAM
#define GET_Y_LPARAM(lp)   ((int)(short)HIWORD(lp))
#endif

/////////////////////////////////////////////////////////////////////////////
// MyTreeCtrl window

class CSimpleTreeCtrl : public CTreeCtrl
{
public:

public:
	class TreeCtrlItem {
	public:
		friend class CSimpleTreeCtrl ;

	public:
		TreeCtrlItem ( CString name ) ;
		virtual ~TreeCtrlItem () ;

		//
		//Item Access Functions
		//
		CString				getName () ;
		void				setName ( CString name ) ;
		HTREEITEM			getHandle ( void ) ;	// Just to access all CTreeCtrl functionality
		void				setTextColor ( COLORREF color )  ;
		void				setBkColor ( COLORREF color )  ;

		//
		//Parent - Child access for easy usage
		//
		int					getNumChildren ()  ;
		void				addChild ( TreeCtrlItem* item ) ;
		void				removeChild ( TreeCtrlItem* item ) ;
		TreeCtrlItem*		getChild ( int i )  ;
		TreeCtrlItem*		getParent ( )  ;



		//
		//Virtual Functions
		//
		virtual void		onSelected   ( void ) {} ;		// will be called on selection
		virtual void		onUnSelected ( void ) {} ;		// will be called when selected item looses his focus
		virtual void		onRClick    ( CPoint pos ) {} ;	//@tricky: pos is in screen coordinates
		virtual void		onLDblClick ( void ) {  AfxMessageBox("asdasd"); } ;
		virtual void		postInsert  ( void ) {} ;		// will be called after item is inserted to the tree

	protected:
		CString							m_name ;
		HTREEITEM						m_hItem ;
		TreeCtrlItem					*m_parent ;
		CSimpleTreeCtrl					*m_treeCtrl ;
		std::vector<TreeCtrlItem*>		m_children ;
		COLORREF						m_bkColor ;
		COLORREF						m_color ;
	};
	
public:
	friend TreeCtrlItem ;

	CSimpleTreeCtrl();
	virtual ~CSimpleTreeCtrl();

	// only first level nodes
	int					getNumChildren ( void ) { return m_itemList.size() ; } ;
	TreeCtrlItem*		getChild ( int idx ) { return m_itemList[idx] ; } ;

	void InsertItem ( TreeCtrlItem *item, TreeCtrlItem *parent = NULL ) ;
	BOOL SelectItem ( TreeCtrlItem *item );
	BOOL DeleteItem ( TreeCtrlItem *item );
	BOOL DeleteAllItems( );
	

// Operations
public:
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimpleTreeCtrl)
	//}}AFX_VIRTUAL


	virtual void		selChanged ( TreeCtrlItem *item ) {} ;
	virtual void		lClick ( TreeCtrlItem *item ) {} ;
	virtual void		lDblClick ( TreeCtrlItem *item ) {} ;
	virtual void		rClick ( TreeCtrlItem *item ) {} ;
	virtual void		postCreate ( void ) {} ;
	
	void				setSelectedItem ( TreeCtrlItem *item, bool select = false ) ;

protected:
	std::vector<TreeCtrlItem *>			m_itemList ;
	TreeCtrlItem						*m_selectedItem ;

	// Generated message map functions
	//{{AFX_MSG(CSimpleTreeCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDblclk(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeleteItem(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCustomdraw ( NMHDR* pNMHDR, LRESULT* pResult ) ;
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(SIMPLE_TREE_CTRL_H)
