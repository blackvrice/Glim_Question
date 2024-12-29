#pragma once

// MFCActiveXControl1Ctrl.h : CMFCActiveXControl1Ctrl ActiveX 컨트롤 클래스의 선언입니다.


// CMFCActiveXControl1Ctrl : 구현에 대해서는 MFCActiveXControl1Ctrl.cpp을(를) 참조하세요.

class CMFCActiveXControl1Ctrl : public COleControl
{
	DECLARE_DYNCREATE(CMFCActiveXControl1Ctrl)

// 생성자입니다.
public:
	CMFCActiveXControl1Ctrl();

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 구현입니다.
protected:
	~CMFCActiveXControl1Ctrl();

	DECLARE_OLECREATE_EX(CMFCActiveXControl1Ctrl)    // 클래스 팩터리와 GUID입니다.
	DECLARE_OLETYPELIB(CMFCActiveXControl1Ctrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMFCActiveXControl1Ctrl)     // 속성 페이지 ID입니다.
	DECLARE_OLECTLTYPE(CMFCActiveXControl1Ctrl)		// 형식 이름과 기타 상태입니다.

// 메시지 맵입니다.
	DECLARE_MESSAGE_MAP()

// 디스패치 맵입니다.
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 이벤트 맵입니다.
	DECLARE_EVENT_MAP()

// 디스패치와 이벤트 ID입니다.
public:
	enum {
	};
};

