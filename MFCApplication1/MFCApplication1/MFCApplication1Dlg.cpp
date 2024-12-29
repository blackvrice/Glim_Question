
// MFCApplication1Dlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

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


// CMFCApplication1Dlg 대화 상자



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, m_nStartX(0)
	, m_nStartY(0)
	, m_nEndX(0)
	, m_nEndY(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, Start_x, m_nStartX);
	DDX_Text(pDX, Start_y, m_nStartY);
	DDX_Text(pDX, End_x, m_nEndX);
	DDX_Text(pDX, End_y, m_nEndY);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(DrawButton, &CMFCApplication1Dlg::OnBnClickedDraw)
	ON_BN_CLICKED(DrawButton2, &CMFCApplication1Dlg::OnBnClickedAction)
	ON_BN_CLICKED(DrawButton3, &CMFCApplication1Dlg::OnBnClickedOpen)
	ON_WM_CTLCOLOR()
	ON_WM_CREATE()
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// CMFCApplication1Dlg 메시지 처리기

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCApplication1Dlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication1Dlg::OnBnClickedDraw()
{
	UpdateData(true);
	int nWidth = 1150;
	int nHeight = 660;
	int nBpp = 8;
	int nSttX = m_nStartX;
	int nSttY = m_nStartY;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(10, 25);
	m_nRadius = dis(gen);
	if (m_image != NULL) {
		m_image.Destroy();
	}
	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);
	}
	
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0, nWidth * nHeight);
	drawCircle(fm, nSttX, nSttY);

	UpdateDisplay();
	UpdateData(false);
}

void CMFCApplication1Dlg::moveRect() { 

	double nSttX = m_nStartX;
	double nSttY = m_nStartY;
	int nVectorX = m_nEndX - m_nStartX;
	int nVectorY = m_nEndY - m_nStartY;
	double nIncreaseX;
	double nIncreaseY;
	if (nVectorX == 0) {
		nIncreaseX = 0;
		nIncreaseY = nVectorY > 0 ? 1 : -1;
	}
	else {
		double nRadian = atan2(nVectorX,nVectorY);
		nIncreaseX = sin(nRadian);
		nIncreaseY = cos(nRadian);
	}
	while(true){
		if (abs(nSttX - m_nEndX) < 1 && abs(nSttY - m_nEndY) < 1) break;

		int nWidth = m_image.GetWidth();
		int nHeight = m_image.GetHeight();
		int nPitch = m_image.GetPitch();
		unsigned char* fm = (unsigned char*)m_image.GetBits();

		memset(fm, 0, nWidth * nHeight);
		drawCircle(fm, nSttX, nSttY);
		nSttX += nIncreaseX;
		nSttY += nIncreaseY;
		UpdateDisplay();
		TCHAR path[256] = { 0, };
		GetModuleFileName(NULL, path, 256);
		CString folderPath(path);
		folderPath = folderPath.Left(folderPath.ReverseFind('\\'));
		CString str;
		str.Format(_T("%s\\image\\%d%d.jpg"), folderPath,time(NULL), clock());
		m_image.Save(str);
		Sleep(10);
	}
}

void CMFCApplication1Dlg::UpdateDisplay() {

	CClientDC dc(this);
	m_image.Draw(dc,0, 0);

}

void actionProcess(CMFCApplication1Dlg* dlg) {

	CMFCApplication1Dlg* dlgProcess = dlg;
	dlg->moveRect();
}

void CMFCApplication1Dlg::OnBnClickedAction()
{
	thread _thread0(actionProcess, this);
	_thread0.detach();
}

BOOL CMFCApplication1Dlg::validImagPos(int x, int y) {
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	CRect rect(0, 0, nWidth, nHeight);

	return rect.PtInRect(CPoint(x, y));
}

void CMFCApplication1Dlg::drawCircle(unsigned char* fm, int x, int y) {
	int nCenterX = x + m_nRadius;
	int nCenterY = y + m_nRadius;
	int nPitch = m_image.GetPitch();

	for (int j = y; j < y + m_nRadius * 2; j++) {
		for (int i = x; i < x + m_nRadius * 2; i++) {
			if(isInCircle(i,j, nCenterX, nCenterY) )
				fm[j * nPitch + i] = 255;
		}
	}
}

bool CMFCApplication1Dlg::isInCircle(int i, int j, int nCenterX, int nCenterY) {
	int dX = i - nCenterX;
	int dY = j - nCenterY;
	
	int dDist = dX * dX + dY * dY;

	return m_nRadius * m_nRadius >= dDist;
}

void CMFCApplication1Dlg::OnBnClickedOpen()
{
	static TCHAR BASED_CODE szFilter[] = _T("이미지파일(*.bmp,*.jpg)|*.bmp;*.jpg|모든파일(*.*)|*.*||");
	CFileDialog dlg(TRUE, _T("*.jpg"), _T("image"), OFN_HIDEREADONLY, szFilter);
	if (IDOK == dlg.DoModal()) {
		if (m_image != NULL) {
			m_image.Destroy();
		}
		CString path = dlg.GetPathName();
		m_image.Load(path);

		int nWidth = m_image.GetWidth();
		int nHeight = m_image.GetHeight();
		int nPitch = m_image.GetPitch();
		unsigned char* fm = (unsigned char*)m_image.GetBits();
		int nMinX = nWidth, nMinY = nHeight, nMaxX = 0, nMaxY = 0;
		for (int i = 0; i < nWidth; i++) {
			for (int j = 0; j < nHeight; j++) {
				if (m_image.GetPixel(i,j) == 0xffffff) {
					if (nMinX > i) nMinX = i;
					if (nMinY > j) nMinY = j;
					if (nMaxX < i) nMaxX = i;
					if (nMaxY < j) nMaxY = j;
				}
			}
		}
		int x = (nMinX + nMaxX) / 2, y = (nMinY + nMaxY) / 2;

		UpdateDisplay();
		CString str;
		str.Format(_T("x ( %d, %d)"), x, y);
		CClientDC dc(this);
		dc.SetBkMode(TRANSPARENT);
		dc.SetTextColor(0x0000ff);
		dc.TextOutW(x-4, y-8, str);
	}
}