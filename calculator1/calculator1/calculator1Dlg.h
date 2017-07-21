
// calculator1Dlg.h : 头文件
//

#pragma once


// Ccalculator1Dlg 对话框
class Ccalculator1Dlg : public CDialogEx
{
// 构造
public:
	void SaveValue1();
	Ccalculator1Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR1_DIALOG };
#endif

	CEdit	m_edit;
	CString	m_str;

	//输入的2个值
	double m_fNumber1;
	double m_fNumber2;

	//储存值
	double m_m;

	//保存计算符号 0='+',1='-',2='*',3='/'
	int m_iSign;

	//计算次数
	int m_time;

	//输入数据
	int m_number;

	//正负号
	int m_symbol;

	//进制
	int m_num;
	int m_2;

	//计算
	void Calculator();

	//字符串转换
	void str_to_double(double f);

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnMyAbout();
	afx_msg void OnButtonBack();
	afx_msg void OnButtonClearall();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnButton0();
	afx_msg void OnButtonPoint();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonMinus();
	afx_msg void OnButtonMultiply();
	afx_msg void OnButtonDivide();
	afx_msg void OnButtonEqual();
	afx_msg void OnButtonMod();
	afx_msg void OnButtonSquare();
	afx_msg void OnButtonSqrt();
	afx_msg void OnButtonPrecent();
	afx_msg void OnButtonReciprocal();
	afx_msg void OnButtonPositive_or_negative();
	afx_msg void OnButtonClear();
	afx_msg void OnButtonMS();
	afx_msg void OnButtonMR();
	afx_msg void OnButtonMC();
	afx_msg void OnButtonMadd();
	afx_msg void OnButtonMminus();
	afx_msg void OnButtonSin();
	afx_msg void OnButtonCos();
	afx_msg void OnButtonTan();
	afx_msg void OnButton00();
	afx_msg void OnButtonPI();
	afx_msg void OnButtonN();
	afx_msg void OnButtonX_Y();
	afx_msg void OnButtonLog();
	afx_msg void OnButtonLn();
	afx_msg void OnButtonNot();
	afx_msg void OnButtonAnd();
	afx_msg void OnRadioChange_2();
	afx_msg void OnFineClose();
	afx_msg void OnRadioChange_10();
	afx_msg void OnHelpAbout();
	afx_msg void OnButtonOr();
	afx_msg void OnButtonXol();
};
