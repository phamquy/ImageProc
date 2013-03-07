#pragma once


// CTEST dialog

class CTEST : public CDialog
{
	DECLARE_DYNAMIC(CTEST)

public:
	CTEST(CWnd* pParent = NULL);   // standard constructor
	virtual ~CTEST();

// Dialog Data
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
