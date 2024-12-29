// MFCActiveXControl1PropPage.cpp : CMFCActiveXControl1PropPage 속성 페이지 클래스의 구현입니다.

#include "pch.h"
#include "framework.h"
#include "MFCActiveXControl1.h"
#include "MFCActiveXControl1PropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCActiveXControl1PropPage, COlePropertyPage)

// 메시지 맵입니다.

BEGIN_MESSAGE_MAP(CMFCActiveXControl1PropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 클래스 팩터리와 GUID를 초기화합니다.

IMPLEMENT_OLECREATE_EX(CMFCActiveXControl1PropPage, "MFCACTIVEXCONT.MFCActiveXControl1PropPage.1",
	0x86854d6e,0xf7d9,0x41a8,0x90,0x45,0x73,0x23,0x75,0x86,0x04,0x1a)

// CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPageFactory::UpdateRegistry -
// CMFCActiveXControl1PropPage에 대한 시스템 레지스트리 항목을 추가하거나 제거합니다.

BOOL CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MFCACTIVEXCONTROL1_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, nullptr);
}

// CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPage - 생성자

CMFCActiveXControl1PropPage::CMFCActiveXControl1PropPage() :
	COlePropertyPage(IDD, IDS_MFCACTIVEXCONTROL1_PPG_CAPTION)
{
}

// CMFCActiveXControl1PropPage::DoDataExchange - 페이지와 속성 간 데이터를 이동합니다.

void CMFCActiveXControl1PropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CMFCActiveXControl1PropPage 메시지 처리기
