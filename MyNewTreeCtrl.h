// MyNewTreeCtrl.h: interface for the MyNewTreeCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYNEWTREECTRL_H__058210E8_A15C_44EC_9F99_AB61044BDFC5__INCLUDED_)
#define AFX_MYNEWTREECTRL_H__058210E8_A15C_44EC_9F99_AB61044BDFC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "SimpleTreeCtrl.h"
#include "ImgDoc.h"
 
class CTReePopup ;

class MyNewTreeCtrl : public CSimpleTreeCtrl  
{
public:

	//=========================== TREE ITEM DEFINITION============================
	class NewTreeCtrlItem : public CSimpleTreeCtrl::TreeCtrlItem {
	public:
		NewTreeCtrlItem ( CString name ) ;
		~NewTreeCtrlItem () {} ;

		virtual void		onSelected  ( void ) ;
		virtual void		onRClick    ( CPoint pos ) ;
		virtual void		onLDblClick ( void ) ;
		virtual void		postInsert ( void ) ;
		
		// ADD [12/28/2007 QUYPS]
		CImgDoc*			getDocument(){return m_pDocument;};
		VOID				setDocument(CImgDoc* in_pDoc);
		
	protected:
		CImgDoc* m_pDocument;
	};

	//============================================================================

public:
	MyNewTreeCtrl();
	virtual ~MyNewTreeCtrl();
	virtual void		rClick ( TreeCtrlItem *item ) ;


protected:
};

#endif // !defined(AFX_MYNEWTREECTRL_H__058210E8_A15C_44EC_9F99_AB61044BDFC5__INCLUDED_)
