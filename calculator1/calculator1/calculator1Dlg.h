
// calculator1Dlg.h : ͷ�ļ�
//

#pragma once


// Ccalculator1Dlg �Ի���
class Ccalculator1Dlg : public CDialogEx
{
// ����
public:
	void SaveValue1();
	Ccalculator1Dlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CALCULATOR1_DIALOG };
#endif

	CEdit	m_edit;
	CString	m_str;

	//�����2��ֵ
	double m_fNumber1;
	double m_fNumber2;

	//����ֵ
	double m_m;

	//���������� 0='+',1='-',2='*',3='/'
	int m_iSign;

	//�������
	int m_time;

	//��������
	int m_number;

	//������
	int m_symbol;

	//����
	int m_num;
	int m_2;

	//����
	void Calculator();

	//�ַ���ת��
	void str_to_double(double f);

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
