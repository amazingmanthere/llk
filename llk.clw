; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CGameDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "llk.h"
LastPage=0

ClassCount=8
Class1=CLlkApp
Class2=CLlkDoc
Class3=CLlkView
Class4=CMainFrame

ResourceCount=5
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=CRankDlg
Resource3=IDD_DLG_RANK
Class7=CSettingDlg
Resource4=IDD_DLG_SETTING_MUSIC
Class8=CGameDlg
Resource5=IDD_DLG_SETTING_GAME

[CLS:CLlkApp]
Type=0
HeaderFile=llk.h
ImplementationFile=llk.cpp
Filter=N

[CLS:CLlkDoc]
Type=0
HeaderFile=llkDoc.h
ImplementationFile=llkDoc.cpp
Filter=N

[CLS:CLlkView]
Type=0
HeaderFile=llkView.h
ImplementationFile=llkView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CLlkView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=IDM_SETTING




[CLS:CAboutDlg]
Type=0
HeaderFile=llk.cpp
ImplementationFile=llk.cpp
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
Command1=IDM_GAME_START
Command2=IDM_RANK
Command3=ID_APP_EXIT
Command4=IDM_VOICE
Command5=IDM_MUSIC
Command6=IDM_SETTING
Command7=ID_APP_ABOUT
CommandCount=7

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

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DLG_RANK]
Type=1
Class=CRankDlg
ControlCount=12
Control1=65535,static,1342308352
Control2=65535,static,1342308352
Control3=65535,static,1342308352
Control4=65535,static,1342308352
Control5=65535,static,1342308352
Control6=65535,static,1342308352
Control7=65535,static,1342308352
Control8=IDC_RANK1,static,1342308352
Control9=IDC_RANK2,static,1342308352
Control10=IDC_RANK3,static,1342308352
Control11=IDC_RANK4,static,1342308352
Control12=IDC_RANK5,static,1342308352

[CLS:CRankDlg]
Type=0
HeaderFile=RankDlg.h
ImplementationFile=RankDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_RANK1
VirtualFilter=dWC

[CLS:CSettingDlg]
Type=0
HeaderFile=SettingDlg.h
ImplementationFile=SettingDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_FILE
VirtualFilter=dWC

[DLG:IDD_DLG_SETTING_MUSIC]
Type=1
Class=CSettingDlg
ControlCount=5
Control1=IDC_FILE,combobox,1344340290
Control2=IDC_BTN_OPEN,button,1342242816
Control3=IDOK,button,1342242816
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC,button,1342177287

[DLG:IDD_DLG_SETTING_GAME]
Type=1
Class=CGameDlg
ControlCount=0

[CLS:CGameDlg]
Type=0
HeaderFile=GameDlg.h
ImplementationFile=GameDlg.cpp
BaseClass=CDialog
Filter=D

