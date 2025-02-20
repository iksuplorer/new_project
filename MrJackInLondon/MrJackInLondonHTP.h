﻿#pragma once


// MrJackInLondonHTP 대화 상자

class CMrJackInLondonRule : public CDialogEx
{
	DECLARE_DYNAMIC(CMrJackInLondonRule)

public:
	CMrJackInLondonRule(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CMrJackInLondonRule();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_HTP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
private:
	int i_page_num;
public:
	afx_msg void OnPaint();
	afx_msg void OnBnClickedHtpbPrev();
	afx_msg void OnBnClickedHtpbNext();
};
