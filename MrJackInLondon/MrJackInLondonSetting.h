﻿#pragma once


// MrJackInLondonSetting 대화 상자

class CMrJackInLondonSetting : public CDialogEx
{
	DECLARE_DYNAMIC(CMrJackInLondonSetting)

public:
	CMrJackInLondonSetting(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMrJackInLondonSetting();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Setting };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
