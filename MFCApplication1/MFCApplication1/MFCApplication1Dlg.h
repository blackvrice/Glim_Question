﻿// MFCApplication1Dlg.h: 헤더 파일
//
#define _USE_MATH_DEFINES
#include <thread>
#include <cmath>
#include <random>
#include <ctime>
#include <format>
#include <iostream>
using namespace std;
#pragma once


// CMFCApplication1Dlg 대화 상자
class CMFCApplication1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
private:
	CImage m_image;
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedDraw();
	int m_nStartX;
	int m_nStartY;
	int m_nEndX;
	int m_nEndY;
	int m_nRadius;
	void UpdateDisplay();
	void moveRect();
	void drawCircle(unsigned char* fm, int x, int y);
	bool isInCircle(int i, int j, int nCenterX, int nCenterY);
	afx_msg void OnBnClickedAction();
	BOOL validImagPos(int x, int y);
	afx_msg void OnBnClickedOpen();
};