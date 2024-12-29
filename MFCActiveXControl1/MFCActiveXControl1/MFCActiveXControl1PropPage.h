#pragma once

// MFCActiveXControl1PropPage.h : CMFCActiveXControl1PropPage 속성 페이지 클래스의 선언입니다.


// CMFCActiveXControl1PropPage : 구현에 대해서는 MFCActiveXControl1PropPage.cpp을(를) 참조하세요.

class CMFCActiveXControl1PropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMFCActiveXControl1PropPage)
	DECLARE_OLECREATE_EX(CMFCActiveXControl1PropPage)

// 생성자입니다.
public:
	CMFCActiveXControl1PropPage();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PROPPAGE_MFCACTIVEXCONTROL1 };

// 구현입니다.
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 메시지 맵입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

