; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CImgView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "ImageProcessing.h"
LastPage=0

ClassCount=9
Class1=CImgApp
Class2=CImgDoc
Class3=CImgView
Class4=CMainFrame

ResourceCount=6
Resource1=IDD_DLG_LAPLACIAN
Resource2=IDD_DLG_THRE
Class5=CChildFrame
Class6=CAboutDlg
Resource3=IDR_IMAGEPTYPE
Class7=CRawInfoDlg
Resource4=IDD_RAW_INFOR
Class8=CLaplacianSelectDlg
Resource5=IDR_MAINFRAME
Class9=CThresoldDlg
Resource6=IDD_ABOUTBOX

[CLS:CImgApp]
Type=0
HeaderFile=ImageProcessing.h
ImplementationFile=ImageProcessing.cpp
Filter=N
LastObject=CImgApp
BaseClass=CWinApp
VirtualFilter=AC

[CLS:CImgDoc]
Type=0
HeaderFile=ImgDoc.h
ImplementationFile=ImgDoc.cpp
Filter=N
BaseClass=CDocument
VirtualFilter=DC
LastObject=ID_FILE_OPEN

[CLS:CImgView]
Type=0
HeaderFile=ImgView.h
ImplementationFile=ImgView.cpp
Filter=C
LastObject=CImgView
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame
BaseClass=CMDIFrameWnd
VirtualFilter=fWC


[CLS:CChildFrame]
Type=0
HeaderFile=ChildFrm.h
ImplementationFile=ChildFrm.cpp
Filter=M
LastObject=CChildFrame


[CLS:CAboutDlg]
Type=0
HeaderFile=ImageProcessing.cpp
ImplementationFile=ImageProcessing.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_PRINT_SETUP
Command4=ID_FILE_MRU_FILE1
Command5=ID_APP_EXIT
Command6=ID_VIEW_TOOLBAR
Command7=ID_VIEW_STATUS_BAR
Command8=ID_APP_ABOUT
CommandCount=8

[TB:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_IMAGEPTYPE]
Type=1
Class=CImgView
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_CLOSE
Command4=ID_FILE_SAVE
Command5=ID_FILE_SAVE_AS
Command6=ID_FILE_PRINT
Command7=ID_FILE_PRINT_PREVIEW
Command8=ID_FILE_PRINT_SETUP
Command9=ID_FILE_MRU_FILE1
Command10=ID_APP_EXIT
Command11=ID_EDIT_UNDO
Command12=ID_EDIT_CUT
Command13=ID_EDIT_COPY
Command14=ID_EDIT_PASTE
Command15=ID_VIEW_TOOLBAR
Command16=ID_VIEW_STATUS_BAR
Command17=ID_WINDOW_NEW
Command18=ID_WINDOW_CASCADE
Command19=ID_WINDOW_TILE_HORZ
Command20=ID_WINDOW_ARRANGE
Command21=ID_APP_ABOUT
CommandCount=21

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_RAW_INFOR]
Type=1
Class=CRawInfoDlg
ControlCount=6
Control1=IDC_EDIT_COLS,edit,1350631552
Control2=IDC_EDIT_ROWS,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_CMD_OK,button,1342242816
Control6=IDC_CMD_CANCEL,button,1342242816

[CLS:CRawInfoDlg]
Type=0
HeaderFile=RawInfoDlg.h
ImplementationFile=RawInfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CRawInfoDlg
VirtualFilter=dWC

[DLG:IDD_DLG_LAPLACIAN]
Type=1
Class=CLaplacianSelectDlg
ControlCount=7
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_RD_LAPOP,button,1342312457
Control6=IDC_RADIO3,button,1342181385
Control7=IDC_RADIO4,button,1342181385

[CLS:CLaplacianSelectDlg]
Type=0
HeaderFile=LaplacianSelectDlg.h
ImplementationFile=LaplacianSelectDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CLaplacianSelectDlg
VirtualFilter=dWC

[DLG:IDD_DLG_THRE]
Type=1
Class=CThresoldDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_RD_PASS,button,1342308361
Control3=IDC_RD_PASS2,button,1342177289
Control4=IDC_EDIT2,edit,1350631552
Control5=IDC_STATIC,static,1342308352

[CLS:CThresoldDlg]
Type=0
HeaderFile=ThresoldDlg.h
ImplementationFile=ThresoldDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CThresoldDlg

