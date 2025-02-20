﻿
// MrJackInLondonDlg.cpp: 구현 파일
//
#include <iostream>
#include "pch.h"
#include "framework.h"
#include "MrJackInLondon.h"
#include "MrJackInLondonDlg.h"
#include "afxdialogex.h"
#include "MrJackInLondonInGame.h"
#include "MrJackInLondonHTP.h"
#include "Client.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMrJackInLondonDlg 대화 상자



CMrJackInLondonDlg::CMrJackInLondonDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MRJACKINLONDON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMrJackInLondonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BT_HTP, m_button_Rule);
	DDX_Control(pDX, IDC_BT_START, m_button_Play);
}

BEGIN_MESSAGE_MAP(CMrJackInLondonDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_BT_START, &CMrJackInLondonDlg::OnBnClickedBtStart)
	ON_BN_CLICKED(IDC_BT_HTP, &CMrJackInLondonDlg::OnBnClickedBtHtp)
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()


// CMrJackInLondonDlg 메시지 처리기

BOOL CMrJackInLondonDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	/*
	CMrJackInLondonInGame dialogig;
	dialogig.DoModal();
	*/
	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_png_image_of_Main.Load(L"res\\Mr_Jack_Title.png");
	m_button_Play.LoadBitmaps(IDB_BITMAP_PLAY_DEF, IDB_BITMAP_PLAY_ON, NULL, NULL);
	m_button_Play.SizeToContent();
	GetClientRect(&m_rect);
	SetWindowPos(&wndTop, 0, 0, m_png_image_of_Main.GetWidth() / 3, m_png_image_of_Main.GetHeight() / 3, SWP_SHOWWINDOW);
	//GetDlgItem(IDC_BT_GAMEPLAY)->MoveWindow(width/2 , 2 * height/3, width/2, 2*height / 3);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMrJackInLondonDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMrJackInLondonDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		//CDialogEx::OnPaint();
		CPaintDC dc(this);
		//m_png_image_of_Main.Draw(dc, 0, 0);

		GetClientRect(&m_rect);
		m_png_image_of_Main.StretchBlt(dc.m_hDC, 0, 0, m_rect.right - m_rect.left, m_rect.bottom - m_rect.top, SRCCOPY);
		m_button_Play.LoadBitmaps(IDB_BITMAP_PLAY_DEF, IDB_BITMAP_PLAY_ON, NULL, NULL);
		m_button_Play.SizeToContent();
		m_button_Rule.LoadBitmaps(IDB_BITMAP_RULE_DEF, IDB_BITMAP_RULE_ON, NULL, NULL);
		m_button_Rule.SizeToContent();
		
		//SetWindowPos(&wndTop, 0, 0, rectCtl.right - rectCtl.left, rectCtl.bottom - rectCtl.top, SWP_SHOWWINDOW);
		
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMrJackInLondonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMrJackInLondonDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	GetClientRect(&m_rect);
	
	Invalidate();

	/*pCt1 = GetDlgItem(IDD_MRJACKINLONDON_DIALOG);

	pCt1->GetWindowRect(&rectCtl);
	ScreenToClient(&rectCtl);

	pCt1->MoveWindow(rectCtl.left, rectCtl.top, cx -2*rectCtl.left, cy - rectCtl.top-rectCtl.left, TRUE);*/
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}

// 게임 시작 버튼 클릭 시
void CMrJackInLondonDlg::OnBnClickedBtStart()
{
	CClient clientsocket;
	//SOCKET sock;
	if (clientsocket.Create() == false)
	{
		int err = clientsocket.GetLastError();
		TRACE("create error: %d\n", err);
	}
	if (clientsocket.Connect(_T(IP), PORT) == false)
	{
		int err = clientsocket.GetLastError();
		TRACE("connect error: %d\n", err);
	}

	/*char role[32] = "";
	clientsocket.Receive(role, sizeof(role), 0);
	if (!strcmp(role, "jack")) {
		MessageBox(_T("i am jack"));
	}
	else if (!strcmp(role, "police")) {
		MessageBox(_T("i am a police officer"));
	}*/

	//TRACE("\n~~~~~~~~~~~clientsocket address: %#x~~~~~~~~~~n", &clientsocket);
	CMrJackInLondonInGame dialog1(nullptr, &clientsocket);
	dialog1.DoModal();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CMrJackInLondonDlg::OnBnClickedBtHtp()
{
	CMrJackInLondonRule dialog2;
	dialog2.DoModal();
	/*
	TCHAR path[_MAX_PATH];

	GetModuleFileName(NULL, path, sizeof path);
	CString strpath = path;
	int i = strpath.ReverseFind('\\');
	strpath = strpath.Left(i);
	CString realpath = strpath + "/HTP.pdf";
	ShellExecute(NULL, _T("open"), _T("MicrosoftEDGE.EXE"), realpath , NULL, SW_SHOW);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*/
}


void CMrJackInLondonDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnGetMinMaxInfo(lpMMI);
}

