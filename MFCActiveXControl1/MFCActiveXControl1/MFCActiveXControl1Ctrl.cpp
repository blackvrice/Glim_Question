// MFCActiveXControl1Ctrl.cpp : CMFCActiveXControl1Ctrl ActiveX 컨트롤 클래스의 구현입니다.

#include "pch.h"
#include "framework.h"
#include "MFCActiveXControl1.h"
#include "MFCActiveXControl1Ctrl.h"
#include "MFCActiveXControl1PropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXControl1Ctrl, COleControl)

// 메시지 맵입니다.

BEGIN_MESSAGE_MAP(CMFCActiveXControl1Ctrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 디스패치 맵입니다.

BEGIN_DISPATCH_MAP(CMFCActiveXControl1Ctrl, COleControl)
	DISP_FUNCTION_ID(CMFCActiveXControl1Ctrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// 이벤트 맵입니다.

BEGIN_EVENT_MAP(CMFCActiveXControl1Ctrl, COleControl)
END_EVENT_MAP()

// 속성 페이지입니다.

// TODO: 필요에 따라 속성 페이지를 추가합니다.  카운트도 이에 따라 증가해야 합니다.
BEGIN_PROPPAGEIDS(CMFCActiveXControl1Ctrl, 1)
	PROPPAGEID(CMFCActiveXControl1PropPage::guid)
END_PROPPAGEIDS(CMFCActiveXControl1Ctrl)

// 클래스 팩터리와 GUID를 초기화합니다.

IMPLEMENT_OLECREATE_EX(CMFCActiveXControl1Ctrl, "MFCACTIVEXCONTRO.MFCActiveXControl1Ctrl.1",
	0x9f093275,0x16a5,0x4659,0x9f,0x01,0xb4,0x0f,0x49,0xbc,0xf8,0x0a)

// 형식 라이브러리 ID와 버전입니다.

IMPLEMENT_OLETYPELIB(CMFCActiveXControl1Ctrl, _tlid, _wVerMajor, _wVerMinor)

// 인터페이스 ID입니다.

const IID IID_DMFCActiveXControl1 = {0x9ed9f641,0xd8fc,0x4391,{0x8d,0xd3,0xb0,0xaf,0xfd,0x1f,0x2c,0xa8}};
const IID IID_DMFCActiveXControl1Events = {0x460ce216,0x5fb3,0x4533,{0xbe,0x80,0x1c,0xc1,0xdd,0x6a,0x9d,0x1c}};

// 컨트롤 형식 정보입니다.

static const DWORD _dwMFCActiveXControl1OleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMFCActiveXControl1Ctrl, IDS_MFCACTIVEXCONTROL1, _dwMFCActiveXControl1OleMisc)

// CMFCActiveXControl1Ctrl::CMFCActiveXControl1CtrlFactory::UpdateRegistry -
// CMFCActiveXControl1Ctrl에 대한 시스템 레지스트리 항목을 추가하거나 제거합니다.

BOOL CMFCActiveXControl1Ctrl::CMFCActiveXControl1CtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: 컨트롤이 아파트 모델 스레딩 규칙을 준수하는지
	// 확인합니다. 자세한 내용은 MFC Technical Note 64를
	// 참조하십시오. 컨트롤이 아파트 모델 규칙에
	// 맞지 않는 경우 다음에서 여섯 번째 매개 변수를 변경합니다.
	// afxRegApartmentThreading을 0으로 설정합니다.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MFCACTIVEXCONTROL1,
			IDB_MFCACTIVEXCONTROL1,
			afxRegApartmentThreading,
			_dwMFCActiveXControl1OleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CMFCActiveXControl1Ctrl::CMFCActiveXControl1Ctrl - 생성자

CMFCActiveXControl1Ctrl::CMFCActiveXControl1Ctrl()
{
	InitializeIIDs(&IID_DMFCActiveXControl1, &IID_DMFCActiveXControl1Events);
	// TODO: 여기에서 컨트롤의 인스턴스 데이터를 초기화합니다.
}

// CMFCActiveXControl1Ctrl::~CMFCActiveXControl1Ctrl - 소멸자

CMFCActiveXControl1Ctrl::~CMFCActiveXControl1Ctrl()
{
	// TODO: 여기에서 컨트롤의 인스턴스 데이터를 정리합니다.
}

// CMFCActiveXControl1Ctrl::OnDraw - 그리기 함수

void CMFCActiveXControl1Ctrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	// TODO: 다음 코드를 사용자가 직접 작성한 그리기 코드로 바꾸십시오.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}

// CMFCActiveXControl1Ctrl::DoPropExchange - 지속성 지원

void CMFCActiveXControl1Ctrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 지속적인 사용자 지정 속성 모두에 대해 PX_ functions를 호출합니다.
}


// CMFCActiveXControl1Ctrl::OnResetState - 컨트롤을 기본 상태로 다시 설정

void CMFCActiveXControl1Ctrl::OnResetState()
{
	COleControl::OnResetState();  // DoPropExchange에 들어 있는 기본값을 다시 설정합니다.

	// TODO: 여기에서 다른 모든 컨트롤의 상태를 다시 설정합니다.
}


// CMFCActiveXControl1Ctrl::AboutBox - "정보" 대화 상자를 사용자에게 표시

void CMFCActiveXControl1Ctrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MFCACTIVEXCONTROL1);
	dlgAbout.DoModal();
}


// CMFCActiveXControl1Ctrl 메시지 처리기
